#ifndef _ROUTER_H_
#define _ROUTER_H_

#include "shares.h"
#include "packer.h"
#include "logger.h"

// interfaces
class Router{
public:
    virtual void run() = 0;
};

#endif