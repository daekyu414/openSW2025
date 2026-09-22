#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s [file1 name] ... \n", argv[0]);

        return 1;
    }

    int file_nums = argc - 1;
    int* file_list = (int*)malloc(sizeof(int) * file_nums);

    for(int i = 0; i < file_nums; i++)
    {
        int fd = open(argv[i + 1], O_RDONLY);

        file_list[i] = fd;

        if(fd == -1)
        {
            perror(argv[i + 1]);
        }
        else
        {
            printf("Opened successfully: %s (fd = %d)\n", argv[i + 1], fd);
        }
    }

    for(int i = 0; i < file_nums; i++)
    {
        if(file_list[i] != -1)
        {
            close(file_list[i]);
            printf("Closed successfully: %s\n", argv[i + 1]);
        }
    }

    free(file_list);

    return 0;
}