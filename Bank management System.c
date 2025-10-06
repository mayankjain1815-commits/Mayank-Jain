// Bank Management System in C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to hold account information
struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

// Global array to store all accounts
// We can store a maximum of 100 accounts
struct Account accounts[100];
int totalAccounts = 0;

// Function to create a new account
void create_account() {
    if (totalAccounts >= 100) {
        printf("Maximum account limit reached.\n");
        return;
    }

    struct Account newAccount;
    // Assign a simple account number
    newAccount.accountNumber = 1001 + totalAccounts;

    printf("\nEnter account holder's name: ");
    scanf("%s", newAccount.name);

    printf("Enter initial deposit amount: ");
    scanf("%f", &newAccount.balance);

    accounts[totalAccounts] = newAccount;
    totalAccounts++;

    printf("\n✅ Account created successfully!\n");
    printf("Your Account Number is: %d\n", newAccount.accountNumber);
}

// Function to find an account by its number
// Returns the index of the account in the array, or -1 if not found
int find_account(int accNum) {
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            return i; // Found the account at index i
        }
    }
    return -1; // Account not found
}


// Function to deposit money
void deposit_money() {
    int accNum;
    float amount;

    printf("\nEnter your account number: ");
    scanf("%d", &accNum);

    int accountIndex = find_account(accNum);

    if (accountIndex == -1) {
        printf("❌ Error: Account not found.\n");
    } else {
        printf("Enter amount to deposit: ");
        scanf("%f", &amount);

        if (amount <= 0) {
            printf("❌ Error: Invalid deposit amount.\n");
        } else {
            accounts[accountIndex].balance += amount;
            printf("✅ Rs. %.2f deposited successfully.\n", amount);
            printf("New Balance: Rs. %.2f\n", accounts[accountIndex].balance);
        }
    }
}

// Function to withdraw money
void withdraw_money() {
    int accNum;
    float amount;

    printf("\nEnter your account number: ");
    scanf("%d", &accNum);

    int accountIndex = find_account(accNum);

    if (accountIndex == -1) {
        printf("❌ Error: Account not found.\n");
    } else {
        printf("Enter amount to withdraw: ");
        scanf("%f", &amount);

        if (amount <= 0) {
            printf("❌ Error: Invalid withdrawal amount.\n");
        } else if (amount > accounts[accountIndex].balance) {
            printf("❌ Error: Insufficient balance.\n");
        } else {
            accounts[accountIndex].balance -= amount;
            printf("✅ Rs. %.2f withdrawn successfully.\n", amount);
            printf("Remaining Balance: Rs. %.2f\n", accounts[accountIndex].balance);
        }
    }
}

// Function to check account details
void check_balance() {
    int accNum;
    printf("\nEnter your account number: ");
    scanf("%d", &accNum);

    int accountIndex = find_account(accNum);

    if (accountIndex == -1) {
        printf("❌ Error: Account not found.\n");
    } else {
        printf("\n--- Account Details ---\n");
        printf("Account Number: %d\n", accounts[accountIndex].accountNumber);
        printf("Account Holder: %s\n", accounts[accountIndex].name);
        printf("Current Balance: Rs. %.2f\n", accounts[accountIndex].balance);
        printf("-----------------------\n");
    }
}


int main() {
    int choice;

    while (1) {
        // Display the main menu
        printf("\n===== Simple Bank Management System =====\n");
        printf("1. Create a new account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Check account balance\n");
        printf("5. Exit\n");
        printf("=========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit_money();
                break;
            case 3:
                withdraw_money();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                printf("\nThank you for using our banking system. Goodbye! 👋\n");
                exit(0); // Exit the program
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}
