#include <stdio.h>

int main(){

    int arr[5] = {100, 200, 300, 400, 500};
    int *ptr1, *ptr2, *ptr3;

    int i;
    ptr1 = arr;     // Assignment: arr[]'s address will be assigned to ptr1

    printf("%p %d %p\n", ptr1, *ptr1, &ptr1); // dereferencing, Taking pointer address
                                              // you can also check pointer variable's address

    ptr2 = &arr[2]; // Address-of operator &, third element of the array
    printf("%p %d %p\n", ptr2, *ptr2, &ptr2);
    

    ptr3 = ptr1 + 4;    // 4바이트 짜리가 4개 저장될 수 있는 공간만큼 더한다
    printf("%p %d %p\n", ptr3, *ptr3, &ptr3);

    // Differencing
    printf("%td\n", ptr3 - ptr1);       // Note: t is for pointer difference

    ptr3 = ptr3 - 4;        // Subtracting 4 integers' size from a pointer

    printf("%p %d %p\n", ptr3, *ptr3, &ptr3);

    ptr1++;     // Incrementing, ptr1 = ptr1 +1
    ptr1--;     // Decrementing
    --ptr1;
    ++ptr1;

    if (ptr1 == ptr3)
        printf("Same\n");
    else
        printf("Difference\n");

    double d = 3.14;
    double* ptr_d = &d;         // double과 int 형의 사이즈는 동일하다 따라서 비교 가능

    if (ptr1 == (int*)ptr_d)
        printf("Same\n");       // warning C4133 '==': incompatible types: 단, casting하면 warning이 사라짐
    else
        printf("Difference\n");

    return 0;
}