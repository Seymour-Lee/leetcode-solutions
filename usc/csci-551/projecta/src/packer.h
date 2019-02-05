#ifndef _PACKER_H_
#define _PACKER_H_

#include "shares.h"

class Packer{
public:
    int type;
    string src;
    string dst;

    Packer(char* buf, int read);
    int parse();
    char* getPacket();
    int getPacketLen();
    
    int icmpReply();
    int sendUDP(struct sockaddr_in *addr, int sock, char* payload, int len);

    int printPacket();
    int printICMP();

private:
    char* packet;
    int len;
};

Packer::Packer(char* buf, int nread)
{
    packet = buf;
    len = nread;
}

/*******************************************************************
    Parse the packet, get type, src and dst
*******************************************************************/
int Packer::parse()
{
    if (len<IPV4_OFFSET+8) // invalid ICMP packet
        return 0;

    char buf[BUF_SIZE];
    /* type */
    sprintf(&buf[0], "%d", *(packet+IPV4_OFFSET));
    type = atoi(buf);
    /* src */
    std::stringstream ss;
    for(size_t i=0; i<4; i++){
        memset(&buf, 0, sizeof(buf));
        sprintf(&buf[0], "%d", *(packet+IPV4_OFFSET-8+i));
        ss << buf << '.';
    }
    src = ss.str().substr(0, ss.str().length()-1);
    /* dst */
    ss.str("");
    for(size_t i=0; i<4; i++){
        memset(&buf, 0, sizeof(buf));
        sprintf(&buf[0], "%d", *(packet+IPV4_OFFSET-4+i));
        ss << buf << '.';
    }
    dst = ss.str().substr(0, ss.str().length()-1);
    return 1;
}

/*******************************************************************
Print the ICMP ECHO Header:

    0                   1                   2                   3
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |     Type      |     Code      |          Checksum             |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |           Identifier          |        Sequence Number        |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |     Data ...
    +-+-+-+-+-
*******************************************************************/
int Packer::printICMP()
{
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

/*******************************************************************
    Print the Whole packet
*******************************************************************/
int Packer::printPacket() {
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

/*******************************************************************
    Generate the ICMP echo reply Packer of char* p
*******************************************************************/
int Packer::icmpReply()
{
    /* type = 0 */
    *(packet+IPV4_OFFSET) = 0;

    /* swap dst and src */
    char tmp;
    for(size_t i=0; i<4; i++){
        tmp = *(packet+IPV4_OFFSET-8+i);
        *(packet+IPV4_OFFSET-8+i) = *(packet+IPV4_OFFSET-4+i);
        *(packet+IPV4_OFFSET-4+i) = tmp;
    }

    return 0;
}


/*******************************************************************
    Get the whole packet (include IPv4 header)
*******************************************************************/
char* Packer::getPacket()
{
    return packet;
}

int Packer::getPacketLen() {
    return len;
}

/*******************************************************************
    Send the packet payload to another UDP socket
*******************************************************************/
int Packer::sendUDP(struct sockaddr_in *addr, int sock, char* payload, int len){
    socklen_t addrlen = sizeof(struct sockaddr_in);
    sendto(sock, payload, len, 0, (struct sockaddr*) addr, addrlen);
    return 0;
}

#endif