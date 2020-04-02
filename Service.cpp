#include <iostream>
#include <algorithm>
#include "Repo.h"
#include "Expense.h"
#include "Service.h"

using namespace std;

Service::Service() {
	//cout << "This is a default constructor" << endl;
}

Service::Service(Repo r) {
	//cout << "This is an implicit constructor with parameters" << endl;
	repo = r;
}

Service::Service(const Service &s) {
	//cout << "This is a copy constructor" << endl;
	repo = s.repo;
}

Service::~Service() {
	//cout << "This is a destructor" << endl;
}

void Service::createElement(int ID, int day, int sum, char* type) {
	Expense e(ID, day, sum, type);
	repo.addElem(e);
}

void Service::updateElement(int ID, int newDay, int newSum, char* newType) {
	repo.updateElem(ID, newDay, newSum, newType);
}

void Service::deleteElement(int ID) {
	repo.deleteElem(ID);
}

Repo Service::readRepo() {
	return this->repo;
}

void Service::showExpenses(char* type, Expense filteredExpenses[1000], int &length) {
	for (int index = 0; index < readRepo().getSize(); index++) {
		if (strcmp(readRepo().getElemFromPos(index).getType(), type) == 0) {
			filteredExpenses[++length] = readRepo().getElemFromPos(index);
		}
	}
}

void Service::sortExpenses(Expense sortedExpenses[1000]) {
	for (int index = 0; index < readRepo().getSize(); index++)
		sortedExpenses[index] = readRepo().getElemFromPos(index);
	for (int indexI = 0; indexI < readRepo().getSize() - 1; indexI++) {
		for (int indexJ = indexI + 1; indexJ < readRepo().getSize(); indexJ++) {
			if (sortedExpenses[indexI].getSum() < sortedExpenses[indexJ].getSum()) {
				Expense aux = sortedExpenses[indexI];
				sortedExpenses[indexI] = sortedExpenses[indexJ];
				sortedExpenses[indexJ] = aux;
			}
		}
	}
}

void Service::filterExpenses(char* type) {
	int length = readRepo().getSize();
	Repo auxRepo = readRepo();
	for (int index = 0; index < length; index++) {
		if (!strcmp(auxRepo.getElemFromPos(index).getType(), type) == 0) {
			repo.deleteElem(auxRepo.getElemFromPos(index).getID());
		}
	}
}

void Service::addToUndoList(Expense undoList[1000][1000], int &undoListLength, int lastListSize[1000]) {
	undoListLength++;
	lastListSize[undoListLength] = readRepo().getSize();
	for (int index = 0; index < lastListSize[undoListLength]; index++) {
		undoList[undoListLength][index] = readRepo().getElemFromPos(index);
	}
}

void Service::doUndo(Expense lastList[1000], Expense undoList[1000][1000], int &undoListLength, int lastListSize[1000]) {
	undoListLength--;

	for (int index = 0; index <= lastListSize[undoListLength]; index++) {
		lastList[index] = undoList[undoListLength][index];
	}

	int length = readRepo().getSize();
	Repo auxRepo = readRepo();

	for (int index = 0; index < length; index++) {
		deleteElement(auxRepo.getElemFromPos(index).getID());
	}

	for (int index = 0; index < lastListSize[undoListLength]; index++) {
		int ID = lastList[index].getID();
		int day = lastList[index].getDay();
		int sum = lastList[index].getSum();
		char* type = new char[strlen(lastList[index].getType()) + 1];
		strcpy_s(type, strlen(lastList[index].getType()) + 1, lastList[index].getType());
		Expense e(ID, day, sum, lastList[index].getType());
		repo.addElem(e);
	}
}
