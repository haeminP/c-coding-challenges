#include <stdio.h>

int main()
{

    int i, n;
    int fibonacci[30];

    printf("Enter a number: ");
    scanf("%d", &n);

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (i = 2; i <= n; ++i)
    {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }

    printf("The Fibonacci sequence: ");

    for (i = 0; i <= n; ++i)
        printf("%d, ", fibonacci[i]);



    return 0;
}

