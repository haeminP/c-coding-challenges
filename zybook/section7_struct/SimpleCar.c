#include <stdio.h>

#include "SimpleCar.h"

SimpleCar InitCar(){
    SimpleCar newCar;
    
    newCar.miles = 0;
    
    return newCar;
}

SimpleCar Drive(int dist, SimpleCar car){
    car.miles = car.miles + dist;
    
    return car;
}

SimpleCar Reverse(int dist, SimpleCar car){
    car.miles = car.miles - dist;
    
    return car;
}

int GetOdometer(SimpleCar car){
    return car.miles;
}

void HonkHorn(SimpleCar car){
    printf("beep beep\n");
}

void Report(SimpleCar car){
    printf("Car has driven: %d miles\n", car.miles);
}