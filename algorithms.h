#pragma once

#include "PCB.h"
#include "Helpers.h"

using namespace std;

int first_come_first_serve(vector<PCB> v, int context_switch = 0)
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
    return time;
}
void shortest_job_first(vector<PCB> v, int context_switch = 0)
{
}
void round_robin(int quantum, vector<PCB> v, int context_switch = 0)
{
}
