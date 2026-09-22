#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t child_pid;

    child_pid = fork();
    if(child_pid == 0) // child process
    {
        execl("/usr/bin/ls", "ls", "-l", NULL);
        printf("child terminated\n");
    }
    else               // parent process
    {
        int wstatus;
        waitpid(child_pid, &wstatus, 0);
        if(WIFEXITED(wstatus) == 1)
        {
            printf("Child process %lu exited with code %d\n", (unsigned long)child_pid, WEXITSTATUS(wstatus));
        }
    }
    
    printf("Hello world\n");

    return 0;
}