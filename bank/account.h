#include<iostream>
#include<string>
#include"atm.h"
using namespace std; 

class Account : public ATM{
private:
	string customerName;
	double balance;
public:
	Account(string, double);
	void updateBalance();
	void setCustomerName(string);
	string getCustomerName();
	void setBalance(double);
	double getBalance();
};