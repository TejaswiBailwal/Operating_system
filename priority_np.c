#include <stdio.h>
#include <stdlib.h>
typedef struct process {
    int pid, at, bt, p;
    int ct, tat, wt, rt;
    int completed;
} process;
int main() 
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    process arr[n];
    int completed = 0;
    printf("Enter arrival time, burst time and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        arr[i].pid = i + 1;
        arr[i].completed = 0;
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &arr[i].at, &arr[i].bt, &arr[i].p);
    }
    int time = 0;
    int gantt[1000], g_index = 0;
    while (completed != n) 
    {
        int index = -1;
        int cur_pr = 99999;
        for (int i = 0; i < n; i++) {
            if (arr[i].at <= time && arr[i].completed != 1) {
                if (arr[i].p < cur_pr) {
                    index = i;
                    cur_pr = arr[i].p;
                } 
	else if (arr[i].p == cur_pr) {
                    if (arr[i].at < arr[index].at) {
                        index = i;
                        cur_pr = arr[i].p;
                    } 
	}  
          }  
       }
        if (index != -1) {
            arr[index].rt = time - arr[index].at;
            gantt[g_index++] = arr[index].pid;
            time += arr[index].bt;
            arr[index].ct = time;
            arr[index].tat = arr[index].ct - arr[index].at;
            arr[index].wt = arr[index].tat - arr[index].bt;
            arr[index].completed = 1;
            completed++;
        } 
else {
            time++;
        } 
 }
    float avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < n; i++) {
        avg_tat += arr[i].tat;
        avg_wt += arr[i].wt;
    }
    printf("\nGantt chart: ");
    for (int i = 0; i < g_index; i++) {
        printf("P%d ", gantt[i]);
    }
    printf("\n");
    printf("Average waiting time: %.2f\n", avg_wt / n);
    printf("Average turnaround time: %.2f\n", avg_tat / n);
    return 0;
}
