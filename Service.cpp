#include <iostream>
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
	//cout << "Inserted ID is : " << ID << "\n";
	Expense e(ID, day, sum, type);
	//cout << "The created element's ID is " << ID << "\nThe created element is : " << e.toString() << "\n";
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