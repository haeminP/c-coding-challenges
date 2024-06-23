#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdbool.h>

int isprime(int n){
    int i;
    if (n <= 1) return 0;
    for (i=2; i*i <= n; i++) {
    if (n % i == 0) return 0;
    return 1;
}
}

int main() {
    int number;
    pid_t pid;
    int fd;
    char filename[] = "data";

    // Fork a new process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process

        // Wait for the parent to finish writing to the file
        sleep(3); // Simple method to ensure parent writes first, for demo purposes

        // Open the file for reading
        fd = open("data", O_RDONLY);
        if (fd < 0) {
            perror("Failed to open file");
            exit(1);
        }

        // Read the number from the file
        if (read(fd, &number, sizeof(int)) == 0) {
            close(fd);
            return 0;
        }

        close(fd);

        // Check if the number is prime
        if (isprime(number) == 1) {
            printf("%d is a prime number.\n", number);
        } else {
            printf("%d is not a prime number.\n", number);
        }

    } else {
        // Parent process

        // Get the number from the user
        printf("Enter a number between 1 and 15: ");
        scanf("%d", &number);

        // Validate the number
        if (number < 1 || number > 15) {
            fprintf(stderr, "Error: Number must be between 1 and 15.\n");
            exit(1);
        }

        // Open the file for writing
        fd = open("data", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0) {
            perror("Failed to open file");
            exit(1);
        }

        // Write the number to the file
        if (write(fd, &number, sizeof(int)) != sizeof(int)) {
            perror("Failed to write to file");
            close(fd);
            exit(1);
        }

        close(fd);

        // Wait for the child process to finish
        wait(NULL);
    }

    return 0;
}