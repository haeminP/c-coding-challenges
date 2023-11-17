#include <stdio.h>
#include <math.h>

/*
    decimal to binary
    10
    10 / 2 = 5, remainder = 0
    5 / 2 = 2, remainder = 1
    2 / 2 = 1, remainder = 0
    1 / 2 = 0, remainder = 1
*/

void print_binary(unsigned long n);
void print_binary_loop(unsigned long n);

int main()
{

    int num = 10;

    print_binary_loop(num);
    print_binary(num);
    printf("\n");

    // int decimal_num = 10;
    // int binary_num = 0, i = 1, remainder;
    // while (decimal_num != 0)
    // {
    //     remainder = decimal_num % 2;
    //     decimal_num /= 2;
    //     binary_num += remainder * i;
    //     i *= 10;

    //     printf("Binary number: %d\n", binary_num);
    // }

    return 0;
}


/*
remainders = 
1   0   1   0
[0] [1] [2] [3]


1 * 2 ^ 3
0 * 2 ^ 2


*/


// Note: printing order is reversed!
void print_binary_loop(unsigned long num)
{
    while (1)
    {
        int quotient = num / 2;
        int remainder = num % 2;

        printf("%d", remainder);    // remainder is 0 or 1

        num = quotient;

        if (num == 0) break;
    }

    printf("\n");
}



void print_binary(unsigned long num)
{
    int remainder = num % 2;
    if (num >= 2)
        print_binary (num / 2);
    printf("%d", remainder);

    return;
}