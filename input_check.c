#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

long get_long(void);

int main()
{   

    long number;

    while (1)
    {
        printf("Please input an integer between 1 and 100.\n");

        number = get_long();

        if (number > 1 && number < 100)
        {
            printf("OK. Thank you.\n");
            break;
        }    

        else
            printf("Wrong input. Please try again.\n");
    }

    printf("Your input %d is between 1 and 100.", number);

    return 0;

}


long get_long(void)
{
    printf("Please input an integer and press enter.\n");

    long input;
    char c;

    while (scanf("%ld", &input) != 1)
    {
        printf("Your input - ");

        while ((c = getchar()) != '\n')
            putchar(c);     // input left in buffer
                            // 버퍼를 비우면서 사용자가 입력한 내용을 그대로 표시함

        printf(" - is not an integer. Please try again.\n");
    }

    printf("Your input %ld is an integer. Thank you.\n", input);

    return input;
}

