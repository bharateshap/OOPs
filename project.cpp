#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string account_number;
    double balance;
public:
    Account() {
        cout << "Enter account number: ";
        cin >> account_number;
        cout << "Enter initial balance: ";
        cin >> balance;
    }
    
    Account(string number, double initial_balance) : account_number(number), balance(initial_balance) {}

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (balance < amount) {
            cout << "Insufficient balance" << endl;
        } else {
            balance -= amount;
        }
    }

    virtual void display_balance() {
        cout << "Account number: " << account_number << endl;
        cout << "Current balance: $" << balance << endl;
    }
};

class CheckingAccount : public Account {
private:
    double monthly_fee;
public:
    CheckingAccount(string number, double initial_balance, double fee) : Account(number, initial_balance), monthly_fee(fee) {}
    void deduct_monthly_fee() {
        balance -= monthly_fee;
    } };

int main() {
    Account* my_account = new Account();
    my_account->deposit(500.0);
    my_account->withdraw(200.0);
    my_account->display_balance();

    CheckingAccount* my_checking_account = new CheckingAccount("987654321", 2000.0, 5.0);
    my_checking_account->deposit(1000.0);
    my_checking_account->deduct_monthly_fee();
    my_checking_account->display_balance();
 	 return 0;  }
