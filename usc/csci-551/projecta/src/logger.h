#ifndef _LOGGER_H_
#define _LOGGER_H_

#include "shares.h"

#define logger Logger::getInstance()

class Logger{
public:
    static Logger & getInstance() {
        static Logger instance;
        return instance;
    }

    std::streambuf * rdbuf() const {
        return stream.rdbuf();
    }

    std::streambuf * rdbuf(std::streambuf * sb) {
        return stream.rdbuf(sb);
    }

    operator std::ostream&() {
        return stream;
    }
    
private:
    Logger();
    
    int tabCounter;
    
    std::ostream stream;
};

#endif