#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Seat_struct {
    char firstName[50];
    char lastName[50];
    int amountPaid;
} Seat;


/* Functions for Seat */
void SeatMakeEmpty(Seat* seat);
bool SeatIsEmpty(Seat seat);
void SeatPrint(Seat seat);

/* Functions for array */
void SeatsMakeEmpty(Seat seats[], int numSeats);
void SeatsPrint(Seat seats[], int numSeats);


int main(){
    const int NUM_SEATS = 5;
    char userKey;
    int seatNum;
    Seat allSeats[NUM_SEATS];
    Seat currSeat;

    userKey = ' ';

    // In the beginning, make all seats empty
        SeatsMakeEmpty(allSeats, NUM_SEATS);

    while (userKey != 'q'){

        printf("Enter command (p/r/d/q): ");
        scanf(" %c", &userKey);

        if (userKey == 'p'){    // Print seats
            SeatsPrint(allSeats, NUM_SEATS);
            printf("\n");
        }

        else if (userKey == 'r'){   // Reserve seats
            // Ask user to choose a seat number (0~4)

            printf("Enter seat num: ");
            scanf("%d", &seatNum);

            if (!SeatIsEmpty(allSeats[seatNum])){
                printf("Seat is not empty.\n\n");
            }

       
            else {
            printf("Enter first name: ");
            scanf("%s", &currSeat.firstName);

            printf("Enter last name: ");
            scanf("%s", &currSeat.lastName);

            printf("Enter amount paid: ");
            scanf("%d", &currSeat.amountPaid);

            allSeats[seatNum] = currSeat;

            printf("Completed\n\n");
            }
        }

        else if (userKey == 'd'){
            printf("Enter seat num: ");
            scanf("%d", &seatNum);

            SeatMakeEmpty(&(allSeats[seatNum]));
            printf("Deleted.\n\n");
        }

        else if (userKey == 'q'){
            printf("Quitting.\n");
        }

        else {
            printf("Invalid command.\n\n");
        }

    }


    return 0;
}





void SeatMakeEmpty(Seat* seat){
    
    strcpy((*seat).firstName, "empty");
    strcpy((*seat).lastName, "empty");
    (*seat).amountPaid = 0;
}

bool SeatIsEmpty(Seat seat){
    return (strcmp(seat.firstName, "empty") == 0);
}

void SeatPrint(Seat seat){
    printf("%s ", seat.firstName);
    printf("%s, ", seat.lastName);
    printf("Paid: %d\n", seat.amountPaid);
}

void SeatsMakeEmpty(Seat seats[], int numSeats){
    int i;
    for (i = 0; i < numSeats; ++i)
        SeatMakeEmpty(&seats[i]);
}

void SeatsPrint(Seat seats[], int numSeats){
    int i;
    for (i = 0; i < numSeats; ++i)
        SeatPrint(seats[i]);
}