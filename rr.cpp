//Wrong code
//Might not work
#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<vector>
using namespace std;

struct Process {
    int pid;
    int waitingTime;
    int burstTime;
    int turnAroundTime;
    int arrivalTime;

    Process(int _pid, int _burstTime, int _arrivalTime) : pid(_pid), burstTime(_burstTime), arrivalTime(_arrivalTime){
        waitingTime = 0;
        turnAroundTime = 0;
    };
};

void findTurnAroundTime(Process processes[], int n) {
    for(int i = 0; i < n; i++) {
        processes[i].turnAroundTime = processes[i].waitingTime + processes[i].burstTime - processes[i].arrivalTime;
    }
}

void findWaitingTime(Process processes[], int n, int burstTime) {
    int remainingTime[n];
    for(int i = 0; i < n; i++)
        remainingTime[i] = processes[i].burstTime;

    int completedProcess = 0, t = 0;
    bool check = false;
    vector<int> queue;

    int timeSlotCount = 0;
    int index = 0;
    
    while(completedProcess != n) {
        for(int i =0; i < n; i ++) {
            if(processes[i].arrivalTime == t) {
                queue.push_back(i);
                check = true;
            }
        }

        if(check == false) {
            t++;
            continue;        }

        if(timeSlotCount == 4) {
            timeSlotCount = 0;
            if(index - 1 > 0 && queue.size() > index - 1) {
                processes[queue.at(index - 1)].waitingTime += 4;
            }
            index = index + 1 >= queue.size() ? 0 : index + 1;
        }

        if(remainingTime[queue.at(index)] == 0) {
            queue.erase(queue.begin() + index);
            completedProcess++;
        } else {
            timeSlotCount++;
            remainingTime[queue.at(index)]--;
        }

        if(queue.size() == 0) {
            check = false;
        }
    }
    t++;
}

int compare(const void* item1, const void* item2) {
    return (*(Process*)item1).arrivalTime - (*(Process*)item2).arrivalTime;
}

void compute(Process processes[], int n, int burstTime) {
    qsort(processes, n, sizeof(Process), compare);

    findWaitingTime(processes, n, burstTime);
    findTurnAroundTime(processes, n);
    
    cout<<"Process\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time\n";
        for(int i = 0; i < n; i++) 
        printf("%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrivalTime, processes[i].burstTime, processes[i].waitingTime, processes[i].turnAroundTime);

        int aveargeWaitTime = 0;
        for(int i = 0; i < n; i++) {
            aveargeWaitTime += processes[i].waitingTime;
        }
    aveargeWaitTime /= n;

    int aveargeTurnAroundTime = 0;
    for(int i = 0; i < n; i++) {
        aveargeTurnAroundTime += processes[i].turnAroundTime;
    }
    aveargeTurnAroundTime /= n;

    cout<<"Average Wait Time: "<<aveargeWaitTime<<endl;
    cout<<"Avearge Turn Around Time: "<<aveargeTurnAroundTime<<endl;
}

int main() {
    Process processes[] = {
        Process(1, 6, 1),
        Process(2, 8, 1),
        Process(3, 7, 2),
    };

    int n = 3;
    int burstTime = 4;

    compute(processes, n, burstTime);
    return 0;
}