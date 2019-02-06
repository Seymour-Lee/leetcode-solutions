#ifndef _ROUTER_H_
#define _ROUTER_H_

#include "shares.h"
#include "packer.h"
#include "logger.h"

// interfaces
class Router{
public:
    virtual void run() = 0;
};

class Primary: public Router{
public:
    Primary(int _s, int _stage) {
        this->s = _s;
        this->stage = _stage;
    }

    ~Primary() {}

    void run(){
        log_file = "stage" + to_string(stage) + ".primary.out";
        std::ofstream fout;
        fout.open(log_file);
        Logger::getInstance().rdbuf(fout.rdbuf());
        ostream& logger = Logger::getInstance();
        this->stage1();
        if(this->stage == 2) this->stage2();
        close(s);
        logger<<"router 0 closed"<<endl;
    }

private:
    int stage;
    int s;
    string log_file;
    char buffer[BUF_SIZE];
    unsigned char rbuf[BUF_SIZE];
    int strLen;
    int nSize;
    struct sockaddr_in routerAddr;

    void stage1(){
        cout<<"Primary:: get into stage1 "<<this->s<<endl;
        ostream& logger = Logger::getInstance();
        logger<<"primary port: "<<global::primary_port<<endl;

        nSize = sizeof(struct sockaddr);
        socklen_t addrlen = sizeof(struct sockaddr_in);

        /* Stage 1 */
        cout<<"Primary:: Primary router is waiting for I am up message"<<endl;
        strLen = recvfrom(s, buffer, BUF_SIZE, 0, (struct sockaddr*) &routerAddr, (socklen_t*) &nSize);
        cout<<"Primary:: got an the up message from Secondary"<<endl;

        // pthread_mutex_lock(&global::mutex);
        global::pid = atoi(buffer);
        logger<<"router: "<<global::num_routers<<", pid: "<<global::pid<<", port: "<<global::sin.sin_port<<endl;
        // pthread_mutex_unlock(&global::mutex);
    }

