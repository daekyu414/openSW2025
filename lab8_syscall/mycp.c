#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage: opentest filename.\n");
        return 0;
    }

    int fd_src = open(argv[1], O_RDONLY);
    int fd_tgt = open(argv[2], O_WRONLY | O_CREAT, 0644);

    if(fd_src == -1)
    {
        // printf("'%s':File open error\n", (char *)argv[1]);
        perror(argv[1]);
    }

    while(1)
    {
        int rtn = ssize_t read(fd_src, argv[1], size_t 256);
        if(rtn == 0)
        {
            break;
        }
        
    }

    for(int i = 0; i < argc; i++)
    {
        int fd = open(argv[i], O_RDONLY | O_CREAT, 0644);
        if(fd == -1)
        {
            // printf("'%s':File open error\n", (char *)argv[1]);
            perror(argv[1]);
        }

    }

    

    
    else
    {
        printf("'%s':File open successful!\n", (char *)argv[1]);
    }
    
    return 0;
}