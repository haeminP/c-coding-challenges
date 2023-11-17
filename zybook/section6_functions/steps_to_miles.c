#include <stdio.h>

double steps_to_miles(int num_steps);
double steps_to_calories(int num_steps);


int main()
{
    int step_walked;
    printf("Enter number of steps walked: ");
    scanf("%d", &step_walked);

    printf("Miles walked: %lf\n", steps_to_miles(step_walked));
    printf("Calories burnt: %lf\n", steps_to_calories(step_walked));
    
    return 0;
}

double steps_to_miles(int num_steps)
{
    const double FEET_PER_STEP = 2.5;
    const int FEET_PER_MILE = 5280;         // Typical adult

    return num_steps * FEET_PER_STEP * (1.0 / FEET_PER_MILE);
}

double steps_to_calories(int num_steps)
{
   const double STEPS_PER_MINUTE = 70.0;           // Typical adult
   const double CALORIES_PER_MINUTE_WALKING = 3.5; // Typical adult
   double minutes_total;
   double calories_total;

   minutes_total = num_steps / STEPS_PER_MINUTE;
   calories_total = minutes_total * CALORIES_PER_MINUTE_WALKING;

   return calories_total;
}
