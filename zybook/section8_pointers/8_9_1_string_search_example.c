#include <stdio.h>
#include <string.h>

int main() {

    const int MAX_USER_INPUT = 100;
    char userInput[MAX_USER_INPUT];
    char* stringPos = NULL;

    // Prompt user for input
    printf("Enter a line of text: ");
    fgets(userInput, MAX_USER_INPUT, stdin);

    // Locate exclamation point, replace with period
    stringPos = strchr(userInput, '!');
    if (stringPos != NULL) {
        *stringPos = '.';
    }

    // Locate "Boo" and replace with "---"
    stringPos = strstr(userInput, "Boo");
    
    if (stringPos != NULL) {
        strncpy(stringPos, "---", 3);     
    }

    // Outputs modified string
    printf("Censored: %s\n", userInput);

    /* strchr and while loop */
    char userString[50];
    char* stringPointer = NULL;

    strcpy(userString, "I.love.to.code!");

    stringPointer = strchr(userString, '.');
    while (stringPointer != NULL) {
      *stringPointer = ' ';
    stringPointer = strchr(userString, '.');
    }

    printf("%s\n", userString); // output: "I love to code!"

    return 0;
}