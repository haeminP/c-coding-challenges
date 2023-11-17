#include <stdio.h>



int main()
{
    char c;
    
    while((c = getchar()) != '.')
    {
        printf("You love ");

        switch(c)   //Note: integer types only
        {
            case 'a': case 'A':
                printf("apple");
                break;
            case 'b': case 'B':
                printf("baseball");
                break;
            case 'c': case 'C':
                printf("cake");
                break;
            default:
                printf("nothing");
        }

        printf("\n");
        
        // 같은 줄에 abc가 입력되는 경우, 줄바꿈이 나올 때까지
        // 첫 글자를 제외한 나머지 글자는 무시하기 위한 코드
        while(getchar() != '\n')
            continue;
    }

}