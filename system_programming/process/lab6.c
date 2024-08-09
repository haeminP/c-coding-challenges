#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void create_child_processes(int process_number, int *sleep_times) {
    pid_t pid;
    for (int i = 2; i <= 3; i++) {
        if (process_number == 1) {
            pid = fork();
            if (pid == 0) {
                // Child process of the original process (2 and 3)
                process_number = i;


                for (int j = 2 * process_number; j <= 2 * process_number + 1; j++) {
                    pid = fork();
                    if (pid == 0) {
                        // Child process of process 2 or 3 (4, 5, 6, 7)
                        process_number = j;
                        sleep(sleep_times[process_number - 1]);
                        printf("process %d terminated. pid=%d\n", process_number, getpid());
                        exit(0);
                    }
                }
                sleep(sleep_times[process_number - 1]);
                printf("process %d terminated. pid=%d\n", process_number, getpid());
                exit(0);
            }
        }
    }

    // Wait for child processes of the original process (2 and 3) to terminate
    //wait(NULL);
    //wait(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 8) {
            fprintf(stderr, "Usage: %s <sleep_time1> <sleep_time2> <sleep_time3> <sleep_time4> <sleep_time5> <sleep_time6> <sleep_time7>\n", argv[0]);
        exit(1);
    }
    int sleep_times[7];
    for (int i = 0; i < 7; i++) {
        sleep_times[i] = atoi(argv[i + 1]);
    }

    // Original process

    create_child_processes(1, sleep_times);
    sleep(sleep_times[0]);
    printf("process 1 terminated. pid=%d\n", getpid());

    return 0;
}