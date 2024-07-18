#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

// 2 processes
// 1) Child process should generate random numbers and send them to the paretn
// 2) Parent is going to sum all the numbers and print the result
// Only write from Child process, and only read from Parent process

int main() {
    // open a pipe
    int fd[2];
    if (pipe(fd) == -1){
        return 2;
    }
 
    int pid = fork();
    if (pid == -1) {
        return 1;
    }

// child process
    if (pid == 0){
        close(fd[0]);   // fd[0] is for read
        int n, i;
        int arr[10];
        srand(time(NULL));
        n = rand() % 10 + 1;
        printf("Generated: ");

        for (i = 0; i < n; i++) {
            arr[i] = rand() % 11;
            printf("%d ", arr[i]);
        }
        printf("\n");
        // send the number of elements in array
        if (write(fd[1], &n, sizeof(int)) < 0) {
            return 4;
        }

        printf("Sent %d numbers\n", n);

        if (write(fd[1], arr, sizeof(int) * n) < 0) {
            return 3;
        }
    } else {
        // Parent process
        close(fd[1]);   // fd[1] is for write
        int arr[10];
        int n, i;
        int sum = 0;
        // read the number of elements
        if (read(fd[0], &n, sizeof(int)) < 0) {
            return 5;
        }

        printf("Received %d numbers\n", n);
        if (read(fd[0], arr, sizeof(int) * n) < 0) {
            return 6;
        }

        printf("Received array\n");
        for (i = 0; i < n; i++) {
            sum += arr[i];
        }

        close(fd[0]);

        printf("Result is: %d\n", sum);
        wait(NULL);

    }

    return 0;
}