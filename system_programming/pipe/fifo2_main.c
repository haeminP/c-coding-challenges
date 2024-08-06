#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <time.h>

int main(int argc, char* argv[]) {
    // 5 => (5*4 = 20) => 20
    int p1[2];  // Child => Parent
    int p2[2];  // Parent => Child
    if (pipe(p1) == -1) {return 1;}
    if (pipe(p2) == -1) {return 1;}


    int pid = fork();
    if (pid == -1) {return 2;}
    if (pid == 0) {
        // Child process: read data and send it back
        close(p1[0]);   // C => P: write only
        close(p2[1]);   // P => C: read only

        int x;
        read(p2[0], &x, sizeof(x));

        // multiply x by 4 and write it back
        printf("Child Received %d\n", x);
        x *= 4;
        write(p1[1], &x, sizeof(x));
        printf("Child Wrote %d\n", x);

        close(p1[1]);
        close(p2[0]);
    } else {
        // Parent process: generate random number (1-9) and write it to pipe
        // then read the multiplied number sent from the child process

        close(p1[1]);   // C => P: read only, so close write end
        close(p2[0]);   // P => C: write only, so close read end

        srand(time(NULL));
        int y = rand() % 10;
        write(p2[1], &y, sizeof(y));
        read(p1[0], &y, sizeof(y));
        printf("Final Result is %d\n", y);

        // close all the pipes
        close(p1[0]);
        close(p2[1]);
        wait(NULL);
    }


    return 0;
}