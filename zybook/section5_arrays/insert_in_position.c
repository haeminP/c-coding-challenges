#include <stdio.h>

int main()
{
    int arr[100] = {0};
    int i, x, pos, n = 10;

    // populate the original array and print it
    printf("The original array: ");
    for (i = 0; i < n; ++i)
        {
            arr[i] = i + 1;        
            printf("%d ", arr[i]);
        }

    // get a number to insert and position
    printf("\nWhat number do you want to insert? ");
    scanf("%d", &x);
    printf("Which position do you want to put the number in? ");
    scanf("%d", &pos);

    // increase the array size
    n++;

    // change the values in the array to the right
    // as long as the index is bigger than position

    for (i = n-1; i > pos-1; --i)
        {
            arr[i] = arr[i-1];
        }

    // insert the new number in the position
    arr[pos - 1] = x;

    
    // print the new array
    printf("The new array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    






    return 0;
}