#include <bits/stdc++.h>
using namespace std;

struct Process {
	int pid;
	int arrival;
	int burst;
	int start;
	int finish;
	int waiting;
	int turnAround;
};

int main(){
	int n;
	cout << "Enter number of processes : ";
	cin >> n;

	vector<Process> processes(n);

	for(int i = 0; i < n; i++){
		processes[i].pid = i + 1;
		cout << "Enter Arrival and Burst Time for Process " << i + 1 << ": ";
		cin >> processes[i].arrival >> processes[i].burst;
	}

	auto comp = [&](Process& a, Process& b){
		return a.arrival < b.arrival;
	};

	sort(processes.begin(), processes.end(), comp);

	int currTime = 0;
	float totalWaiting = 0, totalTurnAround = 0;

	for(int i = 0; i < n; i++){
		processes[i].start = max(currTime, processes[i].arrival);
		processes[i].finish = processes[i].start + processes[i].burst;
		processes[i].turnAround = processes[i].finish - processes[i].arrival;
        	processes[i].waiting = processes[i].turnAround - processes[i].burst;

		totalWaiting += processes[i].waiting;
        	totalTurnAround += processes[i].turnAround;

        	currTime = processes[i].finish;

	}

	cout << "\nPID\tArrival\tBurst\tStart\tFinish\tWaiting\tTurnaround\n";
    	for (const auto& p : processes) {
        	cout << p.pid << "\t" << p.arrival << "\t" << p.burst << "\t"
             	<< p.start << "\t" << p.finish << "\t" << p.waiting << "\t" << p.turnAround << "\n";
    	}

    	cout << fixed << setprecision(2);
    	cout << "\nAverage Waiting Time: " << totalWaiting / n;
    	cout << "\nAverage Turnaround Time: " << totalTurnAround / n << "\n";

   	return 0;
}
