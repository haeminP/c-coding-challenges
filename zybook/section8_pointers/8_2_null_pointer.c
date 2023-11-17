#include <stdio.h>


void PrintValue(int* valPointer){

    if (valPointer == NULL){
        printf("Pointer is null\n");
    }

    else{
        printf("%d\n", *valPointer);
    }

}


int main(){

    int someInt = 5;
    int* valPointer = NULL;

    PrintValue(valPointer);
    valPointer = &someInt;
    PrintValue(valPointer);

    return 0;
}