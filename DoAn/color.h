#pragma once
#include <windows.h>

enum ColorState {
	ColorCode_Back			= 0,
	ColorCode_DarkBlue		= 1,
	ColorCode_DarkGreen		= 2,
	ColorCode_DarkCyan		= 3,
	ColorCode_DarkRed		= 4,
	ColorCode_DarkPink		= 5,
	ColorCode_DarkYellow	= 6,
	ColorCode_DarkWhite		= 7,
	ColorCode_Grey			= 8,
	ColorCode_Blue			= 9,
	ColorCode_Green			= 10,
	ColorCode_Cyan			= 11,
	ColorCode_Red			= 12,
	ColorCode_Pink			= 13,
	ColorCode_Yellow		= 14,
	ColorCode_White			= 15
};

void setBlackText()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorCode_Back);
}

void setWhiteText()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorCode_White);
}

void setBlueText()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorCode_Blue);
}

void setGreenText()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorCode_Green);
}

void setRedText()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorCode_Red);
}

void setPinkText()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorCode_Pink);
}

void setColorText(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

void BackgroundColor()
{
	system("COLOR 7F");
}