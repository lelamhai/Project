#include "mycolor.h"
#include <windows.h>

void setColorText(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void setColorBT()
{
	system("COLOR 0F");
}

void textbk(WORD color)
{
		HANDLE hConsoleOutput;
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	
		CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
		GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	
		WORD wAttributes = screen_buffer_info.wAttributes;
		color &= 0x000f;
		color <<= 4;
		wAttributes &= 0xff0f;
		wAttributes |= color;
	
		SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}