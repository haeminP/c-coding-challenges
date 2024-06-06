#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 80


int main(void) {
        int fd;
        int readn = 0;
        char buf[MAXLEN];

        fd = open("fly.txt", O_RDONLY);
        if (fd == -1){
                perror("creat"); exit(1);
        }
        memset(buf,0x00,MAXLEN);
        while ((readn = read(fd,buf,MAXLEN-1)) > 0){
                printf("%s", buf);
        }
        close(fd);
        return 0;
}