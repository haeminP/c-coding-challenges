#include <stdio.h>
#include <stdbool.h>

int main()
{
    const int NUM_ELEMENTS = 14;

    // Weights in ounces
    double letter_weights[14] = {1.0, 2.0, 3.0, 3.5, 4.0, 5.0, 6.0,
                               7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0};
    // Costs in cents (usps.com 2017)
    int postage_costs[14] = {49, 70, 91, 112, 161, 182, 203,
                           224, 245, 266, 287, 308, 329, 350};
    
    double user_letter_weight;
    bool found_weight;
    int i;
    
    // Prompt user to enter letter weight
    printf("Enter letter weight (in ounces): ");
    scanf("%lf", &user_letter_weight);
    
    found_weight = false;
    // Postage costs is based on smallest letter weight
    // greater than or equal to mailing letter weight
    for (i = 0; (i < NUM_ELEMENTS) && (!found_weight); ++i)
    {
        if (user_letter_weight <= letter_weights[i])
        {
            found_weight = true;
            printf("Postage cost is %d cents\n", postage_costs[i]);
        }
    }

    // in case the given letter weight is too heavy
    if (!found_weight)
        printf("Letter is too heavy for USPS mail.\n");

        return 0;
}