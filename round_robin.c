#include <stdio.h>
typedef struct {
    int id, arrival, burst;
    int completion, turnaround, waiting, response;
    int remaining;
    int done;
} Process;
int main() {
    int n, quantum = 2;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    Process p[n];
    int finished = 0;
    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        p[i].done = 0;
        scanf("%d %d", &p[i].arrival, &p[i].burst);
        p[i].remaining = p[i].burst;
        p[i].response = -1;
    }

    int time = 0;
    int order[1000], k = 0;
    int all_done = 0;
    while (finished != n) {
        all_done = 1;
        for (int i = 0; i < n; i++) 
        {
            if (p[i].arrival <= time && p[i].done == 0) {
                all_done = 0;
                if (p[i].response == -1) {
                    p[i].response = time - p[i].arrival;
                }
                int run = (p[i].remaining > quantum) ? quantum : p[i].remaining;
                for (int j = 0; j < run; j++) {
                    order[k++] = p[i].id;
                }
                p[i].remaining -= run;
                time += run;
                if (p[i].remaining == 0) {
                    p[i].completion = time;
                    p[i].turnaround = p[i].completion - p[i].arrival;
                    p[i].waiting = p[i].turnaround - p[i].burst;
                    p[i].done = 1;
                    finished++;
                }
            } 
            else if (p[i].arrival > time && !p[i].done) {
                all_done = 0;
            }
        }
        if (all_done) break;
    }
    float avg_tat = 0, avg_wt = 0;
    

   for (int i = 0; i < n; i++) 
   {
        avg_tat += p[i].turnaround;
        avg_wt += p[i].waiting;
    }
    printf("\nGantt chart: ");
    for (int i = 0; i < k; i++) 
   {
        printf("P%d ", order[i]);
    }
    printf("\n");
    printf("Average waiting time: %.2f\n", avg_wt / n);
    printf("Average turnaround time: %.2f\n", avg_tat / n);
    return 0;
}
