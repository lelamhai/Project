#include "Header.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mywindows.h"

#include <iostream>
using namespace std;

void Header()
{
	int width = getConsoleWidth();
	int height = getConsoleHeight();
	lineX(0, 7, width);
	int y = 1;
	gotoXY(0, y++); cout << "\t\t\t\t\t\t ____  _   _    _    _   _   __  __ _____ __  __   _____ _   _ ___   _____ ____      _    ____   _   _  ____ _   _ ___ _____ __  __ ";
	gotoXY(0, y++); cout << "\t\t\t\t\t\t|  _ \\| | | |  / \\  | \\ | | |  \\/  | ____|  \\/  | |_   _| | | |_ _| |_   _|  _ \\    / \\  / ___| | \\ | |/ ___| | | |_ _| ____|  \\/  |";
	gotoXY(0, y++); cout << "\t\t\t\t\t\t| |_) | |_| | / _ \\ |  \\| | | |\\/| |  _| | |\\/| |   | | | |_| || |    | | | |_) |  / _ \\| |     |  \\| | |  _| |_| || ||  _| | |\\/| |";
	gotoXY(0, y++); cout << "\t\t\t\t\t\t|  __/|  _  |/ ___ \\| |\\  | | |  | | |___| |  | |   | | |  _  || |    | | |  _ <  / ___ \\ |___  | |\\  | |_| |  _  || || |___| |  | |";
	gotoXY(0, y++); cout << "\t\t\t\t\t\t|_|   |_| |_/_/   \\_\\_| \\_| |_|  |_|_____|_|  |_|   |_| |_| |_|___|   |_| |_| \\_\\/_/   \\_\\____| |_| \\_|\\____|_| |_|___|_____|_|  |_|";
}