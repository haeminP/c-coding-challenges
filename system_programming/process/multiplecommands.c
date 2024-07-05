#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <command1> [arg1] <command2> [arg2] ...\n", argv[0]);
    exit(1);
  }

  // Loop through 1st, 3rd, and 5th arguments
  for (int i = 1; i < argc; i += 2) {
    pid_t pid = fork();

    if (pid < 0) {
      perror("fork failed");
      exit(1);
    } else if (pid == 0) {
      // Child process
      char *args[3];  // Maximum of 3 arguments (command, arg, NULL)
      args[0] = argv[i];  // Command name

      // Check if there's a potential argument for the current command
      if (i + 1 < argc) {
        args[1] = argv[i + 1];
      } else {
        args[1] = NULL;  // No argument
      }

      args[2] = NULL;  // NULL terminator

      // Execute the command with arguments
      execvp(args[0], args);
      perror("execvp failed");
      exit(1);
    } else {
      // Parent process
      printf("Process ID for command %s: %d\n", argv[i], pid);
    }
  }

  // Wait for all child processes to finish
  for (int i = 1; i < argc; i+=2)  {
    wait(NULL);
  }

  return 0;
}