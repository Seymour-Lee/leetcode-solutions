#ifndef _SHARES_H_
#define _SHARES_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <signal.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/wait.h>
#include <netdb.h>
#include <net/if.h>
#include <linux/if_tun.h>
#include <linux/ip.h>
#include <linux/icmp.h>
#include <linux/tcp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/time.h>

using namespace std;

#define BUF_SIZE 65535
#define MAXSIZE 2048
#define MAXPATHLENGTH 256
#define IPV4_OFFSET 20

struct octane_control{
    uint8_t octane_action; // forward(1), reply(2), drop(3), remove(4)
    uint8_t octane_flags; // "take the action"(0), ACK, "acknowledge action taken"(1)
    uint16_t octane_seqno; // start from 1, incrementing with each subsequent
    uint32_t octane_source_ip; //
    uint32_t octane_dest_ip;
    uint16_t octane_source_port;
    uint16_t octane_dest_port;
    uint16_t octane_protocol;
    uint16_t octane_port;
};

struct psd_tcp {
        struct in_addr src;
        struct in_addr dst;
        unsigned char pad;
        unsigned char proto;
        unsigned short tcp_len;
        struct tcphdr tcp;
};

namespace global{
    // process related
    const char* ip_address = "127.0.0.1";
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pid_t pid;

    // config inf
    string config_file_name = "";
    string log_file_name = "";
    int stage = -1;
    int num_routers = 0;
    // stage4 and above
    int drop_after = -1;

    struct sockaddr_in sin;
    short unsigned int primary_port;
    sigset_t signal_set;
    pthread_t proxy_thread, monitor_thread;
    int tun_fd;
    int service;

    // stage3
    struct sockaddr_in *eth;

    // stage6 and above
    int *routers_pid;
    int *routers_port;

    // struct sockaddr_in *r_addr;
}

#endif