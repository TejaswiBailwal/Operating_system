//Calculate sum of even number sum in parent process and odd number sum in child process. even number sum should print before odd number sum
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    int n;
    printf("Enter number of elements of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int x=fork();
    if(x<0)
    {
        printf("Process failed\n");
        return 0;
    }
    else if(x>0)
    {
        printf("Parent process is executing\n");
        int sum=0;
        for(int i=0;i<n;i+=2)
        {
            sum=sum+arr[i];
        }
        printf("Sum of even numbers: %d\n",sum);
        exit(0);
    }
    else
    {
        wait(NULL);
        printf("Child process is executing\n");
        int sum=0;
        for(int i=1;i<n;i+=2)
        {
            sum=sum+arr[i];
        }
        printf("Sum of odd numbers: %d\n",sum);
    }
    return 0;
}