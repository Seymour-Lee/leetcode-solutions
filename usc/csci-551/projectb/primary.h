#ifndef _PRIMARY_H_
#define _PRIMARY_H_

#include "router.h"

class Primary: public Router{
public:
    Primary(int _s, int _stage) {
        this->s = _s;
        this->stage = _stage;
    }

    ~Primary() {
        ostream& logger = Logger::getInstance();
        logger<<"router 0 closed"<<endl;
    }

    void run(){
        log_file = "stage" + to_string(stage) + ".primary.out";
        global::log_file_name = log_file;
        std::ofstream fout;
        fout.open(log_file);
        Logger::getInstance().rdbuf(fout.rdbuf());
        ostream& logger = Logger::getInstance();
        this->stage1();
        if(this->stage >= 2) this->stage2();
        close(s);
        logger<<"router 0 closed"<<endl;
    }

private:
    int stage;
    int s;
    string log_file;
    char buff[BUF_SIZE];
    unsigned char rbuf[BUF_SIZE];
    int stelen;
    int nsize;
    struct sockaddr_in router_addr;

    // stage3
    

    void stage1(){
        cout<<"Primary:: get into stage1 "<<this->s<<endl;
        ostream& logger = Logger::getInstance();
        logger<<"primary port: "<<global::primary_port<<endl;

        nsize = sizeof(struct sockaddr);
        socklen_t addrlen = sizeof(struct sockaddr_in);

        /* Stage 1 */
        cout<<"Primary:: Primary router is waiting for I am up message"<<endl;
        stelen = recvfrom(s, buff, BUF_SIZE, 0, (struct sockaddr*) &router_addr, (socklen_t*) &nsize);
        cout<<"Primary:: got an the up message from Secondary"<<endl;

        pthread_mutex_lock(&global::mutex);
        global::pid = atoi(buff);
        logger<<"router: "<<global::num_routers<<", pid: "<<global::pid<<", port: "<<router_addr.sin_port<<endl;
        pthread_mutex_unlock(&global::mutex);
    }

    void stage2(){
        cout<<"Primary:: start stage2"<<endl;
        ostream& logger = Logger::getInstance();
        char tun_name[IFNAMSIZ];
        global::tun_fd = utils::tun_alloc(strdup("tun1"), IFF_TUN | IFF_NO_PI);
        if(global::tun_fd < 0){
        	cout<<"Primary:: Failed to open tunnel interface"<<endl;;
        	exit(1);
        }

        fd_set readset;
        int select_ans;
        int maxfd = (global::tun_fd>s)?(global::tun_fd+1):(s+1);
        struct timeval tv;

        while (true){
            cout<<"Primary:: stage2 start to listen"<<endl;
            FD_ZERO(&readset);
            FD_SET(global::tun_fd, &readset);
            FD_SET(s, &readset);
            cout<<"Primary:: waiting"<<endl;
            
            tv.tv_sec = 15;
            tv.tv_usec = 0;
            select_ans = select(maxfd+1, &readset, NULL, NULL, &tv);
            cout<<"Primary:: get an info"<<endl;
            // pthread_mutex_lock(&mutex);
            memset(&buff, 0, sizeof(buff));
            if(select_ans == -1) cout<<"Primary:: select error"<<endl;
            else if(select_ans == 0){
                cout<<"Primary:: time out"<<endl;
                logger<<"router 0 closed"<<endl;
                int status;
                kill(global::pid, SIGTERM);
                wait(&status);
                if (WIFSIGNALED(status))printf("Child process received singal %d\n", WTERMSIG(status));
                close(global::service);
                raise(SIGTERM);
            }
            else{
                if(FD_ISSET(s, &readset)){
                    stelen = recvfrom(s, buff, BUF_SIZE, 0, (struct sockaddr*) &router_addr, (socklen_t*) &nsize);
                    cout<<"Primary:: Read a packet from Secondary, packet length: "<<stelen<<endl;
                    Packer *p = new Packer(buff, stelen);
                    p->parse();
                    if (p->recieve()){
                        logger<<"ICMP from port: "<<router_addr.sin_port<<", src: "<<p->src.data()<<", dst: "<< p->dst.data()<<", type: "<<p->type<<endl;
                        cout<<"Primary:: ICMP from port: "<<router_addr.sin_port<<", src: "<<p->src.data()<<", dst: "<< p->dst.data()<<", type: "<<p->type<<endl;
                        write(global::tun_fd, p->getpacket(), p->getlen());
                    }
                    else cout<<"Primary:: Invalid packet from Secondary!"<<endl;
                    delete p;
                }
                if(FD_ISSET(global::tun_fd, &readset)){
                    // read from tunnel
                    int nread = read(global::tun_fd,buff,BUF_SIZE);
                    if(nread < 0){
                        cout<<"Primary:: Reading from tunnel interface"<<endl;
                        close(global::tun_fd);
                        exit(1);
                    }
                    else{
                        cout<<"Primary:: Read a packet from tunnel, packet length: "<<nread<<endl;
                        Packer *p = new Packer(buff, nread);
                        p->parse();
                        if (p->recieve()){
                            logger<<"ICMP from tunnel, src: "<<p->src.data()<<", dst: "<< p->dst.data()<<", type: "<<p->type<<endl;
                            cout<<"Primary:: ICMP from tunnel, src: "<<p->src.data()<<", dst: "<< p->dst.data()<<", type: "<<p->type<<endl;
                            p->send(&router_addr, s, p->getpacket(), p->getlen());
                        }
                        else{
                            cout<<"Primary:: Invalid packet from tunnel!"<<endl;
                        }
                        delete p;
                    }
                }
            }
            // pthread_mutex_unlock(&mutex);
        }
        close(global::tun_fd);
    }

    void stage3(){}
};

#endif