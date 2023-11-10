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
void run()
{
    int option;
    float balance=1000;
int password=1234;

   ifstream datafile("data.txt");

   if (datafile.is_open())
   {
    datafile>>balance;

   }

    cout <<"Enter your passward \n";
    cin>>password;
    if (password==2512)
    {

    cout << "Welcome to the ATM program!" << endl;
    
   do {
        cout << "\nSelect an option:" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Balance Inquiry" << endl;
        cout << "4. Transaction Information" << endl;
        cout << "5. Exit" << endl;
        cout << "Option: ";
        cin >> option;
        
        switch (option) {
            case 1:
                deposit(balance);
                break;
            case 2:
                withdraw(balance);
                break;
            case 3:
                getBalance(balance);
                break;
            case 4:
                getTransactionInfo();
                break;
            case 5:
                // Save data before exiting the program
                {
                    ofstream dataFile("data.txt");
                    if (dataFile.is_open()) {
                        dataFile << balance << endl;
                        dataFile.close();
                        cout << "Data saved successfully!" << endl;
                    }
                    else {
                        cout << "Unable to save data!" << endl;
                    }
                }
                cout << "Exiting the program. Goodbye!" << endl;
              break;
            default:
                cout << "Invalid option!" << endl;
                break;
        }
    }while(option <5);
    }
    else
    {
        cout<<"incorrect password \n";
        option=5;
    }
    
}