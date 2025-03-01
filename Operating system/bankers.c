#include <stdio.h>

int main() {
    int total_resources = 28;
    int num_processes = 5;
    int allocated[] = {5, 10, 1, 4, 5};
    int maximum[] = {10, 20, 3, 8, 12};
    int need[5];
    int available;
    int finished[5] = {0};
    int safe_sequence[5];
    int count = 0;

    printf("Calculating the Need for each process:\n");
    printf("Process\tAllocated\tMaximum\t\tNeed\n");
    for (int i = 0; i < num_processes; i++) {
        need[i] = maximum[i] - allocated[i];
        printf("\tP%d\t\t%d\t\t%d\t\t\t%d\n", i + 1, allocated[i], maximum[i], need[i]);
    }

    int sum_allocated = 0;
    for (int i = 0; i < num_processes; i++) {
        sum_allocated += allocated[i];
    }
    available = total_resources - sum_allocated;
    printf("\nTotal Available Resources: %d\n", available);

    printf("\nFinding the Safe Sequence:\n");
    while (count < num_processes) {
        int found = 0;
        for (int i = 0; i < num_processes; i++) {
            if (!finished[i] && need[i] <= available) {
                printf("Process P%d can be executed (Need: %d, Available: %d).\n", i + 1, need[i], available);
                safe_sequence[count++] = i;
                available += allocated[i];
                printf("Process P%d finished. New Available Resources: %d\n", i + 1, available);
                finished[i] = 1;
                found = 1;
            }
        }
        if (!found) {
            printf("System is in an unsafe state. Deadlock may occur.\n");
            return 0;
        }
    }

    printf("\nSystem is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d ", safe_sequence[i] + 1);
    }
    printf("\n");

    return 0;
}
//OUTPUT
//Calculating the Need for each process:
//Process	Allocated	Maximum		Need
//	P1		5		10			5
//	P2		10		20			10
//	P3		1		3			2
//	P4		4		8			4
//	P5		5		12			7

//Total Available Resources: 3

//Finding the Safe Sequence:
//Process P3 can be executed (Need: 2, Available: 3).
//Process P3 finished. New Available Resources: 4
//Process P4 can be executed (Need: 4, Available: 4).
//Process P4 finished. New Available Resources: 8
//Process P5 can be executed (Need: 7, Available: 8).
//Process P5 finished. New Available Resources: 13
//Process P1 can be executed (Need: 5, Available: 13).
//Process P1 finished. New Available Resources: 18
//Process P2 can be executed (Need: 10, Available: 18).
//Process P2 finished. New Available Resources: 28

//System is in a safe state.
//Safe sequence is: P3 P4 P5 P1 P2 