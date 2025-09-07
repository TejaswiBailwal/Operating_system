#include <stdio.h>
#include <stdbool.h>
struct Resource 
{
    int A, B, C;
};
struct Resource add(struct Resource a, struct Resource b) {
    struct Resource r = {a.A + b.A, a.B + b.B, a.C + b.C};
    return r;
}
struct Resource subtract(struct Resource a, struct Resource b) {
    struct Resource r = {a.A - b.A, a.B - b.B, a.C - b.C};
    return r;
}
bool canFulfill(struct Resource need, struct Resource avail) {
    return (need.A <= avail.A && need.B <= avail.B && need.C <= avail.C);
}
int main() 
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int maxA, maxB, maxC;
    printf("Enter total resources A, B, C: ");
    scanf("%d %d %d", &maxA, &maxB, &maxC);
    struct Resource allocated[n], maxNeed[n], remaining[n];
    int tempA = 0, tempB = 0, tempC = 0;
    printf("Enter allocated matrix (A B C for each process):\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d %d %d", &allocated[i].A, &allocated[i].B, &allocated[i].C);
        tempA += allocated[i].A;
        tempB += allocated[i].B;
        tempC += allocated[i].C;
    }
    struct Resource available = {maxA - tempA, maxB - tempB, maxC - tempC};
    printf("Enter max need matrix (A B C for each process):\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d %d %d", &maxNeed[i].A, &maxNeed[i].B, &maxNeed[i].C);
        remaining[i] = subtract(maxNeed[i], allocated[i]);
    }
    bool completed[n];
    for (int i = 0; i < n; i++) completed[i] = false;
    int sequence[n], count = 0, progress;
    while (count < n) 
    {
        progress = 0;
        for (int i = 0; i < n; i++) 
        {
            if (!completed[i] && canFulfill(remaining[i], available)) {
                available = add(available, allocated[i]);
                completed[i] = true;
                sequence[count++] = i;
                progress = 1;
            }
        }
        if (!progress) break;
    }
    if (count == n) {
        printf("Request can be fulfilled\nSafe sequence: ");
        for (int i = 0; i < n; i++) {
            printf("P%d ", sequence[i]);
        }
        printf("\nNo deadlock detected\n");
    } 
    else 
    {
        printf("Deadlock detected\n");
    }
    return 0;
}
