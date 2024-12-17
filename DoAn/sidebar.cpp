#include "mycolor.h"
#include "mywindows.h"
#include "mydraw.h"
#include <iostream>
using namespace std;

void Sidebar()
{
	int height = getConsoleHeight();

	lineY(30, 8, height - 8*2);
	gotoXY(30, 8);
	cout << char(194);
}

void TutorialMenu()
{
	string tutorialMenu[] = {
		"* Huong Dan Su Dung Menu",
		"",
		"PGUP|PGDN: Di Chuyen Menu",
		"Tab: Chon Menu"
	};

	int height = getConsoleHeight();
	int posY = height - 8 * 2 + 3;

	for (int i = 0; i < 4; i++)
	{
		setColorText(ColorCode_DarkYellow);
		gotoXY(1, posY + i);
		cout << tutorialMenu[i];
	}
	setColorText(ColorCode_White);
}