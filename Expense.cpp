#include <iostream>
#include <string.h>
#include "Expense.h"

using namespace std;

int Expense::getID() {
	return this->ID;
}
int Expense::getDay() {
	return this->day;
}
int Expense::getSum() {
	return this->sum;
}
char* Expense::getType() {
	return this->type;
}
void Expense::setID(int newID) {
	this->ID = newID;
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
	if (newType != NULL) {
		this->type = new char[strlen(newType) + 1];
		strcpy_s(this->type, strlen(newType) + 1, newType);

	}
	else {
		this->type = NULL;
	}
}
Expense::Expense() {
	//cout << "This is a default constructor" << endl;
	this->ID = 0;
	this->day = 0;
	this->sum = 0;
	this->type = NULL;
}
Expense::Expense(int i, int d, int s, char* t) {
	//cout << "This is an implicit constructor with parameters" << endl;
	ID = i;
	day = d;
	sum = s;
	type = new char[strlen(t) + 1];
	strcpy_s(type, strlen(t) + 1, t);
}
Expense::Expense(const Expense &e) {
	//cout << "This is a copy constructor" << endl;
	ID = e.ID;
	day = e.day;
	sum = e.sum;
	if (e.type != NULL) {
		int n = strlen(e.type);
		type = new char[n + 1];
		strcpy_s(type, n + 1, e.type);
	}
	else { type = NULL; }
}
Expense::~Expense() {
	//cout << "This is a destructor" << endl;
	if (type != NULL) {
		delete[] type;
		type = NULL;
	}
}
const char* Expense::toString() {
	if (this->type != NULL) {
		int noChars = strlen(this->type) + 3 + 6 + 3 + 3 + 3 + 4 + 1;
		char* s = new char[noChars];
		char* strsum = new char[6];
		char* strday = new char[3];
		char* strID = new char[4];
		_itoa_s(this->day, strday, 3, 10);
		_itoa_s(this->sum, strsum, 6, 10);
		_itoa_s(this->ID, strID, 4, 10);
		strcpy_s(s, noChars, this->type);
		strcat_s(s, noChars, " | ");
		strcat_s(s, noChars, strsum);
		strcat_s(s, noChars, " | ");
		strcat_s(s, noChars, strday);
		strcat_s(s, noChars, " | ");
		strcat_s(s, noChars, strID);

		if (strsum) {
			delete[] strsum;
			strsum = NULL;
		}

		if (strday) {
			delete[] strday;
			strday = NULL;
		}

		if (strID) {
			delete[] strID;
			strID = NULL;
		}

		strcat_s(s, noChars, "\n");
		return s;
	}
	return "";
}
bool Expense::operator==(const Expense &e) {
	return ((this->day == e.day) && (this->sum == e.sum) && (strcmp(this->type, e.type) == 0));
}
Expense& Expense::operator=(const Expense& e) {
	//cout << "Expense : operator= ... " << endl;
	if (this != &e) {
		this->setID(e.ID);
		this->setDay(e.day);
		this->setSum(e.sum);
		this->setType(e.type);
	}
	//else
		//cout << "Self assignment ... " << endl;
	return *this;
}
