#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void myhandler(int signo) {};   // to avoid quitting

int main(int argc, char *argv[]){

    pid_t pid;
    int status;

    if ((pid = fork()) > 0) {
        printf("parent: child should wait until I'm done\n");
        sleep(5);
        printf("parent: child can proceed now\n");
        kill(pid, SIGUSR1);
        printf("parent: exiting\n");
        wait(&status);
    } else {
        printf("child: waiting for parent\n");
        signal(SIGUSR1, myhandler);
        pause();
        printf("child: now I can do my job\n");
        sleep(5);
        printf("child: exiting\n");
    }

    exit(0);
}