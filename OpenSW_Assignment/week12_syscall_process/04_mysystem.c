#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int mysystem(const char *command)
{
    pid_t child_pid;

    child_pid = fork();

    if(child_pid == 0)
    {
        execl("/bin/sh", "sh", "-c", command, NULL);

        exit(1);
    }
    else
    {
        int wstatus;

        waitpid(child_pid, &wstatus, 0);

        if(WIFEXITED(wstatus) == 1)
        {
            return WEXITSTATUS(wstatus);
        }
        else
        {
            return -1;
        }
    }
}

int main()
{
    mysystem("ls -l | wc -l");
    mysystem("find . -name '*.c'");

    printf("Good Bye~\n");

    return 0;
}