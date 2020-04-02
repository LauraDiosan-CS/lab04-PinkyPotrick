#include <iostream>
#include "Repo.h"

Repo::Repo() {
	this->noExpenses = 0;
}

Repo::~Repo() {
	this->noExpenses = 0;
}

void Repo::addElem(Expense &e) {
	this->expenses[this->noExpenses++] = e;
}

void Repo::updateElem(int ID, int newDay, int newSum, char* newType) {
	for (int index = 0; index < noExpenses; index++) {
		if (ID == expenses[index].getID()) {
			expenses[index].setDay(newDay);
			expenses[index].setSum(newSum);
			expenses[index].setType(newType);
		}
	}
}

void Repo::deleteElem(int ID) {
	for (int index = 0; index < this->noExpenses; index++)
	{
		if (this->expenses[index].getID() == ID)
		{
			this->expenses[index] = this->expenses[this->noExpenses - 1];
			this->noExpenses--;
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

void Repo::setSize(int newSize) {
	this->noExpenses = newSize;
}
