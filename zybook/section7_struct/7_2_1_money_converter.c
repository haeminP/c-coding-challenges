#include <stdio.h>

typedef struct MonetaryChange_struct {
    int quarters;    // 25
    int dimes;       // 10
    int nickels;     // 5
    int pennies;       // 1

} MonetaryChange;

MonetaryChange ComputeChange(int cents)
{
    MonetaryChange change;

    change.quarters = cents / 25;
    cents %= 25;
    change.dimes =  cents / 10;
    cents %= 10;
    change.nickels = cents / 5;
    cents %= 5;
    change.pennies = cents;

    return change;

}

int main(void) 
{
    int userCents;
    MonetaryChange change;

    printf("Enter cents: \n");
    scanf("%d", &userCents);

    change = ComputeChange(userCents);

    printf("Quarters: %d\n", change.quarters);
    printf("Dimes: %d\n", change.dimes);
    printf("Nickels: %d\n", change.nickels);
    printf("Pennies: %d\n", change.pennies);
    
   return 0;
}