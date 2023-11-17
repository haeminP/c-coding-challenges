#include <stdio.h>
#include "SimpleCar.h"
#include "SimpleCar.c"

int main()
{
   int drive, reverse;
   SimpleCar car;
   scanf("%d", &drive);
   scanf("%d", &reverse);
   

    car = InitCar();
   car = Drive(drive, car);
   car = Reverse(reverse, car);

   car.miles = GetOdometer(car);
   
   HonkHorn(car);
   Report(car);

    return 0;
}