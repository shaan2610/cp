#include <bits/stdc++.h>
using namespace std;

#define N 5

void waiting_time(int burst_time[], int wait_time[]) {
    wait_time[0] = 0;
    for (int i = 1; i < N; i++) {
        wait_time[i]= wait_time[i - 1] + burst_time[i - 1];
    }
}

void turnaround_time(int burst_time[], int Tat[], int wait_time[]) {
    // turn around time = waiting time + burst time
    for (int i = 0; i < N; i++) {
        Tat[i] = wait_time[i] + burst_time[i];
    }
}

void FCFS(int burst_time[], int id[]) {
    int wait_time[N], tar_time[N]; // waiting time and turnaround time respectively

    waiting_time(burst_time, wait_time);
    turnaround_time(burst_time, tar_time, wait_time);

    int totalWaitTime = 0, totalTarTime = 0;
    
    cout << "Process\t\tWait Time\t\tTurn Around Time\n\n";
    for (int i = 0; i < N; i++) {
        cout << "P" << id[i] << "\t\t\t\t" << wait_time[i] << "\t\t\t\t" << tar_time[i] << endl;
        
        totalWaitTime += wait_time[i];
        totalTarTime += tar_time[i];
    }

    float avg_wait = (float)totalWaitTime / (float)N; // average waiting time
    float avg_tat = (float)totalTarTime / (float)N; // average turnaround time

    cout << "\nAverage Waiting time : \t" << avg_wait << "\n";
    cout << "Average Turn Around Time : \t" << avg_tat << "\n\n";
}

void SJF(int burst_time[] , int s[]) {
    vector<pair<int, int> > vp;

    for (int i = 0; i < N; i++) {
        vp.push_back({burst_time[i], s[i]});
    }

    sort(vp.begin(),vp.end()); // gets sorted w.r.t. burst time

    int a[N], ord[N];
    for (int i = 0; i < N; i++) {
        a[i] = vp[i].first;
        ord[i] = vp[i].second;
    }

    FCFS(a, ord);   
}

void Priority_Scheduling(int burst_time[], int s[], int priority[]) {
    vector<pair<pair<int, int>, int> > vp;

    for (int i = 0; i < N; i++) {
        vp.push_back({{priority[i], s[i]}, burst_time[i]});
    }

    sort(vp.begin(), vp.end());
    // sorted according to priority if collision then follows FCFS

    int a[N], id[N];
    for (int i = 0; i < N; i++) {
        id[i] = vp[i].first.second;
        a[i] = vp[i].second;
    }

    FCFS(a, id);
}

void RoundRobin(int burst_time[], int id[]) {
    int quantum = 1, tmr = 0, tmp[N];
    
    int wait_time[N], tar_time[N];

    for (int i = 0; i < N; i++) {
        wait_time[i] = tar_time[i] = 0;
        tmp[i] = burst_time[i];
    }

    while (true) {
        int ok = 0;
        for (int i = 0; i < N; i++) {
            if (tmp[i] == 0) continue;
            if (tmp[i] <= quantum) {
                // tmp[i] finish hone wala hai
                tmr += tmp[i];
                tar_time[i] = tmr;
                wait_time[i] = tar_time[i] - burst_time[i];
                tmp[i] = 0;
            } else {
                tmp[i] -= quantum;
                tmr += quantum;
                ok++;
            }
        }   
        if (ok == 0) break;
    }

    int totalWaitTime = 0, totalTarTime = 0;

    cout << "Process\t\tWait Time\t\tTurn Around Time\n\n";
    for (int i = 0; i < N; i++) {
        cout << "P" << id[i] << "\t\t\t\t" << wait_time[i] << "\t\t\t\t" << tar_time[i] << endl;
        
        totalWaitTime += wait_time[i];
        totalTarTime += tar_time[i];
    }

    float avg_wait = (float)totalWaitTime / (float)N; // average waiting time
    float avg_tat = (float)totalTarTime / (float)N; // average turnaround time

    cout << "\nAverage Waiting time : \t" << avg_wait << "\n";
    cout << "Average Turn Around Time : \t" << avg_tat << "\n\n";
}

signed main() {
    int id[] = {1, 2, 3, 4, 5};
    int burst_time[] = {10, 1, 2, 1, 5};
    int priority[] = {3, 1, 3, 4, 2};

    cout << "\t\tFCFS Sceduling\n\n";
    FCFS(burst_time, id);

    cout << "\t\tSJF Sceduling\n\n";
    SJF(burst_time, id);

    cout << "\t\tNon-Preemptive Priority Sceduling\n\n";
    Priority_Scheduling(burst_time, id, priority);

    cout << "\t\tRR Sceduling\n\n";
    RoundRobin(burst_time, id);

    cout << "SJF Scheduling is best in terms of Average Waiting Time with 3.2 milliseconds.\n";
    return 0;
} 
