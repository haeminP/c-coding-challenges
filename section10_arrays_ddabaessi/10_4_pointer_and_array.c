#include <stdio.h>

int main()
{
    int arr[10];

    int num = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < num; ++i)
        arr[i] = (i + 1) * 100;

    int *ptr = arr;


    // array 이름은 해당 array 첫 번째 원소의 주소
    printf("%p %p %p\n", ptr, arr, &arr[0]);
    
    ptr += 2;

    printf("%p %p %p\n", ptr, arr + 2, &arr[2]);

    // Note: arr += 2; // invalid

    // dereferencing: 그 주소의 값을 가져와라: 400 400 400
    printf("%d %d %d\n", *(ptr +1), *(arr + 3), arr[3]);

    /* array indexing과 pointer 산술 연산은 서로 바꿔가며 사용 가능 */

    // Warning
    // 괄호가 빠지면 dereferencing을 한 값에 1을 더하는 것: 301 301 400
    printf("%d %d %d\n", *ptr +1, *arr + 3, arr[3]);

    int* ptr = arr;

    for (int i = 0, *ptr = arr; i < num; ++i)
    {
        // 먼저 dereferencing한 후 ;(semi-colon)을 만나면 값이 증가함
        printf("%d %d\n", *ptr++, arr[i]);
        printf("%d %d\n", *(ptr + i), arr[i]);
        printf("%d %d\n", *ptr + i, arr[i]);
    }

    return 0;
}