#ifndef _SECONDARY_H_
#define _SECONDARY_H_

#include "router.h"



class Secondary: public Router{
public:
    Secondary(int _s, int _stage, int _router_id) {
        this->s = _s;
        this->stage = _stage;
        this->router_id = _router_id;
        this->drop_after = global::drop_after;
        this->octane_counter = 0;
        this->self_ip_addr = "10.5.51.1"+to_string(this->router_id+1);
        
    }

    ~Secondary() {
        ostream& logger = Logger::getInstance();
        logger<<"router "<<router_id+1<<" closed"<<endl;
    }

    void run(){
        signal(SIGTERM, Secondary::killself);
        signal(SIGABRT, Secondary::killself);
        log_file = "stage" + to_string(stage) + ".r" + to_string(this->router_id+1) + ".out";
        global::log_file_name = log_file;
        std::ofstream fout;
        fout.open(log_file);
        Logger::getInstance().rdbuf(fout.rdbuf());
        ostream& logger = Logger::getInstance();

        if(this->stage <= 5) this->stage1();
        else this->say_hello_to_primary();
        // if(this->stage >= 2) this->stage2();
        // install default rule
        if(this->stage >= 5)
            self_install_rule("255.255.255.255, 65535, 255.255.255.255, 65535", 655535, 3);
        if(this->stage >= 2) this->loop();
        // if(this->stage == 3) this->stage3();
        close(s);
        close(raw_sock);
        close(tcp_sock);
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
    int raw_sock = 0;
    unordered_map<string, string> dst2src;

    // stage4 and above
    int drop_after;
    int octane_counter;
    unordered_map<uint16_t, unordered_set<string>> pro2addr; // octane_protocol to "src_ip, src_port, dst_ip, dst_port"
    unordered_map<string, int> tuple2action;

    // stage6 and above
    string self_ip_addr;
    int tcp_sock = 0;
    unordered_map<string, string> tcp_dst2src;
    unordered_map<string, unsigned int> tcp_dst2srcport;
    

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

    void say_hello_to_primary(){
        s = utils::initSocket();
        ostream& logger = Logger::getInstance();
        logger<<"router: "<<this->router_id+1<<", pid: "<<getpid()<<", port: "<<global::sin.sin_port<<endl;
        global::service = s;
        socklen_t addrlen = sizeof(struct sockaddr_in);
        memset(&primary_addr, 0, sizeof(struct sockaddr_in));
        primary_addr.sin_family = AF_INET;
        primary_addr.sin_addr.s_addr = global::sin.sin_addr.s_addr;
        primary_addr.sin_port = global::primary_port;
        cout<<"Secondary:: Secondary is sending to port "<<primary_addr.sin_port<<endl;

        memset(&buff, 0, sizeof(buff));
        sprintf(buff, "%d,%d,%d", this->router_id, getpid(), global::sin.sin_port);
        sendto(s, buff, strlen(buff), 0, (struct sockaddr*) &primary_addr, addrlen);
        cout<<"Secondary:: I am up message sent"<<endl;
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
            return dst.find("10.5.51") != string::npos;
        }
        else if(socket_no == raw_sock){
            if(strcmp(dst.c_str(), inet_ntoa(global::eth[router_id].sin_addr)) == 0)return true;
            return true;
        }
        return false;
    }

    int hit_rule(Packer *p){
        string srcip = p->src;
        string dstip = p->dst;
        int srcport = p->srcport;
        int dstport = p->dstport;
        int protocol = p->type;
        string addr = srcip+", "+to_string(srcport)+", "+dstip+", "+to_string(dstport);
        // cout<<"DEBUG:: router: "<<router_id+1<<", rule hit ("<<addr<<", "<<protocol<<") action "<<endl;
        if(pro2addr[protocol].find(addr) == pro2addr[protocol].end()) return -1;
        ostream& logger = Logger::getInstance();
        logger<<"router: "<<router_id+1<<", rule hit ("<<addr<<", "<<protocol<<")"<<endl;
        cout<<"router: "<<router_id+1<<", rule hit ("<<addr<<", "<<protocol<<")"<<endl;
        return tuple2action[addr+", "+to_string(protocol)];
    }

