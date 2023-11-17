#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;
    int lowercase_vowel, uppercase_vowel;
    printf("Enter an alphabet:\n");
    scanf(" %c", &c);

    // evaluates to 1 if variable c is lower case vowel
    lowercase_vowel = ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'));
    
    // evaluates to 1 if variable c is upper case vowel
    uppercase_vowel = ((c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'));


    // show error message if c is not an alphabet
    if(!isalpha)
        printf("Error! Non-alphabetic character");
    if else(c == lowercase_vowel || c == uppercase_vowel)
        printf("%c is a bowel", c);
    else
        printf("%c is a consonant", c);

    return 0;

}