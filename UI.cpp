#include "UI.h"
#include <iostream>
#include <string>
#include <string.h>
#include <ctime>

using namespace std;

UI::UI() {
	this->lastListSize[1000];
	this->undoListLength = 0;
}

UI::UI(Service& service) {
	this->service = service;
}

void UI::showRepoElements() {
	cout << "----------------------------------------------------------------------------------------------\n";
	cout << "The repository files are: \n\n";
	cout << "Type  |   Sum   |  Day  |  ID\n\n";
	if (service.readRepo().getSize() == 0)
		cout << "";
	else {
		for (int index = 0; index < service.readRepo().getSize(); index++) {
			cout << service.readRepo().getElemFromPos(index).toString();
		}
	}
}

void UI::showMenu() {
	showRepoElements();
	cout << "----------------------------------------------------------------------------------------------\n";
	cout << "\nMenu:\n\n";
	cout << "1. Add expense.\n";
	cout << "   <add> <ID> <Day> <Sum> <Type>\n";
	cout << "   <add> <ID> <Sum> <Type>\n";
	cout << "   Note: If the day is not specified it will be initialized with the today's date.\n\n";
	cout << "2. Update expense.\n";
	cout << "   <update> <ID> <newDay> <newSum> <newType>\n\n";
	cout << "3. Delete expense/expenses.\n";
	cout << "   <delete> <ID>\n\n";
	cout << "4. Show expenses with specified properties.\n";
	cout << "   <show_all_expenses> <type>\n\n";
	cout << "5. Sort the list of expenses by the sum spent each day.\n";
	cout << "   <sort>\n\n";
	cout << "6. Show only the expenses with a specified type through a filter.\n";
	cout << "   <filter> <type>\n\n";
	cout << "7. Undo.\n";
	cout << "   <undo>\n\n";
	cout << "8. Exit.\n";
	cout << "   <exit>\n\n";
	cout << "User: ";
}

int UI::getToday() {
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int day = newtime.tm_mday;
	return day;
}

void UI::handleAddExpense(string cmd) {

	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int ID = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int day = stoi(token);

	int sum;
	if (day > 31) {
		sum = day;
		day = getToday();
	}
	else {
		cmd.erase(0, pos + sep.length());
		pos = cmd.find(sep);
		token = cmd.substr(0, pos);
		sum = stoi(token);
	}

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	this->service.createElement(ID, day, sum, type);

	service.addToUndoList(undoList, undoListLength, lastListSize);
	cout << "Program: The expense has been added.\n";
}

void UI::handleUpdateExpense(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int ID = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int newDay = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int newSum = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* newType = new char[token.length() + 1];
	strcpy_s(newType, token.length() + 1, token.c_str());

	this->service.updateElement(ID, newDay, newSum, newType);

	service.addToUndoList(undoList, undoListLength, lastListSize);
	cout << "Program: The expense has been updated.\n";
}

void UI::handleDeleteExpense(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int ID = stoi(token);

	this->service.deleteElement(ID);

	service.addToUndoList(undoList, undoListLength, lastListSize);
	cout << "Program: The expense has been deleted.\n";
}

void UI::handleShowExpenses(string cmd) {

	Expense filteredExpenses[1000];
	int length = 0;
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	service.showExpenses(type, filteredExpenses, length);
	cout << "The expenses with the included type '" << type << "' are:\n\n";
	for (int index = 1; index <= length; index++)
		cout << filteredExpenses[index].toString();
	cout << "\n";
}

void UI::handleSortExpenses(string cmd) {
	Expense sortedExpenses[1000];
	cout << "The sorted expenses are:\n\n";
	service.sortExpenses(sortedExpenses);
	for (int index = 0; index < service.readRepo().getSize(); index++)
		cout << sortedExpenses[index].toString();
	cout << "\n";
}

void UI::handleFilter(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	service.filterExpenses(type);

	service.addToUndoList(undoList, undoListLength, lastListSize);
	cout << "Program: The expenses have been filtered.\n";
}

void UI::handleUndo(string cmd) {
	Expense lastList[1000];
	if (undoListLength == 0)
		cout << "Program: There is nothing to undo.\n";
	else
	{
		service.doUndo(lastList, undoList, undoListLength, lastListSize);
		cout << "Program: The last command has been undone.\n";
	}
}

void UI::runUI()
{
	bool shouldRun = true;
	string cmd;
	while (shouldRun)
	{
		this->showMenu();
		getline(cin, cmd);
		if (cmd.find("add") != string::npos)  //string::npos = -1
		{
			this->handleAddExpense(cmd);
		}
		else if (cmd.find("update") != string::npos)
		{
			this->handleUpdateExpense(cmd);
		}
		else if (cmd.find("delete") != string::npos)
		{
			this->handleDeleteExpense(cmd);
		}
		else if (cmd.find("show_all_expenses") != string::npos)
		{
			this->handleShowExpenses(cmd);
		}
		else if (cmd.find("sort") != string::npos)
		{
			this->handleSortExpenses(cmd);
		}
		else if (cmd.find("filter") != string::npos)
		{
			this->handleFilter(cmd);
		}
		else if (cmd.find("undo") != string::npos)
		{
			this->handleUndo(cmd);
		}
		else if (cmd.find("exit") != string::npos)
		{
			shouldRun = false;
		}
		else
		{
			cout << "Program: Error! The given option does not exist!\n";
		}
	}
	cout << "Program: Bye!\n";
	system("pause");
	return;
}

