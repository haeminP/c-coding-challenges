#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server2client> <client2server>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char server_to_client[256];
    char client_to_server[256];
    snprintf(server_to_client, sizeof(server_to_client), "/tmp/%s", argv[1]);
    snprintf(client_to_server, sizeof(client_to_server), "/tmp/%s", argv[2]);

    // Create the FIFO (named pipe) files
    mkfifo(server_to_client, 0666);
    mkfifo(client_to_server, 0666);

    printf("Waiting for connection...\n");

    int client2server_fd = open(client_to_server, O_RDONLY);
    int server2client_fd = open(server_to_client, O_WRONLY);

    if (client2server_fd == -1 || server2client_fd == -1) {
        perror("Error opening FIFO files");
        exit(EXIT_FAILURE);
    }

    int num1, num2;
    read(client2server_fd, &num1, sizeof(int));
    read(client2server_fd, &num2, sizeof(int));

    printf("Server received numbers: %d and %d\n", num1, num2);

    int sum = num1 + num2;
    write(server2client_fd, &sum, sizeof(int));

    printf("Server sent sum: %d\n", sum);

    close(client2server_fd);
    close(server2client_fd);

    // Remove the FIFO files
    unlink(server_to_client);
    unlink(client_to_server);

    return 0;
}
