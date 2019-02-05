#ifndef _ROUTER_H_
#define _ROUTER_H_

#include "shares.h"
#include "packer.h"

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
        cout<<"in Primary::run(), _stage is "<<this->stage<<endl;
        this->stage1();
        if(this->stage == 2) this->stage2();
        close(s);
        // fclose(logfd);
    }

private:
    int stage;
    int s;

    void stage1(){
        char buffer[BUF_SIZE];
        unsigned char rbuf[BUF_SIZE];
        int strLen;

        char filename[MAXPATHLENGTH];
        sprintf(filename, "stage%d.proxy.out", stage);
        // logfd = fopen(filename, "w+");
        // LOG(logfd, "proxy port: %d\n", udp_port);

        struct sockaddr_in routerAddr;
        int nSize = sizeof(struct sockaddr);
        socklen_t addrlen = sizeof(struct sockaddr_in);

        /* Stage 1 */
        strLen = recvfrom(s, buffer, BUF_SIZE, 0, (struct sockaddr*) &routerAddr, (socklen_t*) &nSize);

        pthread_mutex_lock(&global::mutex);
        printf("\nRead a packet from router, packet length:%d\n", strLen);
        global::pid = atoi(buffer);
        // LOG(logfd, "router: %d, pid: %d, port: %d\n", num_routers, router_pid, routerAddr.sin_port);
        pthread_mutex_unlock(&global::mutex);
    }

    void stage2(){

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
        cout<<"in Secondary::run(), _stage is "<<this->stage<<endl;
        // signal(SIGTERM, this->killself);
        // signal(SIGABRT, this->killself);
        this->stage1();
        if(this->stage == 2) this->stage2();
        close(s);
        // fclose(logfd);
    }

private:
    int stage;
    int s;
    char buffer[BUF_SIZE], str[BUF_SIZE];
    struct sockaddr_in proxyAddr;

    // void killself(int sig_id){

    // }

    void stage1(){
        char filename[MAXPATHLENGTH];
        sprintf(filename, "stage%d.router.out", stage);
        // logfd = fopen(filename, "w+");

        // char buffer[BUF_SIZE], str[BUF_SIZE];

        /* bind a socket and get a dynamic UDP port*/
        s = utils::initSocket();
        // LOG(logfd, "router: %d, pid: %d, port: %d\n", num_routers, getpid(), addr.sin_port);

        /* send port to Proxy*/
        
        socklen_t addrlen = sizeof(struct sockaddr_in);
        memset(&proxyAddr, 0, sizeof(struct sockaddr_in));
        proxyAddr.sin_family = AF_INET;
        proxyAddr.sin_addr.s_addr = global::sin.sin_addr.s_addr;
        proxyAddr.sin_port = global::sin.sin_port;

        memset(&buffer, 0, sizeof(buffer));
        sprintf(buffer, "%d", getpid());
        sendto(s, buffer, strlen(buffer), 0, (struct sockaddr*) &proxyAddr, addrlen);
    }

    void stage2(){
        int count = 0;

        while (1){
            count++;
            // if (count%5 == 0) fflush(logfd);

            memset(&buffer, 0, sizeof(buffer));
            int nSize = sizeof(struct sockaddr);
            int strLen = recvfrom(s, buffer, BUF_SIZE, 0, (struct sockaddr*) &proxyAddr, (socklen_t*) &nSize);

            printf("\n%d Router: Read a packet from proxy, packet length:%d\n", count, strLen);

            //get an ICMP ECHO packet from Proxy
            Packer *p = new Packer(buffer, strLen);

            if (p->parse()){
                // LOG(logfd, "ICMP from port: %d, src: %s, dst: %s, type: %d\n", proxyAddr.sin_port, p->src.data(), p->dst.data(), p->type);
                //send it to the router
                p->icmpReply();
                //p->printPacket();
                p->sendUDP(&proxyAddr, s, p->getPacket(), p->getPacketLen());
            }
            else
                fprintf(stderr, "Invalid packet!\n");

            delete p;
        }
    }
};

#endif