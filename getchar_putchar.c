#include <stdio.h>

int main()
{

    // 1. introduce getchar(), putchar()

    char ch;
    
    // putchar(ch);

    // 2. Use while loop to process character sequences

    // 3. Filter a specific character

    while ((ch = getchar()) != '\n')      // Use '\n' to find the end of a sentence
    {
        if (ch >= 'a' && ch <= 'z') // 'A' = 65, 'a' = 97
            ch -= 'a' - 'A';

        else if (ch >= 'A' && ch <= 'Z')
            ch += 'a' - 'A';


        // if (ch >= '0' && ch <= '9')
        //     ch = '*';
        
        putchar(ch);
    }




    return 0;
}