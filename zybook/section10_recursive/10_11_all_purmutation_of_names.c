#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int MAX_NAME_SIZE = 50;

// Function to swap two strings
void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print all permutations of names
void PrintAllPermutations(char **permList, int permSize, int nameSize) {
    if (permSize == nameSize) {
        // Base case: all names are placed, print the permutation
        for (int i = 0; i < nameSize; ++i) {
            printf("%s", permList[i]);
            if (i < nameSize - 1) {
                printf(", ");
            }
        }
        printf("\n");
        return;
    }

    for (int i = permSize; i < nameSize; ++i) {
        // Swap the current name with the first name in the remaining list
        swap(&permList[permSize], &permList[i]);

        // Recursively generate permutations for the remaining names
        PrintAllPermutations(permList, permSize + 1, nameSize);

        // Backtrack: undo the swap to restore the original order
        swap(&permList[permSize], &permList[i]);
    }
}

int main(void) {
    int size;
    int i = 0;

    scanf("%d", &size);
    char *nameList[size];
    char *permList[size];

    for (i = 0; i < size; ++i) {
        nameList[i] = (char *)malloc(MAX_NAME_SIZE);
        permList[i] = (char *)malloc(MAX_NAME_SIZE);
        scanf("%s", nameList[i]);
        strcpy(permList[i], nameList[i]);
    }

    PrintAllPermutations(permList, 0, size);

    // Free dynamically allocated memory
    for (i = 0; i < size; ++i) {
        free(nameList[i]);
        free(permList[i]);
    }

    return 0;
}
