#include <stdio.h>
#include <string.h>

int main()
{
    char wordList[20][10];
    int wordFrequency[20];

    int inputNum;
    int i;

    scanf("%d", &inputNum);

    for(i = 0; i < inputNum; ++i)
        scanf("%s", wordList[i]);

    for(i = 0; i < inputNum; ++i)
        {
            int frequency = 0;
            for (int j = 0; j < inputNum; ++j)
                {
                    if(strcmp(wordList[i], wordList[j]) == 0)
                        ++frequency;
                }
            wordFrequency[i] = frequency;
        }

    for (i = 0; i < inputNum; ++i)
        printf("%s - %d\n", wordList[i], wordFrequency[i]);

    return 0;
}