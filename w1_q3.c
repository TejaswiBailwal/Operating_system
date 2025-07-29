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
                printf("First Child process\n");
                exit(0);
        }
        else
        {
                wait(NULL);//waiting for first child to complete
                printf("Parent process. First child has completed its work.\n");
                int y=fork();//creating the second child process
                if(y<0)
                {
                        printf("Process failed\n");
                        return 0;
                }
                if(x==0)
                {
                        //Second child process executing
                        printf("Second child process\n");
                        sleep(5);
                        printf("Second child process work done\n");
                        exit(0);
                }
                else
                {
                        printf("Parent process done executing\n");
                        exit(0);
                }
        }
        return 0;
}