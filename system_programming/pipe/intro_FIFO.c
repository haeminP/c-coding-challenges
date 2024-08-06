#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char* argv[]){

    // create FIFO file
    if (mkfifo("myfifo1", 0777) == -1) { // 0777: read/write for anyone
        if (errno != EEXIST) {
            printf("Could not create a FIFO file\n");
            return 1;
        }
    } 

    printf("Opening\n...");

    // open FIFO file
    int fd = open("myfifo1", O_WRONLY);  // returns file descriptor
    printf("Opened\n...");
    
    int x = 97;
    write(fd, &x, sizeof(x));

    printf("Written\n...");

    close(fd);

    printf("Closed\n...");


    return 0;
}