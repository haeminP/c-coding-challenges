#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    alarm(5);

    while(1) {
        printf("Going to sleep\n");
        sleep(1);
    }

    printf("Exiting\n");
    exit(0);

}