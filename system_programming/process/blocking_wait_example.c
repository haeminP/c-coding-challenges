#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    int status;
    int pid, child_pid;

    if ((pid=fork()) < 0){
        exit(1);
    }

    if (pid == 0) {
        printf("Child pid: %d\n", getpid());
        sleep(5);
        exit(0);
    }

    child_pid = wait(&status);
    printf("parent received status from pid: %d\n", child_pid);

    return 0;

}