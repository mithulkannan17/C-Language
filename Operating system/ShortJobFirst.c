#include <stdio.h>

void calculateTime(int processes[], int n, int burst_time[])
{
    int wt[n], tat[n], total = 0;
    int temp;

    // Sorting processes by burst time (Shortest Job First)
    for (int i = 0; i < n; i++){
        int pos = i;
        for (int j = i + 1; j < n; j++) {
            if (burst_time[j] < burst_time[pos])
                pos = j;
        }
        temp = processes[i];
        processes[i] = processes[pos];
        processes[pos] = temp;

        temp = burst_time[i];
        burst_time[i] = burst_time[pos];
        burst_time[pos] = temp;
    }

    // Calculate waiting time for each process
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = 0;
        for (int j = 0; j < i; j++) {
            wt[i] += burst_time[j];
        }
        total += wt[i];
    }

    // Print process details
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    float avg_wt = (float)total / n;
    float avg_tat = 0;

    for (int i = 0; i < n; i++) {
        tat[i] = burst_time[i] + wt[i];
        avg_tat += tat[i];
        printf("%d\t\t\t%d\t\t\t%d\t\t\t\t%d\n", processes[i], burst_time[i], wt[i], tat[i]);
    }

    avg_tat /= n;
    printf("\nAverage Waiting Time = %.2f\n", avg_wt);
    printf("Average Turnaround Time = %.2f\n", avg_tat);
}

int main()
{
    int processes[] = {1, 2, 3, 4, 5};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {4, 3, 7, 1, 2};
    calculateTime(processes, n, burst_time);
    return 0;
}
// OUTPUT
// Process	Burst Time	Waiting Time	Turnaround Time
//4			1			0				1
//5			2			1				3
//2			3			3				6
//1			4			6				10
//3			7			10				17

//Average Waiting Time = 4.00
//Average Turnaround Time = 7.40
