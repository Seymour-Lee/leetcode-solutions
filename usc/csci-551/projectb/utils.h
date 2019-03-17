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
                // cout<<*(unsigned short *)addr<<" "<<sum<<endl;
                // printf("%c%c\n", addr[0], addr[1]);
            addr += 2;
                count -= 2;
        }// cout<<endl;

            /*  Add left-over byte, if any */
        if( count > 0 )
                sum += * (unsigned char *) addr;

            /*  Fold 32-bit sum to 16 bits */
        while (sum>>16)
            sum = (sum & 0xffff) + (sum >> 16);
        // cout<<(unsigned short) ~sum<<endl;
        return (unsigned short) ~sum;
    }

    unsigned char * serialize_uint32_t(unsigned char *buffer, uint32_t value){
    /* Write big-endian int value into buffer; assumes 32-bit int and 8-bit char. */
        buffer[0] = value >> 24;
        buffer[1] = value >> 16;
        buffer[2] = value >> 8;
        buffer[3] = value;
        return buffer + 4;
    }

    unsigned char * serialize_uint16_t(unsigned char *buffer, uint16_t value){
        buffer[0] = value >> 8;
        buffer[1] = value;
        return buffer + 2;
    }

    unsigned char * serialize_uint8_t(unsigned char *buffer, uint8_t value){
        buffer[0] = value;
        return buffer + 1;
    }

    unsigned char * serialize_octane_control(unsigned char *buffer, struct octane_control *value){
        buffer = serialize_uint8_t(buffer, value->octane_action);
        buffer = serialize_uint8_t(buffer, value->octane_flags);
        buffer = serialize_uint16_t(buffer, value->octane_seqno);
        buffer = serialize_uint32_t(buffer, value->octane_source_ip);
        buffer = serialize_uint32_t(buffer, value->octane_dest_ip);
        buffer = serialize_uint16_t(buffer, value->octane_source_port);
        buffer = serialize_uint16_t(buffer, value->octane_dest_port);
        buffer = serialize_uint16_t(buffer, value->octane_protocol);
        buffer = serialize_uint16_t(buffer, value->octane_port);
        return buffer;
    }

    unsigned char * deserialize_uint32_t(unsigned char *buffer, uint32_t *value){
        *value = *value | (buffer[0] << 24);
        *value = *value | (buffer[1] << 16);
        *value = *value | (buffer[2] << 8);
        *value = *value | (buffer[3]);
        return buffer + 4;
    }

    unsigned char * deserialize_uint16_t(unsigned char *buffer, uint16_t *value){
        *value = *value | (buffer[0] << 8);
        *value = *value | (buffer[1]);
        return buffer + 2;
    }

    unsigned char * deserialize_uint8_t(unsigned char *buffer, uint8_t *value){
        *value = buffer[0];
        return buffer + 1;
    }

    unsigned char * deserialize_octane_control(unsigned char *buffer, struct octane_control *value){
        // buffer = deserialize_int(buffer, &value->a);
        // buffer = deserialize_char(buffer, &value->b);
        buffer = deserialize_uint8_t(buffer, &value->octane_action);
        buffer = deserialize_uint8_t(buffer, &value->octane_flags);
        buffer = deserialize_uint16_t(buffer, &value->octane_seqno);
        buffer = deserialize_uint32_t(buffer, &value->octane_source_ip);
        buffer = deserialize_uint32_t(buffer, &value->octane_dest_ip);
        buffer = deserialize_uint16_t(buffer, &value->octane_source_port);
        buffer = deserialize_uint16_t(buffer, &value->octane_dest_port);
        buffer = deserialize_uint16_t(buffer, &value->octane_protocol);
        buffer = deserialize_uint16_t(buffer, &value->octane_port);
        return buffer;
    }

    void serialize_octane_messgae(unsigned char *buffer, struct iphdr *ori){
        struct iphdr *iph = (struct iphdr*)buffer;
        *iph = *ori;
        iph->protocol = 253;
        
        struct octane_control* octane = (struct octane_control*)(buffer+sizeof(struct iphdr));
        // memset(octane, 0, sizeof(struct octane_control));
        octane->octane_action = 11;
        octane->octane_flags = 12;
        octane->octane_seqno = 3;
        octane->octane_source_ip = 4;
        octane->octane_dest_ip = 5;
        octane->octane_source_port = 6;
        octane->octane_dest_port = 7;
        octane->octane_protocol = 8;
        octane->octane_port = 9;
    }

    void deserialize_octane_message(unsigned char *buffer){

    }

    void test_send_octane(){
        
    }
}

#endif