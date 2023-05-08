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

    // FCFS algorithm
    cout << "FCFS ----------------------------------\n";
    cout << "Gantt Chart => ";
    pair<int, vector<PCB>> result = first_come_first_serve(v);
    print(result.second);                                               // Print the required fields from the PCB
    print_statistics(result.second, result.first, NUMBER_OF_PROCESSES); // Print the statistics
    cout << "---------------------------------------\n";

    // SJF algorithm
    cout << "SJF -----------------------------------\n";
    cout << "Gantt Chart => ";
    result = shortest_job_first(v);
    print(result.second);                                               // Print the required fields from the PCB
    print_statistics(result.second, result.first, NUMBER_OF_PROCESSES); // Print the statistics
    cout << "---------------------------------------\n";
    return 0;
}