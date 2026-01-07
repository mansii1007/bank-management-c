#include <stdio.h>

#define MAX 100

struct Bank {
    int acc_no;
    char name[50];
    double balance;
};

struct Bank customers[MAX];
int count = 0;

void createAccount() {
    if (count >= MAX) {
        printf("Maximum account limit reached!\n");
        return;
    }

    int acc;
    printf("\n--- Create Account ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc);

    // Check duplicate account
    for (int i = 0; i < count; i++) {
        if (customers[i].acc_no == acc) {
            printf("Account number already exists!\n");
            return;
        }
    }

    customers[count].acc_no = acc;

    printf("Enter Name: ");
    scanf(" %[^\n]", customers[count].name);

    printf("Enter Initial Balance: ");
    scanf("%lf", &customers[count].balance);

    if (customers[count].balance < 0) {
        printf("Invalid balance amount!\n");
        return;
    }

    count++;
    printf("Account Created Successfully!\n");
}

void deposit() {
    int acc;
    double amt;

    printf("\n--- Deposit ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc);

    for (int i = 0; i < count; i++) {
        if (customers[i].acc_no == acc) {
            printf("Enter Amount to Deposit: ");
            scanf("%lf", &amt);

            if (amt <= 0) {
                printf("Invalid amount!\n");
                return;
            }

            customers[i].balance += amt;
            printf("Amount Deposited! New Balance: %.2lf\n", customers[i].balance);
            return;
        }
    }

    printf("Account Not Found!\n");
}

void withdraw() {
    int acc;
    double amt;

    printf("\n--- Withdraw ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc);

    for (int i = 0; i < count; i++) {
        if (customers[i].acc_no == acc) {
            printf("Enter Amount to Withdraw: ");
            scanf("%lf", &amt);

            if (amt <= 0) {
                printf("Invalid amount!\n");
                return;
            }

            if (customers[i].balance >= amt) {
                customers[i].balance -= amt;
                printf("Withdrawal Successful! Remaining Balance: %.2lf\n",
                       customers[i].balance);
            } else {
                printf("Insufficient Balance!\n");
            }
            return;
        }
    }

    printf("Account Not Found!\n");
}

void showBalance() {
    int acc;

    printf("\n--- Check Balance ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc);

    for (int i = 0; i < count; i++) {
        if (customers[i].acc_no == acc) {
            printf("Account No: %d\nName: %s\nBalance: %.2lf\n",
                   customers[i].acc_no,
                   customers[i].name,
                   customers[i].balance);
            return;
        }
    }

    printf("Account Not Found!\n");
}

void displayAll() {
    if (count == 0) {
        printf("\nNo accounts available.\n");
        return;
    }

    printf("\n--- All Accounts ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d) Acc No: %d | Name: %s | Balance: %.2lf\n",
               i + 1,
               customers[i].acc_no,
               customers[i].name,
               customers[i].balance);
    }
}

int main() {
    int ch;

    while (1) {
        printf("\n===== BANK MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Choose Option: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: showBalance(); break;
            case 5: displayAll(); break;
            case 6: 
                printf("Thank you for using Bank Management System!\n");
                return 0;
            default:
                printf("Invalid Choice! Try again.\n");
        }
    }
}
