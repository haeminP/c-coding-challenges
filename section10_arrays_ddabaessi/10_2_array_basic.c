#include <stdio.h>
#define MONTHS 12       // symbolic constants, macro

int main()
{

    /* Basic usage */
    int high[MONTHS] = {2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4};

    for (int i = 0; i < MONTHS; ++i)
        printf("%d ", high[i]);
    printf("\n");

    float avg = 0.0;
    for (int i = 0; i < MONTHS; ++i)
        avg += high[i];
    printf("Average = %f\n", avg / (float)MONTHS);


    //  Address
    printf("%p %p\n", high, &high[0]);
    
    for (int i = 0; i < MONTHS; ++i)
        printf("%lld\n", (long long)&high[i]);
    printf("\n");

    /* Compiler doesn't check whether indices are valid: Runtime Error */ 
    // high[12] = 4; // Error
    // high[-1] = 5; // Error
    // 범위를 벗어난 index 값


    /*  Const and array */
    const int temp = 0;
    temp = 4;
    const int low[12] = {-7, -5, 1, 7, 13, 18, 22, 22, 16, 9, 2, -5};
    low[0] = 123;


    /* When array is not initialized */
    int not_init[4];    //TODO: try static (storage class)
    for (int i = 0; i < 4; ++i)
        printf("%d\n", not_init[i])

    
    /* Overly initialized */
    int over[2] = {2, 4, 8, 16};

    /* Omitting size */
    const int power_of_twos[] = {1, 2, 4, 8, 16, 32, 64};
    printf("%d\n", sizeof(power_of_twos));
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(power_of_twos[0]));

    for (int i = 0; i < sizeof power_of_twos / sizeof power_of_twos[0]; ++i)
        printf("%d ", power_of_twos[i]);

    /* Designated initializers */
    int days[MONTHS] = {31, 28, [4] = 31, 30, 31, [1] = 29};
    for (int i = 0; i < MONTHS; ++i)
        printf("%d ", days[i]);

    /* Specifying Array sizes */
    int arr1[MONTHS];   // Symbolic integer constant
    double arr2[123];
    float arr3[3*4 + 1];
    float arr4[sizeof(int) + 1];

    // float arr5[-10]; // No
    // float arr6[0];   // No
    // float arr7[1.5]; // No
    float arr8[(int)1.5];   // Yes

    //int n = 8;
    //float arr9[n];    // Variable-Length Array is optional from C11


    int n = 5;
    float arr[n];
    
    for(int i = 0; i < n; ++i)
        arr[i] = (float)i;







    return 0;
}