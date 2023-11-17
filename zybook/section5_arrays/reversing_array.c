#include <stdio.h>

int main()
{
    const int NUM_ELEMENTS = 8;
    int user_vals[NUM_ELEMENTS];
    int i, temp_val;

    // Prompt user to enter values
    printf("Enter %d integer values...\n", NUM_ELEMENTS);
    for (i = 0; i < NUM_ELEMENTS; ++i)
    {
        printf("Values: ");
        scanf("%d", &user_vals[i]);
    }

    // Reverse array's elements
    // The iteration should only go until the half the array
    // Otherwise, the swap will happen twice, the array will go back to the original array
    for (i = 0; i < NUM_ELEMENTS / 2; ++i)
    {
        temp_val = user_vals[i];
        user_vals[i] = user_vals[NUM_ELEMENTS - 1- i];
        user_vals[NUM_ELEMENTS - 1- i] = temp_val;
    }

    printf("New values:\n");

    for (i = 0; i < NUM_ELEMENTS; ++i)
        printf("%d ", user_vals[i]);

    return 0;
}