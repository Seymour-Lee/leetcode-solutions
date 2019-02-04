#include "headers.h"

int main(int argc, char const *argv[]){
    std::cout<<"in main()"<<std::endl;
    utils::test();
    // parse args && get conf info
    utils::GetConf(argc, argv);

    // run process:
    // clear env
    utils::CleanEnv();

    // set global variables
    utils::SetGlobals();

    // instaniate socket

    // fork child process

    // run self or child
    
    return 0;
}