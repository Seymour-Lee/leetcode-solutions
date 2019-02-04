#ifndef _UTILS_H_
#define _UTILS_H_

#include "headers.h"

namespace utils{
    void test(){
        std::cout<<"in utils::test()"<<std::endl;
    }

    namespace global{
        int stage = -1;
        // int num_routers;
        // pid_t router_pid;
        // short unsigned int udp_port;

        // FILE *logfd;

        sigset_t signal_set;
        // pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
        // pthread_t proxy_thread, monitor_thread;

        // /* -------------- Global Variables for Proxy Only --------------- */
        // int sock;
        // int tun_fd;
        // struct sockaddr_in addr;

    }

    void GetConf(int argc, char const *argv[]){

    }

    void CleanEnv(){
        sigemptyset(&global::signal_set);
        sigaddset(&global::signal_set, SIGINT);
        sigprocmask(SIG_BLOCK, &global::signal_set, 0);
    }

    void SetGlobals(){

    }



    

}

#endif