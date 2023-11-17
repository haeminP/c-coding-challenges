#include <stdio.h>

int main()
{
    // 1000 50 0.03
    // after one month: 1000 (1+0.03) = 1030 
    // curr_balance = 1030 - 50 = 980
    // after two month: 980 (1 + 0.03) = 1009.4


    double balance = 0.0;
    double payment = 0.0;
    double rate = 0.0;
    int payment_count = 0;

    // prompt user to enter input
    printf("Enter loan, monthly payment and interest rate: ");
    scanf("%lf %lf %lf", &balance, &payment, &rate);

    balance *= (1 + rate);

    while (balance >= 0)
    {
        balance = (balance - payment) * (1 + rate);
        ++ payment_count;
    }

    printf("%d payment", payment_count);


    return 0;
}