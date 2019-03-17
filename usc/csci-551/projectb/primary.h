#ifndef _PRIMARY_H_
#define _PRIMARY_H_

#include "router.h"

class Primary: public Router{
public:
    Primary(int _s, int _stage) {
        this->s = _s;
        this->stage = _stage;
        this->octane_counter = 0;
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

    // stage4 and above
    int octane_counter;
    

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
        // sleep(1);

        // receive a octane packet from secondary
        // unsigned char* buffer = (unsigned char*)malloc(sizeof(struct iphdr)+sizeof(struct octane_control));
        // memset(&buffer, 0, sizeof(struct iphdr)+sizeof(struct octane_control));
        // cout<<"sizeof: "<<sizeof(struct iphdr)+sizeof(struct octane_control)<<" "<<sizeof(buffer)<<endl;
        // unsigned char *buffer = (unsigned char *)malloc(BUF_SIZE);// [BUF_SIZE];
        // memset(buffer, 0, BUF_SIZE);
        // int len = recvfrom(s, buffer, BUF_SIZE, 0, (struct sockaddr*) &router_addr, (socklen_t*) &nsize);
        // cout<<"Recieve a message from secondary, len is: "<<len<<endl;
        // // struct temp dese;
        // // memset(&dese, 0, sizeof(struct temp));
        // // unsigned char *ptr = deserialize_temp(buffer, &dese);
        // // cout<<"Recieve a message from secondary, len is: "<<len<<" "<<(ptr-buffer)<<endl;
        // // cout<<dese.a<<" "<<dese.b<<endl;
        // struct iphdr *iph = (struct iphdr *)buffer;
        // cout<<"Primary:: iph->protocol is "<<(int)iph->protocol<<endl;
        // struct octane_control *octane = (struct octane_control*)(buffer + sizeof(struct iphdr));
        // // memset(&octane, 0, sizeof(struct octane_control));
        // // unsigned char *ptr = utils::deserialize_octane_control(buffer, &octane);
        // // cout<<"Recieve a message from secondary, len is: "<<len<<" "<<(ptr-buffer)<<endl;
        // cout<<(int)octane->octane_action<<endl;
        // cout<<(int)octane->octane_flags<<endl;
        // cout<<(int)octane->octane_seqno<<endl;
        // cout<<octane->octane_source_ip<<endl;
        // cout<<octane->octane_dest_ip<<endl;
        // cout<<octane->octane_source_port<<endl;
        // cout<<octane->octane_dest_port<<endl;
        // cout<<octane->octane_protocol<<endl;
        // cout<<octane->octane_port<<endl;
        // Packer *p = new Packer((char *)buffer, len);
        // p->parse();
        // cout<<"p->type is "<<p->type<<endl;
        // delete p;
    }

    unsigned char * deserialize_temp(unsigned char *buffer, struct temp *value){
        buffer = deserialize_int(buffer, &value->a);
        buffer = deserialize_char(buffer, &value->b);
        return buffer;
    }

    unsigned char * deserialize_int(unsigned char *buffer, int *value){
        *value = *value | (buffer[0] << 24);
        *value = *value | (buffer[1] << 16);
        *value = *value | (buffer[2] << 8);
        *value = *value | (buffer[3]);
        return buffer + 4;
    }

