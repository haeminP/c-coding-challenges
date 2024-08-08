#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/wait.h>

int x = 0;


void handle_sigusr1(int sig){
    if (x == 0) {
    printf("\n(HINT) Remember that multiplication is repetitive addition!\n");
    }
}


int main(int argc, char* argv[]) {
    int pid = fork();
    if (pid == -1) {
        return 1;
    }

    if (pid == 0) {
        sleep(5);
        // now send the signal to parent after 5 seconds of sleep
        kill(getppid(), SIGUSR1);
    } else {
        // Parent process

        // handler signal
        struct sigaction sa = {0};
        sa.sa_flags = SA_RESTART;  // redo the scanf()
        sa.sa_handler = &handle_sigusr1;
        sigaction(SIGUSR1, &sa, NULL);

        printf("What is the result of 3 x 5: ");
        scanf("%d", &x);

        if (x == 15){
            printf("Right!");
        } else {
            printf("Wrong!");
        }
        wait(NULL);
    }
    return 0;
}