#include<stdio.h>

int main()
{
    int memory_partitions[] = {200,400,600,500,300,250};
    int processes[] = {357,210,468,491};
    int n = sizeof(processes)/sizeof(processes[0]);
    int m = sizeof(memory_partitions)/sizeof(memory_partitions[0]);
    int allocation[n];
    int internal_fragmentation = 0;

    for(int i = 0; i < n; i++) {
        allocation[i] = -1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(memory_partitions[j] >= processes[i]) {
            allocation[i] = j;
            internal_fragmentation += (memory_partitions[j]-processes[i]);
            memory_partitions[j] -= processes[i];
            break;
            }
        }
    }
    int external_fragmentation = 0;
    for(int i = 0; i < n; i++) {
        if(allocation[i] == -1) {
            external_fragmentation += processes[i];
        }
    }
    printf("Process Allocation:\n");
    printf("process\t|\tsize\t|\tpartition\n\n");
    for(int i = 0; i < n; i++) {
        if(allocation[i] != -1){
            printf("\tP%d\t|\t%d\t\t|\tBlock %d\n",i + 1,processes[i], allocation[i] + 1);
        }
        else{
            printf("\tP%d\t|\t%d\t\t|\tNot Allocated\n", i + 1, processes[i]);
        }     
    }
    printf("\nTotal internal fragementation = %d KB", internal_fragmentation);
    printf("\ntotal external fragementation = %d KB", external_fragmentation);

    return 0;
}
//OUTPUT
//Process Allocation:
//process	|	size	|	partition

//	P1	|	357		|	Block 2
//	P2	|	210		|	Block 3
//	P3	|	468		|	Block 4
//	P4	|	491		|	Not Allocated

//Total internal fragementation = 465 KB
//Total external fragementation = 491 KB

