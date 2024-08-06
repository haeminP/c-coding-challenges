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
    int fd = open("sum", O_RDONLY);
    if (fd == -2){
        return 1;
    }

    int i;
    for (i = 0; i < 5; i++){
        read(fd, &arr[i], sizeof(int));
        printf("Received %d\n", arr[i]);
    }
    close(fd);
    
    return 0;
}