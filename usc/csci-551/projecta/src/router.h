#ifndef _ROUTER_H_
#define _ROUTER_H_

#include "shares.h"

// interfaces
class Router{
public:
    virtual void run(int _stage) = 0;
};

class Primary: public Router{
public:
    Primary() {}

    ~Primary() {}

    void run(int _stage){
        cout<<"in Primary::run(), _stage is "<<_stage<<endl;
    }
};

class Secondary: public Router{
public:
    Secondary() {
        signal(SIGTERM, this->killself);
        signal(SIGABRT, this->killself);
    }

    ~Secondary() {}

    void run(int _stage){
        cout<<"in Secondary::run(), _stage is "<<_stage<<endl;
        


    }

private:
    int stage;
    int s;

    void killself(){

    }

    void stage1(){

    }

    void stage2(){

    }
};

#endif