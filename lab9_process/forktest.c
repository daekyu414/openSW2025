#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t child_pid;

    child_pid = fork();
    if(child_pid == 0) // child process
    {
        printf("Child pid: %lu, parent pid: %lu\n", (unsigned long)getpid(), (unsigned long)getppid());

        return 100;
    }
    else               // parent process
    {
        int wstatus;
        // for(;;)
        // {
        //                 // busy busy ...
        // }
        waitpid(child_pid, &wstatus, 0);
        if(WIFEXITED(wstatus) == 1)
        {
            printf("Child process %lu exited with code %d\n", (unsigned long)child_pid, WEXITSTATUS(wstatus));
        }
        printf("Parant pid: %lu, parent pid: %lu\n", (unsigned long)getpid(), (unsigned long)getppid());
    }
    
    printf("Hello world\n");

    return 0;
}