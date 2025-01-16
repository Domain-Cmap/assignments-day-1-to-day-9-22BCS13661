#include<iostream>
using namespace std;
class BankAccount {
private:
    int accountNumber;
    double balance;
public:
    BankAccount(int accNum, double bal) {
        accountNumber = accNum;
        balance = bal;
    }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Invalid withdraw amount or insufficient balance." << endl;
        }
    }
    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};
int main() {
    BankAccount account(123456, 1000.0);
    account.display();
    account.deposit(500.0);
    account.withdraw(200.0);
    account.display();
    return 0;
}