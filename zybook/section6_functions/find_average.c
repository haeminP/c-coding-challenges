#include <stdio.h>

double compute_average(int num_count);


int main()
{
    int num_values;
    double average_val;

    printf("Enter number of values: ");
    scanf("%d", &num_values);
    average_val = compute_average(num_values);

    printf("Average: ");
    printf("%.3f\n", average_val);
    
    return 0;
}

double compute_average(int num_count)
{
    double sum = 0;
    int curr_value = 0;

    for (int i = 0; i < num_count; ++i)
    {
        printf("Enter number: ");
        scanf("%d", &curr_value);
        sum += curr_value;
    }

    return sum / num_count;
}