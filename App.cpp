#include <iostream>
#include "Tests.h"
#include "Expense.h"
#include "Repo.h"

using namespace std;

Repo repo;

void showMenu() {
	cout << "The repository files are: \n\n";
	if (repo.getSize() == 0)
		cout << "";
	else {
		for (int index = 0; index < repo.getSize(); index++) {
			cout << repo.getAll()[index].toString();
		}
	}
	cout << "\nMenu:\n\n";
	cout << "1. Add expense.\n";
	cout << "2. Update expense.\n";
	cout << "3. Show expenses with specified properties.\n";
	cout << "4. Obtaining the properties for different sublists.\n";
	cout << "5. Filter of the list.\n";
	cout << "6. Undo.\n";
	cout << "7. Exit.\n";
}

void handleAddExpense() {
	//cout << "Program: Option not implemented yet.\n\n";
	int day, sum;
	char* type;
	type = new char[10];
	cout << "Program: Give a day of a month.\nUser: ";
	cin >> day;
	cout << "\nProgram: Give a sum.\nUser: ";
	cin >> sum;
	cout << "\nProgram: Give a type of expense (haine, internet, mancare, altele).\nUser: ";
	cin >> type;
	Expense e(day, sum, type);
	cout << e.toString();
	repo.addElem(e);
}

void handleUpdateExpense() {
	cout << "Program: Option not implemented yet.\n\n";
}

void handleShowExpenses() {
	cout << "Program: Option not implemented yet.\n\n";
}

void handleObtainProperties() {
	cout << "Program: Option not implemented yet.\n\n";
}

void handleFilter() {
	cout << "Program: Option not implemented yet.\n\n";
}

void handleUndo() {
	cout << "Program: Option not implemented yet.\n\n";
}

int main()
{
	cout << "hi";
	testExpense();
	testRepo();
	int option;
	while (true)
	{
		showMenu();
		cout << "\nProgram: Give an option.\nUser: ";
		cin >> option;
		switch (option) {
		case 1:
			handleAddExpense();
			break;
		case 2:
			handleUpdateExpense();
			break;
		case 3:
			handleShowExpenses();
			break;
		case 4:
			handleObtainProperties();
			break;
		case 5:
			handleFilter();
			break;
		case 6:
			handleUndo();
			break;
		case 7:
			cout << "Program: Bye!\n";
			system("pause");
			return 0;
		default:
			cout << "Program: Error! The given option does not exist!\n";
		}
	}
}
