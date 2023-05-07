#include <iostream>

#include "PCB.h"
#include "Helpers.h"

using namespace std;

#define NUMBER_OF_PROCESSES 5
#define INPUT_FILE_PATH "process.txt"
int memory_size, page_size, quantum, context_switch;
vector<PCB> v;

int main()
{
    read_input(memory_size, page_size, quantum, context_switch, v, NUMBER_OF_PROCESSES, INPUT_FILE_PATH);
    print(v);
    system("pause");
    return 0;
}