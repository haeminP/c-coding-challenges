#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int pid = fork();
    if (pid == -1) {
        return 1;
    }

    if (pid == 0) {
        // child process
        while (1) {
            printf("Some text goes here\n");
            usleep(50000);  // 50 milliseconds
        }
    } else {
        sleep(1);   // wait one second before killing the child process
        kill(pid, SIGKILL); // terminates the child process
        wait(NULL);
    }
}