#include <stdio.h>

int main()
{
    int count = 0;
    
    while(1)
    {
        printf("Current count is %d. Continue? (y/n)\n", count);

        int c = getchar();

        if (c == 'n')
            break;

        else if (c == 'y')    
            count++;

        else
            printf("Please input y or n\n");

        // 아래 코드를 통해 new line을 만나기 전까지
        // 첫 글자만 가져오고 다음 글자들은 무시 (continue이므로 루프 밖으로 나감): 예 yes / no가 나오면 y/n만 읽어들임
        // 일명 버퍼 지우기
        
        while(getchar() != '\n')
            continue;
            
    }

    return 0;
}