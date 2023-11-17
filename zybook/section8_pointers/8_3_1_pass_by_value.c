#include <stdio.h>

// typedef struct Times_struct
// {
//     int hrVal;
//     int minVal;
// } Times;



// Times ConvHrMin(int timeVal, Times time){
//     time.hrVal = timeVal / 60;
//     time.minVal = timeVal % 60;

//     return time;
// }

void ConvHrMin(int timeVal, int* hrVal, int* minVal){
    *hrVal = timeVal / 60;
    *minVal = timeVal % 60;
}



int main() {

    int totalTime;
    int userHr;
    int userMin;
    // Times time;


    totalTime = 0;
    userHr = 0;
    userMin = 0;

    // time.hrVal = 0;
    // time.minVal = 0;

    printf("Enter total minutes: ");
    scanf("%d", &totalTime);

    ConvHrMin(totalTime, &userHr, &userMin);
    printf("Equals: %d hrs %d min\n", userHr, userMin);

    // time = ConvHrMin(totalTime, time);
    // printf("Equals: %d hrs %d min\n", time.hrVal, time.minVal);

    
    return 0;
}
