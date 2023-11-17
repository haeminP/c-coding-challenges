#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    double seed_money = 0, target_money = 0, current_money = 0, interest = 0;
    int years = 0;

    printf("Input seed money: ");
    scanf("%lf", &seed_money);

    printf("Input target money: ");
    scanf("%lf", &target_money);

    printf("Input annual interest: "); 
    scanf("%lf", &interest);

    double fund = seed_money;

    while(fund < target_money)
    {
        // fund = fund + fund * interest/100.0;
        fund += fund * interest/100.0;
        years += 1;
        printf("year %d, fund %f\n", years, fund);
    }

    printf("It takes %d years", years);

    return 0;
}