#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.141592f
#define AI_NAME "Jarvis"
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    char fruit_name[40]; // 1 char stores only one character 
                         // 1바이트짜리 저장 공간 40개 확보

    printf("What is your favorite fruit?\n");

    scanf("%s", fruit_name); // string의 경우 scanf에서 &가 불필요함
                             // 그 이유는 fruit_name 자체가 주소이기 때문

    printf("You like %s!\n", fruit_name);



    // 4.3 문자열이 메모리에 저장되는 구조
    char c = 'a';
    char str1[10] = "Hello"; // null character - 사실 문자 6개임
    char str2[10] = {'H', 'i'};

    printf("%c\n", c);
    printf("%s\n", str1);
    printf("%s\n", str2);

    // 4.4 strlen() 함수
    char str3[100] = "Hello";
    char str4[] = "Hello";
    char str5[100] = "\0";
    char str6[100] = "\n";

    printf("%zu %zu\n", sizeof(str3), strlen(str3));
    printf("%zu %zu\n", sizeof(str4), strlen(str4));
    printf("%zu %zu\n", sizeof(str5), strlen(str5));
    printf("%zu %zu\n", sizeof(str6), strlen(str6));
    

    // 4.5 기호적 상수와 전처리기

    // #define PI 3.141592f, 주의할 점! PI = 3.141592f가 아님
    // =를 더하면 컴파일러가 =까지 함께 복사해 PI 자리에 넣게 됨

    // #define AI_NAME "Jarvis" 이렇게 선언해주면
    // 나중에 AI 이름이 바뀌더라도 위에서 한 번만 바꿔주면 됨

    float radius, area, circum;
    printf("I am %s.\n", AI_NAME);
    printf("Input radius\n");
    scanf("%f", &radius);

    area = PI * radius * radius;
    circum = 2.0 * PI * radius;

    printf("Area is %f\n", area);
    printf("Circumference is %f\n", circum);


    return 0;


}