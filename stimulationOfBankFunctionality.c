/*
Name : Ayesha Siddiqua
Date : 2/22/2020
Project 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu();
/* #1 */ void new_accounts(int *, float *, int *, float *);
/* #2 */ void summary(int, float, int, float);
/* #3 */ void withdraw(int, float *, float);
/* #4 */ void deposit(int, float *, float);
/* #5 */ void transfer(int, float *, int, float *, float);
/* #6 */ void exchange(int, float *, int, float *);
/* #7 */ int *high_balance(int *, float, int *, float, float *);
/* #8 */ void reset(float *, float *);
/* #9 */ void change(int *, int);

int main(void)
{
    srand((unsigned) time(NULL));
    menu();

    return 0;
}

int menu() {

    int user;

    int aNo1, aNo2;
    float b1, b2;

    int user_choose_acc;
    int to, from;
    char result = 'a';

    float difference = 0.0f;
    //int *p; ***** changed
    //int * p = NULL;
    int * p;
    withdraw_invalid_acc: ;

    do {
        printf("\n");
        printf(":-------------------------------------------\n");
        printf(": Main Menu\n");
        printf(":\n");
        printf(": 1 New Accounts\n");
        printf(": 2 All Accounts\n");
        printf(": 3 Withdraw\n");
        printf(": 4 Deposit\n");
        printf(": 5 Transfer Funds\n");
        printf(": 6 Exchange Balance\n");
        printf(": 7 High Balance\n");
        printf(": 8 Reset All Balance\n");
        printf(": 9 Change Account Number\n");
        printf(": 0 Exit\n");
        printf(":-------------------------------------------\n");
        printf("--> Choose your transaction (1, 2,..... 9, or 0 to exit): ");
        scanf("%d", &user);
        printf("\n");

        switch(user) {
            case 1: new_accounts(&aNo1, &b1, &aNo2, &b2); break;

            case 2: summary(aNo1, b1, aNo2, b2); break;

            case 3:
                printf("Enter account to withdraw (%d or %d): ", aNo1, aNo2);
                scanf("%d", &user_choose_acc);

                if( (user_choose_acc != aNo1) && (user_choose_acc != aNo2)  ) {
                    printf("\n>>>> Account %d doesn't exist!\n", user_choose_acc);
                    goto withdraw_invalid_acc;
                } // end if

                float amountToWithdraw;
                printf("Enter amount to withdraw: $");
                scanf("%f", &amountToWithdraw);

                if((user_choose_acc == aNo1)) {
                    withdraw(aNo1, &b1, amountToWithdraw);
                }

                if((user_choose_acc == aNo2)) {
                    withdraw(aNo2, &b2, amountToWithdraw);
                }

                break;

            case 4:
                printf("Enter account to deposit (%d or %d): ", aNo1, aNo2);
                scanf("%d", &user_choose_acc);

                if( (user_choose_acc != aNo1) && (user_choose_acc != aNo2)  ) {
                    printf("\n>>>> Account %d doesn't exist!\n", user_choose_acc);
                    goto withdraw_invalid_acc;
                } // end if

                float amountToDeposit;
                printf("Enter amount to deposit: $");
                scanf("%f", &amountToDeposit);

                //withdraw(int, float *, float);

                if((user_choose_acc == aNo1)) {
                    deposit(aNo1, &b1, amountToDeposit);
                }

                if((user_choose_acc == aNo2)) {
                    deposit(aNo2, &b2, amountToDeposit);
                }

                break;

            case 5:
                printf("Enter \'FROM\' account and \'TO\' account separated by a space: ");
                scanf("%d %d", &from, &to);

                if( to == from ) {
                    printf("\n>>>> Cannot transfer from and to the same account!\n");
                    goto withdraw_invalid_acc;
                }

                if( (to!=aNo1) && (to!=aNo2) ) {
                    printf(">>>> Account %d doesn't exist!", to);
                    break;
                }

                if( (from!=aNo1) && (from!=aNo2) ) {
                    printf(">>>> Account %d doesn't exist!", from);
                    break;
                }

                float amountToTransfer;
                printf("Enter amount to transfer: $");
                scanf("%f", &amountToTransfer);

                if( (from == aNo1) && (to == aNo2) ) {
                    transfer(from, &b1, to, &b2, amountToTransfer);
                }

                if( (to == aNo1) && (from == aNo2) ) {
                    transfer(to, &b1, from, &b2, amountToTransfer);
                }

                break;

            case 6:
                printf("Are you sure you want to exchange balance of account %d and %d (y/n) ", aNo1, aNo2);
                while (getchar() != '\n') {}
                result = getchar();

                if( result == 'y' || result == 'Y') {
                    exchange(aNo1, &b1, aNo2, &b2);
                }else{
                    printf("\n");
                }

                break;

            case 7:
                p =  high_balance(&aNo1, b1, &aNo2, b2, &difference);


                if(*p == aNo1) {
                    printf("\n");
                    printf(">>>> Account %d ($%.2f) has balance of %.2f more than account %d ($%.2f)", *p, b1, difference, aNo2, b2);
                    printf("\n");
                    break;
                }

                if(*p == aNo2) {
                    printf("\n");
                    printf(">>>> Account %d ($%.2f) has balance of %.2f more than account %d ($%.2f)", *p, b2, difference, aNo1, b1);
                    printf("\n");
                    break;
                }


                printf("\n>>>>No any account's balance is $200 or higher than the other's\n");
                break;


            case 8:
                printf("Are you sure to reset balance of both accounts(y\\n)? ", aNo1, aNo2);


                while (getchar() != '\n') {}
                result = getchar();

                if( result == 'y' || result == 'Y') {
                    reset(&b1, &b2);
                }

                printf("\n");
                break;


            case 9:
                printf("\nWhich account number to change, %d or %d? ", aNo1, aNo2);
                scanf("%d", &user_choose_acc);

                if( (user_choose_acc != aNo1) && (user_choose_acc != aNo2)  ) {
                    printf("\n>>>> Account %d doesn't exist!\n", user_choose_acc);
                    goto withdraw_invalid_acc; //break??
                } // end if
                printf("\n");
                if(user_choose_acc == aNo1) {
                    change(&aNo1, aNo2);
                }

                if(user_choose_acc == aNo2) {
                    change(&aNo2, aNo1);
                }
                printf("\n");
                break;

            case 0: printf(">>>> GOOD BYE!\n"); break;
            default: printf("Please choose number between 0 and 9 inclusive.");
                    break;
        } // end switch

    }while(user != 0); // end WHILE LOOP
} // end menu()

