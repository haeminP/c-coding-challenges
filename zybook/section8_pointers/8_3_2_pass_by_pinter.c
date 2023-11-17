#include <stdio.h>
#include <stdbool.h>

bool AdjustState(int temperature, char* state){

    bool isChanged;
    

    if (temperature < 100){
        *state = 'L';
        isChanged = true;
    }

    else if (temperature > 100){
        *state = 'G';
        isChanged = true;
    }

    else {
        isChanged = false;
    }
    
    return isChanged;
    
}


int main(){
    int waterTemperature;
    char waterState;
    bool isChanged;

    waterState = 'B';
    scanf("%d", &waterTemperature);

    isChanged = AdjustState(waterTemperature, &waterState);

    if (isChanged){
        printf("Water state is changed to %c.\n", waterState);
    }

    else {
        printf("Water state %c is not changed.\n", waterState);
    }

    return 0;
}