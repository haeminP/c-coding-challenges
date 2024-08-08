#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]){
    int fd[3][2];
    int i;
    for (i = 0; i < 3; i++){
        if(pipe(fd[i]) < 0) {
            return 1;
        }
    }


    int pid1 = fork();
    if (pid1 < 0){ return 2;}

    if (pid == 0){
        // Child process 1
        // close all unused fd
        closed(fd[0][1]);
        close(fd[1]fd[0]);
        close(fd[2][0]);
        close(fd[2][1]);

        int x;
        read(fd[0][0], &x, sizeof(int));
        x += 5;
        write(fd[1][1], &x, sizeof(int));

        close(fd[0][0]);
        close(fd[1][1]);
    }
    return 0;
}