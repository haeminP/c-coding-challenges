#include <stdio.h>
#include <stdlib.h>

typedef struct Time_struct {
    int hours;
    int minutes;
    int seconds;
} Time;

// Allocate and return a Time as per parameters
Time* CreateTime(int hours, int minutes, int seconds)
{
    Time* newTime = NULL;
    newTime = (Time*)malloc(sizeof(Time));

    newTime->hours = hours;
    newTime->minutes = minutes;
    newTime->seconds = seconds;

    return newTime;
}

// Read integer hours, minutes, seconds
// Create and return a Time using the input values
Time* ReadTime(){
    int hours;
    int minutes;
    int seconds;

    scanf("%d %d %d", &hours, &minutes, &seconds);

    return CreateTime(hours, minutes, seconds);
}

Time* TimeDifference(Time* end, Time* start)
{
    Time* diff = NULL;
    
    // Allocate a new Time
    diff = (Time*)malloc(sizeof(Time));

    // Begin with uncorrected arithmetic
    diff->hours = end->hours - start->hours;
    diff->minutes = end->minutes - start->minutes;
    diff->seconds = end->seconds - start->seconds;

    if (diff->seconds < 0)
        {
            diff->seconds += 60;

            if (diff->minutes > 0)
                diff->minutes -= 1;

            
            // In case minutes gets smaller than 0
            else if (diff->minutes <= 0)
            {
                diff->hours -= 1;
                diff->minutes += 59;
            }
        }

    if (diff->minutes < 0)
        {
            diff->minutes += 60;
            diff->hours -= 1;
        }

    return diff;
}

void PrintTime(Time* t)
{
    printf("%02d:%02d:%02d", t->hours, t->minutes, t->seconds);
}

int main(){
    Time* start = NULL;
    Time* end = NULL;
    Time* difference = NULL;

    start = ReadTime();
    end = ReadTime();
    difference = TimeDifference(end, start);

   printf("Start:\t");
   PrintTime(start);
   printf("\nEnd:\t");
   PrintTime(end);
   printf("\nDifference: ");
   PrintTime(difference);
   printf("\n");

   // Always free dynamically allocated memory when no longer needed
   free(start);
   free(end);
   free(difference);

   return 0;
}