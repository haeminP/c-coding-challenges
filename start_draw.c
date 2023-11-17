#include <stdio.h>

void draw(int n);

int main()
{
    int i = 5;
    char c = '#';   // 35
    float f = 7.1f;

    draw(i);
    draw((int)c);
    draw((int)f);

    return 0;
}

void draw(int n)
{
    int i = 0;
    while(i < n)
    {
        printf("*");
        i++;
    }
    printf("\n");
}
