#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void child(int fd[]);
void parent(int fd[]);

int main(int argc, char *argv[]){
    int fd[2];
    if (pipe(fd) == -1)
        exit(1);
    if (fork() == 0)
        child(fd);
    else 
        parent (fd);

    exit(0);
}

void child(int fd[]){
    char message[255] = "Hello from child process\n";
    close(fd[0]);
    sleep(5);   // this shows blocking read
    write(fd[1], message, 26);
}

void parent(int, *fd){
    char ch;
    close(fd[1]);
    printf("Reading data from child...\n");
    for (int = 0; i < 28; i++){
        read(fd[0], &ch, 1);
        printf("%c", ch);
        if (ch == '\n') // \n being part of the protocol
            break;
    }
}