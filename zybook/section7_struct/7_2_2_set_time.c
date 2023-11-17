#include <stdio.h>

typedef struct TimeHrMin_struct {

    int numHours;
    int numMinutes;

} TimeHrMin;

TimeHrMin SetTime(int hoursVal, int minutesVal)
{
    TimeHrMin tempVal;
    
    tempVal.numHours = hoursVal;
    tempVal.numMinutes = minutesVal;

    return tempVal;
}

int main()
{
    TimeHrMin lateBy;
    int hoursVal;
    int minutesVal;

    scanf("%d", &hoursVal);
    scanf("%d", &minutesVal);

    lateBy = SetTime(hoursVal, minutesVal);
    
    printf("We met %d:%d hours ago.\n", lateBy.numHours, lateBy.numMinutes);
    
    return 0;
}