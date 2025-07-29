#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
        int x=fork();//creating first child process of the parent
        if(x<0)
        {
                printf("Process failed\n");
                return 0;
        }
        else if(x==0)
        {
                //first child process working
                execlp("ls","ls","-l",(char*)NULL);
                exit(0);
        }
        else
        {
            wait(NULL);//waiting for first child to complete
            printf("Parent process. Child has done its work.\n");
        }
        return 0;
}