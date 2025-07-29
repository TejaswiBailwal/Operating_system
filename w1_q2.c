#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork(); //creating a child process

    if (pid < 0) 
    {
        printf("Process failed\n");
        return 1;
    } 
    else if (pid == 0) 
    {
        // Child process is executing
        printf("Child Process:\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID (from child): %d\n", getppid());
    } 
    else 
    {
        // Parent process is executing
        printf("Parent Process:\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID (from parent): %d\n", pid);
    }
    return 0;
}
