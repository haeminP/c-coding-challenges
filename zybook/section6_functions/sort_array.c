#include <stdio.h>

void swap_array_ends(int sort_array[], int num_vals);


int main()
{
    const int ARRAY_SIZE = 4;
    int sort_array[ARRAY_SIZE];
    int i;
    int user_num;

    for (i = 0; i < ARRAY_SIZE; ++i)
    {
        scanf("%d", &sort_array[i]);
    }

    swap_array_ends(sort_array, ARRAY_SIZE);

    for (i = 0; i < ARRAY_SIZE; ++i)
    {
        printf("%d ", sort_array[i]);
    }

    return 0;
}

void swap_array_ends(int sort_array[], int num_vals)
{
    int temp_val;
    temp_val = sort_array[0];
    sort_array[0] = sort_array[num_vals - 1];
    sort_array[num_vals - 1] = temp_val;
}
