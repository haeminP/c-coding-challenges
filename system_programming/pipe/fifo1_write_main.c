#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char* argv[]) {
    int arr[5];
    srand(time(NULL));
    int i;

    mkfifo("sum", 0777);

    // generate array of 5 numbers
    for (i = 0; i < 5; i++){
        arr[i] = rand() % 100;
    }

    // open FIFO
    int fd = open("sum", O_WRONLY);
    if (fd == -1) {
        return 1;
    }

    // send the numbers thru FIFO
    for (i = 0; i < 5; i++) {
        write(fd, &arr[i], sizeof(int));
        printf("Wrote %d\n", arr[i]);
    }
    close(fd);
    return 0;
}