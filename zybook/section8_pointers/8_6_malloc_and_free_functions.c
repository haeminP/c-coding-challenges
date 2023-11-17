#include <stdio.h>
#include <stdlib.h>

int main() {

    int* myPtr = NULL;

    printf("myPtr: %p\n", (void*) myPtr);
    // printf("myPtr: %d\n", *myPtr);   // Error - myPtr is null


    myPtr = (int*) malloc(sizeof(int));
    printf("myPtr: %p\n", (void*) myPtr);

    *myPtr = 555;
    printf("*myPtr: %d\n", *myPtr);


    // how malloc/free function works

    int* numPtr1 = NULL;
    int* numPtr2 = NULL;

    numPtr1 = (int*) malloc(sizeof(int));
    numPtr2 = (int*) malloc(sizeof(int));

    scanf("%d", numPtr1);
    scanf("%d", numPtr2);

    printf("numPtr1 = %d, numPtr2 = %d\n", *numPtr1, *numPtr2);

    free(numPtr1);
    free(numPtr2);

    return 0;
}