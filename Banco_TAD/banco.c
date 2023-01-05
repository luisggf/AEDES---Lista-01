#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "banco.h"

void withdraw(BankAccount *x, float value)
{
    x->balance -= value;
}

void deposit(BankAccount *x, float value)
{
    x->balance += value;
}
void create(BankAccount *x)
{
    srand(time(NULL));
    x->balance = 0;
    x->number = rand() % 999;
}
void show_info(BankAccount x)
{
    printf("\nCurrent account balance: %.2f\n", x.balance);
    printf("Account number: %d\n", x.number);
}

void menu()
{
    BankAccount acc1;
    create(&acc1);
    int flag = 0;
    float amount_w;
    float amount;
    do
    {
        printf(" Press: \n (1) To see current balance: \n (2) To withdraw: \n (3) to deposit: \n (4) to exit!\n Option: ");
        scanf("%d", &flag);
        switch (flag)
        {
        case 1:

            show_info(acc1);
            break;
        case 2:
            printf("Inform withdraw amount: ");
            scanf("%f", &amount_w);
            if (acc1.balance <= -100.00)
            {
                printf("Your account doesn't have enough to withdraw! You must deposit %.2f to be able to withdraw again!\n", (acc1.balance * (-1)));
                break;
            }
            withdraw(&acc1, amount_w);
            break;
        case 3:
            printf("Inform deposit amount: ");
            scanf("%f", &amount);
            deposit(&acc1, amount);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("\nPlease inform a number between range (1-4)!");
        }
    } while (flag != 4);
}

