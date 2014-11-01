#include<iostream>
#include<string>
using namespace std;

class ATM{
private:
	double balance;
	string name;
public:
	ATM();
	ATM(string, double);
	void credit(double amt);
	void debit(double amt);
	double getBalance();
	void setName(string newName);
	string getName();
};