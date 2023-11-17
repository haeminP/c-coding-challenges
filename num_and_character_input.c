#include <stdio.h>

void display(char ch, int lines, int width);


int main()
{
    char c;
    int rows, cols;


    printf("Input one character and two integers:\n");
    while ((c = getchar()) != '\n')
    {
        scanf("%d %d", &rows, &cols);
        
        // scanf는 필요한 거 읽은 다음 맨 뒤의 \n을 버퍼에 남겨두게 됨
        // 따라서 첫 문자만 읽어오는 기능을 넣어줘야 함 (즉, 두 번째 문자부터는 무시함(continue) until 새로운 \n 뉴라인 문자가 나올 때까지):
        // 일명: 버퍼 지우기
        while(getchar() != '\n') 
            continue;
        

        display(c, rows, cols);
        printf("Input another character and two integers:\n");
        printf("Press Enter to quit.\n");

    }

    return 0;
}


void display(char ch, int lines, int width)
{
    int row, col;

    for (row = 1; row <= lines; ++row)
    {
        for (col = 1; col <= width; ++col)
            putchar(ch);
        putchar('\n');
    }

}