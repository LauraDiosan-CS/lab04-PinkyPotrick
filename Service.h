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
	Description: Reads the repo
	Input: -
	Output: -
	*/
	Repo readRepo();
};
#endif
