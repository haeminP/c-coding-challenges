#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int hours, minutes, seconds;

    
    // will need this code in case seconds = -1, 그럼 while문 안에서 한 번은 돌아갈 테니까
    printf("Input seconds: ");
    scanf("%d", &seconds);


    while (seconds >= 0)
    {

        minutes = seconds / 60;
        hours = minutes / 60;
        // minutes = minutes %60;
        minutes %= 60;
        // seconds = seconds % 60;
        seconds %= 60;
        printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);
        printf("Input seconds: ");
        scanf("%d", &seconds);

    }

    printf("Good bye!\n");
    
    return 0;
}