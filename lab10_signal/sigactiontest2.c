#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sigquit_handler(int sig)
{
    printf("Good bye QUIT\n");
    exit(0);
}

void sigint_handler(int sig)
{
    printf("Ouch! I got SIGINT\n");
}

int main()
{
    struct sigaction sa_int;
    struct sigaction sa_quit;

    sa_int.sa_handler = sigint_handler;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;

    sa_quit.sa_handler = sigquit_handler;
    sigemptyset(&sa_quit.sa_mask);
    sa_quit.sa_flags = 0;

    sigaction(SIGINT, &sa_int, NULL);
    sigaction(SIGQUIT, &sa_quit, NULL);
    
    for(;;)
    {
        printf("pid: %lu\n", (unsigned long)getpid());
        sleep(1);
    }

    return 0;
}