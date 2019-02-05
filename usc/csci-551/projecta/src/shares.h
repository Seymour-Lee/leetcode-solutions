#ifndef _SHARES_H_
#define _SHARES_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>

#include <csignal>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

namespace global{
    // process related
    const char* ip_address = "127.0.0.1";
    pid_t pid;
    // FILE *logfd;


    // config inf
    string config_file_name = "";
    int stage = -1;
    int num_routers = 0;

    // socket related
    // short unsigned int upd_port; // use sin.sin_port
    struct sockaddr_in sin;

    

    sigset_t signal_set;
    // pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    // pthread_t proxy_thread, monitor_thread;

    // /* -------------- Global Variables for Proxy Only --------------- */
    // int sock;
    // int tun_fd;

}

#endif