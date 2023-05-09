#pragma once

#include <deque>

#include "PCB.h"
#include "Helpers.h"

using namespace std;

// First Come First Serve Algorithm
pair<int, vector<PCB>> first_come_first_serve(vector<PCB> v, int context_switch = 0)
{
    sort_on_arrival_time_then_id(v);
    int time = 0;
    cout << "0 | ";
    for (PCB &current_process : v)
    {
        time += current_process.cpu_burst;
        cout << UNDERLINE << "P" << current_process.id << CLOSE << " | " << time << " | ";
        handle_processing_in_FCFS(time, current_process);
        if (context_switch != 0)
        {
            cout << UNDERLINE << "CS = " << context_switch << CLOSE << " | ";
            time += context_switch;
            cout << time << " | ";
        }
    }
    cout << '\n';
    return {time, v};
}

// Shortest Job First
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
        cout << UNDERLINE << "P" << current_process.id << CLOSE << " | " << time << " | ";

        handle_processing_in_SJF(time, current_process, v);
        if (context_switch != 0)
        {
            cout << UNDERLINE << "CS = " << context_switch << CLOSE << " | ";
            time += context_switch;
            cout << time << " | ";
        }
    }
    cout << '\n';
    return {time, v};
}

// Round Robin
pair<int, vector<PCB>> round_robin(int quantum, vector<PCB> v, int context_switch = 0)
{
    int time = 0;
    cout << "0 | ";
    deque<PCB> remain_processes(begin(v), end(v)); // Give the processes to the deque
    int last_process_id = -1;
    sort_on_RR(remain_processes, time);
    while (!remain_processes.empty())
    {
        PCB current_process = remain_processes.front();
        remain_processes.pop_front();
        last_process_id = current_process.id;
        if (quantum >= current_process.remaining_burst)
        {
            time += current_process.remaining_burst;
            cout << UNDERLINE << "P" << current_process.id << CLOSE << " | " << time << " | ";
            handle_processing_in_RR(time, current_process, v, true, quantum);
        }
        else
        {
            time += quantum;
            cout << UNDERLINE << "P" << current_process.id << CLOSE << " | " << time << " | ";
            PCB new_process = handle_processing_in_RR(time, current_process, v, false, quantum);
            remain_processes.emplace_front(new_process);
        }
        sort_on_RR(remain_processes, time);

        if (context_switch != 0 && remain_processes[0].id != last_process_id)
        {
            cout << UNDERLINE << "CS = " << context_switch << CLOSE << " | ";
            time += context_switch;
            cout << time << " | ";
        }
    }
    cout << '\n';
    return {time, v};
}
