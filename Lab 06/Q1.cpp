/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>

using namespace std;

class Bankaccount
{
private:
    int accountId;
    double balance;
    int *transactionHistory;
    int numTransactions;

public:
    // initialize account information and allocate memory
    Bankaccount(int accountId, double balance, int *transaction, int numTransactions) : accountId(accountId), balance(balance), numTransactions(numTransactions)
    {
        transactionHistory = new int[numTransactions];
        for (int i = 0; i < numTransactions; i++)
        {
            transactionHistory[i] = transaction[i];
        }
    }

    // Copy constructor
    Bankaccount(const Bankaccount &obj) : accountId(obj.accountId), balance(obj.balance), numTransactions(obj.numTransactions)
    {
        transactionHistory = new int[numTransactions];
        for (int i = 0; i < numTransactions; i++)
        {
            transactionHistory[i] = obj.transactionHistory[i];
        }
    }

    // Destructor
    ~Bankaccount()
    {
        delete[] transactionHistory;
    }

    // display Function
    void display() const
    {
        cout << "Account ID: " << accountId << endl
             << "Balance: " << balance << endl
             << "Transaction History: ";
        for (int i = 0; i < numTransactions; ++i)
        {
            cout << transactionHistory[i] << " ";
        }
        cout << endl;
    }

    // updateTransactionHistory() Function
    void updateTransactionHistory(int *transactions, int numTransactions)
    {
        delete[] transactionHistory;
        this->numTransactions = numTransactions;
        transactionHistory = new int[numTransactions];
        for (int i = 0; i < numTransactions; ++i)
        {
            transactionHistory[i] = transactions[i];
        }
    }
};

int main()
{

    int transactions[] = {123, 334, 80};
    Bankaccount initial(12345, 6908.00, transactions, 3);
    Bankaccount copiedAccount(initial);

    cout << "---- Original Account ----" << endl;
    initial.display();
    cout << endl;

    cout << "---- Copied Account ----" << endl;
    copiedAccount.display();
    cout << endl;

    int updatedTransactions[] = {200, -100};
    initial.updateTransactionHistory(updatedTransactions, 2);

    cout << "---- Updated Account ----" << endl;
    initial.display(); 
    
    return 0;
}
 