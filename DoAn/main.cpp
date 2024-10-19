#include "PageSplash.h"
#include "PageLogin.h"
#include "PageManage.h"
#include "mylib.h"

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	ShowCur(0);

	/*SplashScreen();
	Login();*/

	Manage();


	_getch();
	system("pause");
	return 0;
}