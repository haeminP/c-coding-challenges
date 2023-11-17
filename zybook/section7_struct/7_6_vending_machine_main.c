#include <stdio.h>
#include "VendingMachine.h"

int main()
{
    VendingMachine vm;
    int purchaseNum;
    int restockNum;
    
    scanf("%d", &purchaseNum);
    scanf("%d", &restockNum);
    vm = InitVendingMachine();
    vm = Purchase(purchaseNum, vm);
    vm = Restock(restockNum, vm);

    vm.bottles = GetInventory(vm);

    Report(vm);


    return 0;
}