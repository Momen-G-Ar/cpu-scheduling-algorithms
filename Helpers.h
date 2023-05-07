#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "PCB.h"

using namespace std;

// This file is the place of the helper functions

// To print the PCB information
void print(vector<PCB> &v)
{
    for (PCB val : v) // For each for loop to print the PCB information
    {
        cout << val.id << " " << val.arrival_time << " "
             << val.cpu_burst << " " << val.size_in_bytes << '\n';
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
