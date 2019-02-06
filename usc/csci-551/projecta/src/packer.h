#ifndef _PACKER_H_
#define _PACKER_H_

#include "shares.h"
#include "utils.h"

class Packer{
public:
    int type;
    string src;
    string dst;

    Packer(char* buf, int nread): packet(buf), len(nread){}

    int recieve(){
        if(len < IPV4_OFFSET+8) return 0;
        char buf[BUF_SIZE];
        sprintf(&buf[0], "%d", *(packet+IPV4_OFFSET));
        type = atoi(buf);
        std::stringstream ss;
        for(size_t i = 0; i < 4; i++){
            memset(&buf, 0, sizeof(buf));
            sprintf(&buf[0], "%d", *(packet+IPV4_OFFSET-8+i));
            ss << buf << '.';
        }
        src = ss.str();
        ss.str("");
        for(size_t i = 0; i < 4; i++){
            memset(&buf, 0, sizeof(buf));
            sprintf(&buf[0], "%d", *(packet+IPV4_OFFSET-4+i));
            ss << buf << '.';
        }
        dst = ss.str();
        return 1;
    }

    char* getpacket() {return packet;}

    int getlen() {return len;}
    
    int switchip(){
        *(packet+IPV4_OFFSET) = 0;
        char tmp;
        for(size_t i = 0; i < 4; i++){
            tmp = *(packet+IPV4_OFFSET-8+i);
            *(packet+IPV4_OFFSET-8+i) = *(packet+IPV4_OFFSET-4+i);
            *(packet+IPV4_OFFSET-4+i) = tmp;
        }
        return 0;
    }
    int send(struct sockaddr_in *addr, int sock, char* payload, int len){
        socklen_t addrlen = sizeof(struct sockaddr_in);
        sendto(sock, payload, len, 0, (struct sockaddr*) addr, addrlen);
        return 0;
    }

    int printPacket(){
        char converted[len*2 + 1];
        for(size_t i=0; i<len; i++){
            sprintf(&converted[i*2], "%02X", *(packet+i));
        }

        for (size_t i = 0; i < len/8; ++i)
        {
            printf("%c%c : %c%c : %c%c : %c%c\n",
                converted[8*i+0],converted[8*i+1],converted[8*i+2],converted[8*i+3],
                converted[8*i+4],converted[8*i+5],converted[8*i+6],converted[8*i+7]);
        }
        return 0;
    }
    int printICMP(){
        char converted[BUF_SIZE];
        for(size_t i=0; i<8; i++){
            sprintf(&converted[i*2], "%02X", *(packet+i+IPV4_OFFSET));
        }

        for (size_t i = 0; i < 2; ++i)
        {
            if (i==0)
                printf("Type : Code :  Checksum\n");
            else
                printf(" Identifier : Sequence #\n");

            printf("%c%c : %c%c : %c%c : %c%c\n",
                converted[8*i+0],converted[8*i+1],converted[8*i+2],converted[8*i+3],
                converted[8*i+4],converted[8*i+5],converted[8*i+6],converted[8*i+7]);
        }
        return 0;
    }
    void setChecksum(){
        *(packet+IPV4_OFFSET+2) = 0;
        *(packet+IPV4_OFFSET+3) = 0;
        unsigned short chksum = utils::checksum(packet+IPV4_OFFSET, len-IPV4_OFFSET);
        cout<<chksum<<" "<<(chksum >> 8)<<" "<<(chksum & 0x00ff)<<endl;
        *(packet+IPV4_OFFSET+2) = chksum >> 8;
        *(packet+IPV4_OFFSET+3) = chksum & 0x00ff;
    }
    void check(){
        cout<<len<<" "<<len-IPV4_OFFSET<<endl;
        unsigned short chksum = utils::checksum(packet+IPV4_OFFSET, len-IPV4_OFFSET);
        cout<<chksum<<" "<<(chksum >> 8)<<" "<<(chksum & 0x00ff)<<endl;
        *(packet+IPV4_OFFSET+2) = chksum >> 8;
        *(packet+IPV4_OFFSET+3) = chksum & 0x00ff;
    }

private:
    char* packet;
    int len; // number of bytes    
};

#endif