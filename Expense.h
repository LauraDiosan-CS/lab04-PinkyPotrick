#pragma once

#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Expense {
private:
	int ID;
	int day;
	int sum;
	char* type;

public:
	/*
	Description: Returns the ID of the expense
	Input: -
	Output: ID - int, the ID of the expense
	*/
	int getID();
	/*
	Description: Returns the index of the day
	Input: -
	Output: day - int, the index of the day
	*/
	int getDay();
	/*
	Description: Returns the sum
	Input: -
	Output: sum - int, the sum
	*/
	int getSum();
	/*
	Description: Returns the type
	Input: -
	Output: type - char*, the type
	*/
	char* getType();
	void setID(int newID);
	/*
	Description: Sets the index of the day
	Input: newDay - int, the new day index
	Output: -
	*/
	void setDay(int newDay);
	/*
	Description: Sets the sum
	Input: newSum - int, the new sum
	Output: -
	*/
	void setSum(int newSum);
	/*
	Description: Sets the type
	Input: newType - char*, the new type
	Output: -
	*/
	void setType(char* newType);
	/*
	Description: The following is a default constructor
	Input: -
	Output: -
	*/
	Expense();
	/*
	Description: The following is a constructor with parameters
	Input: i - int, the id of the expense
	       d - int, the index of the day
		   s - int, the sum
		   t - char*, the type
	Output: -
	*/
	Expense(int i, int d, int s, char* t);
	/*
	Description: The following is a copy constructor
	Input: e - const class, the Expense class object
	Output: -
	*/
	Expense(const Expense &e);
	/*
	Description: The following is a destructor "~"
	Input: -
	Output: -
	*/
	~Expense();
	/*
	Description: The following is a conversion to string
	Input: -
	Output: -
	*/
	const char* toString();
	/*
	Description: The following is the comparation between to objects
	Input: e - class, the Expense class object
	Output: -
	*/
	bool operator==(const Expense &e);
	/*
	Description: create a new Expense (equal to a given Expense e)
	Input: e - class, the Expense class object
	Output: a new expense (equal to e)
	*/
	Expense& operator=(const Expense& e);
};

#endif
