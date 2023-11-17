#include <stdio.h>

int main()
{
    char first_char, current_char, last_char;
    int repetition;

    first_char = 'A';
    // char second_char = first_char + 1;
    // char third_char = second_char + 1;

    // printf("%c %c %c", first_char, second_char, third_char);

    printf("Enter the last character: ");
    scanf(" %c", &last_char);

    printf("Enter number of repetition: ");
    scanf("%d", &repetition);


    // for(int i = 0; i <= repetition; ++i)   
    // {
    //     for(current_char = first_char; current_char <= last_char; ++current_char)
    //         printf("%c ", current_char);
    //     printf("\n");
    // }


    
    for(int i = 0; i <= repetition; ++i)   
    {
        for(current_char = first_char; current_char <= first_char + i; ++current_char)
            printf("%c ", current_char);
        printf("\n");
    }

        
    // for(int i = 0; i <= repetition; ++i)   
    // {
    //     for(current_char = first_char; current_char <= last_char - i; ++current_char)
    //         printf("%c ", current_char);
    //     printf("\n");
    // }



    return 0;
}