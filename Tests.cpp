#include <iostream>
#include <assert.h>
#include "Expense.h"
#include "Repo.h"

void testExpense() {
	char* type1 = new char[10];
	strcpy_s(type1, strlen("haine") + 1, "haine");

	Expense e1(10, 100, type1);

	assert(e1.getDay() == 10);
	assert(e1.getSum() == 100);
	assert(strcmp(e1.getType(), type1) == 0);

	Expense e2 = e1;
	//assert(e2.compare(e1));
	assert(e1.getDay() == e2.getDay());

	char* type2 = new char[10];
	strcpy_s(type2, strlen("internet") + 1, "internet");

	e2.setDay(28);
	e2.setSum(500);
	e2.setType(type2);

	assert(e2.getDay() == 28);
	assert(e2.getSum() == 500);
	assert(strcmp(e2.getType(), type2) == 0);
}

void testRepo() {
	Repo repo;

	char* type1 = new char[10];
	strcpy_s(type1, strlen("haine") + 1, "haine");
	char* type2 = new char[10];
	strcpy_s(type2, strlen("internet") + 1, "internet");

	Expense e1(10, 100, type1);
	Expense e2(27, 600, type2);

	repo.addElem(e1);
	repo.addElem(e2);

	assert(repo.getSize() == 2);

	assert(repo.getElemFromPos(1).getSum() == e2.getSum());

	assert(repo.getAll()[0].getDay() == e1.getDay());
	assert(repo.getAll()[1].getSum() == e2.getSum());
}
