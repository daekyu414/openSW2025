#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void sigint_handler(int sig)
{
    printf("[SIGINT handler] -------------\n");
    
    pid_t child_pid = fork();

    if(child_pid == 0)
    {
        char* argv[] = {"ls", NULL};
        execve("/usr/bin/ls", argv, NULL);
        // 실패 시 아래 코드 실행
        exit(1);
    }
    else
    {
        int wstatus;
        
        waitpid(child_pid, &wstatus, 0);
    }
}

void sigquit_handler(int sig)
{
    printf("[SIGQUIT handler] ------------\n");
    
    pid_t child_pid = fork();

    if(child_pid == 0)
    {
        char* argv[] = {"date", NULL};

        execve("/usr/bin/date", argv, NULL);
        // 실패 시 아래 코드 실행
        exit(1);
    }
    else
    {
        int wstatus;

        waitpid(child_pid, &wstatus, 0);
    }
}

void sigalrm_handler(int sig)
{
    printf("[SIGALRM handler] ------------\n");
    
    pid_t child_pid = fork();

    if(child_pid == 0)
    {
        char* argv[] = {"whoami", NULL};

        execve("/usr/bin/whoami", argv, NULL);
        // 실패 시 아래 코드 실행
        exit(1);
    }
    else
    {
        int wstatus;

        waitpid(child_pid, &wstatus, 0);

        alarm(3);
    }
}

int main()
{
    struct sigaction sa_alrm;
    struct sigaction sa_int;
    struct sigaction sa_quit;

    sa_alrm.sa_handler = sigalrm_handler;
    sigemptyset(&sa_alrm.sa_mask);
    sa_alrm.sa_flags = 0;
    sigaction(SIGALRM, &sa_alrm, NULL);

    sa_int.sa_handler = sigint_handler;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;
    sigaction(SIGINT, &sa_int, NULL);

    sa_quit.sa_handler = sigquit_handler;
    sigemptyset(&sa_quit.sa_mask);
    sa_quit.sa_flags = 0;
    sigaction(SIGQUIT, &sa_quit, NULL);

    alarm(3);

    while(1)
    {
        sleep(1);
    }

    return 0;
}