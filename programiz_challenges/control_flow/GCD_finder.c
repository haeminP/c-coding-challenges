#include <stdio.h>

int main()
{

    /*
    Method 1:
    48  =  2 * 2 * 2 * 2 * 3
    18  =  2 * 3 * 3

    */

    int n1, n2, gcd;
    printf("Enter two integers: ");
    scanf("%d %d", &n1, &n2);

    // gcd should be equal or smaller than the dividend
    // as long as the divisor is smaller than both nums, for loop goes on
    for (int i = 2; i <= n1 && i <= n2; ++i)
        {
            // check if the divisor is factor of both integer
            if ((n1 % i) == 0 && (n2 % i) == 0)
                gcd = i;
        }
    
    printf("The GCD of %d and %d is %d", n1, n2, gcd);  




    /* 
    Method 2:
    Euclid's algorithm
    common divisor of a and b (a > b) = common divisor of a-b and b
    */
    
    // int n1, n2;
    // printf("Enter two integers: ");
    // scanf("%d %d", &n1, &n2);


    // // check if the numbers are positive. if negative, change it to positive by adding - sign.
    // n1 = (n1 > 0) ? n1 : -n1;
    // n2 = (n2 > 0) ? n2 : -n2;    

    // while (n1 != n2)
    // {
    //     if (n1 > n2)
    //         n1 -= n2;

    //     else
    //         n2 -= n1;
    // }

    // printf("The GCD is %d", n1);


    return 0;

}