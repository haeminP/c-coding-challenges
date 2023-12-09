#include <stdio.h>

/* Recursive DigitCount function */
int DigitCount(int num) {
    // Base case: when num is less than 10, it has only one digit
    if (num < 10) {
        return 1;
    }

    // Recursive case: divide num by 10 and call DigitCount with the remaining part
    return 1 + DigitCount(num / 10);
}

int main(void) {
    int num;
    int digits;

    scanf("%d", &num);
    digits = DigitCount(num);
    printf("%d", digits);

    return 0;
}
