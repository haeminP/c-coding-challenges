#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main() {
    int fd[2];

    if (pipe(fd) == -1){
        return 1;
    }

    int pid = fork();

    if (pid < 0) {
        return 2;
    }

    if (pid == 0) {
        // child process
        char str[200];
        printf("Input string: ");
        fgets(str, 200, stdin);
        str[strlen(str) -1] = '\0';

        // send number of characters
        int n = strlen(str) + 1;
        if (write(fd[1], &n, sizeof(int)) < 0) {  // you need to send the reference
            return 4;
        }

        // send the string to parent process
        if (write(fd[1], str, strlen(str) + 1 ) < 0) {
            return 3;
        }

        close(fd[1]);
    } else {
        // Parent process
        close(fd[1]);
        char str[200];
        int n;

        if (read(fd[0], &n, sizeof(int)) < 0) {
            return 5;
        }

        if (read(fd[0], str, sizeof(char) * n) < 0) {
            return 6;
        }
        printf("Received: %s\n", str);
        close(fd[0]);
        wait(NULL);
    }


    

    return 0;
}