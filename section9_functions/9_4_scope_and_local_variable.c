#include <stdio.h>

// int a;       global variable: 파일 전체에서 사용 가능

int int_max(int i, int j);

int int_max(int i, int j)
{
    // a = 456;
    int m;      // 변수의 scope이 한정되는 이유: stack frame
    m = i > j ? i : j;
    return m;
}

int main()
{
    // m = 123;

    int a;
    a = int_max(1, 2);

    printf("%d\n", a);
    printf("%p\n", &a);

    {
        int a;
        a = int_max(4, 5);

        printf("%d\n", a);
        printf("%p\n", &a);

        int b = 123;

    }

    printf("%d\n", a);
    printf("%p\n", &a);
}