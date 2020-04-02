#pragma once

#ifndef SERVICE_H
#define SERVICE_H
#include <iostream>
#include <string.h>
#include "Repo.h"
#include "Expense.h"

using namespace std;

class Service
{
private:
	Repo repo;
public:
	/*
	Description: The following is a default constructor
	Input: -
	Output: -
	*/
	Service();
	/*
	Description: The following is a constructor with parameters
	Input: r - Repo, the repository class
	Output: -
	*/
	Service(Repo r);
	/*
	Description: The following is a copy constructor
	Input: e - const class, the Service class object
	Output: -
	*/
	Service(const Service &s);
	/*
	Description: The following is a destructor "~"
	Input: -
	Output: -
	*/
	~Service();
	/*
	Description: Creates an element
	Input: ID - int, the ID of the expense
	       day - int, the index of the day
		   sum - int, the total of the expense
		   type - char*, the type of eexpense
	Output: -
	*/
	void createElement(int ID, int day, int sum, char* type);
	/*
	Description: Reads an element
	Input: -
	Output: -
	void readElement();
	*/
	/*
	Description: Updates an element
	Input: ID - int, the ID of the expense
		   newDay - int, the new day index
	       newSum - int, the new sum
		   newType - char*, the new type
	Output: -
	*/
	void updateElement(int ID, int newDay, int newSum, char* newType);
	/*
	Description: Deletes an element
	Input: ID - int, the ID of the expense
	Output: -
	*/
	void deleteElement(int ID);
	/*
	Description: Shows the expenses with the specified type
	Input: type - char*, the type of the expense
		   filteredExpenses - Expense class object, the filtered list of expenses
		   length - int, the length of the filtered list
	Output: -
	*/
	void showExpenses(char* type, Expense filteredExpenses[1000], int &length);
	/*
	Description: Sorts the expenses list in a decreasing order
	Input: sortedExpenses - Expense class object, the sorted list of expenses
	Output: -
	*/
	void sortExpenses(Expense sortedExpenses[1000]);
	/*
	Description: Filters the expenses by deleting the ones that are not specified by the given type
	Input: type - char*, the type of the expense
	Output: -
	*/
	void filterExpenses(char* type);
	/*
	Description: Adds the last command copy of list to the undo list
	Input: undoList - Expense Type Objects, the list of undo lists
	       undoListLength - int, the length of the undo list
		   lastListSize - int, the length of the list for every list
	Output: -
	*/
	void addToUndoList(Expense undoList[1000][1000], int &undoListLength, int lastListSize[1000]);
	/*
	Description: Undoes the last command
	Input: lastList - Expense Type Objects, the last list
	       undoList - Expense Type Objects, the list of undo lists
	       undoListLength - int, the length of the undo list
		   lastListSize - int, the length of the list for every list
	Output: - 
	*/
	void doUndo(Expense lastList[1000], Expense undoList[1000][1000], int &undoListLength, int lastListSize[1000]);
	/*
	Description: Reads the repo
	Input: -
	Output: -
	*/
	Repo readRepo();
};
#endif
