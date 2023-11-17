#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COUNTRY_NAME_LENGTH 50

typedef struct CountryTVWatch_struct 
{
    char countryName[MAX_COUNTRY_NAME_LENGTH];
    int tvMinutes;
} CountryTVWatch;


void PrintCountryNames(CountryTVWatch ctryList[], int numCountries)
{
    for (int i = 0; i < numCountries; ++i)
        printf("%s ", ctryList[i].countryName);
}

int main()
{
    const int NUM_COUNTRIES = 4;

    CountryTVWatch countryList[NUM_COUNTRIES];
    char countryToFind[MAX_COUNTRY_NAME_LENGTH];
    bool countryFound;
    int i;

    // populate the array
    strcpy(countryList[0].countryName, "Brazil");
    countryList[0].tvMinutes = 222;

    strcpy(countryList[1].countryName, "India");
    countryList[1].tvMinutes = 119;

    strcpy(countryList[2].countryName, "UK");
    countryList[2].tvMinutes = 242;

    strcpy(countryList[3].countryName, "USA");
    countryList[2].tvMinutes = 283;


    // prompt user to enter country name
    printf("Enter country name: ");
    scanf("%s", countryToFind);

    // start a loop to compare user input with each element of the array
    countryFound = false;
    for (i = 0; i < NUM_COUNTRIES && !countryFound; ++i)
    {
        if(strcmp(countryList[i].countryName, countryToFind) == 0)
        {
            countryFound = true;
            printf("People in %s watch\n", countryToFind);
            printf("%d minutes of TV daily.", countryList[0].tvMinutes);
        }
    }

    /*

    strcmp() function result:
    0: if two strings are same
    > 0: if the first non-matching character in str1 is greater than str2
    < 0: if the first non-matching character in str1 is lower than str2
    
    */


    if(!countryFound)
    {
        printf("Country not found, try again.\n");
        printf("Valid countries:\n");
        PrintCountryNames(countryList, NUM_COUNTRIES);
    }

}