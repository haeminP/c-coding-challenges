#include <stdio.h>
#include <math.h>

float find_max_abs_value(const float input_vals[], int num_vals);

int main() 
{
    const int NUM_VALUES = 5;

   // Array of changes in temperatures
    float temp_changes[5] = {10.0, 0.5, -5.1, -11.2, 3.0};
    float max_abs_change;
    int i;

   // Print array before function call
    printf("tempChanges array before function call: ");
    
    for(i = 0; i < NUM_VALUES; ++i)
        printf("%f ", temp_changes[i]);
    printf("\n");

   // Find the largest temperature change, and print result.
    max_abs_change = find_max_abs_value(temp_changes, NUM_VALUES);
    printf("Max absolute temperature change: %f\n", max_abs_change);

   // Print array after function call
    printf("tempChanges array after function call:  ");
    for(i = 0; i < NUM_VALUES; ++i)
        printf("%f ", temp_changes[i]);
    printf("\n");

    return 0;
}

float find_max_abs_value(const float input_vals[], int num_vals) 
{
    int i;
    float max_abs_val;
    float input_abs_val;

    max_abs_val = fabs(input_vals[0]);

    for (i = 0; i < num_vals; ++i) 
    {
        input_abs_val = fabs(input_vals[i]);
        if (input_abs_val > max_abs_val)
            max_abs_val = input_abs_val;
    }

    return max_abs_val;
}