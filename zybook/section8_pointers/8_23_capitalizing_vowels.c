#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Return a newly allocated copy of original
// with the first occurrence of each vowel capitalized
char* CapVowels(char* original){
    char* subString = NULL;
    char* result;

    result = (char*)malloc(strlen(original)*sizeof(char));
    strcpy(result, original);

    if(strchr(result, 'a') != NULL){
        subString = strchr(result, 'a');
        *subString = 'A';
    }

    if(strchr(result, 'e') != NULL){
        subString = strchr(result, 'e');
        *subString = 'E';
    }

    if(strchr(result, 'i') != NULL){
        subString = strchr(result, 'i');
        *subString = 'I';
    }


    if(strchr(result, 'o') != NULL){
        subString = strchr(result, 'o');
        *subString = 'O';
    }

    if(strchr(result, 'u') != NULL){
        subString = strchr(result, 'u');
        *subString = 'U';
    }

    return result;
}

int main(void){
    char userCaption[50];
    char* resultStr;
    scanf("%s", userCaption);

    resultStr = CapVowels(userCaption);

    printf("Original: %s\n", userCaption);
    printf("Modified: %s\n", resultStr);

    // Always free dynamically allocated memory when no longer needed
    free(resultStr);

    return 0;
}
