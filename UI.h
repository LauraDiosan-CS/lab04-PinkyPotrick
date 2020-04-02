#pragma once
#include "Service.h"
class UI {
private:
	Expense undoList[1000][1000]; 
	int undoListLength;
	int lastListSize[1000];
	Service service;
	/*
	Description: Shows the elements from the repository
	Input: -
	Output: -
	*/
	void showRepoElements();
	/*
	Description: Shows the options menu
	Input: -
	Output: -
	*/
	void showMenu();
	/*
	Description: Returns the index of today's day
	Input: -
	Output: todayIndex - int, today's day index
	*/
	int getToday();
	/*
	Description: Adds an expense to the repository
	Input: cmd - string, the written command
	Output: -
	*/
	void handleAddExpense(string cmd);
	/*
	Description: Updates an expense from the repository
	Input: cmd - string, the written command
	Output: -
	*/
	void handleUpdateExpense(string cmd);
	/*
	Description: Deletes an expense from the repository
	Input: cmd - string, the written command
	Output: -
	*/
	void handleDeleteExpense(string cmd);
	/*
	Description: Shows an expense/expenses with a specified property
	Input: cmd - string, the written command
	Output: -
	*/
	void handleShowExpenses(string cmd);
	/*
	Description: Sorts the expenses
	Input: cmd - string, the written command
	Output: -
	*/
	void handleSortExpenses(string cmd);
	/*
	Description: Keeps only the specified properties
	Input: cmd - string, the written command
	Output: -
	*/
	void handleFilter(string cmd);
	/*
	Description: Undoes the last command
	Input: cmd - string, the written command
	Output: -
	*/
	void handleUndo(string cmd);
public:
	/*
	Description: The constructor for the UI
	Input: - 
	Output: -
	*/
	UI();
	/*
	Description: This is a copy constructor
	Input: service - class type object, the service class
	Output: -
	*/
	UI(Service& service);
	/*
	Description: Runs the UI
	Input:
	Output: -
	*/
	void runUI();
};
