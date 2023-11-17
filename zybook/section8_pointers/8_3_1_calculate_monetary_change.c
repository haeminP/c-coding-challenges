#include <stdio.h>
void ComputeChange(int totalCents, int* numQuarters, int* dimes, int* nickels, int* pennies){
    *numQuarters = totalCents / 25;
    totalCents %= 25;
    
    *dimes = totalCents / 10;
    totalCents %= 10;
    
    *nickels = totalCents / 2;
    totalCents %= 2;
    
    *pennies = totalCents;
}


int main(){

    int userCents;
    int numQuarters;
    int dimes;
    int nickels;
    int pennies;

    printf("Enter total cents: \n");
    scanf("%d", &userCents);

    ComputeChange(userCents, &numQuarters, &dimes, &nickels, &pennies);

    printf("Quarters: %d\n", numQuarters);
    printf("Dimes: %d\n", dimes);
    printf("Nickels: %d\n", nickels);
    printf("Pennies: %d\n", dimes);

    return 0;
}