#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#inclu:de <sys/stat.h>
#include <fcntl.h>


int main() {
    int fd;
    char buf[256];
    int bytes_read, bytes_written;

    // Open file for reading and writing
    fd = open("list1.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Read the content of the file
    bytes_read = read(fd, buf, sizeof(buf) - 1);
    if (bytes_read == -1) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    // add null-terminate at the end of buffer
    buf[bytes_read] = '\0';


    // replace the string "101" with integer 101
    off_t start = lseek(fd, 0, SEEK_SET);

    char sub_string[4];
    int len = 3;
    int c = 0;

    while (c < len) {
        sub_string[c] = buf[c];
        c++;
    }

    sub_string[4] = '\0';

    int num = atoi(sub_string);


}