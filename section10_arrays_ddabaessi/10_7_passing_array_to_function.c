#include <stdio.h>


// 함수를 선언하는 방법

/*
double calculate_ avg(double *arr, int n);
double calculate_ avg(double *, int n);
double calculate_ avg(double arr[], int n);
double calculate_ avg(double [], int n);
*/


double calculate_avg(double arr[], int n)
{
    // 배열의 크기가 달라질 때 어떻게 해야 할지?
    // 배열은 그 특성상 데이터가 많기 때문에, 배열을 통째로 복사해서 가져오는 것이 아닌
    // 포인터처럼 행동하며 포인터처럼 데이터의 첫 번째 주소를 가져옴
    // 즉, 함수에서 parameter로 배열을 받을 때는 배열이 아닌 포인터로 받는다
    // 함수에서 받는 배열의 정보는 배열의 '첫 번째 주소'일 뿐이므로, 배열 원소 개수 정보도 함께 가져와야 함

    // arr1의 경우 첫 번째 주소 즉, double형 포인터의 데이터 크기 = 8
    printf("Size = %zd in function average\n", sizeof(arr));

    double avg = 0.0;
    for (int i = 0; i < n; ++i)
            avg += arr[i];
    avg /= (double)n;

    return avg;
}


int main()
{
    double arr1[5] = {10, 13, 12, 7, 8};
    // double arr2[5] = {1.8, -0.2, 6.3, 13.9, 20.5};
    double arr2[3] = {1.8, -0.2, 6.3}; // size is different

    printf("Address = %p\n", arr1);
    printf("Size = %zd\n", sizeof(arr1));

    printf("Address = %p\n", arr2);
    printf("Size = %zd\n", sizeof(arr2));

    // calculate avg of each array: make it to a function
    // so we can reuse it for each array
    printf("Avg = %f\n", calculate_avg(arr1, 5));
    printf("Avg = %f\n", calculate_avg(arr2, 3));   // 원소 개수 구하는 법: sizeof(arr)/sizeof(arr[0])


    return 0;
}