#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 32

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        printf("Usage: %s [sourcefile] [destination file1] [destination file2] ... \n", argv[0]);
        return 1;
    }

    // open src
    int src_fd = open(argv[1], O_RDONLY);
    if(src_fd == -1)
    {
        perror("open file");

        return 1;
    }

    // open destination
    int file_nums = argc - 2;
    int *dest_fd_list = (int *)malloc(sizeof(int) * file_nums);

    for(int i = 0; i < file_nums; i++)
    {
        dest_fd_list[i] = open(argv[i + 2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if(dest_fd_list[i] == -1)
        {
            perror("open dest");
        }
    }

    char buf[BUF_SIZE];

    // read and write
    while(1)
    {
        ssize_t src_read = read(src_fd, buf, BUF_SIZE);

        if(src_read == -1)
        {
            perror("read");
            break;
        }
        else if(src_read == 0)
        {
            break;
        }

        ssize_t w_stdout = write(1, buf, src_read);
        if(w_stdout == -1)
        {
            perror("write stdout");

            break;
        }

        for(int i = 0; i < file_nums; i++)
        {
            if(dest_fd_list[i] != -1)
            {
                ssize_t w_dest = write(dest_fd_list[i], buf, src_read);
                if(w_dest == -1)
                {
                    perror("write dest");
                }
            }
        }
    }

    close(src_fd);
    for (int i = 0; i < file_nums; i++)
    {
        if (dest_fd_list[i] != -1)
        {
            close(dest_fd_list[i]);
        }
    }

    free(dest_fd_list);

    return 0;
}