#include <iostream>
#include <cstring>
#include <cstdlib>
#define MAX_SIZE 1001

using namespace std;

struct setting
{
    int arrivalTime[MAX_SIZE];
    int workTime[MAX_SIZE];
    int priority[MAX_SIZE] = { 0 };
};

void sjf_select();
void sjf_input(struct setting s, int size);

void fcfs_select();
void fcfs_input(struct setting s, int size);

struct setting process_sort(struct setting s, int size);

void gant_list_sort(struct setting s, int size , int gantt[][MAX_SIZE], int total, char* kind);