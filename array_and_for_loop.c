#include <stdio.h>
#define SIZE 5
// SIZE를 나중에 한 번에 바꿀 수 있도록 define하기
int main()
{
    int myarr[SIZE];
    int sum = 0;

    printf("Enter %d numbers: \n", SIZE);

    // for 문은 기능별로 나누어서 구현하는 것이 좋음! 
    for (int i = 0; i < SIZE; ++i)
        scanf("%d", &myarr[i]);

    for (int i = 0; i < SIZE; ++i)
            sum += myarr[i];

    printf("Sum = %d", sum);


    return 0;
}