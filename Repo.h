#pragma once

#ifndef REPO_H
#define REPO_H
#include "Expense.h"

using namespace std;

class Repo {
private:
	Expense expenses[1000];
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
	Description: Updates an elements of the repository
	Input: ID - int, the ID of the expense
	       newDay - int, the new day index
	       newSum - int, the new sum
		   newType - char*, the new type
	Output: -
	*/
	void updateElem(int ID, int newDay, int newSum, char* newType);
	/*
	Description: Deletes an elements from the repository
	Input: ID - int, the ID of the expense
	Output: -
	*/
	void deleteElem(int ID);
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
	/*
	Description: Sets the size of the repository
	Input: newSize - int, the new size of the repository
	Output: - 
	*/
	void setSize(int newSize);
};
#endif
