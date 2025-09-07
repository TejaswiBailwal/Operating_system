#include <stdio.h>
#include <stdbool.h>
typedef struct 
{
    int A, B, C;
} Resource;
int canFulfill(Resource need, Resource avail) {
    return (need.A <= avail.A && need.B <= avail.B && need.C <= avail.C);
}
Resource add(Resource a, Resource b) {
    Resource res = {a.A + b.A, a.B + b.B, a.C + b.C};
    return res;
}
Resource subtract(Resource a, Resource b) {
    Resource res = {a.A - b.A, a.B - b.B, a.C - b.C};
    return res;
}
int main() 
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int maxA, maxB, maxC;
    printf("Enter total resources A, B, C: ");
    scanf("%d %d %d", &maxA, &maxB, &maxC);
    Resource allocated[n], maxNeed[n], remaining[n];
    int tempA = 0, tempB = 0, tempC = 0;
    printf("Enter allocated matrix:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &allocated[i].A, &allocated[i].B, &allocated[i].C);
        tempA += allocated[i].A;
        tempB += allocated[i].B;
        tempC += allocated[i].C;
    }
    Resource available = {maxA - tempA, maxB - tempB, maxC - tempC};
    printf("Enter max need matrix:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d %d %d", &maxNeed[i].A, &maxNeed[i].B, &maxNeed[i].C);
        remaining[i] = subtract(maxNeed[i], allocated[i]);
    }
    bool completed[n];
    for (int i = 0; i < n; i++) completed[i] = false;
    int sequence[n], seqSize = 0;
    while (seqSize < n) 
    {
        int found = 0;
        for (int i = 0; i < n; i++) 
        {
            if (!completed[i] && canFulfill(remaining[i], available)) 
            {
                available = add(available, allocated[i]);
                completed[i] = true;
                sequence[seqSize++] = i;
                found = 1;
            }
        }
        
if (!found) break;
    }
    if (seqSize == n) {
        printf("Request can be fulfilled\nSafe sequence: ");
        for (int i = 0; i < n; i++) {
            printf("P%d ", sequence[i]);
        }
        printf("\n");
    }
    else {
        printf("Request cannot be fulfilled\n");
    }
    return 0;
}
