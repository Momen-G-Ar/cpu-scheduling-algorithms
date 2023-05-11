#include <iostream>
#include <iomanip>

#include "PCB.h"
#include "Helpers.h"
#include "Algorithms.h"

using namespace std;

/*
    Name : Momin Ghazi Arafa
    Number : 201016
*/

#define NUMBER_OF_PROCESSES 5         // The number of processes
#define INPUT_FILE_PATH "process.txt" // The input file path

int memory_size, page_size, quantum, context_switch; // The input variables
vector<PCB> v;                                       // Data structure to store the information of the processes

int main()
{
    cout << fixed << setprecision(2);                                                                     // To set 2 decimal points
    read_input(memory_size, page_size, quantum, context_switch, v, NUMBER_OF_PROCESSES, INPUT_FILE_PATH); // Read the input from the file
    // FCFS algorithm
    cout << UNDERLINE << RED << "\nFirst Come First Serve" << CLOSE << " <------------------------------------>\n\n";
    cout << "Gantt Chart => ";
    pair<int, vector<PCB>> result = first_come_first_serve(v, context_switch); // Define a variable to take the result of each algorithm
    cout << '\n';
    print(result.second);                                               // Print the required fields from the PCB
    print_statistics(result.second, result.first, NUMBER_OF_PROCESSES); // Print the statistics
    cout << "-------------------------------------------\n";

    // SJF algorithm
    cout << UNDERLINE << RED << "\nShortest Job First" << CLOSE << " <------------------------------------>\n\n";
    cout << "Gantt Chart => ";
    result = shortest_job_first(v, context_switch);
    cout << '\n';
    print(result.second);                                               // Print the required fields from the PCB
    print_statistics(result.second, result.first, NUMBER_OF_PROCESSES); // Print the statistics
    cout << "-------------------------------------------\n";

    // RR algorithm
    cout << UNDERLINE << RED << "\nRound Robin" << CLOSE << " <------------------------------------>\n\n";
    cout << "Gantt Chart => ";
    result = round_robin(quantum, v, context_switch);
    cout << '\n';
    print(result.second);                                               // Print the required fields from the PCB
    print_statistics(result.second, result.first, NUMBER_OF_PROCESSES); // Print the statistics
    cout << "-------------------------------------------\n";
    return 0;
}