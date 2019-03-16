#ifndef _SECONDARY_H_
#define _SECONDARY_H_

#include "router.h"



class Secondary: public Router{
public:
    Secondary(int _s, int _stage, int _router_id) {
        this->s = _s;
        this->stage = _stage;
        this->router_id = _router_id;
    }

    ~Secondary() {
        ostream& logger = Logger::getInstance();
        logger<<"router "<<router_id+1<<" closed"<<endl;
    }

    void run(){
        signal(SIGTERM, Secondary::killself);
        signal(SIGABRT, Secondary::killself);
        log_file = "stage" + to_string(stage) + ".secondary.out";
        global::log_file_name = log_file;
        std::ofstream fout;
        fout.open(log_file);
        Logger::getInstance().rdbuf(fout.rdbuf());
        ostream& logger = Logger::getInstance();

        this->stage1();
        // if(this->stage >= 2) this->stage2();
        if(this->stage >= 2) this->loop();
        // if(this->stage == 3) this->stage3();
        close(s);
        logger<<"router 1 closed"<<endl;
    }

private:
    int stage;
    int s;
    int router_id;
    char buff[BUF_SIZE], str[BUF_SIZE];
    struct sockaddr_in primary_addr;
    string log_file;

    // stage3
    
    

    static void killself(int sig_id){
        // std::ofstream fout;
        // fout.open(global::log_file_name);
        // Logger::getInstance().rdbuf(fout.rdbuf());
        ostream& logger = Logger::getInstance();
        logger<<"router 1 closed"<<endl;
        close(global::service);
        cout<<endl;
        exit(1);
    }

    void stage1(){
        cout<<"Secondary:: get into stage1 "<<this->s<<endl;
        ostream& logger = Logger::getInstance();
        s = utils::initSocket();
        logger<<"router: "<<global::num_routers<<", pid: "<<getpid()<<", port: "<<global::sin.sin_port<<endl;
        global::service = s;
        
        socklen_t addrlen = sizeof(struct sockaddr_in);
        memset(&primary_addr, 0, sizeof(struct sockaddr_in));
        primary_addr.sin_family = AF_INET;
        primary_addr.sin_addr.s_addr = global::sin.sin_addr.s_addr;
        primary_addr.sin_port = global::primary_port;
        cout<<"Secondary:: Secondary is sending to port "<<primary_addr.sin_port<<endl;

        memset(&buff, 0, sizeof(buff));
        sprintf(buff, "%d", getpid());
        sendto(s, buff, strlen(buff), 0, (struct sockaddr*) &primary_addr, addrlen);
        cout<<"Secondary:: I am up message sent"<<endl;
    }

    bool send_to_secondary(Packer *p, int socket_no){
        
        string dst = p->dst;
        // cout<<dst<<endl;
        // if(dst == "10.5.51.3."){
        //     return true;
        // }
        if(socket_no == s){
            return dst == "10.5.51.3";
        }
        else if(socket_no == raw_sock){
            if(strcmp(dst.c_str(), inet_ntoa(global::eth[router_id].sin_addr)) == 0)return true;
            return true;
        }
        return false;
    }

    void read_from_primary(){
        cout<<"Secondary:: start stage2"<<endl;
        ostream& logger = Logger::getInstance();
        
        memset(&buff, 0, sizeof(buff));
        int nsize = sizeof(struct sockaddr);
        cout<<"Secondary::  waiting info from Primary router"<<endl;
        int stelen = recvfrom(s, buff, BUF_SIZE, 0, (struct sockaddr*) &primary_addr, (socklen_t*) &nsize);

        Packer *p = new Packer(buff, stelen);
        p->parse();
        if (p->recieve()){
            logger<<"ICMP from port: "<<primary_addr.sin_port<<", src: "<<p->src.data()<<", dst: "<<p->dst.data()<<", type: "<<p->type<<endl;
            cout<<"Secondary:: ICMP from port: "<<primary_addr.sin_port<<", src: "<<p->src.data()<<", dst: "<<p->dst.data()<<", type: "<<p->type<<endl;
            if(send_to_secondary(p, s)){ // stage2
                p->switchip();
                p->setchecksum();
                p->send(&primary_addr, s, p->getpacket(), p->getlen());
            }
            else{ //stage3
                cout<<"Secondary:: rewrite and send to outside"<<endl;
                dst2src[p->dst] = p->src;
                cout<<p->dst<<" "<<p->src<<endl;
                send_to_raw(p);
            }
            
        }
        else{
            cout<<"Secondary:: Invalid packet from Primary!"<<endl;
        }
        delete p;
        
    }

