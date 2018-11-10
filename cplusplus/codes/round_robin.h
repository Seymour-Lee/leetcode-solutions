// C++ program for implementation of RR scheduling 
#include <iostream> 
#include <deque>

using namespace std; 

// Function to find the waiting time for all 
// processes 
void findWaitingTime(int processes[], int n, 
			int bt[], int wt[], int quantum) 
{ 
	// Make a copy of burst times bt[] to store remaining 
	// burst times. 
	int rem_bt[n]; 
	for (int i = 0 ; i < n ; i++) 
		rem_bt[i] = bt[i]; 

	int t = 0; // Current time 

	// Keep traversing processes in round robin manner 
	// until all of them are not done. 
	while (1) 
	{ 
		bool done = true; 

		// Traverse all processes one by one repeatedly 
		for (int i = 0 ; i < n; i++) 
		{ 
			// If burst time of a process is greater than 0 
			// then only need to process further 
			if (rem_bt[i] > 0) 
			{ 
				done = false; // There is a pending process 

				if (rem_bt[i] > quantum) 
				{ 
					// Increase the value of t i.e. shows 
					// how much time a process has been processed 
					t += quantum; 

					// Decrease the burst_time of current process 
					// by quantum 
					rem_bt[i] -= quantum; 
				} 

				// If burst time is smaller than or equal to 
				// quantum. Last cycle for this process 
				else
				{ 
					// Increase the value of t i.e. shows 
					// how much time a process has been processed 
					t = t + rem_bt[i]; 

					// Waiting time is current time minus time 
					// used by this process 
					wt[i] = t - bt[i]; 

					// As the process gets fully executed 
					// make its remaining burst time = 0 
					rem_bt[i] = 0; 
				} 
			} 
		} 

		// If all processes are done 
		if (done == true) 
		break; 
	} 
} 

// Function to calculate turn around time 
void findTurnAroundTime(int processes[], int n, 
						int bt[], int wt[], int tat[]) 
{ 
	// calculating turnaround time by adding 
	// bt[i] + wt[i] 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 

// Function to calculate average time 
void findavgTime(int processes[], int n, int bt[], 
									int quantum) 
{ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 

	// Function to find waiting time of all processes 
	findWaitingTime(processes, n, bt, wt, quantum); 

	// Function to find turn around time for all processes 
	findTurnAroundTime(processes, n, bt, wt, tat); 

	// Display processes along with all details 
	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n"; 

	// Calculate total waiting time and total turn 
	// around time 
	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl; 
	} 

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n; 
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n; 
}

// Driver code 
void test_round_robin() 
{ 
	// process id's 
	int processes[] = { 1, 2, 3}; 
	int n = sizeof processes / sizeof processes[0]; 

	// Burst time of all processes 
	int burst_time[] = {10, 5, 8}; 

	// Time quantum 
	int quantum = 2; 
	findavgTime(processes, n, burst_time, quantum); 
}

struct Job{
	int pid;
	int job_time;
	int arrive_time;
	// update the following variables
	// turnaround = completion - arrival
	// waittime = turnaround - burst
	int wait_time; // remember to update this
	int execution_time; //remaining time for the current job? Maybe! > time_quantum -> running_queue
	int turnaround_time; // = wait_time + execution_time

	void print(){
		cout<<pid<<"--"<<job_time<<" "<<arrive_time<<" "<<wait_time<<" "<<execution_time<<" "<<turnaround_time<<endl;
	}
};

// If many Jobs arrive at time t, I only need to deal with the top() Job of the queue, right?
class Scheduler{
public:
	// 把run_queue里面的Job一个个pop出来，在时间片内完成就push到done queue里面，否则更新一下job time、execution time，再push进入run queue
	// Is it possible that o job's arrive_time is later than current_time?
	void process_run_queue(deque<Job> &running_queue, deque<Job> &done_queue, int time_quantum, int& current_time){
		int size = running_queue.size();
		while(size--){
			auto job = running_queue.front(); running_queue.pop_front();
			// How to update wait_time?
			if(job.execution_time+time_quantum >= job.job_time){ // finish
				int remain_time = job.job_time - job.execution_time;
				current_time += remain_time;
				job.execution_time += remain_time;
				job.wait_time = current_time - job.arrive_time - job.job_time;
				job.turnaround_time = current_time - job.arrive_time;
				done_queue.push_back(job);
			}
			else{ // push back to running_queue
				job.execution_time += time_quantum;
				current_time += time_quantum;
				running_queue.push_back(job);
			}
		}
	}

private:
	// deque<Job> running_jobs;
	// deque<Job> done_jobs;
	// int time_quantum;
};

// Find some test cases online
void test_scheduler(){
	Scheduler scheduler;
	Job a = {1, 10, 0, 0, 0, 0};
	Job b = {2, 5, 0, 0, 0, 0};
	Job c = {3, 8, 0, 0, 0, 0};
	// Job a = {1, 10, 0, 0, 0, 0};
	// Job b = {2, 4, 1, 0, 0, 0};
	// Job c = {3, 5, 2, 0, 0, 0};
	// Job d = {4, 3, 3, 0, 0, 0};
	deque<Job> running_queue;
	running_queue.push_back(a);
	running_queue.push_back(b);
	running_queue.push_back(c);
	// running_queue.push_back(d);
	deque<Job> done_queue;
	const int time_quantum = 2;
	int current_time = 0;
	int round = 5;
	while(round--){
		scheduler.process_run_queue(running_queue, done_queue, time_quantum, current_time);
		cout<<round<<endl;
		for(auto p: running_queue) p.print();
		cout<<endl;
	}
	double total_wait_time = 0;
	double total_turnaround_time = 0;
	for(auto p: done_queue){
		p.print();
		total_wait_time += p.wait_time;
		total_turnaround_time += p.turnaround_time;
	}
	cout<<"Average waiting time:     "<<total_wait_time / done_queue.size()<<endl;
	cout<<"Average turn around time: "<<total_turnaround_time / done_queue.size()<<endl;
	
	

}


