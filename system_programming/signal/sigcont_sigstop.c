#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){

    int pid = fork();
    if (pid == -1) {
        return 1;
    }

    if (pid == 0){
        while(1){
            printf("Some output\n");
            usleep(50000);
        }
    } else {
        kill(pid, SIGSTOP);
        int t;
        do {
            printf("Time in seconds for execution (enter 0 to stop execution): ");
            scanf("%d", &t);

            if (t > 0) {
                kill(pid, SIGCONT);
                sleep(t);
                kill(pid, SIGSTOP);
            }
        } while (t > 0);

        kill(pid, SIGKILL);
        wait(NULL);
    }

    return 0;

}