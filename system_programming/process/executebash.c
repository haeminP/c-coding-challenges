#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
  pid_t pid = fork();

  if (pid < 0) {
    perror("fork failed");
    exit(1);
  } else if (pid == 0) {
    // Child process
    execlp("bash", "bash", "-c", "./mybash", NULL);
    perror("execlp failed");
    exit(1);
  } else {
    // Parent process
    wait(NULL); // Wait for child process to finish
    printf("STUDY! STUDY! STUDY!\n");
  }

  return 0;
}
