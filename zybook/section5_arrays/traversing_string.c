#include <stdio.h>

int main()
{
    char user_str[20] = "1234567890123456789";   // Input string
    int i;

    // Prompt user for string input

    printf("Enter string (<20 chars): ");
    scanf("%s", user_str);

    // Print string
    printf("\n%s\n", user_str);

    // Look for '@'
    // loop stops when it reaches the null character
    for (i = 0; user_str[i] != '\0'; ++i)
    {
        if (user_str[i] == '@')
            printf("Found '@'\n");
    }



    return 0;
}