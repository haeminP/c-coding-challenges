#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS


int main()
{
    unsigned int i = 0;
    unsigned int u_max = UINT_MAX;  // macro
    signed int i_max = INT_MAX;

    unsigned int u_min = 0;  // macro
    signed int i_min = INT_MIN;


    printf("max of unit: %u\n", u_max);
    printf("max of int: %d\n", i_max);

    printf("min of unit: %u\n", u_min);
    printf("min of int: %d\n", i_min);
    


    // overflow
    unsigned int u_max_extra = UINT_MAX;
    printf("%u\n", u_max_extra);

    // UNIT_MAX에 1을 더하면 가장 작은 수로 변해버림
    // 한편 0-1 (가장 작은 값 - 1)을 하면 가장 큰 수로 변함

    // i to binary representation
    char buffer[33];
    _itoa(u_max_extra, buffer, 2);

    // print decimal and binary
    printf("decimal: %u\n", u_max_extra);
    printf("binary: %s\n", buffer);


    // different types of int

    char c = 65;
    short s = 200;
    unsigned int ui = 3000000000U; // 3'000'000'000U
    long int l = 65537L;
    long long int ll = 12345678908642LL; // 12'345'678'908'642ll

    printf("char = %hhd, %d, %c\n", c, c, c);
    printf("short = %hhd, %hd, %d\n", s, s, s);
    printf("unsigned int = %u, %d\n", ui, ui);
    printf("long = %ld, %hd\n", l, l);
    printf("long long = %lld, %ld, %hd\n", ll, ll, ll);


    // 8진수(octal)와 16진수(hexadecimal)
    unsigned int decimal = 4294967295;
    unsigned int binary = 0b11111111111111111111111111111111; // 32개
    unsigned int oct = 037777777777;
    unsigned int hex = 0xffffffff;

    printf("%u\n", decimal);
    printf("%u\n", binary);
    printf("%u\n", oct);
    printf("%u\n", hex);

    printf("%o %x %#o %#x %#x", decimal, decimal, decimal, decimal, decimal);



    


    return 0;
}