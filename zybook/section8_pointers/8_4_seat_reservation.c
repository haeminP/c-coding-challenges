#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
void SeatsMakeEmpty(Seat seats[], int numSeats) {
   int i;
   
   for (i = 0; i < numSeats; ++i) {
      SeatMakeEmpty(&seats[i]);
   }
}
*/

// whole array is 'pass by reference'
// but the each element of array is 'pass by value'
// so to pass each element reference (to be able to change the content)
// you need to send the address of each element (pass by reference)

/*
void SeatMakeEmpty(Seat* seat) {
   strcpy((*seat).firstName, "empty");
   strcpy((*seat).lastName,  "empty");
   (*seat).amountPaid = 0;
}
*/
// the parameter of the above function is Seat* seat
// because &seats[i] was passed as an parameter



typedef struct Seat_struct {
   char firstName[50];
   char lastName[50];
   int  amountPaid;
} Seat;

/*** Functions for Seat ***/

void SeatMakeEmpty(Seat* seat) {
   strcpy((*seat).firstName, "empty");
   strcpy((*seat).lastName,  "empty");
   (*seat).amountPaid = 0;
}

bool SeatIsEmpty(Seat seat) {
   return (strcmp(seat.firstName, "empty") == 0);
}

void SeatPrint(Seat seat) {
   printf("%s ", seat.firstName);
   printf("%s, ", seat.lastName);
   printf("Paid: %d\n", seat.amountPaid);
}
/*** End functions for Seat ***/

/*** Functions for array of Seat ***/
void SeatsMakeEmpty(Seat seats[], int numSeats) {
   int i;
   
   for (i = 0; i < numSeats; ++i) {
      SeatMakeEmpty(&seats[i]);
   }
}

void SeatsPrint(Seat seats[], int numSeats) {
   int i;
   
   for (i = 0; i < numSeats; ++i) {
      printf("%d: ", i);
      SeatPrint(seats[i]);
   }
}
/*** End functions for array of Seat ***/

int main(void) {
   const int NUM_SEATS = 5;
   char userKey;
   int  seatNum;
   Seat allSeats[NUM_SEATS];
   Seat currSeat;
   
   userKey = '-';
   seatNum = 0;

   SeatsMakeEmpty(allSeats, NUM_SEATS);
   
   while (userKey != 'q') {
      printf("Enter command (p/r/q/d): \n");
      scanf(" %c", &userKey);
      
      if (userKey == 'p') { // Print seats
         SeatsPrint(allSeats, NUM_SEATS);
         printf("\n");
      }
      else if (userKey == 'r') { // Reserve seat
         printf("Enter seat num: \n");
         scanf("%d", &seatNum);
         
         if (!SeatIsEmpty(allSeats[seatNum])) {
            printf("Seat not empty.\n\n");
         }
         else {
            printf("Enter first name: \n");
            scanf("%s", currSeat.firstName);
            printf("Enter last name: \n");
            scanf("%s", currSeat.lastName);
            printf("Enter amount paid: \n");
            scanf("%d", &currSeat.amountPaid);
            
            allSeats[seatNum] = currSeat;
            
            printf("Completed.\n\n");
         }
      }
      
      else if (userKey == 'd')
         {
            printf("Enter seat num: \n");
            scanf("%d", &seatNum);
            
            if (SeatIsEmpty(allSeats[seatNum]))
               printf("Seat is already empty\n");
            
            else{
            SeatMakeEmpty(&allSeats[seatNum]);
            }
         }
         
      
      else if (userKey == 'q') { // Quit
         printf("Quitting.\n");
      }
      else {
         printf("Invalid command.\n\n");
      }
   }
   
   return 0;
}
