#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void PrintArray(int* array, int size);

//Return the first n Fibonacci numbers
int* Fibonacci(int n);

// Return sequence of squares for 1..n (inclusive)
int* Squares(int n);

// Return an array that is copy of array1 followed by the elements of array2
int* Concatenate(int* array1, int size1, int* array2, int size2);

int main(){
    
    int fibn;       // seq of first fibn Fibonacci numbers
                    // Ex: fibn = 5, seq = 0 1 1 2 3
    
    int sqrn;       // number of squares starting with 1
                    // Ex: sqrn = 3, seq = 1 4 9

    scanf("%d %d", &fibn, &sqrn);

    int* fibs;
    int* sqrs;
    int* conc;

    fibs = Fibonacci(fibn);
    PrintArray(fibs, fibn);
    printf("\n");

    sqrs = Squares(sqrn);
    PrintArray(sqrs, sqrn);
    printf("\n");
    
    conc = Concatenate(fibs, fibn, sqrs, sqrn);
    PrintArray(conc, fibn + sqrn);
    printf("\n");

    return 0;

}

void PrintArray(int* array, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", array[i]);
}

//Return the first n Fibonacci numbers
int* Fibonacci(int n)
{
    int i;
    int* fibNums;
    fibNums = (int*)malloc(n * sizeof(int));
    fibNums[0] = 0;
    fibNums[1] = 1;

    for (i = 2; i < n; ++i){
        fibNums[i] = fibNums[i-1] + fibNums[i-2];
    }
    
    return fibNums;
}

// Return sequence of squares for 1..n (inclusive)
int* Squares(int n)
{
    int i;
    int* squareNums;
    squareNums = (int*)malloc(n * sizeof(int));
    
    for (i = 0; i < n; ++i){
        squareNums[i] = pow(i+1, 2);
    }

    return squareNums;
}

// Return an array that is copy of array1 followed by the elements of array2
int* Concatenate(int* array1, int size1, int* array2, int size2){
    int i;
    int j;
    int* newArray;
    int newSize = size1 + size2;
    newArray = (int*)malloc(newSize * sizeof(int));


    for (i = 0; i < size1; ++i){
        newArray[i] = array1[i];
    }

    for (i = size1; i < newSize; ++i){
        newArray[i] = array2[i- size1];
    }

    return newArray;
}