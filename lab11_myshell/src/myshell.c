#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "do_exec.h"

#define MAX_LINE_COLUMNS 80
#define MAX_ARGS 10

void run_shell()
{
    char input[MAX_LINE_COLUMNS];
    char* argv[MAX_ARGS];
    char* token;

    while(1)
    {
        printf("myshell> ");
        fgets(input, MAX_LINE_COLUMNS, stdin);
        // printf("Executing %s\n", input);

        token = strtok(input, " \t\n");
        int i = 0;

        if(token == NULL)
        {
            continue;
        }
        while(token != NULL)
        {
            argv[i] = token;
            // printf("argv[%d]: %s\n", i, token);
            token = strtok(NULL, " \t\n");
            i++;
        }
        argv[i] = NULL;

        if(argv[0] == NULL)
        {
            continue;
        }

        // execute a command
        if(strcmp(argv[0], "quit") == 0)
        {
            printf("Good Bye!\n");
            return;
        }
        else if(strcmp(argv[0], "cd") == 0)
        {
            chdir(argv[1]);
            perror("cd");
        }
        else if(strcmp(argv[0], "pwd") == 0)
        {
            char path[MAX_LINE_COLUMNS];

            getcwd(path, MAX_LINE_COLUMNS);
            printf("%s\n", path);
        }
        else if(access(argv[0], F_OK & R_OK & X_OK) == 0)
        {
            // printf("executing %s\n", argv[0]);
            do_exec(argv);
        }
    }
}

int main(int argc, char* argv[])
{
    run_shell();

    return 0;
}