    void loop(){
        fd_set readset;
        int return_val;
        if(this->stage >= 3){
            raw_sock = this->raw_alloc();
        }
        else{
            raw_sock = 0;
        }
        int max_fd = max(s, raw_sock);
        cout<<"max_fd is "<<max_fd<<endl;
        while(true){
            cout<<"Secondary:: in loop() while"<<endl;
            FD_ZERO(&readset);
            FD_SET(raw_sock, &readset);
            FD_SET(s, &readset);
            return_val = select(max_fd+1, &readset, nullptr, nullptr, nullptr);
            if(return_val == 0) perror("select");
            else{
                if(FD_ISSET(raw_sock, &readset)) read_from_raw();
                if(FD_ISSET(s, &readset)) read_from_primary();
                
            }
        }
        close(s);
        close(raw_sock);
    }

    // stage3
    int raw_sock = 0;
    unordered_map<string, string> dst2src;

    void read_from_raw(){
        cout<<"Secondary:: in read_from_raw()"<<endl;
        char buffer[BUF_SIZE];
        memset(&buffer, 0, sizeof(buffer));
        int buf_len = read(raw_sock, buffer, BUF_SIZE);
        if(buf_len < 0){
            perror("Reading from raw socket");
            close(raw_sock);
            exit(1);
        }
        else{
            cout<<"Router"<<router_id+1<<": read a pecket from raw socket, packet length: "<<buf_len<<endl;
            Packer *p = new Packer(buffer, buf_len);
            p->parse();
            if (p->recieve()){
                handle_icmp_from_raw(p);
            }
            else{
                cout<<"Secondary:: Invalid packet from Raw Socket!"<<endl;
            }
            delete p;
        }
    }

    void send_to_raw(Packer *p){
        struct iovec iov;
        struct msghdr msgsent;
        struct sockaddr_in dest;

        memset(&dest, '\0', sizeof(dest));
        dest.sin_family = AF_INET;
        dest.sin_port = htons(IPPROTO_ICMP);
        inet_pton(AF_INET, p->dst.c_str(), &dest.sin_addr);

        iov.iov_base = p->get_payload();
        iov.iov_len = p->get_payload_len();

        //construct message
        msgsent.msg_iov        = &iov;
        msgsent.msg_iovlen     = 1;
        msgsent.msg_name       = (caddr_t) &dest;
        msgsent.msg_namelen    = sizeof(struct sockaddr_in);
        msgsent.msg_control    = 0;
        msgsent.msg_controllen = 0;

        //send message
        if (sendmsg(raw_sock, &msgsent, 0)==-1) {
                perror("sendmsg");
        }
        else
            printf("Rewrite msg to the Internet!\n");
    }

    void handle_icmp_from_raw(Packer *p){
        // cout<<"Secondary:: handle icmp from raw, src: "<<p->src.data()<<", dst: ">>p->dst.data()<<", type: "<<(p->type)<<endl;
        cout<<"Secondary:: handle icmp from raw, src: "<<p->src.data()<<", dst: "<<p->dst.data()<<", type: "<<p->type<<endl;
        if(send_to_secondary(p, raw_sock)){
            cout<<"icmp from raw p->src is "<<p->src<<endl;
            if(dst2src.find(p->src) != dst2src.end()){
                p->change_dst(dst2src[p->src]);
                // p->switchip();
                // p->setchecksum();
                cout<<"Secondary:: Send message to Primary from outside world"<<endl;
                p->send(&primary_addr, s, p->getpacket(), p->getlen());
            }
        }
    }

    int raw_alloc(){
        int raw_socket_des = 0;
        raw_socket_des = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
        socklen_t addr_len = sizeof(struct sockaddr_in);
        cout<<"raw_socket_des of socket: "<<raw_socket_des<<endl;
        if(::bind(raw_socket_des, (struct sockaddr*) &global::eth[router_id], addr_len)){
            perror("raw bind");
            cout<<"ready to exit"<<endl;
            exit(EXIT_FAILURE);
        }
        return raw_socket_des;
    }

    void stage3(){}
};

#endif