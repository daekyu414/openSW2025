#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("pid: %u\n", getpid());
    printf("ppid: %u\n", getppid());

    return 0;
}