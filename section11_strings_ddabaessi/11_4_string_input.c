#include <stdio.h>

int main()
{
    // 123456789 입력 시 null character 제외 4글자만 읽어와서 출력: 1234
    char small_array[5];
    puts("Enter long strings:");
    fgets(small_array, 5, stdin);   // FILE *_Stream

    //printf("%p\n", small_buffer);
    //printf("%p\n", fgets(small_buffer, 5, stdin));    // Return value of fgets
    fputs(small_array, stdout);
    puts("");

    

    /* 
    Repeating short reading 
    반복해서 받아들이고 반복해서 출력하면
    긴 문자열을 한 번에 가져오는 것처럼 보임
    */

   char small_array2[5];
   puts("Enter long strings:");
   while (fgets(small_array2, 5, stdin) != NULL && small_array2[0] != '\n')
    fputs(small_array2, stdout);
    //puts(small_array2);       // What if we use puts()


    

    return 0;
}