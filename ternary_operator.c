#include <stdio.h>
#include <stdbool.h>

int main()
{
    int number;
    scanf("%d", &number);


    bool is_even;

    is_even = (number % 2 == 0) ? true : false;

    //const bool is_even = (number % 2 == 0) ? true : false;
    
    if (is_even)
        printf("Even");
    else
        printf("Odd");

    //     (number % 2 == 0) ?  printf("Even") : printf("odd");


    // int a = 1, b = 2;
    // int max = (a > b) ? a : b;


    return 0;
}