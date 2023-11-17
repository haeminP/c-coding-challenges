#include <stdio.h>
#include <string.h>     // strlen()


#define WIDTH   30
#define NAME    "Haemin Park"
#define ADDRESS "3072 Erindale"


// 동일한 기능을 하는 코드가 2번 이상 나올 경우 함수로 묶어준다
// 함수의 장점: 더 일반적으로 사용 가능, 장기적으로 유지보수가 쉬움
void print_stars(int n_stars)
{
    // printf("********************\n");
    // star의 개수와 상관 없이 작동하는 코드
    for (int i = 0; i < n_stars; ++i)
        printf("*");
    printf("\n");
}

void print_blank(int n_blank)
{
    for (int i = 0; i < n_blank; ++i)
        printf(" ");
    printf("\n");
}

// print_stars와 print_blank를 합친 함수:
void print_multiple_char(char c, int n_times)
{
    for (int i = 0; i < n_times; ++i)
        printf("%c", c);        // putchar(c)
}

// blank 개수를 계산해 문자들을 가운데 출력하는 함수
void print_centered_str(char str[])
{
    // blank 개수 계산
    int n_blanks = 0;
    n_blanks = (WIDTH - strlen(str)) / 2;
    print_multiple_char(' ', n_blanks);
    printf("%s\n", str);
}


int main()
{
    print_multiple_char('*', WIDTH);
    printf("\n");

    print_centered_str(NAME);
    print_centered_str(ADDRESS);
    print_centered_str("I love blanket");

    print_multiple_char('*', WIDTH);
    return 0;
}

