#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void hoo(int i)
{
    int j = 0;

    j = j + i;

    printf("Hello hoo, j = %d\n", j);
}

void goo()
{
    printf("Hello goo\n");
    hoo(1);
}

void foo()
{
    printf("Hello foo\n");
    goo();
}

int main()
{
    while(1)
    {
        foo();
        
        printf("pid: %lu\n", (unsigned long)getpid());

        sleep(1);
    }

    return 0;
}