    void read_from_primary(){
        cout<<"Secondary:: read_from_primary()"<<endl;
        ostream& logger = Logger::getInstance();
        
        memset(&buff, 0, sizeof(buff));
        int nsize = sizeof(struct sockaddr);
        cout<<"Secondary::  waiting info from Primary router"<<endl;
        int stelen = recvfrom(s, buff, BUF_SIZE, 0, (struct sockaddr*) &primary_addr, (socklen_t*) &nsize);

        Packer *p = new Packer(buff, stelen);
        p->parse();
        // if (p->recieve()){
        if(p->type == 1 && p->icmptype != 3){
            logger<<"ICMP from port: "<<primary_addr.sin_port<<", src: "<<p->src.data()<<", dst: "<<p->dst.data()<<", type: "<<p->icmptype<<endl;
            cout<<"Secondary:: ICMP from port: "<<primary_addr.sin_port<<", src: "<<p->src.data()<<", dst: "<<p->dst.data()<<", type: "<<p->icmptype<<endl;
            int ans = -1;
            if(this->stage >= 5) ans = hit_rule(p);
            if(this->stage <= 4 || ans == 1 || ans == 2){
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
                // drop
            }
        }
        else if(p->type == 6){
            if(this->stage == 6){
                int ans = hit_rule(p);
                if(ans == 1 || ans == 2){
                    cout<<"Secondary:: "<<this->router_id+1<<", get an tcp packet from primary"<<endl;
                    p->parse_tcp();
                    // p->change_src(selfIP);
                    cout<<"-----"<<p->src<<" "<<p->srcport<<" "<<p->dst<<" "<<p->dstport<<endl;
                    tcp_dst2src[p->dst] = p->src;
                    tcp_dst2srcport[p->dst] = p->srcport;
                    p->change_src("192.168.20"+to_string(this->router_id+1)+".2");// this->self_ip_addr);
                    p->parse();
                    send_to_tcp_raw(p);
                    cout<<p->src<<" "<<p->srcport<<" "<<p->dst<<" "<<p->dstport<<endl;
                }
            }
            if(this->stage == 7){
                if(this->router_id == 0){
                    // BUG: send to r2
                    int ans = hit_rule(p);
                    if(ans == 1 || ans == 2){
                        cout<<"Secondary:: "<<this->router_id+1<<", get an tcp packet from primary"<<endl;
                        p->parse_tcp();
                        // p->change_src(selfIP);
                        cout<<"-----"<<p->src<<" "<<p->srcport<<" "<<p->dst<<" "<<p->dstport<<endl;
                        tcp_dst2src[p->dst] = p->src;
                        tcp_dst2srcport[p->dst] = p->srcport;
                        p->change_src("192.168.20"+to_string(this->router_id+1)+".2");// this->self_ip_addr);
                        p->parse();
                        send_to_tcp_raw(p);
                        cout<<p->src<<" "<<p->srcport<<" "<<p->dst<<" "<<p->dstport<<endl;
                    }

                }
                if(this->router_id == 1){
                    int ans = hit_rule(p);
                    if(ans == 1 || ans == 2){
                        cout<<"Secondary:: "<<this->router_id+1<<", get an tcp packet from primary"<<endl;
                        p->parse_tcp();
                        // p->change_src(selfIP);
                        cout<<"-----"<<p->src<<" "<<p->srcport<<" "<<p->dst<<" "<<p->dstport<<endl;
                        tcp_dst2src[p->dst] = p->src;
                        tcp_dst2srcport[p->dst] = p->srcport;
                        p->change_src("192.168.20"+to_string(this->router_id+1)+".2");// this->self_ip_addr);
                        p->parse();
                        send_to_tcp_raw(p);
                        cout<<p->src<<" "<<p->srcport<<" "<<p->dst<<" "<<p->dstport<<endl;
                    }
                }
            }
            
            
        }
        else if(p->type == 253){
            if(this->stage >= 4){
                get_octane_message(p);
            }
            
            
        }
        else{
            cout<<"Secondary:: Invalid packet from Primary! IP protocol type is "<<p->type<<endl;
        }
        delete p;
        
    }

    void get_octane_message(Packer *p){
        cout<<"Secondary:: get an octane control message"<<endl;
        ostream& logger = Logger::getInstance();
        unsigned char *buffer = (unsigned char *)p->getpacket();
        struct octane_control *octane = (struct octane_control *)(buffer+sizeof(struct iphdr));
        handle_octane_message(octane);
        send_ack(p);
    }

