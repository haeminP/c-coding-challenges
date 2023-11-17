#include <stdio.h>
#include <string.h>
#define SIZE 50


int main()
{
    char input1[SIZE];
    char input2[SIZE];
    char filtered_input1[SIZE];
    char filtered_input2[SIZE];
    char ch;
    int i, j;
    int counter = 0;

    // get 2 strings

    scanf("%s", input1);
    scanf("%s", input2);


    // filter string1 for redundant characters
            
    int filtered_index1 = 0;        

    for (i = 0; i < strlen(input1); ++i)
        {
            int is_unique = 1;

            for (j = 0; j <= filtered_index1; j++)
            {
                if (input1[i] == filtered_input1[j])
                    {
                        is_unique = 0;
                        break;
                    }
            }

            if (is_unique)
            {
                filtered_input1[filtered_index1] = input1[i];
                ++filtered_index1;
            }
        }

    // filter string2 for redundant characters

    int filtered_index2 = 0;        

    for (i = 0; i < strlen(input2); ++i)
        {
            int is_unique = 1;

            for (j = 0; j <= filtered_index2; j++)
            {
                if (input2[i] == filtered_input2[j])
                    {
                        is_unique = 0;
                        break;
                    }
            }

            if (is_unique)
            {
                filtered_input2[filtered_index2] = input2[i];
                ++filtered_index2;
            }
        }

    // compare each element of filtered strings

    if (strlen(filtered_input1) <= strlen(filtered_input2))
    {
        for (i = 0; i < strlen(filtered_input1); ++i)
            for (j = 0; j < strlen(filtered_input2); ++j)
                {
                    ch = filtered_input1[i];
                    if (ch == filtered_input2[j])
                        ++counter;
                }
    }

    else
    {
        for (i = 0; i < strlen(filtered_input2); ++i)
            for (j = 0; j < strlen(filtered_input1); ++j)
                {
                    ch = filtered_input2[i];
                    if (ch == filtered_input1[j])
                        ++counter;
                }
    }


    // display result
    if (counter <= 1)
        printf("%d character matches", counter);
    else
        printf("%d characters match", counter);


    return 0;
}