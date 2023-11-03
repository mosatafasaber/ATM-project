#include "atm.h"
#include "atm.cpp"

// global variables
int option;


int main() 
{

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
    
    return 0;
}