    void stage2(){
        cout<<"Primary:: start stage2"<<endl;
        ostream& logger = Logger::getInstance();
        /* Set up for Connecting to the tunnel interface */
        char tun_name[IFNAMSIZ];
        global::tun_fd = utils::tun_alloc(strdup("tun1"), IFF_TUN | IFF_NO_PI);
        if(global::tun_fd < 0){
        	cout<<"Primary:: Failed to open tunnel interface"<<endl;;
        	exit(1);
        }

        fd_set readset;
        int ret;
        int maxfd = (global::tun_fd>s)?(global::tun_fd+1):(s+1);

        while (true){
            cout<<"Primary:: stage2 start to listen"<<endl;
            FD_ZERO(&readset);
            FD_SET(global::tun_fd, &readset);
            FD_SET(s, &readset);
            cout<<"Primary:: waiting"<<endl;
            ret = select(maxfd+1, &readset, NULL, NULL, NULL);
            cout<<"Primary:: get an info"<<endl;
            // pthread_mutex_lock(&mutex);
            memset(&buffer, 0, sizeof(buffer));
            switch (ret){
                case -1: cout<<"Primary:: select error"<<endl;
                case  0: cout<<"Primary:: time out"<<endl;;
                default:
                    if(FD_ISSET(s, &readset)){
                        strLen = recvfrom(s, buffer, BUF_SIZE, 0, (struct sockaddr*) &routerAddr, (socklen_t*) &nSize);
                        cout<<"Primary:: Read a packet from Secondary, packet length: "<<strLen<<endl;

                        Packer *p = new Packer(buffer, strLen);
                        if (p->parse()){
                            logger<<"ICMP from port: "<<routerAddr.sin_port<<", src: "<<p->src.data()<<", dst: "<< p->dst.data()<<", type: "<<p->type<<endl;
                            cout<<"Primary:: ICMP from port: "<<routerAddr.sin_port<<", src: "<<p->src.data()<<", dst: "<< p->dst.data()<<", type: "<<p->type<<endl;
                            write(global::tun_fd, p->getPacket(), p->getPacketLen());
                        }
                        else
                            cout<<"Primary:: Invalid packet from Secondary!"<<endl;
                        delete p;

                    }
                    if(FD_ISSET(global::tun_fd, &readset)){
                        int nread = read(global::tun_fd,buffer,BUF_SIZE);

                        if(nread < 0){
                            cout<<"Primary:: Reading from tunnel interface"<<endl;
                            close(global::tun_fd);
                            exit(1);
                        }
                        else{
                            cout<<"Primary:: Read a packet from tunnel, packet length: "<<nread<<endl;
                            Packer *p = new Packer(buffer, nread);
                            if (p->parse()){
                                //p->printPacket();
                                // LOG(logfd, "ICMP from tunnel, src: %s, dst: %s, type: %d\n", p->src.data(), p->dst.data(), p->type);
                                logger<<"ICMP from tunnel, src: "<<p->src.data()<<", dst: "<< p->dst.data()<<", type: "<<p->type<<endl;
                                cout<<"Primary:: ICMP from tunnel, src: "<<p->src.data()<<", dst: "<< p->dst.data()<<", type: "<<p->type<<endl;
                                //send it to the router
                                p->sendUDP(&routerAddr, s, p->getPacket(), p->getPacketLen());
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
};

class Secondary: public Router{
public:
    Secondary(int _s, int _stage) {
        this->s = _s;
        this->stage = _stage;
    }

    ~Secondary() {}

    void run(){
        // signal(SIGTERM, this->killself);
        // signal(SIGABRT, this->killself);
        log_file = "stage" + to_string(stage) + ".secondary.out";
        std::ofstream fout;
        fout.open(log_file);
        Logger::getInstance().rdbuf(fout.rdbuf());
        ostream& logger = Logger::getInstance();

        this->stage1();
        if(this->stage == 2) this->stage2();
        close(s);
        logger<<"router 1 closed"<<endl;
    }

private:
    int stage;
    int s;
    char buffer[BUF_SIZE], str[BUF_SIZE];
    struct sockaddr_in proxyAddr;
    string log_file;
    

    // void killself(int sig_id){

    // }

    void stage1(){
        cout<<"Secondary:: get into stage1 "<<this->s<<endl;
        ostream& logger = Logger::getInstance();
        // char buffer[BUF_SIZE], str[BUF_SIZE];

        /* bind a socket and get a dynamic UDP port*/
        s = utils::initSocket();
        logger<<"router: "<<global::num_routers<<", pid: "<<getpid()<<", port: "<<global::sin.sin_port<<endl;

        /* send port to Proxy*/
        
        socklen_t addrlen = sizeof(struct sockaddr_in);
        memset(&proxyAddr, 0, sizeof(struct sockaddr_in));
        proxyAddr.sin_family = AF_INET;
        proxyAddr.sin_addr.s_addr = global::sin.sin_addr.s_addr;
        proxyAddr.sin_port = global::primary_port;
        cout<<"Secondary:: Secondary is sending to port "<<proxyAddr.sin_port<<endl;

        memset(&buffer, 0, sizeof(buffer));
        sprintf(buffer, "%d", getpid());
        sendto(s, buffer, strlen(buffer), 0, (struct sockaddr*) &proxyAddr, addrlen);
        cout<<"Secondary:: I am up message sent"<<endl;
    }

    void stage2(){
        cout<<"Secondary:: start stage2"<<endl;
        ostream& logger = Logger::getInstance();
        while (true){
            memset(&buffer, 0, sizeof(buffer));
            int nSize = sizeof(struct sockaddr);
            cout<<"Secondary::  waiting info from Primary router"<<endl;
            int strLen = recvfrom(s, buffer, BUF_SIZE, 0, (struct sockaddr*) &proxyAddr, (socklen_t*) &nSize);

            Packer *p = new Packer(buffer, strLen);
            if (p->parse()){
                logger<<"ICMP from port: "<<proxyAddr.sin_port<<", src: "<<p->src.data()<<", dst: "<<p->dst.data()<<", type: "<<p->type<<endl;
                cout<<"Secondary:: ICMP from port: "<<proxyAddr.sin_port<<", src: "<<p->src.data()<<", dst: "<<p->dst.data()<<", type: "<<p->type<<endl;
                p->icmpReply();
                p->sendUDP(&proxyAddr, s, p->getPacket(), p->getPacketLen());
            }
            else{
                cout<<"Secondary:: Invalid packet from Primary!"<<endl;
            }
            delete p;
        }
    }
};

#endif