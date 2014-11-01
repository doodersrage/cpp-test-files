// Robert S. McDowell
// 10/22/2014
// employee class
#include<iostream>
#include<string>
using namespace std;

class Employee{
	private:
		string firstName;
		string lastName;
		double hourlyRate;
	public:
		void setFirstName(string);
		string getFirstName();
		void setLastName(string);
		string getLastName();
		void setHourlyRate(double);
		double getHourlyRate();
		double calculateGross(double);
};

void Employee::setFirstName(string fn){
	firstName = fn;
}
string Employee::getFirstName(){
	return firstName;
}
void Employee::setLastName(string ln){
	lastName = ln;
}
string Employee::getLastName(){
	return lastName;
}
void Employee::setHourlyRate(double hr){
	if (hr < 0) hr = 0;
	hourlyRate = hr;
}
double Employee::getHourlyRate(){
	return hourlyRate;
}
double Employee::calculateGross(double hours){
	double OTHours, grossPay = 0;
	// calc overtime pay
	if (hours > 40){
		OTHours = hours - 40;
		grossPay = (hourlyRate * 1.5) * hours;
		hours -= 40;
	}
	// calc regular pay
	grossPay += (double)hourlyRate * (double)hours;

	return grossPay;
}

int main(){
	string strInpVal;
	double dblInpVal, hoursWorked;
	Employee emp1;
	Employee emp2;

	// employee 1 data
	cout << "Enter employee 1 first name: ";
	cin >> strInpVal;
	emp1.setFirstName(strInpVal);

	cout << "Enter employee 1 last name: ";
	cin >> strInpVal;
	emp1.setLastName(strInpVal);

	cout << "Enter employee 1 hourly rate: ";
	cin >> dblInpVal;
	emp1.setHourlyRate(dblInpVal);

	cout << "Enter employee 1 hours worked: ";
	cin >> hoursWorked;

	cout << emp1.getFirstName() << " " << emp1.getLastName() << " gross pay: " << emp1.calculateGross(hoursWorked) << endl;

	// employee 2 data
	cout << "Enter employee 2 first name: ";
	cin >> strInpVal;
	emp2.setFirstName(strInpVal);

	cout << "Enter employee 2 last name: ";
	cin >> strInpVal;
	emp2.setLastName(strInpVal);

	cout << "Enter employee 2 hourly rate: ";
	cin >> dblInpVal;
	emp2.setHourlyRate(dblInpVal);

	cout << "Enter employee 2 hours worked: ";
	cin >> hoursWorked;

	cout << emp2.getFirstName() << " " << emp2.getLastName() << " gross pay: " << emp2.calculateGross(hoursWorked) << endl;

	system("pause");
}