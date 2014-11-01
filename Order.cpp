// Robert S. McDowell
// 11/1/2014
// final problem 1
// order class
#include<iostream>
#include<string>
using namespace std;

class Order{
private:
	int orderNumber;
	string customerName;
	int quantity;
	double totalPrice;
public:
	Order();
	Order(int, string, int);
	int getOrderNumber();
	void setOrderNumber(int);
	string getCustomerName();
	void setCustomerName(string);
	int getQuantity();
	void setQuantity(int);
	double getTotalPrice();
	void printOrder();
};

Order::Order(){}

Order::Order(int ordNum, string custN, int qty){
	setOrderNumber(ordNum);
	setCustomerName(custN);
	setQuantity(qty);
}
int Order::getOrderNumber(){
	return orderNumber;
}
void Order::setOrderNumber(int ordNum){
	orderNumber = ordNum;
}
string Order::getCustomerName(){
	return customerName;
}
void Order::setCustomerName(string custN){
	customerName = custN;
}
int Order::getQuantity(){
	return quantity;
}
void Order::setQuantity(int qty){
	quantity = qty;
	totalPrice = getTotalPrice();
}
double Order::getTotalPrice(){
	return (double)quantity * 19.95;
}
void Order::printOrder(){
	cout << "Order details:" << endl;
	cout << "Order Number: " << orderNumber << endl;
	cout << "Customer Name: " << customerName << endl;
	cout << "Quantity: " << quantity << endl;
	cout << "Total Price: $" << totalPrice << endl;
}

int main(){
	// asign variables
	const int LIMIT = 3;
	Order orders[LIMIT];
	int ordNum, qty;
	string custName;

	// request user input for order data
	for(int i = 0; i < LIMIT; ++i){
		// reset vals
		qty = 0;
		ordNum = 0;

		while(ordNum <= 0 || cin.fail()){
			cout << "Please enter an order number: ";
			cin >> ordNum;
			cin.clear();cin.ignore(10000,'\n');
		}
		

		cout << "Please enter a customer name: ";
		getline(cin,custName);

		while(qty <= 0 || cin.fail()){
			cout << "Please enter a quantity amount: ";
			cin >> qty;
			cin.clear();cin.ignore(10000,'\n');
		}

		// create object
		Order temp(ordNum, custName, qty);

		// store order data
		orders[i] = temp;
	}

	for(int i = 0; i < LIMIT; ++i)
		orders[i].printOrder();

	system("pause");
}