#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

typedef struct {
    int width;
    int height;
    int max_color;
    unsigned char *data;
} PPMImage;

int read_int_from_string(const char *str, int length) {
    int result = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        }
    }
    return result;
}

void read_header(int fd, PPMImage *img, char *width_str, char *height_str, char *max_color_str) {
    char buffer[256];
    int bytes_read, index = 0;

    // Read "P6" header
    bytes_read = read(fd, buffer, 3);
    if (bytes_read != 3 || buffer[0] != 'P' || buffer[1] != '6') {
        write(STDERR_FILENO, "Invalid PPM file\n", 17);
        exit(EXIT_FAILURE);
    }

    // Read width
    index = 0;
    while (1) {
        bytes_read = read(fd, buffer + index, 1);
        if (bytes_read <= 0) {
            write(STDERR_FILENO, "Error reading PPM file\n", 23);
            exit(EXIT_FAILURE);
        }
        if (buffer[index] == ' ') {
            buffer[index] = '\0';
            strcpy(width_str, buffer);
            img->width = read_int_from_string(buffer, index);
            break;
        }
        index++;
    }

    // Read height
    index = 0;
    while (1) {
        bytes_read = read(fd, buffer + index, 1);
        if (bytes_read <= 0) {
            write(STDERR_FILENO, "Error reading PPM file\n", 23);
            exit(EXIT_FAILURE);
        }
        if (buffer[index] == '\n') {
            buffer[index] = '\0';
            strcpy(height_str, buffer);
            img->height = read_int_from_string(buffer, index);
            break;
        }
        index++;
    }

    // Read max color value
    index = 0;
    while (1) {
        bytes_read = read(fd, buffer + index, 1);
        if (bytes_read <= 0) {
            write(STDERR_FILENO, "Error reading PPM file\n", 23);
            exit(EXIT_FAILURE);
        }
        if (buffer[index] == '\n') {
            buffer[index] = '\0';
            strcpy(max_color_str, buffer);
            img->max_color = read_int_from_string(buffer, index);
            break;
        }
        index++;
    }
}

PPMImage *read_ppm(const char *filename, char *width_str, char *height_str, char *max_color_str) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        write(STDERR_FILENO, "Error opening file\n", 19);
        exit(EXIT_FAILURE);
    }

    PPMImage *img = (PPMImage *)malloc(sizeof(PPMImage));
    read_header(fd, img, width_str, height_str, max_color_str);

    img->data = (unsigned char *)malloc(3 * img->width * img->height);
    int total_bytes = 3 * img->width * img->height;
    int bytes_read = read(fd, img->data, total_bytes);
    if (bytes_read != total_bytes) {
        write(STDERR_FILENO, "Error reading image data\n", 25);
        exit(EXIT_FAILURE);
    }

    close(fd);
    return img;
}

void write_ppm(const char *filename, PPMImage *img, const char *width_str, const char *height_str, const char *max_color_str) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        write(STDERR_FILENO, "Error opening file for writing\n", 31);
        exit(EXIT_FAILURE);
    }

    // Write "P6" header
    write(fd, "P6\n", 3);

    // Write width
    write(fd, width_str, strlen(width_str));
    write(fd, " ", 1);

    // Write height
    write(fd, height_str, strlen(height_str));
    write(fd, "\n", 1);

    // Write max color value
    write(fd, max_color_str, strlen(max_color_str));
    write(fd, "\n", 1);

    // Write image data
    int total_bytes = 3 * img->width * img->height;
    int bytes_written = write(fd, img->data, total_bytes);
    if (bytes_written != total_bytes) {
        write(STDERR_FILENO, "Error writing image data\n", 25);
        exit(EXIT_FAILURE);
    }

    close(fd);
}

void merge_images(PPMImage *img1, PPMImage *img2) {
    if (img1->width < img2->width || img1->height < img2->height) {
        write(STDERR_FILENO, "Error: The first image dimensions are smaller than the second image.\n", 69);
        exit(EXIT_FAILURE);
    }

    for (int y = 0; y < img2->height; y++) {
        for (int x = 0; x < img2->width; x++) {
            int img1_index = ((y * img1->width) + (img1->width - img2->width + x)) * 3;
            int img2_index = (y * img2->width + x) * 3;
            memcpy(&img1->data[img1_index], &img2->data[img2_index], 3);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        write(STDERR_FILENO, "Usage: <image1.ppm> <image2.ppm> <output.ppm>\n", 46);
        exit(EXIT_FAILURE);
    }

    char width_str1[20], height_str1[20], max_color_str1[20];
    char width_str2[20], height_str2[20], max_color_str2[20];

    PPMImage *img1 = read_ppm(argv[1], width_str1, height_str1, max_color_str1);
    PPMImage *img2 = read_ppm(argv[2], width_str2, height_str2, max_color_str2);

    merge_images(img1, img2);

    write_ppm(argv[3], img1, width_str1, height_str1, max_color_str1);

    free(img1->data);
    free(img1);
    free(img2->data);
    free(img2);

    return 0;
}

