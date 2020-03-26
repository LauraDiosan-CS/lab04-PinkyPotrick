#include <iostream>
#include "Repo.h"

Repo::Repo() {
	this->noExpenses = 0;
}

Repo::~Repo() {
	this->noExpenses = 0;
}

void Repo::addElem(Expense &e) {
	//cout << "Adding the element : " << e.toString() << "\n";
	this->expenses[this->noExpenses++] = e;
	//cout << "The element added on expense[" << this->noExpenses - 1 << "] = " << e.toString() << "\n";
}

void Repo::updateElem(int ID, int newDay, int newSum, char* newType) {
	for (int index = 0; index < noExpenses; index++) {
		//cout << "ID = " << ID << " element ID = " << expenses[index].getID() << endl;
		if (ID == expenses[index].getID()) {
			expenses[index].setDay(newDay);
			expenses[index].setSum(newSum);
			expenses[index].setType(newType);
		}
	}
}

void Repo::deleteElem(int ID) {
	for (int index = 0; index < noExpenses; index++) {
		Expense element = expenses[index];
		if (ID == element.getID()) {
			for (int index2 = index; index2 < noExpenses - 1; index2++)
				expenses[index2] = expenses[index2 + 1];
			noExpenses--;
			index--;
		}
	}
}

Expense Repo::getElemFromPos(int pos) {
	return this->expenses[pos];
}

Expense* Repo::getAll() {
	return this->expenses;
}

int Repo::getSize() {
	return this->noExpenses;
}
