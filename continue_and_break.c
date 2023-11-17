#include <stdio.h>

int main()
{


    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 5)
                break;
            
            printf("(%d %d)", i, j);
        }

        printf("\n");
    }

    int count = 0;
    while (count < 5)
    {
        int c = getchar();
        if (c == 'a')
            continue;
        putchar(c);
        count++;
    }
    printf("%d", count);



    // break example

    // char ch;
    // while ((ch = getchar()) != '.')
    //     {
    //         putchar(ch);
    //     }

    while (1)
    {
        char ch = getchar();
        if (ch == '.')
            break;

        putchar(ch);
    }

    return 0;
}