#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void say_hello(void)
{
    printf("Hello, world!\n");

    return;
}

int main()
{
    int x;  // declaration
    int y;
    int z;

    x = 1;   // assignment
    y = 2;
    z = 2;

    z = x + y;
    printf("The answer is %d\n", z);

    int i = 0;
    scanf("%d", &i);
    printf("Value is %d\n", i);

    say_hello();



    return 0;
    // return 다음에 일어나는 일들은 무시됨
    // 이미 compiler에게 return의 결과를 보냈기 때문
}

