#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <command>\n", argv[0]);
    exit(1);
  }

  int pipefd[2];
  if (pipe(pipefd) == -1) {
    perror("pipe");
    exit(1);
  }

  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(1);
  }

  if (pid == 0) {
    // child process
    close(pipefd[1]); // close writing end in child process

    char buffer[1024];
    ssize_t nread;
    while ((nread = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
      write(STDOUT_FILENO, buffer, nread);
    }

    if (nread == -1) {
      perror("read");
    }

    close(pipefd[0]); // close reading end after all data is read
    exit(0);
  } else {
    // parent process
    close(pipefd[0]); // close reading end in parent process

    FILE *fp = fopen("result.txt", "w");
    if (fp == NULL) {
      perror("fopen");
      exit(1);
    }

    write(pipefd[1], argv[1], strlen(argv[1])); // write command to child process

    char buffer[1024];
    ssize_t nread;
    while ((nread = read(pipefd[1], buffer, sizeof(buffer))) > 0) {
      write(fp, buffer, nread);
    }

    if (nread == -1) {
      perror("read");
    }

    fclose(fp);
    close(pipefd[1]); // close writing end after all data is written

    int status;
    waitpid(pid, &status, 0);

    printf("The result of %s is written into result.txt with total %ld bytes.\n", argv[1], ftell(fp));
  }

  return 0;
}
