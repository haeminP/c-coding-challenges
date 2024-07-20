#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <number_of_tasks>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Get the current number of tasks
  int current_tasks = atoi(argv[1]);

  // Decrease the number of tasks by 3
  current_tasks -= 3;

  // Print the current total after decreasing
  printf("from worker: current total is %d\n", current_tasks);

  // Convert the current number of tasks to a string
  char tasks_str[10];
  snprintf(tasks_str, sizeof(tasks_str), "%d", current_tasks);

  // Call the manager with the updated number of tasks
  char *args[] = {"./manager", tasks_str, NULL};
  execvp(args[0], args);

  // If execvp fails
  perror("execvp");
  return EXIT_FAILURE;
}