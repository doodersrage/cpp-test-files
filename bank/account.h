#include<iostream>
#include<string>
using namespace std; 

class Account{
private:
	string customerName;
	double balance;
public:
	void setCustomerName(string);
	string getCustomerName();
	void setBalance(double);
	double getBalance();
};