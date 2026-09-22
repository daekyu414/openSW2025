#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sigint_handler(int sig)
{
    printf("Ouch! I got SIGINT\n");
}

int main()
{
    struct sigaction sa_int;

    sa_int.sa_handler = sigint_handler;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;

    sigaction(SIGINT, &sa_int, NULL);
    
    for(;;)
    {
        printf("pid: %lu\n", (unsigned long)getpid());
        sleep(1);
    }

    return 0;
}