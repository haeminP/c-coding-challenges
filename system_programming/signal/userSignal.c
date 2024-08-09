#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>


static void sig_usr(int);  /* one handler for both signals*/

int main(void) {
    if (signal(SIGUSR1, sig_usr) == SIG_ERR) {
        perror("Can't catch SIGUSR1");
    }
    if (signal(SIGUSR2, sig_usr) == SIG_ERR) {
        perror("Can't catch SIGUSR2");
    }

    for (int i = 0; i < 100; i++){
        printf("%d\n", i);
        sleep(5);
    }
}

static void sig_usr(int signo){
    if (signo == SIGUSR1) {
        printf("received SIGUSR1\n");
    }

    else if (signo == SIGUSR2) {
        printf("received SIGUSR2\n");
    }
    else {
        printf("received signal %d\n", signo);
    }
}