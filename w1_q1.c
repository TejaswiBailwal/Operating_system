#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x=fork();//creating a child process
    if(x<0)
    {
        printf("Failed to create a child process\n");
        return 0;
    }
    else if(x==0)
    {
        //Child process is executing
        printf("Child Process is executing\n");
    }
    else
    {
        //Parent process is executing
        printf("Parent process is executing\n");
    }
    return 0;
}