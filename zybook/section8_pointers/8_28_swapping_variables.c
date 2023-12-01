#include <stdio.h>

void SwapValues(int* userVal1, int* userVal2, int* userVal3, int* userVal4){
    int temp;

    temp = *userVal1;
    *userVal1 = *userVal2;
    *userVal2 = temp;

    temp = *userVal3;
    *userVal3 = *userVal4;
    *userVal4 = temp;
}

int main(){

    int num1, num2, num3, num4;
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    SwapValues(&num1, &num2, &num3, &num4);

    printf("%d %d %d %d", num1, num2, num3, num4);

    return 0;
}