#include <stdio.h>

void GuessNumber(int lowVal, int highVal){
    int midVal;
    char userAnswer;

    midVal = (highVal + lowVal) / 2;

    // Prompt user for input
    printf("Is it %d? (l/h/y): ", midVal);
    scanf(" %c", &userAnswer);

    if ((userAnswer != 'l') && (userAnswer != 'h')){    // Base case: found number
        printf("Thank you!");
    }

    else{
        if (userAnswer == 'l'){
            GuessNumber(lowVal, midVal);
        }

        else{
            GuessNumber(midVal + 1, highVal);
        }
    }
}


int main(){
    
    // Print game objective, user input commnads
    printf("Choose a number from 0 to 100.\n");
    printf("Answer with:\n");
    printf("   l (your num is lower)\n");
    printf("   h (your num is higher)\n");
    printf("   any other key (guess is right).\n");

    // Call recursive function to guess number
    GuessNumber(0, 100);

    return 0;
}