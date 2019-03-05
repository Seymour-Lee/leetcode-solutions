#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <unistd.h>
#include <cassert>

struct job{
    int pid;
    int arrival_time;
    int job_time;

    int execution_time; // job done when job_time == execution_time
    int stats_waiting_time;
    int stats_turnaround_time;
};

int process_run_queue(std::deque<job> &run_queue,
                      std::deque<job> &done_queue,
                      int time_quantum,
                      int current_time)
{
    int time_consumed = 0;
    job proc = run_queue.front();
    run_queue.pop_front();
    bool finish = false;

    if(proc.execution_time + time_quantum >= proc.job_time){
        finish = true;
        time_consumed = proc.job_time - proc.execution_time;
        proc.execution_time += time_consumed;
        proc.stats_turnaround_time = proc.execution_time + proc.stats_waiting_time;
    }
    else{
        time_consumed = time_quantum;
        proc.execution_time += time_consumed;
    }

    for(auto &wait_proc: run_queue) wait_proc.stats_waiting_time += time_consumed;

    if(finish) done_queue.push_back(proc);
    else run_queue.push_back(proc);

    // cout<<"current_time "<<current_time<<", "
    
    return time_consumed;
}

void calculate_round_robin(std::deque<job> &global_queue,
                           std::deque<job> &done_queue,
                           int time_quantum){
    std::sort(std::begin(global_queue), std::end(global_queue), [](const job &a, const job &b)->bool{
        return a.arrival_time <= b.arrival_time;
    });
    std::deque<job> run_queue;
    int current_time = 0;
    int done = 0;
    while(!run_queue.empty() || !global_queue.empty()){
        if(!global_queue.empty()){
            while(!global_queue.empty() && current_time > global_queue.front().arrival_time){
                run_queue.push_back(global_queue.front());
                global_queue.pop_front();
            }
            if(run_queue.empty()){
                run_queue.push_back(global_queue.front());
                current_time = global_queue.front().arrival_time;
                global_queue.pop_front();
            }
        }
        current_time += process_run_queue(run_queue, done_queue, time_quantum, current_time);
    }
    cout<<"current_time is "<<current_time<<endl;

}

void test_rrschedual(){
    // t = 0
    std::deque<job> jobs {
        {0, 0, 9, 0, 0, 0},
        {1, 1, 5, 0, 0, 0},
        {2, 2, 3, 0, 0, 0},
        {3, 3, 4, 0, 0, 0},
    };
    // std::deque<job> jobs {
    //     {1, 0, 10, 0, 0, 0},
    //     {2, 1, 4, 0, 0, 0},
    //     {3, 2, 5, 0, 0, 0},
    //     {4, 3, 3, 0, 0, 0},
    // };

    // t = 0, 0 comes, [0].exe = 2, [0].wait = 0,
    // t = 2
    std::deque<job> done_queue;
    calculate_round_robin(jobs, done_queue, 2);
    fprintf(stdout, "pid\t arrival_time\t job_time\t execution_time\t turnaround\t waiting_time\n");
    for(auto &job: done_queue){
        fprintf(stdout, "%d\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",
                job.pid, job.arrival_time, job.job_time, job.execution_time,
                job.stats_turnaround_time, job.stats_waiting_time);
    }
}




