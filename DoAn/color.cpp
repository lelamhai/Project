#include "mycolor.h"
#include <windows.h>

void setColorText(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void setColorBT()
{
	system("COLOR 9F");
}