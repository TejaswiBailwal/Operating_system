#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

typedef struct process
{
    int id,at,bt,ct,st,tat,wt,rt;
}process;

int compare(const void *a, const void *b) 
{
    process *p1 = (process *)a;
    process *p2 = (process *)b;
    return p1->at - p2->at;
}

int main()
{
    printf("Enter the number of processes: ");
    int n;
    scanf("%d",&n);
    bool is_completed[100]={false},is_first_process=true;
    int current_time=0;
    int completed=0;
    int max_completion_time,min_arrival_time;
    struct process p[n];
    for (int i = 0; i < n; i++) 
    {
        p[i].id = i + 1;
    }
    printf("Enter their arrival time: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i].at);
    }
    printf("Enter their burst time: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i].bt);
    }
    int total_tat=0,total_wt=0,total_rt=0;
    int prev=0;
    while(completed!=n)
    {
        int index=-1;
        int value=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(p[i].at<=current_time && is_completed[i]==false)
            {
                if(p[i].bt<value)
                {
                    value=p[i].bt;
                    index=i;
                }
                if(p[i].bt==value)
                {
                    if(p[i].at<p[index].at)
                    {
                        if(p[i].at<p[index].at)
                        {
                            value=p[i].bt;
                            index=i;
                        }
                    }
                }
            }
        }
        if(index==-1)
            {
                current_time++;
            }
            else
            {
                p[index].st=current_time;
                p[index].ct=p[index].st+p[index].bt;
                p[index].tat=p[index].ct-p[index].at;
                p[index].wt=p[index].tat-p[index].bt;
                p[index].rt=p[index].at;

                total_tat+=p[index].tat;
                total_wt+=p[index].wt;
                total_rt+=p[index].rt;

                completed++;
                is_completed[index]=true;
                current_time=p[index].ct;
                prev=current_time;
                is_first_process=false;
            }
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
