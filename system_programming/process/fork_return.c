#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc, char* argv[]){
    int id = fork();

    // Inside parent process - child process id - it's going to be different from getpid()
    // Inside child process - 0 - arbitrary number - it's going to be different from getpid()

    if (id == 0) {
        sleep(1);
    }

    printf("Returned by fork: %d, Current ID: %d, parent ID: %d\n", id, getpid(), getppid());

    int res = wait(NULL);

    if (res == -1) {
        printf("No children to wait for \n");   // printed on child process
    } else {
        printf("%d finished execution\n", res); // printed on parent process
    }

    return 0;
}