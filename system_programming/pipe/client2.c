#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int keep_running = 1;
int client2server_fd, server2client_fd;
char server_to_client[256];
char client_to_server[256];

void handle_signal(int sig) {
    if (sig == SIGINT) {
        keep_running = 0;
        close(client2server_fd);
        close(server2client_fd);
        printf("\nClient terminated.\n");
        exit(0);
    }
}

void print_message(const char *client_msg, const char *server_msg) {
    printf("%-40s | %s\n", client_msg, server_msg);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server2client> <client2server>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    snprintf(server_to_client, sizeof(server_to_client), "/tmp/%s", argv[1]);
    snprintf(client_to_server, sizeof(client_to_server), "/tmp/%s", argv[2]);

    signal(SIGINT, handle_signal);

    printf("Connected.\n");

    client2server_fd = open(client_to_server, O_WRONLY);
    server2client_fd = open(server_to_client, O_RDONLY);

    if (client2server_fd == -1 || server2client_fd == -1) {
        perror("Error opening FIFO files");
        exit(EXIT_FAILURE);
    }

    char client_message[256];
    char server_message[256];

    printf("my messages (client)                            received messages (server)\n");
    printf("-------------------------------------------------------------------------\n");

    while (keep_running) {
        fgets(client_message, sizeof(client_message), stdin);
        client_message[strcspn(client_message, "\n")] = 0; // Remove newline character
        write(client2server_fd, client_message, strlen(client_message) + 1);

        if (strcmp(client_message, "exit") == 0) {
            printf("Client exited.\n");
            break;
        }

        ssize_t bytes_read = read(server2client_fd, server_message, sizeof(server_message));
        server_message[bytes_read] = '\0'; // Null-terminate the string
        print_message("", server_message); // Print server's message
    }

    close(client2server_fd);
    close(server2client_fd);

    return 0;
}