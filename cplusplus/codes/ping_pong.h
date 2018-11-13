// Given:
// rev()
// send()
// wait(): after rev and send后有一个handler给wait来等待收发完成
// getCurrentTime()
// non-blocking to blocking?
// Calculate Round Trip Time (RTT)
// 自己新建char数组当作buffer，用delete[]删除创建的数组
// todo: ping(): send req 
//       pong(): receive req, return data


#include <stdio.h>
#include <stdlib.h>

struct Request;

extern char *msgError;



int Send(const void *buf, size_t size, int destination, Request *r);

int Recv(void *buf, size_t size, int source, Request *r);

int Wait(Request *r, size_t size);

double GetTimeNS();

int Rank();

int Size();

void ping(const int destination){
    Request r;
    char buf[8];
    int flag;
    double start_time = GetTimeNS();
    if(Send(&buf, sizeof(buf), destination, &r) != 0){
        throw "send error";
    }
    if(Wait(&r, sizeof(buf)) != 0){
        throw "";
    }

}

void pong(const int destination){

}

int main(int, char *[]){
    int size = Size();
    int rank = Rank();
    if(size < 2){
        fprintf(stderr, "Fatal error: need at least two hosts\n");
    }
    if(rank == 0);


    return 0;
}
