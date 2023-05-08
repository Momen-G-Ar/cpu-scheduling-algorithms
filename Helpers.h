#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <deque>
#include "PCB.h"

using namespace std;

// This file is the place of the helper functions

// To print the PCB information
void print(vector<PCB> &v)
{
    for (PCB val : v) // For each for loop to print the PCB information
    {
        cout << "ID = " << val.id << '\n'
             << "Finish Time = " << val.finish_time << '\n'
             << "Waiting Time = " << val.waiting_time << '\n'
             << "Turnaround Time = " << val.turn_around_time << '\n'
             << '\n';
    }
}

void print2(vector<PCB> &v)
{
    for (PCB val : v) // For each for loop to print the PCB information
    {
        cout << "ID = " << val.id << '\n'
             << "Arrival Time = " << val.arrival_time << '\n'
             << "CPU burst = " << val.cpu_burst << '\n'
             << "Size in Bytes = " << val.size_in_bytes << '\n'
             << "Last Time in Ready = " << val.last_time_in_ready << '\n'
             << "Turnaround Time = " << val.turn_around_time << '\n'
             << "Waiting Time = " << val.waiting_time << '\n'
             << "Finish Time = " << val.finish_time << '\n'
             << '\n';
    }
}

// To Read the input from the file
void read_input(int &memory_size, int &page_size, int &quantum, int &context_switch, vector<PCB> &v, int NUMBER_OF_PROCESSES, const string file_name)
{
    ifstream in;        // To read from file stream
    in.open(file_name); // Initialize the file stream from the needed file
    // Read operation
    in >> memory_size >> page_size >> quantum >> context_switch;
    for (int i = 0; i < NUMBER_OF_PROCESSES; ++i)
    {
        int process_id, arrival_time, cpu_burst, size_in_bytes;
        in >> process_id >> arrival_time >> cpu_burst >> size_in_bytes;
        v.emplace_back(PCB(process_id, arrival_time, cpu_burst, size_in_bytes));
    }
    in.close(); // Close the file stream
}

// Sort depends on arrival time
void sort_on_arrival_time_then_id(vector<PCB> &v)
{
    sort(begin(v), end(v),
         [v](PCB a, PCB b) // Comparator function
         {
             if (a.arrival_time != b.arrival_time)
                 return (a.arrival_time < b.arrival_time);
             else
                 return (a.id <= b.id);
         });
}

void sort_on_SJF(deque<PCB> &d, int time)
{
    sort(begin(d), end(d),
         [time](PCB a, PCB b)
         {
             if (a.arrival_time <= time && b.arrival_time <= time)
                 return a.cpu_burst <= b.cpu_burst;
             else if (a.arrival_time <= time)
                 return true;
             else if (b.arrival_time <= time)
                 return false;
             else
                 return a.arrival_time <= b.arrival_time;
         });
}

// Print the statistics of the PCB
void print_statistics(vector<PCB> &v, int end_of_all_processes_time, int number_of_processes)
{
    double average_waiting_time = 0;
    double average_turnaround_time = 0;
    double cpu_utilization = v.size();
    double throughput = 0;
    double execution_time = 0;

    for (PCB process : v)
    {
        average_turnaround_time += process.turn_around_time;
        average_waiting_time += process.waiting_time;
        execution_time += process.cpu_burst;
    }
    throughput = number_of_processes * 1.0 / end_of_all_processes_time;
    cpu_utilization = 1.0 * execution_time / end_of_all_processes_time;

    cout << "Average Waiting Time = " << average_waiting_time << '\n'
         << "Average Turnaround Time = " << average_turnaround_time << '\n'
         << "CPU Utilization = " << cpu_utilization << '\n'
         << "Throughput = " << throughput << '\n';
}

// To handle the processing of burst time in the FCFS
void handle_processing_in_FCFS(int time, PCB &p)
{
    p.finish_time = time;
    p.turn_around_time = p.finish_time - p.arrival_time;
    p.waiting_time += (time - p.last_time_in_ready - p.remaining_burst);
    p.last_time_in_ready = time - p.remaining_burst;
    p.remaining_burst = 0;
    if (p.response_time == -1)
        p.response_time = p.last_time_in_ready - p.arrival_time;
}

// To handle the processing of burst time in the SJF
void handle_processing_in_SJF(int time, PCB &p, vector<PCB> &v)
{
    int id = p.id, index = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (id == v[i].id)
        {
            index = i;
            break;
        }
    }
    v[index].finish_time = time;
    v[index].turn_around_time = v[index].finish_time - v[index].arrival_time;
    v[index].waiting_time += (time - v[index].last_time_in_ready - v[index].remaining_burst);
    v[index].last_time_in_ready = time - v[index].remaining_burst;
    v[index].remaining_burst = 0;
    if (v[index].response_time == -1)
        v[index].response_time = v[index].last_time_in_ready - v[index].arrival_time;
}
