#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Open the storage file for reading
    FILE *file = fopen("storage", "r");
    if (file == NULL) {
        perror("Failed to open storage file");
        exit(EXIT_FAILURE);
    }

    // Read the current number of tasks from the storage
    int current_tasks;
    if (fscanf(file, "%d", &current_tasks) != 1) {
        perror("Failed to read from storage file");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fclose(file);

    // Decrease the number of tasks by 3
    current_tasks -= 3;

    // Print the current total after decreasing
    printf("from consumer: current total is %d\n", current_tasks);

    // Open the storage file for writing
    file = fopen("storage", "w");
    if (file == NULL) {
        perror("Failed to open storage file");
        exit(EXIT_FAILURE);
    }

    // Write the new number of tasks to the storage
    fprintf(file, "%d\n", current_tasks);
    fclose(file);

    // Call the producer to continue
    execl("./producer", "producer", (char *)NULL);

    // If execl fails
    perror("execl");
    return EXIT_FAILURE;
}