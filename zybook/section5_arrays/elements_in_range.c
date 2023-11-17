#include <stdio.h>

int main()
{
    int num_elements;
    int numbers[20];
    int lower_bound, upper_bound;
    int i;

    scanf("%d", &num_elements);

    for (i = 0; i < num_elements; ++i)
        scanf("%d", &numbers[i]);
    
    scanf("%d", &lower_bound);
    scanf("%d", &upper_bound);


    for (i = 0; i < num_elements; ++i)
        {
            if (numbers[i] >= lower_bound && numbers[i] <= upper_bound)
                printf("%d, ", numbers[i]);
        }
    printf("\n");
    
    

    return 0;

}