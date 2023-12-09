#include <stdio.h>
#include <string.h>

void strreplace(char *s, const char *s1, const char *s2) {
    char *p = strstr(s, s1);
    if (p != NULL) {
        size_t len1 = strlen(s1);
        size_t len2 = strlen(s2);
        if (len1 != len2)
            memmove(p + len2, p + len1, strlen(p + len1) + 1);
        memcpy(p, s2, len2);
    }
}

int main(void) {

    FILE* inFile = NULL;    // File pointer
    int arrSize = 0;
    char str[50];
    int i;
    int stringRead;


// Try to open the file
    char fileName[50];
    scanf("%s", fileName);
    inFile = fopen(fileName, "r");

    if (inFile == NULL){
        return -1;
    }

// Count the lines in the file
    while (fgets(str, 50, inFile) != NULL) {
        ++arrSize;
    }

// Rewind the file pointer to the beginning of the file
    rewind(inFile);
    
    char files[arrSize][100];

    i = 0;
    stringRead = fscanf(inFile, "%s", files[i]);

    while (!feof(inFile)){
        if (stringRead == 1){
            strreplace(files[i], "_photo.jpg", "_info.txt");
            printf("%s\n", files[i]);
            ++i;
        }

        else {
            printf("Input failure before reaching end of file.\n");
            break;
        }

        stringRead = fscanf(inFile, "%s", files[i]);
    }


    fclose(inFile);

    return 0;
}