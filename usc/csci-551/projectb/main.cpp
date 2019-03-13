#include "shares.h"
#include "utils.h"
#include "router.h"
#include "logger.h"

Router *router = nullptr;

void* watcher(void* arg){
    int sig2wait;
    sigwait(&global::signal_set, &sig2wait);
    pthread_mutex_lock(&global::mutex);
    close(global::tun_fd);
    int status;
    kill(global::pid, SIGTERM);
    wait(&status);
    if (WIFSIGNALED(status)) cout<<"Secondary got killed"<<endl;
    close(global::service);
    pthread_cancel(global::proxy_thread);
    pthread_mutex_unlock(&global::mutex);
    // std::ofstream fout;
    // fout.open(global::log_file_name);
    // Logger::getInstance().rdbuf(fout.rdbuf());
    ostream& logger = Logger::getInstance();
    logger<<"router 0 closed"<<endl;
}

void* doer(void* arg){
    router = new Primary(global::service, global::stage);
    router->run();
}

int main(int argc, char const *argv[]){
    cout<<"in main()"<<endl;

    try{
        // parse args && get conf info
        utils::getConf(argc, argv);
        cout<<global::config_file_name<<" "<<global::stage<<" "<<global::num_routers<<endl;

        // run process:
        // clear env
        utils::cleanEnv();

        // set socket
        int s = utils::initSocket();
        if(s < 0) throw "an error occured while initializing socket";
        global::primary_port = global::sin.sin_port;
        global::service = s;

        // fork child process
        global::pid = fork();
        // run self or child
        
        if(global::pid == 0) {
            router = new Secondary(s, global::stage);
            router->run();
        }
        else {
            pthread_create(&global::proxy_thread, NULL, doer, NULL);
            pthread_create(&global::monitor_thread, NULL, watcher, NULL);
            pthread_join(global::proxy_thread,0);
            pthread_cancel(global::monitor_thread);
        }
        // if(router != nullptr) delete router;
    }
    catch(exception& e){
        cout<<"in catch"<<endl;
        cout << e.what() << endl;
    }
    
    return 0;
}