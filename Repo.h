#pragma once
#pragma once

#ifndef REPO_H
#define REPO_H
#include "Expense.h"

using namespace std;

class Repo {
private:
	Expense expenses[100];
	int noExpenses;
public:
	/*
	Description: The following is a default constructor
	Input: -
	Output: -
	*/
	Repo();
	/*
	Description: The following is a destructor
	Input: -
	Output: -
	*/
	~Repo();
	/*
	Description: Adds an elements to the repository
	Input: &e - class, the Expense class object with reference
	Output: -
	*/
	void addElem(Expense &e);
	/*
	Description: Returns the element at a specified position
	Input: pos - int, the position
	Output: expenses[pos] - class, the Expense class object at the specified position
	*/
	Expense getElemFromPos(int pos);
	/*
	Description: Returns all the elements from the repository
	Input: -
	Output: expenses - class, the Expense class objects from the repository
	*/
	Expense* getAll();
	/*
	Description: Returns the size of the repository
	Input: -
	Output: noExpenses - int, the number of elements in the repository
	*/
	int getSize();
};
#endif
