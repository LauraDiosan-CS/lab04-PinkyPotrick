#include <iostream>
#include <cstring>
#include "Expense.h"

using namespace std;

int Expense::getDay() {
	return this->day;
}
int Expense::getSum() {
	return this->sum;
}
char* Expense::getType() {
	return this->type;
}
void Expense::setDay(int newDay) {
	this->day = newDay;
}
void Expense::setSum(int newSum) {
	this->sum = newSum;
}
void Expense::setType(char* newType) {
	if (this->type) {
		delete[] this->type;
	}
	this->type = new char[strlen(newType) + 1];
	strcpy_s(this->type, strlen(newType) + 1, newType);
}
Expense::Expense(int d, int s, char* t) {
	cout << "This is an implicit constructor with parameters" << endl;
	day = d;
	sum = s;
	type = new char[strlen(t) + 1];
	strcpy_s(type, strlen(t) + 1, t);
}
Expense::Expense(const Expense &e) {
	cout << "This is a copy constructor" << endl;
	day = e.day;
	sum = e.sum;
	type = new char[strlen(e.type) + 1];
	strcpy_s(type, strlen(e.type) + 1, e.type);
}
Expense::~Expense() {
	cout << "This is a destructor" << endl;
	if (type != NULL) {
		delete[] type;
		type = NULL;
	}
}
Expense::Expense() {
	cout << "This is a default constructor" << endl;
	this->day = 0;
	this->sum = 0;
	this->type = NULL;
}
const char* Expense::toString() {
	if (this->type != NULL) {
		int noChars = 3 + strlen(this->type) + 1 + 20 + 2;
		char* s = new char[noChars];
		char* aux = new char[20];
		char* d = new char[3];
		_itoa_s(this->day, aux, 20, 10);
		//strcat_s(s, noChars, aux);
		//strcat_s(s, noChars, "|");
		strcpy_s(s, noChars, this->type);
		strcat_s(s, noChars, "|");
		_itoa_s(this->sum, aux, 5, 10);
		strcat_s(s, noChars, aux);

		if (aux) {
			delete[] aux;
			aux = NULL;
		}
		strcat_s(s, noChars, "\n");
		return s;
	}
		return "";
}
bool Expense::compare(Expense &e) {
	return ((this->day == e.day) && (this->sum == e.sum) && (strcmp(this->type, e.type) == 0));
}
Expense& Expense::operator=(const Expense& e) {
	cout << "Expense : operator= ... " << endl;
	if (this != &e) {
		this->setDay(e.day);
		this->setSum(e.sum);
		this->setType(e.type);
	}
	else
		cout << "Self assignment ... " << endl;
	return *this;
}
