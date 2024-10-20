#include "Header.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mywindows.h"

#include <iostream>
using namespace std;

void Footer()
{
	int width = getConsoleWidth();
	int height = getConsoleHeight();
	lineX(0, height - 7, width);

	gotoXY(30, height-7);
	cout << char(193);
}