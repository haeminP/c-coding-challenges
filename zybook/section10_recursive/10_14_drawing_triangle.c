#include <stdio.h>

/* Recursive DrawTriangle function */
void DrawTriangle(int baseLength, int currentLength, int spaces) {
    // Base case: when currentLength is greater than baseLength, return
    if (currentLength > baseLength) {
        return;
    }

    // Print the current line with '*' characters
    for (int i = 0; i < spaces; ++i) {
        printf(" ");
    }
    for (int i = 0; i < currentLength; ++i) {
        printf("*");
    }

    // Move to the next line
    printf("\n");

    // Adjust spaces for the next line, excluding the last line
    if (currentLength + 2 <= baseLength) {
        --spaces;
    }

    // Recursive case: draw the remaining part of the triangle
    DrawTriangle(baseLength, currentLength + 2, spaces);
}

int main(void) {
    int baseLength;

    // Input: Read the base length of the triangle
    scanf("%d", &baseLength);

    // Call DrawTriangle with the initial currentLength and spaces
    DrawTriangle(baseLength, 1, 9);

    return 0;
}
