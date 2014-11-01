// Robert S. McDowell
// 10/29/2014
// Bank program
#include<iostream>
#include<string>
#include"account.h"
#include"atm.h"
using namespace std;

int main(){
	// set vars
	int mnuOpt = 0;
	string cName,strBuffer;
	double usrAmt;

	// assign class objects
	Account aAccount;

	// gather initial values
	cout << "Enter your name: ";
	getline(cin, cName);
	aAccount.setCustomerName(cName);

	cout << "Enter your initial balance : ";
	cin >> usrAmt;
	aAccount.setBalance(usrAmt);

	// set initial ATM values
	ATM aATM(aAccount.getCustomerName(), aAccount.getBalance());

	while (mnuOpt != 6){

		// clear console
		system("CLS");

		// print user menu
		cout << aATM.getName() << ", what would you like to do today?" << endl;
		cout << "1. Deposit funds" << endl;
		cout << "2. Withdraw funds" << endl;
		cout << "3. Get Balance" << endl;
		cout << "4. Change name on account" << endl;
		cout << "5. Get Name on account" << endl;
		cout << "6. QUIT" << endl;

		// gather user input
		cin >> mnuOpt;

		// clear console
		system("CLS");

		// perform selected action
		switch (mnuOpt){
		case 1:
			// deposit funds
			cout << "What amount would you like to deposit? ";
			cin >> usrAmt;
			aATM.credit(usrAmt);
			// update user account balance
			aAccount.setBalance(aATM.getBalance());
			break;
			// withdraw funds
		case 2:
			cout << "What amount would you like to withdraw from your account? ";
			cin >> usrAmt;
			aATM.debit(usrAmt);
			// update user account balance
			aAccount.setBalance(aATM.getBalance());
			break;
			// get user balance
		case 3:
			cout << "Available balance: $" << aATM.getBalance() << endl;
			break;
			// change name on account
		case 4:
			cout << "Please enter a new name: ";
			getline(cin, cName);
			aAccount.setCustomerName(cName);
			aATM.setName(aAccount.getCustomerName());
			break;
			// print name on account
		case 5:
			cout << "Name on account: " << aATM.getName() << endl;
			break;
		case 6:
			cout << "Thank you for banking with CIS203 bank!!" << endl;
			break;
		default:
			cout << "An invalid entry was detected. Please try again!" << endl;
			break;
		}

		cout << "Press enter to continue." << endl;
		cin.clear(); cin.ignore(INT_MAX,'\n'); 
		cin.get();
	}
}