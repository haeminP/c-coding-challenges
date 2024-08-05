#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("gua", O_WRONLY | O_CREAT | O_TRUNC, "0722");
    dup2(fd, STDOUT_FILENO);
    printf("goose goose gua gua goose goose gua!\n");
}