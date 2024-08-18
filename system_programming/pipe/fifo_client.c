#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]){
    
    char ch, fifoName[100];
    int fd;
    pid_t pid;

    while((fd=open("./serverfifo.fifo", O_WRONLY)) == -1) {sleep(1)};
    pid = getpid();

    write(fd, &pid, sizeof(pid_t));
    close(fd);
    sprintf(fifoName, "./clientfifo%d.fifo", pid);
    sleep(1);
    while((fd=open(fifoName, O_RDONLY)) == -1) {sleep(1)};
    while (read(fd, &ch, 1) == 1){printf("%c", ch);}
    close(fd);
}

