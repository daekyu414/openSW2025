#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

pid_t getpid(void);

int main()
{
    pid_t my_pid;

    my_pid = getpid();
    
    printf("My pid is %lu\n", (unsigned long)my_pid);

    return 0;
}