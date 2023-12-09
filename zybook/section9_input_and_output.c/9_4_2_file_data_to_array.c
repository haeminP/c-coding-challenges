#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* inFile = NULL;    // File pointer
    int* userNums;          // User numbers; memory allocated later
    int arrSize;
    int i;


// Try to open the file
    inFile = fopen("myfile.txt", "r");

    if (inFile == NULL){
        printf("Could not open file myfile.txt.\n");
        return -1;
    }

    // Can now use fscanf(inFile, ...) like scanf()
    fscanf(inFile, "%d", &arrSize);

    // Allocate enough memory for nums
    userNums = (int*)malloc(arrSize * sizeof(int));

    if (userNums == NULL){
        fclose(inFile);     // Done with file, so close it
        return -1;
    }

    // Get user specified numbers. If too few, may encounter probelms
    i = 1;
    while (i <= arrSize){
        fscanf(inFile, "%d", &(userNums[i-1]));
        ++i;
    }

    // Done with file, so close it
    fclose(inFile);

    // Print numbers
    printf("Numbers: ");
    
    i = 0;
    while (i < arrSize){
        printf("%d ", userNums[i]);
        ++i;
    }

    printf("\n");

    // Deallocate memory for nums
    free(userNums);
    
    return 0;


        


    return 0;
}