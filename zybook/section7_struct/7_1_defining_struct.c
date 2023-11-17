#include <stdio.h>

typedef struct PatientData_struct {
    int heightInches;
    int weightPounds;

} PatientData;


typedef struct InventoryTag_struct
{
    int itemID;
    int quantityRemaining;
} InventoryTag;



int main(void) {

    /* Patient Data struct example */
    PatientData lunaLovegood;

    scanf("%d", &lunaLovegood.heightInches);
    scanf("%d", &lunaLovegood.weightPounds);

    printf("Patient data: %d in, %d lbs\n", lunaLovegood.heightInches, lunaLovegood.weightPounds);

    /* Inventory tag struct example */
    InventoryTag redSweater;

    scanf("%d", &redSweater.itemID);
    scanf("%d", &redSweater.quantityRemaining);

    printf("Inventory ID: %d, Qty: %d\n", redSweater.itemID, redSweater.quantityRemaining);

    return 0;
}