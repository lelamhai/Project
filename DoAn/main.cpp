#include "configApp.h"
#include "ManageClass.h"
#include <conio.h>
#include <iostream>
using namespace std;


int main()
{
	ConfigApp config;
	config.init();

	ManageClassroom* lop = new ManageClassroom();
	lop->mainClassroom();
	delete lop;

	_getch();
	system("pause");
	return 0;
}