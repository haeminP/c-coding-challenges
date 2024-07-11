#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define WIDTH 1000
#define HEIGHT 1000
#define MAX_COLOR_VALUE 255

typedef struct {
    unsigned char r, g, b;
} Color;

void error_exit(const char *message) {
    write(STDERR_FILENO, message, strlen(message));
    write(STDERR_FILENO, "\n", 1);
    _exit(1);
}

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
        error_exit("Unknown color");
    }
    return color;
}

void int_to_str(int num, char *str) {
    char temp[12];
    int i = 0, j, len;
    
    if (num == 0) {
        str[i++] = '0';
    } else {
        while (num > 0) {
            temp[i++] = '0' + (num % 10);
            num /= 10;
        }
    }
    len = i;
    for (j = 0; j < len; j++) {
        str[j] = temp[len - j - 1];
    }
    str[len] = '\0';
}

void write_header(int fd) {
    char header[32];
    char width_str[12], height_str[12], max_color_str[12];

    int_to_str(WIDTH, width_str);
    int_to_str(HEIGHT, height_str);
    int_to_str(MAX_COLOR_VALUE, max_color_str);

    int length = 0;
    length += snprintf(header + length, sizeof(header) - length, "P6\n");
    length += snprintf(header + length, sizeof(header) - length, "%s %s\n", width_str, height_str);
    length += snprintf(header + length, sizeof(header) - length, "%s\n", max_color_str);
    
    write(fd, header, length);
}

int my_abs(int value) {
    return value < 0 ? -value : value;
}

void write_pixels(int fd, int start_row, int num_rows, Color colors[5]) {
    unsigned char buffer[WIDTH * 3 * num_rows];
    int index = 0;
    for (int y = start_row; y < start_row + num_rows; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Color color;
            int center_x = WIDTH / 2;
            int center_y = HEIGHT / 2;

            // Horizontal and vertical distances from the current pixel position to the center of the image
            int dx = my_abs(x - center_x);
            int dy = my_abs(y - center_y);

            if (dx + dy < 250) {
                color = colors[0];  // Center
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
        error_exit("Usage: <file_name> <center_color> <top_left_color> <top_right_color> <bottom_left_color> <bottom_right_color>");
    }

    const char *file_name = argv[1];
    Color colors[5];
    for (int i = 0; i < 5; i++) {
        colors[i] = parse_color(argv[i + 2]);
    }

    int fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (fd < 0) {
        error_exit("Failed to open file");
    }

    write_header(fd);

    for (int i = 0; i < 10; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            error_exit("Failed to fork");
        } else if (pid == 0) {
            int start_row = i * 100;
            write_pixels(fd, start_row, 100, colors);
            close(fd);
            _exit(0);
        } else {
            wait(NULL);
        }
    }

    close(fd);
    return 0;
}
