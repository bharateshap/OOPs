#include <iostream>
#include <string>
using namespace std;

struct Account {
    string account_number;
    double balance;
};

void init_account(Account &acc) {
    cout << "Enter account number: ";
    cin >> acc.account_number;
    cout << "Enter initial balance: ";
    cin >> acc.balance;
}

void deposit(Account &acc, double amount) {
    acc.balance += amount;
}

void withdraw(Account &acc, double amount) {
    if (acc.balance < amount) {
        cout << "Insufficient balance" << endl;
    } else {
        acc.balance -= amount;
    }
}

void display_balance(const Account &acc) {
    cout << "Account number: " << acc.account_number << endl;
    cout << "Current balance: $" << acc.balance << endl;
}

struct CheckingAccount : public Account {
    double monthly_fee;
};

void init_checking_account(CheckingAccount &chk_acc) {
    init_account(chk_acc);
    cout << "Enter monthly fee: ";
    cin >> chk_acc.monthly_fee;
}

void deduct_monthly_fee(CheckingAccount &chk_acc) {
    chk_acc.balance -= chk_acc.monthly_fee;
}

int main() {
    Account my_account;
    init_account(my_account);
    deposit(my_account, 500.0);
    withdraw(my_account, 200.0);
    display_balance(my_account);

    CheckingAccount my_checking_account;
    init_checking_account(my_checking_account);
    deposit(my_checking_account, 1000.0);
    deduct_monthly_fee(my_checking_account);
    display_balance(my_checking_account);

    return 0;
}
