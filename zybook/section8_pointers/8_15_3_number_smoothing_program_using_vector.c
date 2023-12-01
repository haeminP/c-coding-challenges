#include <stdio.h>
#include "vector.h"
#include "vector.c"


// Get number from user
void GetNums(vector* nums)
{
    int numSize;
    int i;

    printf("Enter number of integers to be entered: ");
    scanf("%d", &numSize);

    vector_resize(nums, numSize);

    for (i = 0; i < numSize; ++i){
        printf("%d: ", i+1);
        scanf("%d", vector_at(nums, i));
    }
}

// Smooths by setting element to average of itself and next two elements
void FilterNums(vector* nums)
{
    int i;

    for (i = 0; i < vector_size(nums) - 2; ++i){
        *vector_at(nums, i) = (*vector_at(nums, i) +
                                *vector_at(nums, i+1) +
                                *vector_at(nums, i+2)) / 3;
    }

    *vector_at(nums, i) = (*vector_at(nums, i) +
                           *vector_at(nums, i+1)) / 2;

    // last element need no averaging
}

// Print all elements within the vector
void PrintsNums(vector* nums)
{
    int i;
    printf("Numbers: ");
    for (i = 0; i < vector_size(nums); ++i){
        printf("%d ", *vector_at(nums, i));
    }
    printf("\n");
}

int main(){
    vector nums;

    vector_create(&nums, 0);
    
    GetNums(&nums);
    PrintsNums(&nums);
    FilterNums(&nums);
    PrintsNums(&nums);

    vector_destroy(&nums);

    return 0;
}