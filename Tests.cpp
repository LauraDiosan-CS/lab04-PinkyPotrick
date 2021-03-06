#include <iostream>
#include <assert.h>
#include "Service.h"

void testExpense() {
	char* type1 = new char[10];
	strcpy_s(type1, strlen("haine") + 1, "haine");

	Expense e1(1, 10, 100, type1);

	assert(e1.getDay() == 10);
	assert(e1.getSum() == 100);
	assert(strcmp(e1.getType(), type1) == 0);

	Expense e2 = e1;
	assert(e1 == e2);
	assert(e1.getDay() == e2.getDay());

	char* type2 = new char[10];
	strcpy_s(type2, strlen("internet") + 1, "internet");

	e2.setDay(28);
	e2.setSum(500);
	e2.setType(type2);

	assert(e2.getID() == 1);
	assert(e2.getDay() == 28);
	assert(e2.getSum() == 500);
	assert(strcmp(e2.getType(), type2) == 0);

	char* s = new char[100];
	Expense e3;
	strcpy_s(s, strlen("haine | 100 | 10 | 1\n") + 1, "haine | 100 | 10 | 1\n");

	assert(strcmp(e3.toString(), "") == 0);
	assert(strcmp(e1.toString(), s) == 0);

	delete[] s;
}

void testRepo() {
	Repo repo;

	char* type1 = new char[10];
	strcpy_s(type1, strlen("haine") + 1, "haine");
	char* type2 = new char[10];
	strcpy_s(type2, strlen("internet") + 1, "internet");

	Expense e1(1, 10, 100, type1);
	Expense e2(2, 27, 600, type2);

	repo.addElem(e1);
	repo.addElem(e2);

	assert(repo.getSize() == 2);

	assert(repo.getElemFromPos(1).getSum() == e2.getSum());

	assert(repo.getAll()[0].getDay() == e1.getDay());
	assert(repo.getAll()[1].getSum() == e2.getSum());
}

void testService() {
	Repo repo;
	Service service(repo);

	char* type1 = new char[10];
	strcpy_s(type1, strlen("haine") + 1, "haine");
	char* type2 = new char[10];
	strcpy_s(type2, strlen("internet") + 1, "internet");

	service.createElement(1, 10, 100, type1);//e1
	service.createElement(2, 27, 600, type2);//e2
	service.createElement(3, 30, 3500, type1);//e3

	assert(service.readRepo().getSize() == 3);

	Expense e1 = service.readRepo().getAll()[0];
	Expense e2 = service.readRepo().getAll()[1];
	Expense e3 = service.readRepo().getAll()[2];

	service.updateElement(1, 27, 600, type2);

	e1 = service.readRepo().getElemFromPos(0);
	e2 = service.readRepo().getElemFromPos(1);

	assert(e1 == e2);

	service.deleteElement(3);
	assert(service.readRepo().getSize() == 2);

	service.createElement(4, 10, 1000, type1);//e4
	Expense e4 = service.readRepo().getAll()[2];

	Expense filteredExpenses[1000];
	int length = 0;
	service.showExpenses(type2, filteredExpenses, length);

	assert(length == 2);
	assert(filteredExpenses[1] == e1);
	assert(filteredExpenses[2] == e2);

	length = 0;
	service.showExpenses(type1, filteredExpenses, length);

	assert(length == 1);
	assert(filteredExpenses[1] == e4);

	Expense sortedExpenses[1000];
	service.sortExpenses(sortedExpenses);

	assert(sortedExpenses[0] == e4);
	assert(sortedExpenses[1] == e2);
	assert(sortedExpenses[2] == e1);

	service.filterExpenses(type2);

	assert(service.readRepo().getSize() == 2);
}
