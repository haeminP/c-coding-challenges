#include <string.h>
#include <stdio.h>

int main () {
    char str[] = "This is a test, to show: how to tokenize a string with some delimiters.";
    const char* delimiters = " .,-:";
    char* token;
    char words[14][20];

    printf( "Source String = %s\n", str);

   /* Get the first token, if any. */
    token = strtok(str, delimiters);


   /* Get the rest of the tokens, if any. */
    int num = 0;
    while( token != NULL ) {
        strcpy(words[num++], token);
        token = strtok(NULL, delimiters);
    }

    for (int i = 0; i < 14; ++i)
        printf("%s\n", words[i]);

    // how to keep only the unique words?

    // Test string: This is a test, to test text processing using a C program to tokenize a test and show the list of unique words, frequency of unique words, and count of the words.
    // How to check the the number of unique words inside the test
    // The frequency of every unique word



    return(0);
}