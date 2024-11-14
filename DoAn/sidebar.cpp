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
		"PGUP|PGDN",
		"Enter"
	};

	int height = getConsoleHeight();
	int posY = height - 8 * 2 + 6;

	setColorText(ColorCode_DarkYellow);
	gotoXY(1, posY);
	cout << tutorialMenu[0];

	gotoXY(24, posY);
	cout << tutorialMenu[1];
	setColorText(ColorCode_DarkWhite);
}