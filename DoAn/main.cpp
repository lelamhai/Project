#include "configApp.h"
#include "ManageLop.h"

#include <iostream>
using namespace std;


int main()
{
	ConfigApp config;
	config.init();

	ManageLop lop;
	lop.renderPage();

	system("pause");
	return 0;
}