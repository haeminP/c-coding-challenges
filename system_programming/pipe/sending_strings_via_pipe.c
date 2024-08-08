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
        str[strlen(str) -1] = '\0'; // set the last character as null-terminating char

        // send number of characters
        int n = strlen(str) + 1;
        write(fd[1], &n, sizeof(int)); // you need to send the reference
    

        // send the string to parent process
        write(fd[1], str, strlen(str) + 1);

        close(fd[1]);
    } else {
        // Parent process
        close(fd[1]);   // close the write end
        char str[200];
        int n;
        
        // read how many characters we want to read
        read(fd[0], &n, sizeof(int));

        // read the string
        read(fd[0], str, sizeof(char) * n);
        printf("Received: %s\n", str);
        close(fd[0]);
        wait(NULL);
    }


    

    return 0;
}