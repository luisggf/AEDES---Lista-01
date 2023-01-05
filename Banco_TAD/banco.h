#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED

typedef struct BANK_
{
    float balance;
    int number;
} BankAccount;

void withdraw(BankAccount *x, float value);
void deposit(BankAccount *x, float value);
void create(BankAccount *x);
void show_info(BankAccount x);
void menu();

#endif // BANCO_H_INCLUDED
