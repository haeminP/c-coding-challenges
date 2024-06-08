#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    int fd;
    char *content = "101   GM\tBuick\t2010\n102   Ford\tLincoln\t2005";

    // Open the file
    fd = open("list1.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    
    if (fd == -1){
        perror("Error opening file");
        return 1;
    }

    // Write the content to the file
    int bytes_written = write(fd, content, strlen(content));

    if (bytes_written == -1) {
        perror("Error writing to file");
        return 1;
    }

    // Close the file
    close(fd);

    return 0;

}