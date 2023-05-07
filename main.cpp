#include <iostream>
#include <iomanip>
#include "PCB.h"
#include "Helpers.h"
#include "Algorithms.h"

using namespace std;

#define NUMBER_OF_PROCESSES 5
#define INPUT_FILE_PATH "process.txt"
int memory_size, page_size, quantum, context_switch;
vector<PCB> v;

int main()
{
    cout << fixed << setprecision(2);
    read_input(memory_size, page_size, quantum, context_switch, v, NUMBER_OF_PROCESSES, INPUT_FILE_PATH);

    sort_on_arrival_time_then_id(v);

    // Start from FCFS algorithm
    cout << "Gantt Chart => ";
    int end_of_all_processes_time = first_come_first_serve(v);
    print(v);                                                            // Print the required fields from the PCB
    print_statistics(v, end_of_all_processes_time, NUMBER_OF_PROCESSES); // Print the statistics

    return 0;
}