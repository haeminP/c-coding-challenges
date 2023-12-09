#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){

    const int USER_TEXT_LIMIT = 1000;   // Limit input size
    char userText[USER_TEXT_LIMIT];     // Hold input
    char firstName[50];
    char lastName[50];
    int userAge;
    int valuesRead;
    bool inputDone;     // Flag to indicate next iteration

    inputDone = false;

    // Prompt user for input
    printf("Enter \"firstname lastname age\" on each line\n");
    printf("(\"Exit\" as firstname exits.)\n\n");

    // Grab data as long as "Exit" is not entered
    while (!inputDone) {

        // Grab entire line, store in userText
        // By using fgets(), null character will be written to the end of the string read.
        fgets(userText, USER_TEXT_LIMIT, stdin);

        // Parse the line and check for correct number of entries
        // width specifiers (%49s and %d) is to prevent buffer overflow
        // By specifying the maximum number of characters to read
        // the input does not exceed the size of the destination arrays 
        valuesRead = sscanf(userText, "%49s %49s %d", firstName, lastName, &userAge);
        if (valuesRead >= 1 && strcmp(firstName, "Exit") == 0){
            printf("Exiting.\n");
            inputDone = true;
        }

        else if (valuesRead == 3){
            printf("   First name: %s\n", firstName);
            printf("   Last name: %s\n", lastName);
            printf("\n");
        }

        else {
            printf("Invalid entry. Please try again.\n\n");
        }
    }

    return 0;
}