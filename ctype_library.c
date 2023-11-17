#include <stdio.h>
#include <ctype.h>

int main()
{

    char ch;

    while ((ch = getchar()) != '\n')
    {
        if (islower(ch))
            ch = toupper(ch);

        else if (isupper(ch))
            ch = tolower(ch);
        
        if(isdigit(ch))
            ch = '*';

        putchar(ch);

    }

    return 0;
    
}