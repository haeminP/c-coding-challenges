#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

char get_choice(void);
char get_first_char(void);
int get_integer(void);
void count(void);


int main()
{

    int user_choice;

    while ((user_choice = get_choice()) != 'q')
    {
        switch(user_choice)
        {
            case 'a':
                printf("Avengers assemble!\n");
                break;
            case 'b':
                putchar('\a'); // Beep
                break;        
            case 'c':
                count();
                break;
            default:
                printf("Error with %d.\n", user_choice);
                exit(1);
                break;
        }



    // printf("Enter the letter of your choice:\n");
    // printf("a. avengers       b. beep\n");
    // printf("c. count          q. quit\n");
    // scanf(" %c", &input);

    // switch(input)
    //     {
    //         case 'a':
    //             printf("Avengers assemble!\n");
    //             break;

    //         case 'b':
    //             Beep(1,1);
    //             break;
    //         case 'c':
    //             {
    //                 printf("Enter an integer:\n");
    //                 scanf("%d", &num);

    //                 for(int i = 1; i <= num; i++)
    //                     printf("%d\n", i);
    //             }
    //             break;
    //         case 'q':
    //             break;
    //     }
    }

    return 0;
}


char get_choice(void)
{
    char input;
    printf("Enter the letter of your choice:\n");
    printf("a. avengers\tb. beep\n");
    printf("c. count\tq. quit\n");
    input = get_first_char();

    // 입력 유효성 검증
    // input이 a, b, c, q 중 하나가 아닌 경우:
    //while ((input < 'a' || user_input >> 'c') && user_input != 'q')

    while (input != 'a' && input != 'b' && input != 'c' && input != 'q')
    {
        printf("Please try again.\n");
        input = get_first_char();
    }

    return input;
}


char get_first_char(void)
{
    int ch;

    ch = getchar();

    while((getchar()) != '\n')
        continue;

    return ch;
}


int get_integer(void)
{
    int input;
    char c;
    
    // 입력이 integer가 아닌 경우 check:
    while (scanf("%d", &input) != 1)
    {
        while((c = getchar()) != '\n')
            putchar(c);
        printf(" is not an integer.\n Please try again.");
    }

    return input;
}


void count(void)
{
    int num;

    printf("Enter an integer:\n");
    num = get_integer();

    for(int i = 1; i <= num; i++)
        printf("%d\n", i);

    // 버퍼 지우는 부분
    while (getchar() != '\n')
        continue;
}