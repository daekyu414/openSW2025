#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

struct two_double
{
    double a;
    double b;
}data;

void sigquit_handler(int sig)
{
    printf("Good bye QUIT\n");
    exit(0);
}

void sigint_handler(int sig)
{
    printf("Ouch! I got SIGINT\n");
}

void sigalarm_handler(int sig)
{
    printf("%f, %f\n", data.a, data.b);
    alarm(1);
}

int main()
{
    struct sigaction sa_int;
    struct sigaction sa_quit;
    struct sigaction sa_alarm;
    struct two_double zeros = {0.0, 0.0}, ones={1.0, 1.0};

    sa_int.sa_handler = sigint_handler;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;

    sa_quit.sa_handler = sigquit_handler;
    sigemptyset(&sa_quit.sa_mask);
    sa_quit.sa_flags = 0;

    sa_alarm.sa_handler = sigalarm_handler;
    sigemptyset(&sa_alarm.sa_mask);
    sa_alarm.sa_flags = 0;


    sigaction(SIGINT, &sa_int, NULL);
    sigaction(SIGQUIT, &sa_quit, NULL);
    sigaction(SIGALRM, &sa_alarm, NULL);

    alarm(1);
    
    for(;;)
    {
        // printf("pid: %lu\n", (unsigned long)getpid());
        // sleep(1);

        // block SIGALRM signal
        data = ones;
        // unblock SIGALRM signal

        // block SIGALRM signal
        data = zeros;
        // unblock SIGALRM signal
    }

    return 0;
}