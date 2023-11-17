#include <stdio.h>

int main()
{
    const int NUM_ELEMENTS = 8;
    int user_vals[NUM_ELEMENTS];
    int copied_vals[NUM_ELEMENTS];
    int i;

    printf("Enter %d integers...\n", NUM_ELEMENTS);

    for (i = 0; i < NUM_ELEMENTS; ++i)
    {
        printf("Value: ");
        scanf("%d", &user_vals[i]);
    }

    // copy user_vals to copied_vals array
    // and if there's negative value in copied_vals, change it to 0
    for (i = 0; i < NUM_ELEMENTS; ++i)
    {
        copied_vals[i] = user_vals[i];
        if (copied_vals[i] < 0)
            copied_vals[i] = 0;
    }

    printf("Original and new values:\n");
    for (i = 0; i < NUM_ELEMENTS; ++i)
        printf("%d became %d\n", user_vals[i], copied_vals[i]);
    

    
    // for (i = 0; i < NUM_ELEMENTS; ++i)
    // {
    //     printf("Value: ");
    //     scanf("%d", &user_vals[i]);

    //     if (user_vals[i] < 0)
    //         user_vals[i] = 0;
    // }

    // printf("New numbers: ");

    // for (i = 0; i < NUM_ELEMENTS; ++i)
    //     printf("%d ", user_vals[i]);

    return 0;
}