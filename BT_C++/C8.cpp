#include <stdio.h>
#include <string.h>
#include <stdint.h>

class Bank{
    private:
        uint16_t accountNumber;
        char accountName[30];
        double balance;
    public:
        Bank(uint16_t accNum, char accName[30], double bal);

        void setAccountName(char accName[]);
        void setAccountNumber(uint16_t accNum);
        void setBalance(double bal);

        uint16_t getAccountNumber();
        char *getAccountName();
        double getBalance();

        void deposit(double amount);
        void withdraw(double amount);
        void checkBalance();
};

Bank::Bank(uint16_t accNum, char accName[30], double bal){
    accountNumber = accNum;
    strcpy(accountName, accName);
    balance = bal;
}

void Bank::setAccountName(char accName[]){
    strcpy(accountName, accName);
}

void Bank::setAccountNumber(uint16_t accNum){
    accountNumber = accNum;
}

void Bank::setBalance(double bal){
    balance = bal;
}

uint16_t Bank::getAccountNumber(){
    return accountNumber;
}
char* Bank::getAccountName(){
    return accountName;
}
double Bank::getBalance(){
    return balance;
}

void Bank::deposit(double amount){
    balance += amount;
}

void Bank::withdraw(double amount){
    if(balance >= amount){
        balance -= amount;
    }
    else{
        printf("Withdrawal amount exceeds the balance.\n");
    }
}

void Bank::checkBalance(){
    printf("Account Name: %s\n", accountName);
    printf("Account Number: %d\n", accountNumber);
    printf("Current Balance: %f\n", balance);
}

enum type{
    CHECK= 1,
    DEPOSIT= 2,
    WITHDRAW = 3,
    EXIT= 4 
}type;

int main(int argc, char const *argv[])
{
    
    uint16_t accountNumber;
    char accountName[30];
    double balance;

    printf("Enter account number: ");
    scanf("%hu", &accountNumber);

    

    printf("Enter account name: ");
    scanf("%s", accountName);

    printf("Enter balance: ");
    scanf("%lf", &balance);

    Bank myAccount(accountNumber, accountName, balance);

    int choice;
    double amount;


    do {
        printf("Select an option:\n");
        printf("1. Check balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case CHECK:
                myAccount.checkBalance();
                break;
            case DEPOSIT:
                printf("Enter deposit amount: ");
                scanf("%lf", &amount);
                myAccount.deposit(amount);
                break;
            case WITHDRAW:
                printf("Enter withdraw amount: ");
                scanf("%lf", &amount);
                myAccount.withdraw(amount);
                break;
            case EXIT:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    } while (choice != 4);

    return 0;


}
