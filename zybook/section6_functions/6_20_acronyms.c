#include <stdio.h>
#include <string.h>
#include <ctype.h>

void CreateAcronym(char userPhrase[], char userAcronym[]);


int main()
{
    char userInput[50];
    char acronym[8];
    int i;

    fgets(userInput, 50, stdin);

    CreateAcronym(userInput, acronym);


    for (i = 0; acronym[i] != '\0'; ++i)
        printf("%c", acronym[i]);
    printf("\n");

    return 0;
    
}

void CreateAcronym(char userPhrase[], char userAcronym[])
{
    char* token;
    int i = 0;

    // tokenize the string into words
    // check if the first letter of each word is capital character
    // and put them in array of first letters to make acronyms

    token = strtok(userPhrase, " ");

    while (token != NULL)
    {   
        if(isupper(token[0]))
        {
            userAcronym[i] = token[0];
            ++i;
            userAcronym[i] = '.';
            ++i;
        }

        token = strtok(NULL, " ");
    }

    userAcronym[i] = '\0';  // Terminate the acronym string
}