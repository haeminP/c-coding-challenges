#include <stdio.h>

#define MONTHS 12
#define YEARS 3

/*
1. Use 2D array
2. Print data
3. Calculate and print yearly average temperature of 3 years
4. Calculate and print monthly average temperature of 3 years
*/

int main()
{
    // double year2016[MONTHS] = {-3.2, -0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2};
    // double year2017[MONTHS] = {-1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9};
    // double year2018[MONTHS] = {-4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.3, 27.8, 21.5, 13.1, 7.8, -0.6};


    double temp_data[YEARS][MONTHS] = {
        {-3.2, -0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2},
        {-1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9},
        {-4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.3, 27.8, 21.5, 13.1, 7.8, -0.6}
    };


    /* Step 2*/
    int i, j;
    // Print data
    printf("[Temperature Data]");
    printf("\nYear index\t:");
    for(i = 0; i < MONTHS; ++i)
        printf("%7d", i+1);

    for(i = 0; i < YEARS; ++i)
    {
        printf("\nYear %d\t\t:", i);
        for (j = 0; j < MONTHS; ++j)
            printf("%7.1lf", temp_data[i][j]);
    }

    // Calculate average and display
    printf("\n[Yearly average temperature of 3 years]");
    for (i = 0; i < YEARS; ++i)
    {
        double total = 0.0;
        printf("\nYear %d\t:", i);

        for (j = 0; j < MONTHS; ++j)
            total += temp_data[i][j]; 

        printf("average temperature = %.1lf", total / MONTHS);
    }

    // Calculate monthly average and display
    printf("\n[Monthly average temperature for 3 years]");
    printf("\n%-15s", "Year index\t:");

    for (i = 0; i < MONTHS; ++i)
        printf("\t%d", i+1);
    
    printf("\n%-15s", "Avg temp\t:");

    for (i = 0; i < MONTHS; ++i)
        {
            double total = 0.0;
            for (j = 0; j < YEARS; ++j)
                total += temp_data[j][i];
            
            printf("\t%.1lf", total / YEARS);
        }


    return 0;

}