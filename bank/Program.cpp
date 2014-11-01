// Robert S. McDowell
// 10/29/2014
// Bank program
#include<iostream>
#include<string>
#include"account.h"
using namespace std;

int main(){
	// set vars
	int mnuOpt = 0;
	string cName,strBuffer;
	double usrAmt = 0;

	// gather initial values
	cout << "Enter your name: ";
	getline(cin, cName);
	cin.clear(); 

	while (usrAmt <= 0 || cin.fail()){
		cout << "Enter your initial balance (positive number please!) : ";
		cin >> usrAmt;
		cin.clear(); cin.ignore(10000, '\n');
	}

	// set initial ATM values
	Account aAccount(cName, usrAmt);

	while (mnuOpt != 6){

		// reset entry amt
		usrAmt = 0;
		mnuOpt = 0;

		// clear console
		while (mnuOpt <= 0 || cin.fail()){
			system("CLS");

			// print user menu
			cout << aAccount.getCustomerName() << ", what would you like to do today?" << endl;
			cout << "1. Deposit funds" << endl;
			cout << "2. Withdraw funds" << endl;
			cout << "3. Get Balance" << endl;
			cout << "4. Change name on account" << endl;
			cout << "5. Get Name on account" << endl;
			cout << "6. QUIT" << endl;

			// gather user input
			cin >> mnuOpt;
			cin.clear(); cin.ignore(10000, '\n');
		}

		// clear console
		system("CLS");

		// perform selected action
		switch (mnuOpt){
		case 1:
			// deposit funds
			while (usrAmt <= 0 || cin.fail()){
				cout << "What amount would you like to deposit? ";
				cin >> usrAmt;
				cin.clear(); cin.ignore(10000, '\n');
			}
			aAccount.credit(usrAmt);
			// update user account balance
			aAccount.updateBalance();
			break;
			// withdraw funds
		case 2:
			while (usrAmt <= 0 || cin.fail()){
				cout << "What amount would you like to withdraw from your account? ";
				cin >> usrAmt;
				cin.clear(); cin.ignore(10000, '\n');
			}
			aAccount.debit(usrAmt);
			// update user account balance
			aAccount.updateBalance();
			break;
			// get user balance
		case 3:
			cout << "Available balance: $" << aAccount.getBalance() << endl;
			break;
			// change name on account
		case 4:
			cout << "Please enter a new name: ";
			getline(cin, cName);
			cin.clear();
			aAccount.setCustomerName(cName);
			cout << "Name on account changed!" << endl;
			break;
			// print name on account
		case 5:
			cout << "Name on account: " << aAccount.getCustomerName() << endl;
			break;
		case 6:
			cout << "Thank you for banking with CIS203 bank!!" << endl;
			break;
		default:
			cout << "An invalid entry was detected. Please try again!" << endl;
			break;
		}

		cout << "Press enter to continue." << endl;
		cin.clear(); 
		cin.get();
	}
}