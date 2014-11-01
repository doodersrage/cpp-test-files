// Robert S. McDowell
// 10/25/2014
// calculate tax owed via cpp  class
#include <iostream>
#include <string> // program uses C++ standard string class
using namespace std;

class Taxpayer{
private:
	string SSN;
	double YGI;
	double taxOwed;
public:
	string getSSN();
	void setSSN(string);
	double getYGI();
	void setYGI(double);
	double getTaxOwed();
};

string Taxpayer::getSSN(){
	return SSN;
}
void Taxpayer::setSSN(string ssn){
	SSN = ssn;
}
double Taxpayer::getYGI(){
	return YGI;
}
void Taxpayer::setYGI(double ygi){
	YGI = ygi;

	if(YGI > 50000){
		taxOwed = YGI * 0.28;
	}else{
		taxOwed = YGI * 0.18;
	}
}
double Taxpayer::getTaxOwed(){
	return taxOwed;
}

int main(){
	Taxpayer aTaxpayer;

	aTaxpayer.setSSN("111-22-3333");
	aTaxpayer.setYGI(60000);

	cout << "Your tax owed is: " << aTaxpayer.getTaxOwed() << endl;

	system("pause");
}