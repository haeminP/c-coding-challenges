#include <stdio.h>
int compute_pow(int base, int exp);     // prototype

int main()
{
    // 3 4
    // 3*3*3*3 = 81

    int base, exp, result;
    while (scanf("%d %d", &base, &exp) == 2)
    {

    result = compute_pow(base, exp);
    printf("Result = %d\n", result); 

    }

    return 0;

}


int compute_pow(int base, int exp)
{
    // main 함수에서 선언된 i & result는 scope 밖의 변수이므로
    // 이 함수에서는 사용할 수 없다
    // 따라서 별도로 선언이 필요함
    int i, result;

    result = 1;
    for(i = 0; i < exp; ++i)
        result *= base;

    return result;
}
