#include <stdio.h>

int main()
{

    int input, sum = 0;
    int status;


    printf("Enter an integer (q to quit): ");
    status = scanf(" %d", &input);      // return value of scanf()
                                        // 즉, 정수인 경우 1, 정수가 아니면 0

    while(status == 1)
    {   
        sum += input;

        printf("Enter an integer (q to quit): ");
        status = scanf(" %d", &input);
    }
    
    printf("Sum = %d", sum);
    
    return 0;
}