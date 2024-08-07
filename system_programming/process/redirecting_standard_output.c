#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>


int main (int argc, char* argv[]) {
    int pid = fork();
    if (pid == -1) {
        return 1;
    }

    // execl should be called on child process:
    // if you call execl on parent process, parent process gets replaced
    // and it will no longer wait for the child process
    // in that case, child process becomes a zombie process

    if (pid == 0) {
        // child process: replaced by ping process
        int file = open("pingResults.txt", O_WRONLY | O_CREAT, 0777);
        if (file == -1) {
            return 2;
        }

        printf("The original fd to pingResults: %d\n", file);
        int file2 = dup2(file, STDOUT_FILENO);  // returns another file descriptor
        printf("The duplicated fd: %d\n", file2);
        close(file);

        int err = execlp("ping", "ping", "-c", "3", "google.com", NULL);

        if (err == -1){
            printf("Could not find program to execute!\n");
            return 2;
        }
        printf("THIS SHOULD NOT PRINT ON THE TERMINAL"); // child process is replaced by Ping
    } else {
        // parent process
        int waitStatus;
        wait(&waitStatus); // wait for child process to finish
        if (WIFEXITED(waitStatus)) { // check if the child process exited normally
            int statusCode = WEXITSTATUS(waitStatus);
            if (statusCode == 0){
                printf("Success!\n");
            } else {
                printf("Failure with status code %d\n", statusCode);
            }
        }
        printf("Some post processing goes here!\n");
    }


    return 0;
}