    unsigned char * deserialize_char(unsigned char *buffer, char *value){
        *value = buffer[0];
        return buffer + 1;
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
                if(FD_ISSET(s, &readset)){ // handle message between primary and secondarys
                    stelen = recvfrom(s, buff, BUF_SIZE, 0, (struct sockaddr*) &router_addr, (socklen_t*) &nsize);
                    cout<<"Primary:: Read a packet from Secondary, packet length: "<<stelen<<endl;
                    Packer *p = new Packer(buff, stelen);
                    p->parse();
                    

                    // if (p->recieve()){
                    if(p->type == 1){
                        logger<<"ICMP from port: "<<router_addr.sin_port<<", src: "<<p->src.data()<<", dst: "<< p->dst.data()<<", type: "<<p->icmptype<<endl;
                        cout<<"Primary:: ICMP from port: "<<router_addr.sin_port<<", src: "<<p->src.data()<<", dst: "<< p->dst.data()<<", type: "<<p->icmptype<<endl;
                        write(global::tun_fd, p->getpacket(), p->getlen());
                    }
                    else cout<<"Primary:: Invalid packet from Secondary!"<<endl;
                    delete p;
                }
                if(FD_ISSET(global::tun_fd, &readset)){ // handle message between primary and tunnel
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
                        // if (p->recieve()){
                        if(p->type == 1){
                            logger<<"ICMP from tunnel, src: "<<p->src.data()<<", dst: "<< p->dst.data()<<", type: "<<p->icmptype<<endl;
                            cout<<"Primary:: ICMP from tunnel, src: "<<p->src.data()<<", dst: "<< p->dst.data()<<", type: "<<p->icmptype<<endl;
                            // judge the action of message from tunnel
                            if(this->stage >= 4){
                                distribute_control_message(p);
                                if(this->stage >= 5){
                                    write_flow_table();
                                }
                            }
                            p->send(&router_addr, s, p->getpacket(), p->getlen());
                        }
                        else{
                            cout<<"Primary:: Invalid packet from tunnel! p->type is "<<p->type<<endl;
                        }
                        delete p;
                    }
                }
            }
            // pthread_mutex_unlock(&mutex);
        }
        close(global::tun_fd);
    }

    void write_flow_table(){
        
    }

    void distribute_control_message(Packer *p){
        cout<<"Primary: distributing octane control message"<<endl;
        ostream& logger = Logger::getInstance();
        if(this->stage == 4){
            logger<<"router: 0, rule installed ("<<p->src<<", 65535, "<<p->dst<<", 65535, "<<p->type<<") action 1"<<endl;
            logger<<"router: 0, rule installed ("<<p->dst<<", 65535, "<<p->src<<", 65535, "<<p->type<<") action 1"<<endl;
            cout<<"router: 0, rule installed ("<<p->src<<", 65535, "<<p->dst<<", 65535, "<<p->type<<") action 1"<<endl;
            cout<<"router: 0, rule installed ("<<p->dst<<", 65535, "<<p->src<<", 65535, "<<p->type<<") action 1"<<endl;
            send_octane_forward(p);
            // send_octane_forward(p);
        }
        
    }

    void send_octane_forward(Packer *p){
        unsigned char* buffer = (unsigned char*)malloc(BUF_SIZE);
        memset(buffer, 0, sizeof(BUF_SIZE));
        struct iphdr *ori = p->get_iphdr();
        // utils::serialize_octane_messgae(buffer, ori);

        struct iphdr *iph = (struct iphdr*)buffer;
        *iph = *ori;
        iph->protocol = 253;
        cout<<"compare iph and ori: "<<endl;
        cout<<iph->saddr<<" "<<ori->saddr<<endl;
        cout<<iph->daddr<<" "<<ori->daddr<<endl;
        
        struct octane_control* octane = (struct octane_control*)(buffer+sizeof(struct iphdr));
        // memset(octane, 0, sizeof(struct octane_control));
        octane->octane_action = 1; // forward
        octane->octane_flags = 0; // take an action
        octane->octane_seqno = this->octane_counter;
        octane->octane_source_ip = p->src_int;
        octane->octane_dest_ip = p->dst_int;
        octane->octane_source_port = 65535;
        octane->octane_dest_port = 65535;
        octane->octane_protocol = p->type;
        octane->octane_port = 0;

        int ans = sendto(s, buffer, BUF_SIZE, 0, (struct sockaddr*) &router_addr, BUF_SIZE);
        cout<<"Sent forward to primary: "<<ans<<endl;
    }

    void send_octane_reply(unsigned char *buffer, struct iphdr *ori){

    }

    void send_octane_drop(unsigned char *buffer, struct iphdr *ori){

    }

    void send_octane_remove(unsigned char *buffer, struct iphdr *ori){

    }

    void stage3(){}
};

#endif