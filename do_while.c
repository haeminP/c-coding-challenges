#include <stdio.h>

int main()
{

    const int CODE = 789;
    int guess;

    // printf("Enter code: ");
    // scanf("%d", &guess);
    

    // while(guess != CODE)
    // {
    //     printf("Enter code: ");
    //     scanf("%d", &guess);
    // }

    do
    {
        printf("Enter code: ");
        scanf("%d", &guess);
    } 
    while (guess != CODE);
    

    printf("Good! You got the secret code.");

}