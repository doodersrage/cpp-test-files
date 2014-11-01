// Robert S. McDowell
// 10/25/2014
// calculate and return results
#include <iostream>
#include <string> // program uses C++ standard string class
using namespace std;

void mathcalcs(float[] , float[]);

int main(){
	float num[3], results[4];

	cout << "Enter a number: ";
	cin >> num[0];

	cout << "Enter another number: ";
	cin >> num[1];

	cout << "Enter a third number: ";
	cin >> num[2];

	mathcalcs(num, results);

	cout << "Your sum: " << results[0] << endl;
	cout << "Your product: " << results[1] << endl;
	cout << "Your quotient: " << results[2] << endl;
	cout << "Your average: " << results[3] << endl;

	system("pause");
}

void mathcalcs(float num[], float results[]){
	// calc sum
	results[0] = num[0] + num[1] + num[2];
	// calc product
	results[1] = num[0] * num[1] * num[2];
	// calc quotient
	results[2] = num[0] / num[1] / num[2];
	// calc average
	results[3] = results[0] / 3;
}