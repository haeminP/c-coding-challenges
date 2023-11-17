#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char nameArr[100];              // User specific name
    char* greetingPtr = NULL;       // Pointer to output greeting and name

    // Prompt user to enter a name
    printf("Enter name: ");
    fgets(nameArr, 100, stdin);

    // Eliminate end-of-line char
    nameArr[strlen(nameArr) - 1] = '\0';

    // Dynamically allocate greeting, 8 for "Hello", " ", ".", "\0"
    greetingPtr = (char*) malloc((strlen(nameArr) + 8) * sizeof(char));

    // Modifying string, hello + user specified name
    strcpy(greetingPtr, "Hello ");
    strcat(greetingPtr, nameArr);
    strcat(greetingPtr, ".");

    // Output greeting and name
    printf("%s\n", greetingPtr);

    free(greetingPtr);

    return 0;
}