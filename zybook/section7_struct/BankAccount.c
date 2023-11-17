#include <stdio.h>
#include "BankAccount.h"
#include <string.h>

BankAccount InitBankAccount(char* newName, double amt1, double amt2)
{
    BankAccount newAccount;
    strcpy(newAccount.name, newName);
    newAccount.checkingBalance = amt1;
    newAccount.savingsBalance = amt2;

    return newAccount; 
}


BankAccount SetName(char* newName, BankAccount account)
{
    strcpy(account.name, newName);
    return account;
}

void GetName(char* customerName, BankAccount account)
{
    strcpy(customerName, account.name);
    printf("%s\n", customerName);
}

BankAccount SetChecking(double amt, BankAccount account)
{
    account.checkingBalance = amt;
    return account;
}


double GetChecking(BankAccount account)
{
    return account.checkingBalance;
}

BankAccount SetSavings(double amt, BankAccount account)
{
    account.savingsBalance = amt;
    return account;
}
double GetSavings(BankAccount account)
{
    return account.savingsBalance;
}

BankAccount DepositChecking(double amt, BankAccount account)
{
    if (amt > 0){
        account.checkingBalance += amt;
    }
    
    return account;
}

BankAccount DepositSavings(double amt, BankAccount account)
{
    if (amt > 0){
        account.savingsBalance += amt;
    }
    return account;
}

BankAccount WithdrawChecking(double amt, BankAccount account)
{
    if (amt > 0){
        account.checkingBalance -= amt;
    }
    return account;
}

BankAccount WithdrawSavings(double amt, BankAccount account)
{
    if (amt > 0){
        account.savingsBalance -= amt;
    }
    return account;
}

BankAccount TransferToSavings(double amt, BankAccount account)
{
    if (amt > 0){
        account.checkingBalance -= amt;
        account.savingsBalance += amt;
    }

    return account;
}