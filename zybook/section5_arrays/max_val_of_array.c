#include <stdio.h>

int main()
{
    const int NUM_ELEMENTS = 8;
    int user_vals[NUM_ELEMENTS];

    int i;
    int max_val;

    printf("Enter %d integers\n", NUM_ELEMENTS);

    for(i = 0; i < NUM_ELEMENTS; ++i)
        {
            printf("Value: ");
            scanf("%d", &user_vals[i]);
        }


    // Determine the largest (max) number
    max_val = user_vals[0]; // largest so far

    for(i = 0; i < NUM_ELEMENTS; ++i)
        {
            if (max_val <= user_vals[i])
                max_val = user_vals[i];
        }

    printf("The max value in the array is %d", max_val);

    return 0;
}