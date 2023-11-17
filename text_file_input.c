#include <stdio.h>
#include <stdlib.h>     // exit()

int main()
{
    int c;

    // file이라는 변수를 선언하고 있음
    // *은 포인터라는 뜻
    // 즉, file은 포인터 변수임

    FILE *file = NULL;

    char file_name[] = "my_file.txt";      //TODO: use scanf(...)

    // fopen: 파일을 열어주고
    // fopen 함수가 반환하는 값이 file에 저장됨

    // r이라는 옵션은 read
    file = fopen(file_name, "r");

    // 해당 이름을 가진 파일이 없는 경우
    // exit되면서 1이 뜨면, 뭔가 잘못됐다는 걸 알려줌
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        exit(1);
    }

    

    while ((c = getc(file)) != EOF)
        putchar(c);
    
    // 파일을 닫아줌으로써 운영프로그램에 알려주기
    fclose(file);

    return 0;
}