#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int keep_running = 1;
int server2client_fd, client2server_fd;
char server_to_client[256];
char client_to_server[256];

void handle_signal(int sig) {
    if (sig == SIGINT) {
        keep_running = 0;
        close(server2client_fd);
        close(client2server_fd);
        unlink(server_to_client);
        unlink(client_to_server);
        printf("\nServer terminated.\n");
        exit(0);
    }
}

// cleanup() is called when the server is terminating
void cleanup() {
    close(server2client_fd);
    close(client2server_fd);
    unlink(server_to_client);
    unlink(client_to_server);
    printf("Server terminated.\n");
    exit(0);
}

void print_message(const char *server_msg, const char *client_msg) {
    printf("%-40s | %s\n", server_msg, client_msg);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server2client> <client2server>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    snprintf(server_to_client, sizeof(server_to_client), "/tmp/%s", argv[1]);
    snprintf(client_to_server, sizeof(client_to_server), "/tmp/%s", argv[2]);

    mkfifo(server_to_client, 0666);
    mkfifo(client_to_server, 0666);

    signal(SIGINT, handle_signal);

    printf("Waiting for connection...\n");

    printf("my messages (server)                            received messages (client)\n");
    printf("-------------------------------------------------------------------------\n");

    while (keep_running) {
        client2server_fd = open(client_to_server, O_RDONLY);
        server2client_fd = open(server_to_client, O_WRONLY);

        if (client2server_fd == -1 || server2client_fd == -1) {
            perror("Error opening FIFO files");
            cleanup();
        }

        char client_message[256];
        char server_message[256];


        // The server opens the FIFO files to read from the client and write to the client

        while (keep_running) {
            ssize_t bytes_read = read(client2server_fd, client_message, sizeof(client_message));

            if (bytes_read == 0) {
                // Client has disconnected
                printf("\nClient left. Waiting for new connection...\n");
                break;
            }

            client_message[bytes_read] = '\0'; // Null-terminate the string
            print_message("", client_message); // Print client's message

            if (strcmp(client_message, "exit") == 0) {
                printf("\nClient exited. Waiting for new connection...\n");
                break;
            }

            fgets(server_message, sizeof(server_message), stdin);
            server_message[strcspn(server_message, "\n")] = 0; // Remove newline character
            write(server2client_fd, server_message, strlen(server_message) + 1);
        }

        close(client2server_fd);
        close(server2client_fd);
    }

    cleanup();
    return 0;
}