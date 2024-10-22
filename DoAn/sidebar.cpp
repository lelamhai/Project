#pragma once
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