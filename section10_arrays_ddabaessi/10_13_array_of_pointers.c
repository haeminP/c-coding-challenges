#include <stdio.h>

int main()
{
    // name이라는 배열에는 A, J, M, G가 저장된 위치가 각각 저장됨
    // 사이즈는 4
    // name이라는 포인터의 배열에 4개의 원소가 있고

    char* name[] = {"Aladdin", "Jasmine", "Magic Carpet", "Genie"};
    const int n = sizeof(name) / sizeof(char*);

    for (int i = 0; i < n; ++i)
        printf("%s at %u\n", name[i], (unsigned)name[i]); // Use ull in x64 build
    printf("\n");


    char aname[][15] = {"Aladdin", "Jasmine", "Magic Carpet", "Genie", "Jafar"};

    const int an = sizeof(aname) / sizeof(char[15]);

    for (int i = 0; i < an; ++i)
        printf("%s at %u\n", aname[i], (unsigned)& aname[i]);  // Use ull in x64 build
    printf("\n");       

    return 0;
}