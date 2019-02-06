#ifndef _UTILS_H_
#define _UTILS_H_

#include "shares.h"

namespace utils{
    void getConf(int argc, char const *argv[]){
        argc--, argv++;

        // check arg valid or not
        if(argc != 1) throw "arguments number is wrong";
        global::config_file_name = string(argv[0]);

        // check file existion
        auto checkfile = [](string path){
            ifstream f(path.c_str());
            return f.good();
        };

        if(checkfile(global::config_file_name) == false) throw "invaild file path";
        // set config info
        ifstream inf(global::config_file_name);
        string line = "";
        while(getline(inf, line)) if(line.size() > 0 && line[0] != '#'){
            auto pos = line.find(' ');
            string name = line.substr(0, pos);
            int val = stoi(line.substr(pos));
            if(name == "stage") global::stage = val;
            if(name == "num_routers") global::num_routers = val;
        }
    }

    void cleanEnv(){
        sigemptyset(&global::signal_set);
        sigaddset(&global::signal_set, SIGINT);
        sigprocmask(SIG_BLOCK, &global::signal_set, 0);
    }

    int initSocket(){
        // alloc socket
        int listen = socket(AF_INET, SOCK_DGRAM, 0);
        socklen_t addr_len = sizeof(struct sockaddr_in);

        memset(&global::sin, 0, sizeof(struct sockaddr_in));
        global::sin.sin_family = AF_INET;
        global::sin.sin_addr.s_addr = inet_addr(global::ip_address);
        global::sin.sin_port = htons(0);
        ::bind(listen, (struct sockaddr*) &global::sin, addr_len);
        getsockname(listen, (struct sockaddr*) &global::sin, &addr_len);
        return listen;
    }

    int tun_alloc(char *dev, int flags){
        struct ifreq ifr;
        int fd, err;
        char *clonedev = (char*)"/dev/net/tun";

        if( (fd = open(clonedev , O_RDWR)) < 0 ){
            perror("Opening /dev/net/tun");
            return fd;
        }

        memset(&ifr, 0, sizeof(ifr));

        ifr.ifr_flags = flags;

        if (*dev){
            strncpy(ifr.ifr_name, dev, IFNAMSIZ);
        }

        if( (err = ioctl(fd, TUNSETIFF, (void *)&ifr)) < 0 ){
            perror("ioctl(TUNSETIFF)");
            close(fd);
            return err;
        }
        strcpy(dev, ifr.ifr_name);
        return fd;
    }

    unsigned short checksum(char *addr, short count)
    {
        /* Compute Internet Checksum for "count" bytes
            *         beginning at location "addr".
            */
        long sum = 0;

            while( count > 1 )  {
            /*  This is the inner loop */
                sum += *(unsigned short *) addr;
                cout<<*(unsigned short *)addr<<" "<<sum<<endl;
                // printf("%c%c\n", addr[0], addr[1]);
            addr += 2;
                count -= 2;
        }cout<<endl;

            /*  Add left-over byte, if any */
        if( count > 0 )
                sum += * (unsigned char *) addr;

            /*  Fold 32-bit sum to 16 bits */
        while (sum>>16)
            sum = (sum & 0xffff) + (sum >> 16);
        cout<<(unsigned short) ~sum<<endl;
        return (unsigned short) ~sum;
    }
}

#endif