#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

void child(pid_t client);

int main (int argc, char *argv[]) {
    int fd, status;
    char ch;
    pid_t pid;

    unlink("./severfifo.fifo");
    mkfifo("./serverfifo.fifo", 0777);
    while (1) {
        printf("waiting for a client...\n");
        fd = open("./serverfifo.fifo", O_RDONLY);
        read(fd, &pid, sizeof(pid_t));
        close(fd);
        printf("Got a client with pid: %d\n", pid);
        if (fork() == 0)
            child(pid);
    }
}

void child(pid_t pid) {
    char fifoName[100];
    char newline = '\n';
    int fd, i;

    sprintf(fifoName, "./clientfif%d.fifo", pid);
    unlink(fifoName);
    mkfifo(fifoName, 0777);
    fd = open(fifoName, O_WRONLY);

    for (i = 1; i < 10; i++){
        write(fd, fifoName, strlen(fifoName));
        write(fd, &newline, 1);
        sleep(5);
    }

    close(fd);
    unlink(fifoName);
    exit(0);
}
