#include <stdio.h>


// 정수형(int) 반환자료형은 생략 가능 
// 즉, 반환자료형이 명시되지 않으면 int로 간주

int main()
{
    int i1, i2;

    while (1)
    {
        printf("Input two integers: ");

        if(scanf("%d %d", &i1, &i2) != 2) break;
        int lesser = int_min(i1, i2);
        // int lesser = min;
        printf("The lesser of %d and %d is %d\n", i1, i2, min);

        // 
    }
    return 0;
}

int int_min(int i, int j);
//int_min(int i, int j)
{
    int min;
    if(i < j)
        min = i;
    else
        min = j;

    return min;
}

// return (i < j) ? i: j;

// return (float)min;

/* 
if (i < j)
    return i;
else
    return j;
*/

 // return; // return with no value