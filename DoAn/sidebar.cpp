#pragma once
#include "mycolor.h"
#include "mywindows.h"
#include "mydraw.h"
#include <iostream>
using namespace std;

void Sidebar()
{
	int height = getConsoleHeight();

	lineY(30, 7, height - 14);
	gotoXY(30, 7);
	cout << char(194);
}