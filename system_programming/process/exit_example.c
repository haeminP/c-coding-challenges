#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int newpid;
    printf("before: my pid is %d\n", getpid());

    if ((newpid = fork()) == -1) {
        perror("fork");
    }

    else if (newpid == 0) {
        printf("I'm the child %d now sleeping...\n", getpid());
        sleep(1);
        exit(47);
        printf("I'm gone.");
    } else {
        printf("I'm the parent %d...\n", getpid());
        sleep(3);
        printf("My child %d must be gone by now. I'm leaving...\n", newpid);
        exit(1);
        printf("I'm gone too.");
    }
}