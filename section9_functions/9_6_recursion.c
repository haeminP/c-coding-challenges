#include <stdio.h>

void my_func(int);

int main()
{
    my_func(1);

    return 0;
}

void my_func(int n)
{
    printf("Level %d, address of variable n = %d\n", n, (int)&n);  // ptr -> int casting
                                                                    // 더 직관적으로 이해하기 위함

// TODO: stop condition: stop 조건을 걸어줘야 함

    if(n < 4)
        my_func(n+1);
    
     printf("Level %d, address of variable n = %d\n", n, (int)&n);

}