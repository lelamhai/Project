#pragma once
#include "color.h"
#include <iostream>
using namespace std;
void Sidebar()
{
	int height = getConsoleHeight();
	lineY(30, 6, height-6);
	gotoXY(30, 6);
	cout << char(194);
}