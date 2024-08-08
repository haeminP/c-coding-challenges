#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]){
    int fd[2];  // fd[1]- write end, fd[0] - read end
    if (pipe(fd) == -1){
        return 1;
    }

    int pid1 = fork();
    if (pid1 < 0){return 2;}

    if (pid1 == 0){
        // Child process 1 (ping): it will be replaced by the ping program
        dup2(fd[1], STDOUT_FILENO); // fd[1] will replace the standard output
        close(fd[0]);
        close(fd[1]);
        execlp("ping", "ping", "-c", "5", "google.com", NULL);
    }


    int pid2 = fork();
    if (pid2 < 0){return 3;}

    if(pid2 == 0){
        // Child process 2 (grep)
        dup2(fd[0], STDIN_FILENO);   // grep replaces its standard input (reading end of the pipe)
        close(fd[0]);
        close(fd[1]);
        execlp("grep", "grep", "rtt", NULL);
    }


    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    // when does grep know to stop reading? when all the writers are closed
    // the main process still has write/read ends of the pipe open
    close(fd[0]);
    close(fd[1]);
   
    return 0;
}