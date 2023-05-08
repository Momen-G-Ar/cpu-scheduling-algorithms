#pragma once

using namespace std;

// This file is the place to build the Process control Block (PCB)
class PCB
{
public:
    // The Attributes of the PCB class

    // The id of the process 
    int id;

    // The time that the process enter the ready queue for the first time
    int arrival_time;


    int cpu_burst;


    int size_in_bytes;


    int finish_time;


    int waiting_time;


    int turn_around_time;


    int last_time_in_ready;


    int remaining_burst;
    

    int response_time;

    // The methods of the PCB class
    PCB(int id, int arrival_time, int cpu_burst, int size_in_bytes) // Constructor
    {
        this->id = id;
        this->arrival_time = arrival_time;
        this->cpu_burst = cpu_burst;
        this->remaining_burst = cpu_burst;
        this->size_in_bytes = size_in_bytes;
        this->last_time_in_ready = arrival_time;
        this->finish_time = 0;
        this->waiting_time = 0;
        this->turn_around_time = 0;
        this->response_time = -1;
    }
};
