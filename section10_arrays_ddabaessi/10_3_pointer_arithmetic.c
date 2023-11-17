#include <stdio.h>

int main()
{
    int* ptr = 0;   // try double*, long long*, char*, void*

    printf("%p %lld\n", ptr, (long long)ptr);


    // 포인터에 1을 더하는 것은 자료형의 사이즈만큼 더하는 것
    // int 8, char 1, double 8, long long 8
    ptr ++; // try -=, ++, --, -, +


    printf("%p %lld\n", ptr, (long long)ptr);

    //ptr = -ptr;   // Not working
    //ptr = +ptr;   // Not working

    /* Subtraction */
    double arr[10];
    double *ptr1 = &arr[3], *ptr2 = &arr[5];

    // ptr2 = ptr1 + ptr2;      // Not working: 철수 우편번호+영희 우편번호 = 의미없는 값
    int i = ptr2 - ptr1;     // Meaning? 철수 303호 - 영희 301호 = 두 집 차이라는 의미
                             // 차이를 이용할 수 있는 경우가 있음!

    printf("%p %p %d\n", ptr1, ptr2, i);    // i에 들어가는 값은 arr[5] - arr[3]
                                            // 즉, 배열 안에서 몇 칸 떨어져 있는지 (자료형 사이즈 기준)                               

    return 0;
}