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
        int s = socket(AF_INET, SOCK_DGRAM, 0);
        socklen_t addr_len = sizeof(struct sockaddr_in);

        memset(&global::sin, 0, sizeof(struct sockaddr_in));
        global::sin.sin_family = AF_INET;
        global::sin.sin_addr.s_addr = inet_addr(global::ip_address);
        global::sin.sin_port = htons(0);
        bind(s, (struct sockaddr*) &global::sin, addr_len);
        getsockname(s, (struct sockaddr*) &global::sin, &addr_len);
        return s;
    }
}

#endif