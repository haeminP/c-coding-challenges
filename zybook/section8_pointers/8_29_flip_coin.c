#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void CoinFlip(char* decisionString){
    int flipVal;
    flipVal = rand() % 2;

    if (flipVal == 1)
        strcpy(decisionString, "Heads\n");

    else if (flipVal == 0)
        strcpy(decisionString, "Tails\n"); 
}

int main(){

    int flipNums;
    scanf("%d", &flipNums);
    char* decisionStr = (char*)malloc(5 * sizeof(char));

    srand(2);   /* Unique seed */
    
    for(int i = 0; i < flipNums; ++i){
        CoinFlip(decisionStr);
        printf("%s", decisionStr);
    }

    return 0;
}