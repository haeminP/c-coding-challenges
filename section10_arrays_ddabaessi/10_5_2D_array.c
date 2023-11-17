#include <stdio.h>

int main()
{
    // 3개짜리가 2개 있다
    int arr[2][3] = {{1, 2, 3},
                     {4, 5, 6}};


    // int arr[2][3] = {1, 2, 3
    //                  4, 5, 6};

    // int arr[2][3] = {1, 2};  // insufficient initializer, 나머지는 0으로 채워짐

    int *ptr = &arr[0][0];
    for (int k = 0; k < 6; ++k)
        printf("%d ", ptr[k]);
    printf("\n\n");

    // arr[0]는 3개가 들어있는 한 줄의 크기: 4 bytes x 3 = 12
    printf("%zd %zd\n", sizeof(arr), sizeof(arr[0]));






    return 0;    
}