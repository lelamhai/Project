#include "configApp.h"
#include "Login.h"
#include "About.h"
#include "ManageClass.h"
#include <conio.h>
#include <iostream>
using namespace std;


int main()
{
	ConfigApp config;
	config.init();
	
	Login* login = new Login();
	login->main();

	//_getch();
	system("pause");
	return 0;
}