#include "Footer.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mywindows.h"

#include <iostream>
using namespace std;

void Footer()
{
	Line();
	Left();
	Center();
	Right();
}

void Line() 
{
	int width = getConsoleWidth();
	int height = getConsoleHeight();
	lineX(0, height - 8, width);

	gotoXY(30, height - 8);
	cout << char(193);
}

void Left()
{
	char footerLeft[5][100] = {
		"ThS.Luu Nguyen Ky Thu",
		"",
		"SDT:0913763320",
		"",
		"Mail:Lnkthu@ptithcm.edu.vn"
	};

	int height = getConsoleHeight();
	int posY = height - 6;
	for (int i = 0; i < 5; i++)
	{
		gotoXY(8, posY);
		cout << footerLeft[i];
		posY++;
	}
}

void Center()
{
	int width = getConsoleWidth();
	int height = getConsoleHeight();

	int posX = getCenterX(width, 45);
	int posY = height - 6;

	char center[5][100] = {
		"       Hoc Vien Buu Chinh Vien Thong       ",
		"",
		"       02437562186 - ctsv@ptit.edu.vn      ",
		"",
		" 11 Nguyen Dinh Chieu, P.Da Kao, Q.1 TP.HCM"
		
		
	};
	for (int i = 0; i < 5; i++)
	{
		gotoXY(posX, posY);
		cout << center[i];
		posY++;
	}
}

void Right() 
{
	char right[5][100] = {
		"K23DTCN426 - Le Lam Hai",
		"",
		"K23DTCN269 - Vu Duy Dung",
		"",
		"K24DTCN258 - Cao Ngoc Huy"
	};

	int width = getConsoleWidth();
	int height = getConsoleHeight();
	int posX = width - 25 - 8;
	int posY = height - 6;
	for (int i = 0; i < 5; i++)
	{
		gotoXY(posX, posY);
		cout << right[i];
		posY++;
	}
}