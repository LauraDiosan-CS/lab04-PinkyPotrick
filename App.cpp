#include <iostream>
#include "Tests.h"
//#include "Expense.h"
//#include "Repo.h"
#include "Service.h"

using namespace std;

Repo repo;
Service service(repo);

void showRepoElements() {
	cout << "The repository files are: \n\n";
	cout << "Type  |   Sum   |  Day  |  ID\n";
	if (service.readRepo().getSize() == 0)
		cout << "";
	else {
		for (int index = 0; index < service.readRepo().getSize(); index++) {
			cout << service.readRepo().getElemFromPos(index).toString();
		}
	}
}

void showMenu() {
	showRepoElements();
	cout << "\nMenu:\n\n";
	cout << "1. Add expense.\n";
	cout << "2. Update expense.\n";
	cout << "3. Delete expense.\n";
	cout << "4. Show expenses with specified properties.\n";
	cout << "5. Obtaining the properties for different sublists.\n";
	cout << "6. Filter of the list.\n";
	cout << "7. Undo.\n";
	cout << "8. Exit.\n";
}

void handleAddExpense() {
	//cout << "Program: Option not implemented yet.\n\n";
	int day, sum, ID;
	char* type;
	type = new char[10];
	cout << "Program: Write the ID of the expense.\nUser: ";
	cin >> ID;
	cout << "Program: Give a day of a month.\nUser: ";
	cin >> day;
	cout << "\nProgram: Give a sum.\nUser: ";
	cin >> sum;
	cout << "\nProgram: Give a type of expense (haine, internet, mancare, altele).\nUser: ";
	cin >> type;
	//cout << e.toString();
	service.createElement(ID, day, sum, type);
	cout << "Program: The expense has been added!\n";
}

void handleUpdateExpense() {
	int ID, newDay, newSum;
	char* newType;
	newType = new char[10];
	cout << "Write the ID of the expense that you want to update.\nUser: ";
	cin >> ID;
	cout << "Program: Write the new day for the wanted expense.\nUser: ";
	cin >> newDay;
	cout << "\nProgram: Write the new sum for the wanted expense.\nUser: ";
	cin >> newSum;
	cout << "\nProgram: Write the new type for the wanted expense (haine, internet, mancare, altele).\nUser: ";
	cin >> newType;
	service.updateElement(ID, newDay, newSum, newType);
	cout << "Program: The expense has been updated!\n";
}

void handleDeleteExpense() {
	int ID;
	cout << "Write the ID of the expense that you want to delete.\nUser: ";
	cin >> ID;
	service.deleteElement(ID);
	cout << "Program: The expense has been deleted!\n";
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
	testExpense();
	testRepo();
	testService();
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
			handleDeleteExpense();
			break;
		case 4:
			handleShowExpenses();
			break;
		case 5:
			handleObtainProperties();
			break;
		case 6:
			handleFilter();
			break;
		case 7:
			handleUndo();
			break;
		case 8:
			cout << "Program: Bye!\n";
			system("pause");
			return 0;
		default:
			cout << "Program: Error! The given option does not exist!\n";
		}
	}
}
