#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("pid: %u\n", getpid());

    return 0;
}