/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>

using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(){};
    BankAccount(int accountNumber, string accountHolderName, double balance)
    {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "YOU BROKE!" << endl;
    }

    void display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount account[3];
    account[0] = BankAccount(123, "Areeba", 100);
    account[1] = BankAccount(234, "Rumaisa", 150);
    account[2] = BankAccount(456, "Emman", 100);

    for (int i = 0; i < 3; i++)
    {
        account[i].display();
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "Depositing 500.00 Rs and withdrawing 200.00 Rs from  account # 0" << i+1 << endl;
        account[i].deposit(0.0);
        account[i].withdraw(200.0);
        cout << endl << "Displaying updated information:" << endl;
        account[i].display();
    }
}