// Robert S. McDowell
// 10/29/2014
// program 1
// book class and subs

#include<iostream>
#include<string>
using namespace std; 

class Book{
private:
	string ISBN;
	string author;
	double price;
public:
	void setISBN(string);
	string getISBN();
	void setAuthor(string);
	string getAuthor();
	void setPrice(double);
	double getPrice();
	void printBook();
};

void Book::setISBN(string newISBN){
	ISBN = newISBN;
}
string Book::getISBN(){
	return ISBN;
}
void Book::setAuthor(string newAuthor){
	author = newAuthor;
}
string Book::getAuthor(){
	return author;
}
void Book::setPrice(double newPrice){
	price = newPrice;
}
double Book::getPrice(){
	return price;
}
void Book::printBook(){
	cout << "ISBN: " << ISBN << endl << "Author: " << author
		<< endl << "Price: $" << price << endl;
}

class Textbook : public Book{
private: 
	string gradelevel;
public:
	void setGradeLevel(string);
	string getGradeLevel();
	void setPrice(double);
	double getPrice();
	void printBook();
};

void Textbook::setGradeLevel(string newGradeLevel){
	gradelevel = newGradeLevel;
}
string Textbook::getGradeLevel(){
	return gradelevel;
}
void Textbook::setPrice(double newPrice){
	if (newPrice < 20){
		newPrice = 20;
	}
	else if (newPrice > 80){
		newPrice = 80;
	}
	Book::setPrice(newPrice);
}
void Textbook::printBook(){
	Book::printBook();
	cout << "Gradelevel: " << gradelevel;
}

class CoffeeTableBook : public Book{
public:
	void setPrice(double);
};
void CoffeeTableBook::setPrice(double newPrice){
	if (newPrice < 35){
		newPrice = 35;
	}
	else if (newPrice > 100){
		newPrice = 100;
	}
	Book::setPrice(newPrice);
}

int main(){

	Book aBook;
	Textbook aTextbook;
	CoffeeTableBook aCoffeeTableBook;

	aBook.setISBN("HJKHKJHKJ776");
	aBook.setAuthor("Bob");
	aBook.setPrice(10.00);
	aBook.printBook();

	aTextbook.setISBN("768867JHJKHK");
	aTextbook.setAuthor("Deb");
	aTextbook.setPrice(100.00);
	aTextbook.setGradeLevel("Senior");
	aTextbook.printBook();

	aCoffeeTableBook.setISBN("99999HHHHHHH");
	aCoffeeTableBook.setAuthor("Dan");
	aCoffeeTableBook.setPrice(25.00);
	aCoffeeTableBook.printBook();

	system("pause");
}