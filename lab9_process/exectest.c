#include <stdio.h>
#include <unistd.h>

int main()
{
    char *argv[] = {"ls", "-l", NULL};

    // execve("/usr/bin/ls", argv, NULL);
    execl("/usr/bin/ls", "ls", "-l", NULL);
    printf("Hello world\n");

    return 0;
}