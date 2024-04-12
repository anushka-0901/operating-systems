#include <stdio.h>

int main() {
    int arrival_time[10], burst_time[10], temp[10];
    int i, smallest, count = 0, time, limit;
    double wait_time = 0, turnaround_time = 0, end;
    float average_waiting_time, average_turnaround_time;

    printf("\n Enter the total number of processes: ");
    scanf("%d", &limit);

    printf("\n Enter details of %d processes", limit);
    for(i = 0; i < limit; i++) {
        printf("\n Enter arrival time for process %d: ", i+1);
        scanf("%d", &arrival_time[i]);
        printf(" Enter burst time for process %d: ", i+1);
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i];
    }

    printf("\n *******SHORTEST JOB FIRST WITH PRE-EMPTION*******\n");
    printf("\n Process\tTurn Around Time\tWaiting Time\n" );

    burst_time[9] = 9999;
    for(time = 0; count != limit; time++) {
        smallest = 9;
        for(i = 0; i < limit; i++) {
            if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0) {
                smallest = i;
            }
        }
        burst_time[smallest]--;
        if(burst_time[smallest] == 0) {
            count++;
            end = time + 1;

            printf("\n P[%d]\t|\t %lf\t|\t %lf", smallest+1, end-arrival_time[smallest], end-arrival_time[smallest]-temp[smallest]);
            wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
            turnaround_time = turnaround_time + end - arrival_time[smallest];
        }
    }

    printf("\n");
    average_waiting_time = wait_time / limit;
    average_turnaround_time = turnaround_time / limit;

    printf("\n Average Waiting Time= %lf\n", average_waiting_time);
    printf("\n Average Turnaround Time= %lf\n", average_turnaround_time);

    return 0;
}
