#include <stdio.h>
#include <string.h>

int main(){
    const int MAX_LINES = 25;
    const int MAX_STRING_LENGTH = 100;
    const int MAX_LINE_LENGTH = 200;

    char column1[MAX_LINES][MAX_STRING_LENGTH];
    char column2[MAX_LINES][MAX_STRING_LENGTH];
    char column3[MAX_LINES][MAX_STRING_LENGTH];
    char column4[MAX_LINES][MAX_STRING_LENGTH];

    char fileName[25];
    int num_items = 0;

    fgets(fileName, 25, stdin);
    strtok(fileName, "\n");

    FILE* inFile = fopen(fileName, "r");


    if (inFile == NULL){
        printf("Error\n");
    }

    char line[MAX_STRING_LENGTH];
    while (fgets(line, MAX_STRING_LENGTH, inFile) != NULL){
        char* token = strtok(line, "\t");
        strcpy(column1[num_items], token);

        token = strtok(NULL, "\t");
        strcpy(column2[num_items], token);

        token = strtok(NULL, "\t");
        strcpy(column3[num_items], token);

        token = strtok(NULL, "\t");
        strcpy(column4[num_items], token);

        num_items++;
    }

    for (int i = 0; i < num_items; i++) {
        if(strcmp(column4[i], "Available\n") == 0){
            printf("%s (%s) -- %s\n", column2[i], column1[i], column3[i]);
        }
    }

    fclose(inFile);

    return 0;


}