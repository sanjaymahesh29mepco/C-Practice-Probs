/*create a C program that demonstrates a simple banking system that utilizes an array of structures to manage bank accounts, highlighting how memory is allocated for these structures in a contiguous block.*/
#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 5

struct BankAccount {
    int accountNumber;
    char holderName[50];
    double balance;
};

void deposit(struct BankAccount *acc, double amount);
void withdraw(struct BankAccount *acc, double amount);
void displayMemoryStatus(struct BankAccount accs[], int count);

int main() {
    struct BankAccount accounts[MAX_ACCOUNTS];
    int accountCount = 0;
    int choice,index;
    double amount;

    printf("---Online Banking System ---\n");
    printf("Initial Array Base Address: %p\n", (void*)accounts);

    while (1) {
        printf("\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Show Memory Info\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (accountCount < MAX_ACCOUNTS) {
                    accounts[accountCount].accountNumber = 1000 + accountCount;
                    printf("Holder Name: ");
                    scanf("%s", accounts[accountCount].holderName);
                    accounts[accountCount].balance = 0.0;
                    printf("Account created at Address: %p\n", (void*)&accounts[accountCount]);
                    accountCount++;
                } else {
                    printf("Maximum limit reached!\n");
                }
                break;

            case 2:
                printf("Account Index (0 to %d): ", accountCount - 1);
                scanf("%d", &index);
                if (index >= 0 && index < accountCount) {
                    printf("Deposit Amount: ");
                    scanf("%lf", &amount);
                    deposit(&accounts[index], amount);
                }
                break;

            case 3:
                printf("Account Index (0 to %d): ", accountCount - 1);
                scanf("%d", &index);
                if (index >= 0 && index < accountCount) {
                    printf("Withdrawal Amount: ");
                    scanf("%lf", &amount);
                    withdraw(&accounts[index], amount);
                }
                break;

            case 4:
                displayMemoryStatus(accounts, accountCount);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

void deposit(struct BankAccount *acc, double amount) {
    acc->balance += amount;
    printf("Balance Updated: $%.2f (Updated at Address: %p)\n", acc->balance, (void*)acc);
}

void withdraw(struct BankAccount *acc, double amount) {
    if (amount > acc->balance) {
        printf("Insufficient funds!\n");
    } else {
        acc->balance -= amount;
        printf("Balance Updated: $%.2f (Updated at Address: %p)\n", acc->balance, (void*)acc);
    }
}

void displayMemoryStatus(struct BankAccount accs[], int count) {
   int i;
   printf("\n--- Memory Layout of Accounts ---\n");
    for (i = 0; i < count; i++) {
        printf("Index %d | Name: %-10s | Address: %p | Size: %lu bytes\n",
               i, accs[i].holderName, (void*)&accs[i], sizeof(struct BankAccount));
    }
}
