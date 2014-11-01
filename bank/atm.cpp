#include"atm.h"
ATM::ATM(){
	balance = 0;
}
ATM::ATM(string newName, double amt){
	name = newName;
	if (amt < 0){
		balance = 0;
	}
	else {
		balance = amt;
	}
}
void ATM::credit(double amt){
	if (amt < 0){
		cout << "Error! Deposit amount must be greater than 0!" << endl;
	}
	else{
		cout << "$" <<  amt << " has been credited to your account." << endl;
		balance += (double) amt;
	}
}
void ATM::debit(double amt){
	if (amt > balance){
		cout << "We are sorry but that amount is greater than your available balance!" << endl;
	}
	else {
		cout << "$" << amt << " has been removed from your account." << endl;
		balance -= (double)amt;
	}
}
double ATM::getBalance(){
	return balance;
}
void ATM::setName(string newName){
	name = newName;
}
string ATM::getName(){
	return name;
}