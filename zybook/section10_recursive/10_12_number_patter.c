#include <stdio.h>

/* Define PrintNumPattern() here */
void PrintNumPattern(int num1, int num2) {
    // Base case: Stop recursion when num1 becomes negative
    if (num1 < 0) {
        printf("%d ", num1);
        return;
    }

    // Print current value and make a recursive call with updated values
    printf("%d ", num1);
    PrintNumPattern(num1 - num2, num2);

    // Print current value again during the second pass
    printf("%d ", num1);
}

int main(void) {
    int num1;
    int num2;

    scanf("%d", &num1);
    scanf("%d", &num2);
    PrintNumPattern(num1, num2);

    return 0;
}