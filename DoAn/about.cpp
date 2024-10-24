#include "About.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include <iostream>
using namespace std;

About::About()
{
	templateHeader();
	templateSidebar();
	templateFooter();
}

About::~About()
{
}

void About::main()
{
	menu();
	content();
}

void About::menu()
{
	char menu[8][50] = {"Gioi Thieu", "Lop Hoc", "Sinh Vien", "Mom Hoc", "Cau Hoi", "Thi", "Dang Xuat", "Thoat"};
		
	int posY = 11;
	for (int i = 0; i < 8; i++)
	{
		gotoXY(8, posY);
		cout << menu[i];
		posY += 3;
	}
}

void About::content()
{

}

void About::title()
{

}