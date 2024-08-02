#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>

void alarm_handler(int dummy) {
    printf("Your BOAT\n");
    sleep(1);
}

int main(int argc, char *argv[]) {
    signal(SIGALRM, alarm_handler);
    sleep(1);
    alarm(3);
    while (1) {
        printf("Row\n");
        sleep(1);
    }
}

