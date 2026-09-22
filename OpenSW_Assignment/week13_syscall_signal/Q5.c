#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

struct two_double
{
    double a;
    double b;
}data;

void sigalrm_handler(int sig)
{
    printf("%.2f, %.2f\n", data.a, data.b);
    alarm(1);
}

int main()
{
    struct sigaction sa_alrm;
    struct two_double zeros = {0.0, 0.0}, ones = {1.0, 1.0};

    sa_alrm.sa_handler = sigalrm_handler;
    sigemptyset(&sa_alrm.sa_mask);
    sa_alrm.sa_flags = 0;
    sigaction(SIGALRM, &sa_alrm, NULL);

    sigset_t block_mask;
    sigemptyset(&block_mask);
    sigaddset(&block_mask, SIGALRM);

    alarm(1);

    while(1)
    {
        sigprocmask(SIG_BLOCK, &block_mask, NULL);
        data = zeros;
        sigprocmask(SIG_UNBLOCK, &block_mask, NULL);

        sigprocmask(SIG_BLOCK, &block_mask, NULL);
        data = ones;
        sigprocmask(SIG_UNBLOCK, &block_mask, NULL);
    }

    return 0;
}