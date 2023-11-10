#include<iostream>
#include<fstream>
#include<ctime>
#include<string>
using namespace std;
void updateTransactionFile (string fileName, string transactionType, float amount);
void deposit(float&);
void withdraw(float&);
void getBalance(float);
void getTransactionInfo();
void run();