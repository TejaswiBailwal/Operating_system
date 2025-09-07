//not complete
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

typedef struct process
{
    int id,at,bt,ct,tat,wt,st,rt;
    int time_left;
}process;

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    struct process p[n];
    for (int i = 0; i < n; i++) 
    {
        p[i].id = i + 1;
    }
    printf("Enter the arrival time: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i].at);
    }
    printf("Enter the burst time: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i].bt);
        p[i].time_left=p[i].bt;
    }
    bool is_completed[100]={false},is_first_process=true;
    int current_time=0;
    int completed=0;
    int max_completion_time,min_arrival_time;
    int total_tat=0,total_wt=0,total_rt=0;
    while(completed!=n)
    {
        int index=-1;
        int value=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(p[i].at<=current_time && is_completed[i]==false)
            {
                if(p[i].time_left>value)
                {
                    value=p[i].time_left;
                    index=i;
                }
                if(p[i].time_left==value)
                {
                    if(p[i].at>p[index].at)
                    {
                        if(p[i].at>p[index].at)
                        {
                            value=p[i].time_left;
                            index=i;
                        }
                    }
                }
            }
        }
        if(index==-1)
        {
            current_time++;// when cpu is idle no process is taking place
        }
        else
        {
            if(p[index].time_left==p[index].bt)
            {
                p[index].rt=current_time-p[index].at;
            }
            
            p[index].time_left--;
            current_time++;
                
            if(p[index].time_left==0)
            {
                p[index].ct=current_time;
                p[index].tat=p[index].ct-p[index].at;
                p[index].wt=p[index].tat-p[index].bt;
                completed++;
                is_completed[index]=true;
                is_first_process=false;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        total_tat+=p[i].tat;
        total_wt+=p[i].wt;
        total_rt+=p[i].rt;
    }
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) \
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }
    printf("Total turnaround time: %d\n", total_tat);
    printf("Total waiting time: %d\n", total_wt);
    printf("Average turnaround time: %.2f\n", (float)total_tat/n);
    printf("Average waiting time: %.2f\n", (float)total_wt/n);
    int totalbt = 0;
    for (int i = 0; i < n; i++) 
    {
        totalbt += p[i].bt;
    }
    printf("Total CPU utilization = %d%%\n", (totalbt * 100) / p[n - 1].ct);
    printf("Total throughput = %d%%\n", (n * 100) / p[n - 1].ct);
}