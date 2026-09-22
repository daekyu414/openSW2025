#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 128

int main(int argc, char* argv[])
{
    if(argc != 1)
    {
        printf("Usage: %s\n", argv[0]);

        return 1;
    }

    char* readStr = (char *)malloc(sizeof(char) * BUF_SIZE);

    while(1)
    {
        ssize_t read_result = read(0, readStr, BUF_SIZE);

        if(read_result == -1)
        {
            perror("read");

            break;
        }
        else if(read_result == 0)
        {
            printf("Detected EOF (Ctrl + D)\n");
            break;
        }

        ssize_t total_written = 0;
        while (1)
        {
            if(total_written >= read_result)
            {
                break;
            }
            
            ssize_t w = write(1, readStr + total_written, read_result - total_written);
            if (w < 0)
            {
                perror("write");
                free(readStr);
                return 1;
            }
            total_written += w;
        }
    }

    free(readStr);

    return 0;
}