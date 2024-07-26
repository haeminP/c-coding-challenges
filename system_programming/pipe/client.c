#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <server2client> <client2server> <number1> <number2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char server_to_client[256];
    char client_to_server[256];
    snprintf(server_to_client, sizeof(server_to_client), "/tmp/%s", argv[1]);
    snprintf(client_to_server, sizeof(client_to_server), "/tmp/%s", argv[2]);

    int num1 = atoi(argv[3]);
    int num2 = atoi(argv[4]);

    printf("Connected.\n");

    int client2server_fd = open(client_to_server, O_WRONLY);
    int server2client_fd = open(server_to_client, O_RDONLY);

    if (client2server_fd == -1 || server2client_fd == -1) {
        perror("Error opening FIFO files");
        exit(EXIT_FAILURE);
    }

    write(client2server_fd, &num1, sizeof(int));
    write(client2server_fd, &num2, sizeof(int));

    printf("Client sent numbers: %d and %d\n", num1, num2);

    int sum;
    read(server2client_fd, &sum, sizeof(int));

    printf("Client received sum: %d\n", sum);

    close(client2server_fd);
    close(server2client_fd);

    return 0;
}