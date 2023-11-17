#include <stdio.h>

int main()
{
    const int NUM_ELEMENTS = 8;
    int user_vals[NUM_ELEMENTS];
    int i, sum_vals;

    // Prompt user to populate array
    printf("Enter %d integer values\n", NUM_ELEMENTS);

    for (i = 0; i < NUM_ELEMENTS; ++i)
    {
        printf("Value: ");
        scanf("%d", &user_vals[i]);
    }

    // Determine sum
    sum_vals = 0;

    for (i = 0; i < NUM_ELEMENTS; ++i)
        sum_vals += user_vals[i];

    printf("Sum: %d", sum_vals);


    return 0;
}