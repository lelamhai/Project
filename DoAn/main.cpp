//#include "PageSplash.h"
//#include "PageLogin.h"
//#include "Frame.h"
//#include "window.h"
//#include "keyboard.h"

#include "mycolor.h"

#include <thread>
#include <iostream>
using namespace std;
//int keyhit = 0;
//
//void Sidebar()
//{
//	keyhit = 0;
//	while (true)
//	{
//		cout << "Sidebar" << endl;
//		Sleep(200);
//	}
//}
//
//void Content()
//{
//	while (true)
//	{
//		cout << "Content" << endl;
//		Sleep(500);
//	}
//}


int main()
{

	/*ShowCur(0);
	setSizeWindow(1920,1080);
	blockResizeWindow();
	removeScroll();
	setColorBT();*/
	/*SplashScreen();
	Login();
	Manage();*/
	//PageFrame();

	/*thread sidebar(Sidebar);
	thread content(Content);*/

	setColorBT();
	cout << "Sidebar" << endl;


	system("pause");
	return 0;
}