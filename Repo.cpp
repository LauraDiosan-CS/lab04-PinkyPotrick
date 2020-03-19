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

Expense Repo::getElemFromPos(int pos) {
	return this->expenses[pos];
}

Expense* Repo::getAll() {
	return this->expenses;
}

int Repo::getSize() {
	return this->noExpenses;
}