void new_accounts(int *accountNumber1, float *balance1, int *accountNumber2, float *balance2) {

    //*accountNumber1 = (rand() % (upper - lower + 1)) + lower;
    *accountNumber1 = (rand() % (59 - 55 + 1)) + 55;
    *accountNumber2 = (rand() % (59 - 55 + 1)) + 55;

    while(*accountNumber2 == *accountNumber1) {
        *accountNumber2 = (rand() % (59 - 55 + 1)) + 55;
    }

    *balance1 =  ( (rand() % (99999 - (-10000) + 1)) + (-10000) );
    //printf("Old balance1: %f\n", *balance1);
    *balance1 =  *balance1 / 100.0;
    //printf("New balance1: %f\n", *balance1);


    *balance2 =  ( (rand() % (99999 - (-10000) + 1)) + (-10000) );
    //printf("Old balance2: %f\n", *balance2);
    *balance2 =  *balance2 / 100.0;
    //printf("New balance2: %f\n", *balance2);

    printf("\n>>>> Two accounts created!\n");

} // end new_accounts

void summary(int accountNumber1, float balance1, int accountNumber2, float balance2) {

    printf("\n>>>> %d:  $%.2f\n", accountNumber1, balance1);
    printf(">>>> %d:  $%.2f\n", accountNumber2, balance2);

} // end summary

void withdraw(int accountNumber1Or2, float *balance1Or2, float amountToWithdraw) {
    printf("\n>>>> Account %d balance changed from $%.2f", accountNumber1Or2, *balance1Or2);
    *balance1Or2 = *balance1Or2 - amountToWithdraw;
    printf(" to $%.2f\n", *balance1Or2);
} // end withdraw

void deposit(int accountNumber1Or2, float *balance1Or2, float amountToDeposit) {
    printf("\n>>>> Account %d balance changed from $%.2f", accountNumber1Or2, *balance1Or2);
    *balance1Or2 = *balance1Or2 + amountToDeposit;
    printf(" to $%.2f\n", *balance1Or2);

}

void transfer(int fromAccount, float *fromBalance, int toAccount, float *toBalance, float amountToTransfer) {
    printf("\n>>>> Account %d balance changed from $%.2f", fromAccount, *fromBalance);
    *fromBalance = *fromBalance - amountToTransfer;
    printf(" to $%.2f", *fromBalance);

    printf("\n>>>> Account %d balance changed from $%.2f", toAccount, *toBalance);
    *toBalance = *toBalance + amountToTransfer;
    printf(" to $%.2f\n", *toBalance);
}

void exchange(int accountNumber1, float *balance1, int accountNumber2, float *balance2) {
    float temp = *balance1;

    printf("\n>>>> Account %d balance changed from $%.2f", accountNumber1, *balance1);
    *balance1 = *balance2;
    printf(" to $%.2f\n", *balance1);

    printf(">>>> Account %d balance changed from $%.2f", accountNumber2, *balance2);
    *balance2 = temp;
    printf(" to $%.2f\n", *balance2);

} // end exchange


int *high_balance(int *accountNumber1, float balance1, int *accountNumber2, float balance2, float *difference) {

    if(balance1 - balance2 >= 200) {
        *difference = balance1 - balance2;
        return accountNumber1;
    }

    if(balance2 - balance1 >= 200) {
        *difference = balance2 - balance1;
        return accountNumber2;
    }

    return NULL;


} // end *high_balance

void reset(float *balance1, float *balance2) {
    *balance1 = 0.0f;
    *balance2 = 0.0f;
    printf("\n");
    printf(">>>>Balance of both accounts are reset to $0.00");
} // end reset

void change(int *accountNumber1Or2Pointer, int accountNumber1Or2) {
    printf(">>>> Account %d is now", *accountNumber1Or2Pointer);

    *accountNumber1Or2Pointer = (rand() % (59 - 55 + 1)) + 55;
    while(*accountNumber1Or2Pointer == accountNumber1Or2) {
        *accountNumber1Or2Pointer = (rand() % (59 - 55 + 1)) + 55;
    }
    printf(" changed to %d", *accountNumber1Or2Pointer);
} // end change
