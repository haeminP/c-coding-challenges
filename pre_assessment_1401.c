#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void insert(int a1[], int a2[], int a3[], int size);

int main()
{
    // Prompt user to input a size of the array
        srand(time(NULL));
    int user_input;
    int i;
    printf("Please enter a positive integer number (Zero to exit): ");
    scanf("%d", &user_input);


    int first_array[user_input];
    int second_array[user_input];
    int third_array[user_input];

    // populate the first array
    for (i = 0; i < user_input; ++i)
    {   
        first_array[i] = i;
    }

    printf("Array to insert: [ ");
    for (i = 0; i < user_input; ++i)
    {   
        printf("%d ", first_array[i]);
    }

    printf("]\n");

    // populate the second array
    second_array[0] = 0;

    for (i = 1; i < user_input; ++i)
    {
        second_array[i] = rand() % i;
    }

    for (i = 0; i < user_input; ++i)
        printf("%d ", second_array[i]);


    // call function insert
    insert(first_array, second_array, third_array, user_input);

    // third array:
    printf("\nthird array:\n");

    for (i = 0; i < user_input; ++i)
        printf("%d ", third_array[i]);


    return 0;

}


void insert(int a1[], int a2[], int a3[], int size)
{


}