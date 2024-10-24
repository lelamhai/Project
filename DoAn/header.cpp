#include "Header.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mywindows.h"

#include <iostream>
using namespace std;

void Header()
{
	DrawTitle();
	DrawLine();
}

void DrawTitle()
{
	int width = getConsoleWidth();
	
	char inTitle[5][133] = {
		" ____  _   _    _    _   _   __  __ _____ __  __   _____ _   _ ___   _____ ____      _    ____   _   _  ____ _   _ ___ _____ __  __ ",
		"|  _ \\| | | |  / \\  | \\ | | |  \\/  | ____|  \\/  | |_   _| | | |_ _| |_   _|  _ \\    / \\  / ___| | \\ | |/ ___| | | |_ _| ____|  \\/  |",
		"| |_) | |_| | / _ \\ |  \\| | | |\\/| |  _| | |\\/| |   | | | |_| || |    | | | |_) |  / _ \\| |     |  \\| | |  _| |_| || ||  _| | |\\/| |",
		"|  __/|  _  |/ ___ \\| |\\  | | |  | | |___| |  | |   | | |  _  || |    | | |  _ <  / ___ \\ |___  | |\\  | |_| |  _  || || |___| |  | |",
		"|_|   |_| |_/_/   \\_\\_| \\_| |_|  |_|_____|_|  |_|   |_| |_| |_|___|   |_| |_| \\_\\/_/   \\_\\____| |_| \\_|\\____|_| |_|___|_____|_|  |_|"
	};

	int posX = getCenterX(width, 132);
	int posY = 1;
	for (int i = 0; i < 5; i++)
	{
		gotoXY(posX, posY);
		cout << inTitle[i];
		posY++;
	}
}

void DrawLine()
{
	int width = getConsoleWidth();
	int height = getConsoleHeight();
	lineX(0, 8, width);
}