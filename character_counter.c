#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define STOP '.'

int main()
{
    char ch;
    int char_count = 0, word_count = 0, line_count = 0;
    bool word_flag = false;     // false가 버튼이 켜진 상태임
    bool line_flag = false;


    printf("Enter text:\n");

    while((ch =getchar()) != STOP)
    {
        if(!isspace(ch))
            char_count++;   // count non-space characters

        if(!isspace(ch) && !line_flag)  // non-space and line_flag = false 상태일 때
        {                               // line 카운터 늘려주고, line_flag를 꺼줌(true)
            line_count++;
            line_flag = true;
        }

        if (ch == '\n')
            line_flag = false;
        
        if(!isspace(ch) && !word_flag)
        {
            word_count++;
            word_flag = true;
        }

        if (isspace(ch))
            word_flag = false;

    }

    printf("Character count: %d\n", char_count);
    printf("Word count: %d\n", word_count);  
    printf("Line count: %d\n", line_count);

    return 0;
}