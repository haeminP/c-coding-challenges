#include <stdio.h>

// struct
typedef struct TimeHrMin_struct {

    int hourValue;
    int minuteValue;
}   TimeHrMin;

TimeHrMin convert_hr_min (int total_time);
// set the return value of function as a defined struct type

int main()
{
    TimeHrMin runTime1;
    TimeHrMin runTime2;
    TimeHrMin runTime3;

    runTime1.hourValue = 5;
    runTime1.minuteValue = 46;
    runTime3.hourValue = runTime1.hourValue;
    // by just assigning once, all the components in the struct will be assigned

    // advantage of using struct?
    // int h1, m1, h2, m2, h3, m3;
    // later when you want to copy time2 to time1
    // you need to assign hr/min separately

    // advantage of struct 2
    // function can only return 1 piece of information
    // How can we get more than 1 value when we call a function?
    // return type can be 'struct'

    int inTime;
    TimeHrMin travelTime;

    printf("Enter total minutes: ");
    scanf("%d", &inTime);

    travelTime = convert_hr_min(inTime);

    return 0;
}

TimeHrMin convert_hr_min (int total_time)
{
    TimeHrMin timeStruct;
    timeStruct.hourValue = total_time / 60;
    timeStruct.minuteValue = total_time % 60;

    return timeStruct;
}
