#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    // int i = 0;
    // scanf("%d", &i);
    // printf("Value is %d\n", i);

    // 숫자 두 개 입력 받아 출력하는 프로그램
    int x = 0, y =0;
    int sum = 0;
    printf("Input two integers: \n");

    scanf("%d%d", &x, &y);

    sum = x + y;

    printf("%d + %d = %d\n", x, y, sum);

    // 원을 달러로 바꾸는 계산기
    float won = 0;
    float dollar = 0;

    printf("Input won\n");
    scanf("%f", &won);

    dollar = won * 0.00089f;

    printf("Dollar = %f\n", dollar);
     
    return 0;
}
