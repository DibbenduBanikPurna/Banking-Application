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

    void updateAccount()
    {
        int accNum;
        cout << "Enter account number to update: ";
        cin >> accNum;

        auto it = find_if(accounts.begin(), accounts.end(),
                               [accNum](const BankAccount& acc)
        {
            return acc.accountNumber == accNum;
        });

        if (it != accounts.end())
        {
            cout << "Enter new balance: ";
            cin >> it->balance;
            cout << "Account updated successfully!\n";
        }
        else
        {
            cout << "Account not found.\n";
        }
    }

    void deleteAccount()
    {
        int accNum;
        cout << "Enter account number to delete: ";
        cin >> accNum;

        auto it = remove_if(accounts.begin(), accounts.end(),
                                 [accNum](const BankAccount& acc)
        {
            return acc.accountNumber == accNum;
        });

        if (it != accounts.end())
        {
            accounts.erase(it, accounts.end());
            cout << "Account deleted successfully!\n";
        }
        else
        {
            cout << "Account not found.\n";
        }
    }

    void depositAmount()
    {
        int accNum;
        double amount;

        cout << "Enter account number to deposit into: ";
        cin >> accNum;

        auto it = find_if(accounts.begin(), accounts.end(),
                               [accNum](const BankAccount& acc)
        {
            return acc.accountNumber == accNum;
        });

        if (it != accounts.end())
        {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            it->balance += amount;
            cout << "Amount deposited successfully!\n";
        }
        else
        {
            cout << "Account not found.\n";
        }
    }

    void withdrawAmount()
    {
        int accNum;
        double amount;

        cout << "Enter account number to withdraw from: ";
        cin >> accNum;

        auto it = find_if(accounts.begin(), accounts.end(),
                               [accNum](const BankAccount& acc)
        {
            return acc.accountNumber == accNum;
        });

        if (it != accounts.end())
        {
            if(it->balance<50)
            {
                cout<<"You have to have minimum balance of 50 to withdraw. deposit more to withdraw."<<std::endl;
            }
            else
            {
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if (amount <= it->balance)
                {
                    it->balance -= amount;
                    cout << "Amount withdrawn successfully!\n";
                }
                else
                {
                    cout << "Insufficient balance.\n";
                }
            }
        }
        else
        {
            cout << "Account not found.\n";
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
                  "3. Update an account\n"
                  "4. Delete an account\n"
                  "5. Deposit an amount\n"
                  "6. Withdraw an amount\n"
                  "7. Exit\n"
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
            bank.updateAccount();
            break;
        case 4:
            bank.deleteAccount();
            break;
        case 5:
            bank.depositAmount();
            break;
        case 6:
            bank.withdrawAmount();
            break;
        case 7:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    }
    while (choice != 7);

    return 0;
}
