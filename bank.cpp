#include<bits/stdc++.h>
using namespace std;

class BankAccount
{
public:
    int accountNumber;
    string accountHolder;
    double balance;

    BankAccount(int accNum, const string& accHolder, double bal)
        : accountNumber(accNum), accountHolder(accHolder), balance(bal) {}
};

class Bank
{
private:
    vector<BankAccount> accounts;

public:
    void createAccount()
    {
        int accNum;
        string accHolder;
        double balance;

        cout << "Enter account number: ";
        cin >> accNum;
        cin.ignore(); // Clear input buffer
        cout << "Enter account holder name: ";
        getline(std::cin, accHolder);
        cout << "Enter initial balance: ";
        do
        {
            cin >> balance;

            if(balance<50)
            {
                cout<<"Initial balance must be greater than 50. please enter again"<<std::endl;
            }
        }
        while(balance<50);
        BankAccount newAccount(accNum, accHolder, balance);
        accounts.push_back(newAccount);

        std::cout << "Account created successfully!\n";
    }

};

int main()
{
    Bank bank;

    int choice;
    do
    {
        cout << "\nMenu:\n"
             "1. Create a new account\n"
             "2. Exit\n"
             "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bank.createAccount();
            break;
        }
    }
    while (choice != 2);
    return 0;
}
