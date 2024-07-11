#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 1000
#define MAX_COLOR_VALUE 255

typedef struct {
    unsigned char r, g, b;
} Color;

Color parse_color(const char *color_name) {
    Color color;
    if (strcmp(color_name, "red") == 0) {
        color = (Color){255, 0, 0};
    } else if (strcmp(color_name, "green") == 0) {
        color = (Color){0, 255, 0};
    } else if (strcmp(color_name, "blue") == 0) {
        color = (Color){0, 0, 255};
    } else if (strcmp(color_name, "yellow") == 0) {
        color = (Color){255, 255, 0};
    } else if (strcmp(color_name, "orange") == 0) {
        color = (Color){255, 165, 0};
    } else if (strcmp(color_name, "cyan") == 0) {
        color = (Color){0, 255, 255};
    } else if (strcmp(color_name, "magenta") == 0) {
        color = (Color){255, 0, 255};
    } else if (strcmp(color_name, "ocean") == 0) {
        color = (Color){0, 119, 190};
    } else if (strcmp(color_name, "violet") == 0) {
        color = (Color){148, 0, 211};
    } else {
        fprintf(stderr, "Unknown color: %s\n", color_name);
        exit(EXIT_FAILURE);
    }
    return color;
}

void write_header(int fd) {
    char header[32];
    snprintf(header, sizeof(header), "P6\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_COLOR_VALUE);
    write(fd, header, strlen(header));
}

void write_pixels(int fd, int start_row, int num_rows, Color colors[5]) {
    unsigned char buffer[WIDTH * 3 * num_rows];
    int index = 0;
    for (int y = start_row; y < start_row + num_rows; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Color color;
            int center_x = WIDTH / 2;
            int center_y = HEIGHT / 2;
            int dx = abs(x - center_x);
            int dy = abs(y - center_y);

            if (dx + dy < 250) {
                color = colors[0];  // Center (diamond shape)
            } else if (x < WIDTH / 2 && y < HEIGHT / 2) {
                color = colors[1];  // Top-left corner
            } else if (x >= WIDTH / 2 && y < HEIGHT / 2) {
                color = colors[2];  // Top-right corner
            } else if (x < WIDTH / 2 && y >= HEIGHT / 2) {
                color = colors[3];  // Bottom-left corner
            } else {
                color = colors[4];  // Bottom-right corner
            }

            buffer[index++] = color.r;
            buffer[index++] = color.g;
            buffer[index++] = color.b;
        }
    }
    write(fd, buffer, sizeof(buffer));
}

int main(int argc, char *argv[]) {
    if (argc != 7) {
        fprintf(stderr, "Usage: %s <file_name> <center_color> <top_left_color> <top_right_color> <bottom_left_color> <bottom_right_color>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *file_name = argv[1];
    Color colors[5];
    for (int i = 0; i < 5; i++) {
        colors[i] = parse_color(argv[i + 2]);
    }

    int fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    write_header(fd);

    for (int i = 0; i < 10; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            int start_row = i * 100;
            write_pixels(fd, start_row, 100, colors);
            close(fd);
            exit(EXIT_SUCCESS);
        } else {
            wait(NULL);
        }
    }

    close(fd);
    return 0;
}
