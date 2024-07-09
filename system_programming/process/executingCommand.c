#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

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
        execlp("ping", "ping", "-c", "3", "google.com", NULL);
        printf("THIS SHOULD NOT PRINT ON THE TERMINAL");
    } else {
        // parent process
        wait(NULL); // wait for child process to finish
        printf("Some post processing goes here!\n");
    }

    printf("Success!");
    return 0;
}