    void handle_octane_message(struct octane_control *octane){
        ostream& logger = Logger::getInstance();
        int protocol = octane->octane_protocol;
        int srcip = octane->octane_source_ip;
        int srcport = octane->octane_source_port;
        int dstip = octane->octane_dest_ip;
        int dstport = octane->octane_dest_port;
        int action = octane->octane_action;
        string addr = ip2str(srcip)+", "+to_string(srcport)+", "+ip2str(dstip)+", "+to_string(dstport);
        if(pro2addr[protocol].find(addr) == pro2addr[protocol].end()){
            self_install_rule(addr, protocol, action);
        }
        else{
            // cout<<"Secondary:: hit!!!"<<endl;
            logger<<"router: "<<router_id+1<<", rule hit ("<<addr<<", "<<protocol<<") action "<<tuple2action[addr+", "+to_string(protocol)]<<endl;
            cout<<"router: "<<router_id+1<<", rule hit ("<<addr<<", "<<protocol<<") action "<<tuple2action[addr+", "+to_string(protocol)]<<endl;
        }
    }

    void self_install_rule(string addr, int protocol, int action){
        ostream& logger = Logger::getInstance();
        logger<<"router: "<<router_id+1<<", rule installed ("<<addr<<", "<<protocol<<") action "<<action<<endl;
        cout<<"router: "<<router_id+1<<", rule installed ("<<addr<<", "<<protocol<<") action "<<action<<endl;
        pro2addr[protocol].insert(addr);
        tuple2action[addr+", "+to_string(protocol)] = action;
    } 

    void send_ack(Packer *p){
        unsigned char *buffer = (unsigned char *)p->getpacket();
        struct octane_control *octane = (struct octane_control *)(buffer+sizeof(struct iphdr));
        octane->octane_flags = 1;
        // p->switchip();
        p->change_dst(p->src); // to primary
        p->change_src(this->self_ip_addr); // from self
        p->setchecksum();
        p->send(&primary_addr, s, p->getpacket(), p->getlen());
    }

    

    string ip2str(uint32_t ip){
        string ans;
        unsigned int a = ip & 0x000000ff;
        unsigned int b = (ip >> 8) & 0x000000ff;
        unsigned int c = (ip >> 16) & 0x000000ff;
        unsigned int d = (ip >> 24) & 0x000000ff;
        ans = to_string(a) + "." + to_string(b) + "." + to_string(c) + "." + to_string(d);
        return ans;
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

        if(this->stage >= 6) tcp_sock = this->raw_alloc_tcp();
        else tcp_sock = 0;
        int max_fd = max(s, raw_sock);
        max_fd = max(max_fd, tcp_sock);
        cout<<"max_fd is "<<max_fd<<endl;
        while(true){
            cout<<"Secondary:: in loop() while"<<endl;
            FD_ZERO(&readset);
            FD_SET(raw_sock, &readset);
            FD_SET(tcp_sock, &readset);
            FD_SET(s, &readset);
            return_val = select(max_fd+1, &readset, nullptr, nullptr, nullptr);
            if(return_val == 0) perror("select");
            else{
                if(FD_ISSET(raw_sock, &readset)) read_from_raw();
                if(FD_ISSET(s, &readset)) read_from_primary();
                if(FD_ISSET(tcp_sock, &readset)) read_from_tcp_raw();
            }
        }
        close(s);
        close(raw_sock);
        close(tcp_sock);
    }

    void read_from_tcp_raw(){
        
        cout<<"Secondary:: in read_from_tcp_raw()"<<endl;
        char buffer[BUF_SIZE];
        memset(&buffer, 0, sizeof(buffer));
        int buf_len = read(tcp_sock, buffer, BUF_SIZE);
        if(buf_len < 0){
            perror("Reading from raw socket");
            close(raw_sock);
            close(tcp_sock);
            exit(1);
        }
        else{
            cout<<"Router"<<router_id+1<<": read a pecket from tcp socket, packet length: "<<buf_len<<endl;
            Packer *p = new Packer(buffer, buf_len);
            p->parse();
            // if (p->recieve()){
            if(p->type == 6){
                if(this->stage == 6){
                    int ans = hit_rule(p);
                    if(ans == 1 || ans == 2){
                        p->parse_tcp();
                        handle_tcp_from_raw(p);
                    }
                }
                if(this->stage == 7){
                    if(this->router_id == 0){
                        // maybe bugs here
                        int ans = hit_rule(p);
                        if(ans == 1 || ans == 2){
                            p->parse_tcp();
                            handle_tcp_from_raw(p);
                        }
                    }
                    if(this->router_id == 1){
                        // BUG: send to r1
                        int ans = hit_rule(p);
                        if(ans == 1 || ans == 2){
                            p->parse_tcp();
                            handle_tcp_from_raw(p);
                        }
                    }
                }
                
            }
            else{
                cout<<"Secondary:: Invalid packet from TCP Socket! type is "<<p->type<<endl;
            }
            delete p;
        }
    }

