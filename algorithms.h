#pragma once

#include <deque>
#include "PCB.h"
#include "Helpers.h"

using namespace std;

pair<int, vector<PCB>> first_come_first_serve(vector<PCB> v, int context_switch = 0)
{
    int time = 0;
    cout << "0 | ";
    for (PCB &current_process : v)
    {
        time += current_process.cpu_burst;
        cout << "P" << current_process.id << " | " << time << " | ";
        handle_processing_in_FCFS(time, current_process);
        if (context_switch != 0)
        {
            cout << "CS = " << context_switch << " | ";
            time += context_switch;
            cout << time << " | ";
        }
    }
    cout << '\n';
    return {time, v};
}
pair<int, vector<PCB>> shortest_job_first(vector<PCB> v, int context_switch = 0)
{
    int time = 0;
    cout << "0 | ";
    deque<PCB> remain_processes(begin(v), end(v)); // Give the processes to the deque
    while (!remain_processes.empty())
    {
        sort_on_SJF(remain_processes, time);
        PCB current_process = remain_processes.front();
        remain_processes.pop_front();
        time += current_process.cpu_burst;
        cout << "P" << current_process.id << " | " << time << " | ";
        handle_processing_in_SJF(time, current_process, v);
        if (context_switch != 0)
        {
            cout << "CS = " << context_switch << " | ";
            time += context_switch;
            cout << time << " | ";
        }
    }
    cout << '\n';
    return {time, v};
}
pair<int, vector<PCB>> round_robin(int quantum, vector<PCB> v, int context_switch = 0)
{
    return {0, vector<PCB>()};
}
