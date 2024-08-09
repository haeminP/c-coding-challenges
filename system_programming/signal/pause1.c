#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void alarmhandler(int signo){
    printf("Alarm! ESCAPE!!!\n");
}

int main(int argc, char *argv[]){
    signal(SIGALRM, alarmhandler);
    alarm(3);
    pause();
}

