#include <stdio.h>
#include <stdboo.h>

typedef struct Seat_struct 
{
    char firstName[50];
    char lastName[50];
    int amountPaid;
}   Seat;

int main()
{
    Seat seat1;
    Seat* seat2;
    strcpy(seat1.firstName, "Haemin");
    strcpy(seat1.lastName, "Park");
    seat1.amountPaid = 100;

    
    seat2 = &seat1;
    // How can change 100 to 200?
    // seat1.amountPaid = 200;
    (*seat2).amountPaid = 200;
    // priority of member access is higher than dereferencing
    // so put the dereferencing part inside parenthesis
    // to access to a struct pointer:
    strcpy((*seat2).firstName, "Fabio");
    *seat2->amountPaid = 300;


    return 0;
}