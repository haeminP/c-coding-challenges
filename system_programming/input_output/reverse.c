#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int rfd, wfd, n;
    off_t start, cur;
    char buf[2];

    rfd = open("sampleinput", O_RDONLY);
    if (rfd == -1) {
        perror("Open sampleinput");
        exit(1);
    }

    wfd = open("sampleoutput", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (wfd == -1) {
        perror("Open sampleoutput");
        exit(1);
    }

    start = lseek(rfd, -1, SEEK_END);
    n = read(rfd, buf, 1);
    cur = lseek(rfd, -1, SEEK_CUR);
    write(wfd, buf, 1);


    while (start > 0) {
    start = lseek(rfd, -1, SEEK_CUR);
    n = read(rfd, buf, 1);
    cur = lseek(rfd, -1, SEEK_CUR);
    write(wfd, buf, 1);
    }


    close(rfd);
    close(wfd);
    return 0;
}