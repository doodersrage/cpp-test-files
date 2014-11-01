// Robert S. McDowell
// 11/1/2014
// final problem 2
// patient class and derived insured patient class
#include<iostream>
#include<string>
using namespace std;

class Patient {
private:
	int patientID;
	string name;
	int age;
	double amtDue;
public:
	Patient(int, string, int);
	Patient(int, string, int, double);
	void setPatientID(int);
	int getPatientID();
	void setName(string);
	string getName();
	void setAge(int);
	int getAge();
	void setAmtDue(double);
	double getAmtDue();
	void patientPrint();
};

Patient::Patient(int patID, string ptName, int ptAge){
	setPatientID(patID);
	setName(ptName);
	setAge(ptAge);
	setAmtDue(0);
}
Patient::Patient(int patID, string ptName, int ptAge, double ptAmtDue){
	setPatientID(patID);
	setName(ptName);
	setAge(ptAge);
	setAmtDue(ptAmtDue);
}
void Patient::setPatientID(int pID){
	patientID = pID;
}
int Patient::getPatientID(){
	return patientID;
}
void Patient::setName(string ptName){
	name = ptName;
}
string Patient::getName(){
	return name;
}
void Patient::setAge(int pAge){
	// convert age to a positiive value
	if(pAge < 0) pAge = pAge * 1;
	age = pAge;
}
int Patient::getAge(){
	return age;
}
void Patient::setAmtDue(double ptAmtDue){
	if(ptAmtDue < 0) ptAmtDue = 0;
	amtDue = ptAmtDue;
}
double Patient::getAmtDue(){
	return amtDue;
}
void Patient::patientPrint(){
	cout << "Patient information: " << endl;
	cout << "ID # : " << patientID << endl;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Amount Due: $" << amtDue << endl;
}

class InsuredPatient : public Patient{
private:
	string insComNme;
	double insPercent;
public:
	InsuredPatient(int, string, int, double, string);
	void setInsComNme(string);
	string getInsComNme();
	void setInsPercent(double);
	double getInsPercent();
	void patientPrint();
};

InsuredPatient::InsuredPatient(int patID, string ptName, int ptAge, double ptAmtDue, string insCpyNme):Patient(patID, ptName, ptAge, ptAmtDue){
	Patient(patID, ptName, ptAge, ptAmtDue);
	setInsComNme(insCpyNme);
}

void InsuredPatient::setInsComNme(string insName){
	if(insName == "Liberty Mutual"){
		setInsPercent(0.80);
	}else if(insName == "UHC"){
		setInsPercent(0.85);
	}else{
		setInsPercent(0.70);
	}
	insComNme = insName;
}
string InsuredPatient::getInsComNme(){
	return insComNme;
}
void InsuredPatient::setInsPercent(double insPct){
	insPercent = insPct;
}
double InsuredPatient::getInsPercent(){
	return insPercent;
}

void InsuredPatient::patientPrint(){
	double insAmtDue;

	insAmtDue = Patient::getAmtDue() - (Patient::getAmtDue() * insPercent);

	Patient::patientPrint();
	cout << "Insurance Company: " << insComNme << endl;
	cout << "Insurance percentage paid: " << insPercent << endl;
	cout << "Patient amount due: $" << insAmtDue << endl;
}

int main(){

	Patient aPatient(12345, "Silly Sally", 30);
	aPatient.patientPrint();

	Patient bPatient(54321, "Sorry Sam", 32, 2200);
	bPatient.patientPrint();

	InsuredPatient aInsuredPatient(56541, "Lucky Liam", 28, 4200, "Liberty Mutual");
	aInsuredPatient.patientPrint();

	system("pause");
}