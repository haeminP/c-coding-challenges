#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

int main(int argc, char *argv[]){

    int i;
    void (*oldHandler1) ();
    void (*oldHandler2) ();

    oldHandler1 = signal(SIGINT, SIG_IGN);  // ignore CTRL-C
    oldHandler2 = signal(SIGTSTP, SIG_IGN); // ignore CTRL-Z

    for (i = 1; i <= 10; i++){
        printf("I'm not sensitive to CTRL-C/CTRL-Z\n");
        sleep(1);
    }
    signal(SIGINT, oldHandler1); // restore default
    signal(SIGTSTP, oldHandler2); // restore default

    for (i = 1; i <= 10; i++){
        printf("I'm sensitive to CTRL-C/CTRL-Z\n");
        sleep(1);
    }
}
