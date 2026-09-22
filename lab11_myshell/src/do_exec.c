#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include "do_exec.h"
#include <errno.h>

void do_exec(char* argv[])
{
    // implement file execution using fork/exeve
    pid_t child_pid = fork();

    if(child_pid == 0)
    {
        if(execve(argv[0], argv, NULL) == -1)
        {
            perror(argv[0]);
        }
        exit(1);
    }
    else
    {
        int wstatus;
        
        waitpid(child_pid, &wstatus, 0);
    }
}