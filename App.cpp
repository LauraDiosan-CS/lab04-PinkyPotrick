#include <iostream>
#include "Tests.h"
#include "UI.h"

Repo repo;
Service service(repo);
UI ui;

int main()
{
	testExpense();
	testRepo();
	testService();
	ui.runUI();
}
