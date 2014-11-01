#include"account.h"

void Account::setCustomerName(string newCustomerName){
	customerName = newCustomerName;
}
string Account::getCustomerName(){
	return customerName;
}
void Account::setBalance(double newBalance){
	balance = newBalance;
}
double Account::getBalance(){
	return balance;
}