#include <stdio.h>

int add_numbers(int a, int b);  // function 
void check_prime();


int main()
{

    // function add_numbers call
    int num1, num2, sum;
    printf("Enters two numbers:\n");
    scanf("%d %d", &num1, &num2);
    sum = add_numbers(num1, num2);

    printf("sum = %d", sum);


    // function check_prime call
    // argument is not passed
    check_prime();

    return 0;
}


int add_numbers(int a, int b)
{
    int result;
    result = a + b;
    return result;
}


// return type is void meaning doesn't return any value
void check_prime()
{
    int n, i, flag = 0;

    printf("\nEnter a positive integer: ");
    scanf("%d", &n);

    // 0 and 1 are not prime numbers
    if (n == 0 || n == 1)
    {
        flag = 1;
    }

    for (i = 2; i <= n/2; i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
        printf("%d is not a prime number.", n);
    else
        printf("%d is a prime number.", n);
}