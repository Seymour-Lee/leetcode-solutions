#ifndef _PACKER_H_
#define _PACKER_H_

#include "shares.h"
#include "utils.h"

struct icmp_header
{
    u_char icmp_type;
    u_char icmp_code;
    u_short icmp_sum;
    u_short icmp_ident;
    u_short icmp_seq;
};

class Packer{
public:
    int type;
    string src;
    string dst;
    int src_int, dst_int;
    int icmptype;

    unsigned int srcport;
    unsigned int dstport;
    unsigned long seqno;
    unsigned long ackno;

    Packer(char* buf, int nread){
        packet = buf;
        len = nread;
        parse();
    }

    void parse(){
        struct sockaddr_in source, dest;
        char src_addr_buf[BUF_SIZE];
        char dst_addr_buf[BUF_SIZE];

        struct iphdr *iph = (struct iphdr *)this->packet;

        this->src_int = iph->saddr;
        this->dst_int = iph->daddr;

        source.sin_addr.s_addr = iph->saddr;
        dest.sin_addr.s_addr = iph->daddr;
        memset(src_addr_buf, 0, BUF_SIZE);
        memset(dst_addr_buf, 0, BUF_SIZE);
        strcpy(src_addr_buf, inet_ntoa(source.sin_addr));
        strcpy(dst_addr_buf, inet_ntoa(dest.sin_addr));

        this->type = iph->protocol;
        this->iphdr_len = iph->ihl * 4;
        this->src = src_addr_buf;
        this->dst = dst_addr_buf;

        this->len = ntohs(iph->tot_len)>0 ? ntohs(iph->tot_len) : len;

        if (this->type == 1)
        {
                // ICMP
                struct icmphdr *icmph = (struct icmphdr *)(packet + iphdr_len);
                this->icmptype = icmph->type;
                this->srcport = 0;
                this->dstport = 0;
        }
        else if (type == 6) {
                // TCP
        }
        else if (type == 253) {
                // the experimental IP protocol number
        }
    }

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
        src.pop_back();
        ss.str("");
        for(size_t i = 0; i < 4; i++){
            memset(&buf, 0, sizeof(buf));
            sprintf(&buf[0], "%d", *(packet+IPV4_OFFSET-4+i));
            ss << buf << '.';
        }
        dst = ss.str();
        dst.pop_back();
        return 1;
    }

    char* getpacket() {return packet;}

    char* get_payload(){return packet+iphdr_len;}
    int get_payload_len(){return len-iphdr_len;}

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

    unsigned short in_cksum(unsigned short *addr, int len) {
        register int sum = 0;
        u_short answer = 0;
        register u_short *w = addr;
        register int nleft = len;

        while (nleft > 1)
        {
                sum += *w++;
                nleft -= 2;
        }

        /* mop up an odd byte, if necessary */
        if (nleft == 1)
        {
                *(u_char *) (&answer) = *(u_char *) w;
                sum += answer;
        }

        /* add back carry outs from top 16 bits to low 16 bits */
        sum = (sum >> 16) + (sum & 0xffff); /* add hi 16 to low 16 */
        sum += (sum >> 16);       /* add carry */
        answer = ~sum;      /* truncate to 16 bits */

        return answer;
    }

    void recheckPkt(){
        struct iphdr *iph = (struct iphdr *)packet;
        iph->check = 0;
        iph->check = in_cksum((unsigned short *)iph, sizeof(struct iphdr));
    }

    int change_dst(string dstIP) {
        struct iphdr *iph = (struct iphdr *)packet;

        /// change src in place
        struct sockaddr_in dst;
        memset(&dst, 0, sizeof(struct sockaddr_in));
        inet_aton(dstIP.c_str(), &dst.sin_addr);

        iph->daddr = dst.sin_addr.s_addr;

        // recompute checksum
        //iph->check = 0;
        //iph->check = in_cksum((unsigned short *)iph, sizeof(struct iphdr));
        recheckPkt();

        // renew src
        char dst_addr_buf[BUF_SIZE];
        memset(dst_addr_buf, 0, BUF_SIZE);
        strcpy(dst_addr_buf, inet_ntoa(dst.sin_addr));
        this->dst = dst_addr_buf;

        return 1;
    }

    int send(struct sockaddr_in *addr, int sock, char* payload, int len){
        socklen_t addrlen = sizeof(struct sockaddr_in);
        sendto(sock, payload, len, 0, (struct sockaddr*) addr, addrlen);
        return 0;
    }

    void setchecksum(){
        // cout<<*(unsigned short *) (packet+IPV4_OFFSET+2)<<endl;
        *(packet+IPV4_OFFSET+2) = 0;
        *(packet+IPV4_OFFSET+3) = 0;
        unsigned short chksum = utils::checksum(packet+IPV4_OFFSET, len-IPV4_OFFSET);
        // cout<<chksum<<" "<<(chksum >> 8)<<" "<<(chksum & 0x00ff)<<endl;
        *(unsigned short *) (packet+IPV4_OFFSET+2) = chksum;
    }
    void check(){
        cout<<len<<" "<<len-IPV4_OFFSET<<endl;
        unsigned short chksum = utils::checksum(packet+IPV4_OFFSET, sizeof(struct icmp_header));
        cout<<chksum<<" "<<(chksum >> 8)<<" "<<(chksum & 0x00ff)<<endl;
        *(unsigned short *) (packet+IPV4_OFFSET+2) = chksum;
        // *(packet+IPV4_OFFSET+2) = (char)(chksum >> 8);
        // *(packet+IPV4_OFFSET+3) = (char)chksum & 0x00ff;
    }

private:
    char* packet;
    int len; // number of bytes
    int iphdr_len;
};

#endif