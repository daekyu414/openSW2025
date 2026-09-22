#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t child_pid;

    child_pid = fork();
    if(child_pid == 0)      // child pid
    {
        for(int i = 0; i < 100; i++)
        {
            printf("%d\n", i);
        }
    }
    else        // parent pid
    {
        int wstatus;
        
        for(int i = 100; i < 200; i++)
        {
            printf("%d\n", i);
        }

        waitpid(child_pid, &wstatus, 0);
    }

    return 0;
}