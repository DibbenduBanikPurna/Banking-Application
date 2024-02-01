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

    void displayAllAccounts()
    {
        if (accounts.empty())
        {
            cout << "No accounts found.\n";
            return;
        }

        cout << "Account details:\n";
        for (const auto& account : accounts)
        {
            cout << "Account Number: " << account.accountNumber << "\n";
            cout << "Account Holder: " << account.accountHolder << "\n";
            cout << "Balance: " << account.balance << "\n\n";
        }
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
                  "2. Display all accounts\n"
                  "3. Exit\n"
                  "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bank.createAccount();
            break;
        case 2:
            bank.displayAllAccounts();
            break;
        case 3:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    }
    while (choice != 3);

    return 0;
}
