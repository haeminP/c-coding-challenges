#include <stdio.h>
#include <string.h>

int GetMonthAsInt(char *monthString) {
	int monthInt;

	if (strcmp(monthString, "January") == 0) {
		monthInt = 1;
	}
	else if (strcmp(monthString, "February") == 0) {
		monthInt = 2;
	}
	else if (strcmp(monthString, "March") == 0) {
		monthInt = 3;
	}
	else if (strcmp(monthString, "April") == 0) {
		monthInt = 4;
	}
	else if (strcmp(monthString, "May") == 0) {
		monthInt = 5;
	}
	else if (strcmp(monthString, "June") == 0) {
		monthInt = 6;
	}
	else if (strcmp(monthString, "July") == 0) {
		monthInt = 7;
	}
	else if (strcmp(monthString, "August") == 0) {
		monthInt = 8;
	}
	else if (strcmp(monthString, "September") == 0) {
		monthInt = 9;
	}
	else if (strcmp(monthString, "October") == 0) {
		monthInt = 10;
	}
	else if (strcmp(monthString, "November") == 0) {
		monthInt = 11;
	}
	else if (strcmp(monthString, "December") == 0) {
		monthInt = 12;
	}
	else {
		monthInt = 0;
	}

	return monthInt;
}

int main(void) {
    const int MAX_TEXT_LENGTH = 30;
    char userText[MAX_TEXT_LENGTH];
    char monthString[10];
    int month;
    int day;
    int year;
    int valueRead;
    bool inputDone = false;


    while (strcmp(monthString, "-1") != 0){
    fgets(userText, MAX_TEXT_LENGTH, stdin);
    valueRead = sscanf(userText, "%10s %2d, %4d", monthString, &day, &year);
    month = GetMonthAsInt(monthString);

        if(valueRead == 3 && month != 0){
            printf("%d-%d-%d", month, day, year);
            if (!inputDone){
                printf("\n");
            }
        }
    }

	return 0;
}
