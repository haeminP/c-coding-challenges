#include <stdio.h>
#include <math.h>

int square_number(int y);


int main()
{   
    // int num;
    // printf("Enter a number:\n");
    // scanf("%d", &num);
    // printf("The square number: %d", square_number(num));

    for (int x = 1; x <= 10; ++x)
    {
        printf("%d ", square_number(x));
    }

    return 0;
}

int square_number(int y)
{
    return y*y;
}