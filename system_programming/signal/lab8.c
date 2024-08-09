#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 3
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

const char *buf[BUF_SIZE] = {
    "EXAM! EXAM! EXAM!\n",
    "HELP! HELP! HELP!\n",
    "STUDY! STUDY! STUDY!\n"
};

int fd;  // File descriptor for the shared file
pid_t pid1, pid2;  // Process IDs of the child processes
int pipefd[2];  // Pipe file descriptors
volatile sig_atomic_t writing_in_progress = 0;  // Flag to indicate if writing is in progress

void write_to_file(const char *message, const char *process_name) {
    while (writing_in_progress) {
        sleep(1);  // Sleep for a short while if another process is writing
    }
    writing_in_progress = 1;  // Indicate that writing is in progress

    ssize_t result = write(fd, message, strlen(message));
    if (result == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    printf("%s has written to file: %s", process_name, message);

    sleep(5);  // Sleep after the write operation to simulate work

    writing_in_progress = 0;  // Indicate that writing is finished
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *file_name = argv[1];

    // Open the file
    fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    printf("parent opened file: %s\n", file_name);

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork the first child process
    pid1 = fork();
    if (pid1 < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) {
        // Child process 1
        close(pipefd[1]);  // Close the write end of the pipe
        char pid_str[10];
        read(pipefd[0], pid_str, sizeof(pid_str));
        close(pipefd[0]);
        pid_str[9] = '\0';  // Ensure null-termination
        write_to_file(buf[0], pid_str);
        exit(EXIT_SUCCESS);
    }

    // Fork the second child process
    pid2 = fork();
    if (pid2 < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) {
        // Child process 2
        close(pipefd[1]);  // Close the write end of the pipe
        char pid_str[10];
        read(pipefd[0], pid_str, sizeof(pid_str));
        close(pipefd[0]);
        pid_str[9] = '\0';  // Ensure null-termination
        write_to_file(buf[1], pid_str);
        exit(EXIT_SUCCESS);
    }

    // Parent process
    printf("parent created child process: %d\n", pid1);
    printf("parent created child process: %d\n", pid2);

    // Write the PIDs to the pipe
    close(pipefd[0]);  // Close the read end of the pipe
    char pid_str[10];
    snprintf(pid_str, sizeof(pid_str), "%d", pid1);
    write(pipefd[1], pid_str, strlen(pid_str) + 1);  // Write PID1 to the pipe
    snprintf(pid_str, sizeof(pid_str), "%d", pid2);
    write(pipefd[1], pid_str, strlen(pid_str) + 1);  // Write PID2 to the pipe
    close(pipefd[1]);  // Close the write end of the pipe

    // Wait for child processes to terminate
    if (waitpid(pid1, NULL, 0) == -1) {
        perror("waitpid");
    }
    if (waitpid(pid2, NULL, 0) == -1) {
        perror("waitpid");
    }

    // Write to the file
    write_to_file(buf[2], "parent");

    // Close the file
    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
    printf("parent closed the file\n");

    return 0;
}
