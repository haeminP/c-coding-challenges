#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {

    int pid;
    pid = fork();

    if (pid > 0) {
        printf("I am parent process, pid = %d\n", getpid());
        while (1) {sleep(5);}
    }

    printf("I am the child process, pid = %d\n", getpid());
    exit(0);
}