    void handle_tcp_from_raw(Packer *p){
        cout<<"Opsssssssssssssssssssssssssss get a tcp packet from tcp_raw_socket"<<endl;
        ostream& logger = Logger::getInstance();
        cout<<"Secondary:: handle tcp from raw, src: "<<p->src.data()<<", dst: "<<p->dst.data()<<", type: "<<p->type<<endl;
        cout<<"tcp from raw p->src is "<<p->src<<endl;
        if(tcp_dst2src.find(p->src) != tcp_dst2src.end()){
            cout<<"Got tcp, in flow table!"<<endl;
            int ans = -1;
            if(this->stage >= 5) ans = hit_rule(p);
            if(true || this->stage <= 4 || ans == 1 || ans == 2){
                cout<<"Secondary:: Send tcp packet to Primary from outside world"<<endl;
                
                p->send(&primary_addr, s, p->getpacket(), p->getlen());
            }
            
        }
        
    }

    void send_to_tcp_raw(Packer *p){
        //construct dst ip address
        struct sockaddr_in dst_addr;
        memset(&dst_addr,'\0',sizeof(struct sockaddr_in));
        dst_addr.sin_family = AF_INET;
        dst_addr.sin_port = htons(p->dstport);
        inet_pton(AF_INET, p->dst.c_str(), &dst_addr.sin_addr);

        //struct iphdr *iph = (struct iphdr *)(p->getPacket());
        //int iphdr_len = iph->ihl * 4;
        //struct tcphdr* tcp= (struct tcphdr*)(p->getPayload());
        struct iovec iov;
        memset(&iov, 0, sizeof(struct iovec));

        struct msghdr m = {
                &dst_addr, sizeof(struct sockaddr_in), &iov,
                1, 0, 0, 0
        };

        ssize_t bs;

        iov.iov_base = p->get_payload();
        iov.iov_len = p->recheck_tcp();
        cout<<"recheck_tcp() result is "<<iov.iov_len<<" "<<p->get_payload_len()<<endl;

        if (0> (bs = sendmsg(tcp_sock, &m, 0)))
        {
                perror ("ERROR: sendmsg ()");
        }
        else
        {
                printf("\nRouter%d: send tcp packet, size:%d\n", this->router_id+1, (int)bs);
        }

        memset(&m, 0, sizeof(struct msghdr));
    }

    void read_from_raw(){
        cout<<"Secondary:: in read_from_raw()"<<endl;
        char buffer[BUF_SIZE];
        memset(&buffer, 0, sizeof(buffer));
        int buf_len = read(raw_sock, buffer, BUF_SIZE);
        if(buf_len < 0){
            perror("Reading from raw socket");
            close(raw_sock);
            close(tcp_sock);
            exit(1);
        }
        else{
            cout<<"Router"<<router_id+1<<": read a pecket from raw socket, packet length: "<<buf_len<<endl;
            Packer *p = new Packer(buffer, buf_len);
            p->parse();
            // if (p->recieve()){
            if(p->type == 1 && p->icmptype != 3){
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
        ostream& logger = Logger::getInstance();
        logger<<"ICMP from raw sock, src: "<<p->src.data()<<", dst: "<<p->dst.data()<<", type: "<<p->icmptype<<endl;
        // cout<<"Secondary:: handle icmp from raw, src: "<<p->src.data()<<", dst: ">>p->dst.data()<<", type: "<<(p->icmptype)<<endl;
        cout<<"Secondary:: handle icmp from raw, src: "<<p->src.data()<<", dst: "<<p->dst.data()<<", type: "<<p->icmptype<<endl;
        if(send_to_secondary(p, raw_sock)){
            cout<<"icmp from raw p->src is "<<p->src<<endl;
            if(dst2src.find(p->src) != dst2src.end()){
                p->change_dst(dst2src[p->src]);
                // p->switchip();
                // p->setchecksum();
                int ans = -1;
                if(this->stage >= 5) ans = hit_rule(p);
                if(this->stage <= 4 || ans == 1 || ans == 2){
                    cout<<"Secondary:: Send message to Primary from outside world"<<endl;
                    p->send(&primary_addr, s, p->getpacket(), p->getlen());
                }
                
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

    int raw_alloc_tcp(){
        int raw_socket_des = 0;
        raw_socket_des = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
        socklen_t addr_len = sizeof(struct sockaddr_in);
        cout<<"raw_socket_des of socket: "<<raw_socket_des<<endl;
        if(::bind(raw_socket_des, (struct sockaddr*) &global::eth[router_id], addr_len)){
            perror("raw bind");
            cout<<"ready to exit"<<endl;
            exit(EXIT_FAILURE);
        }
        return raw_socket_des;
    }
};

#endif