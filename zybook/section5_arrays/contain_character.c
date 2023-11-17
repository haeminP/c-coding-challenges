#include <stdio.h>
#include <string.h>

int main()
{
    int num_words;
    char words[20][10];
    char search_char;
    char filtered_words[20][10];
    int filtered_index = 0;

    int i, j;

// example input:   3 zoo sunny drizzle z
// expected output: zoo, drizzle,

    scanf("%d", &num_words);

    for (i = 0; i < num_words; ++i)
        scanf("%s", words[i]);
    
    scanf(" %c", &search_char);


    // filter array
    // We can’t directly change or assign the values to an array of strings in C
    // need to use 'strcpy' function instead

    for (i = 0; i < num_words; ++i)
        {
            for (j = 0; j < 10; ++j)
                if (words[i][j] == search_char)
                {
                    strcpy(filtered_words[filtered_index], words[i]);
                    ++filtered_index;
                    break;
                }
        }

    for (i = 0; i < filtered_index; ++i)
        printf("%s, ", filtered_words[i]);


    return 0;
}