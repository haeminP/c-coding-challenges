#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    int arr[] = {1, 2, 3, 4, 1, 2};
    int arrSize = sizeof(arr) / sizeof(int);

    int start, end;
    int fd[2];
    if (pipe(fd) == -1){
        return 1;
    }

    int id = fork();
    if (id == -1) {
        return 2;
    }

    // divide elements in array to parent process and child process
    if (id == 0) {
        start = 0;
        end = arrSize / 2;
    } else {
        start = arrSize / 2;
        end = arrSize;
    }

    int sum = 0;
    int i;
    for (i = start; i < end; i++){
        sum += arr[i];
    }

    // two processes run independently
    printf("Calculated partial sum: %d\n", sum);

    // sending the partial sum to the other process
    if (id == 0) {
        // child process
        close(fd[0]);   // close read end
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
    } else {
        // parent process
        int sumFromChild;
        close(fd[1]);
        read(fd[0], &sumFromChild, sizeof(sumFromChild));
        close(fd[0]);

        int totalSum = sum + sumFromChild;
        printf("Total sum is %d\n", totalSum);
        wait(NULL);
    }

    return 0;
}
