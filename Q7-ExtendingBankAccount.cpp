#include<iostream>
using namespace std;
class BankAccount {
protected:
    int accountNumber;
    double balance;
public:
    BankAccount(int accNum, double bal) {
        accountNumber = accNum;
        balance = bal;
    }
    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }
    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Invalid withdraw amount or insufficient balance." << endl;
        }
    }
    virtual void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};
class SavingsAccount : public BankAccount {
private:
    double interestRate;
public:
    SavingsAccount(int accNum, double bal, double rate) : BankAccount(accNum, bal) {
        interestRate = rate;
    }
    void applyInterest() {
        balance += balance * interestRate;
        cout << "Interest applied at rate: " << interestRate << endl;
    }
    void display() override {
        BankAccount::display();
        cout << "Interest Rate: " << interestRate << endl;
    }
};
class CheckingAccount : public BankAccount {
private:
    double withdrawalFee;
public:
    CheckingAccount(int accNum, double bal, double fee) : BankAccount(accNum, bal) {
        withdrawalFee = fee;
    }
    void withdraw(double amount) override {
        if (amount > 0 && (amount + withdrawalFee) <= balance) {
            balance -= (amount + withdrawalFee);
            cout << "Withdrawn: " << amount << " with fee: " << withdrawalFee << endl;
        } else {
            cout << "Invalid withdraw amount or insufficient balance." << endl;
        }
    }
    void display() override {
        BankAccount::display();
        cout << "Withdrawal Fee: " << withdrawalFee << endl;
    }
};
int main() {
    SavingsAccount savings(123456, 1000.0, 0.05);
    CheckingAccount checking(654321, 1000.0, 2.0);
    savings.display();
    savings.deposit(500.0);
    savings.applyInterest();
    savings.display();
    checking.display();
    checking.deposit(500.0);
    checking.withdraw(200.0);
    checking.display();
    return 0;
}