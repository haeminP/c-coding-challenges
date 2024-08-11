#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char buf[50];
    int fd = open("gua", O_RDONLY);
    dup2(fd, STDIN_FILENO);
    scanf("%[^\n]", buf);
    printf("%s\n", buf);
}