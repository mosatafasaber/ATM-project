#include "atm.h"

// Function to update the transaction file
void updateTransactionFile(string fileName, string transactionType, float amount) {
    ofstream transactionFile;
    transactionFile.open(fileName, ios::app);
    if (transactionFile.is_open()) {
        time_t now = time(0);
        char* dt = ctime(&now);
        transactionFile << transactionType << "\t" << amount << "\t" << dt;
        transactionFile.close();
    }
    else {
        cout << "Unable to update transaction file!" << endl;
    }
}

// Function to deposit money
void deposit(float& balance) {
    float amount;
    cout << "Enter the amount to be deposited: ";
    cin >> amount;
    balance += amount;
    cout << "Deposit of $" << amount << " successful!" << endl;
    cout<<"your balance is"<<balance<<endl;
    // Update transaction file
    updateTransactionFile("transaction.txt", "Deposit", amount);
}

// Function to withdraw money
void withdraw(float& balance) {
    float amount;
    cout << "Enter the amount to be withdrawn: ";
    cin >> amount;
    
    if (amount <= balance) {
        balance -= amount;
        cout << "Withdrawal of $" << amount << " successful!" << endl;
            cout<<"your balance is"<<balance<<endl;

        // Update transaction file
        updateTransactionFile("transaction.txt", "Withdrawal", amount);
    }
    else {
        cout << "Insufficient balance!" << endl;
    }
}

// Function to get the account balance
void getBalance(float balance) {
    cout << "Your current balance is: $" << balance << endl;
}

// Function to display the transaction information
void getTransactionInfo() {
    string line;
    ifstream transactionFile("transaction.txt");
    
    if (transactionFile.is_open()) {
        cout << "Transaction history:" << endl;
        while (getline(transactionFile, line)) {
            cout << line << endl;
        }
        transactionFile.close();
    }
    else {
        cout << "No transaction history found!" << endl;
    }
}