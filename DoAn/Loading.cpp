#include "Loading.h"

Loading::Loading()
{
}

Loading::~Loading()
{
}

void Loading::drawPage()
{
	int width = getConsoleWidth();
	int height = getConsoleHeight();
	char inTitle[5][133] = {
		" ____  _   _    _    _   _   __  __ _____ __  __   _____ _   _ ___",
		"|  _ \\| | | |  / \\  | \\ | | |  \\/  | ____|  \\/  | |_   _| | | |_ _|",
		"| |_) | |_| | / _ \\ |  \\| | | |\\/| |  _| | |\\/| |   | | | |_| || |",
		"|  __/|  _  |/ ___ \\| |\\  | | |  | | |___| |  | |   | | |  _  || |",
		"|_|   |_| |_/_/   \\_\\_| \\_| |_|  |_|_____|_|  |_|   |_| |_| |_|___|"
	};

	int posX = width / 10 - 10;
	int posY = height/3 - 8;
	for (int i = 0; i < 5; i++)
	{
		gotoXY(posX, posY);
		cout << inTitle[i];
		posY++;
	}


	char inTitle1[5][133] = {
		" _____ ____      _    ____   _   _  ____ _   _ ___ _____ __  __ ",
		"|_   _|  _ \\    / \\  / ___| | \\ | |/ ___| | | |_ _| ____|  \\/  |",
		"  | | | |_) |  / _ \\| |     |  \\| | |  _| |_| || ||  _| | |\\/| |",
		"  | | |  _ <  / ___ \\ |___  | |\\  | |_| |  _  || || |___| |  | |",
		"  |_| |_| \\_\\/_/   \\_\\____| |_| \\_|\\____|_| |_|___|_____|_|  |_|"
	};

	int x = width / 5;
	int y = height / 2 - 10;
	for (int i = 0; i < 5; i++)
	{
		gotoXY(x, y + i);
		cout << inTitle1[i];
	}

	char right[5][100] = {
		"K23DTCN426 - Le Lam Hai",
		"",
		"K23DTCN269 - Vu Duy Dung",
		"",
		"K24DTCN258 - Cao Ngoc Huy"
	};

	y += 10;
	for (int i = 0; i < 5; i++)
	{
		gotoXY(x + 20, y + i);
		cout << right[i];
	}

	int ix = getCenterX(width + width / 2, 41);
	int iy = getConsoleHeight() / 5 - 2;
	setColorText(ColorCode_DarkRed);
	gotoXY(ix, iy + 0);  cout << "                                         \n";
	gotoXY(ix, iy + 1);  cout << "                                         \n";
	gotoXY(ix, iy + 2);  cout << "                          ,*//,          \n";
	gotoXY(ix, iy + 3);  cout << "                     .(##########(       \n";
	gotoXY(ix, iy + 4);  cout << "                  .*##/,     ,(####,     \n";
	gotoXY(ix, iy + 5);  cout << "                (*#(            /###     \n";
	gotoXY(ix, iy + 6);  cout << "             .#,(                *##,    \n";
	gotoXY(ix, iy + 7);  cout << "            /(/                   ##/    \n";
	gotoXY(ix, iy + 8);  cout << "          ,#,                     /#*    \n";
	gotoXY(ix, iy + 9);  cout << "         /#,                      *#.    \n";
	gotoXY(ix, iy + 10); cout << "        (#                        /#     \n";
	gotoXY(ix, iy + 11); cout << "       (#.                        #/     \n";
	gotoXY(ix, iy + 12); cout << "      ##*                     .   (      \n";
	gotoXY(ix, iy + 13); cout << "     (##                     .,  /       \n";
	gotoXY(ix, iy + 14); cout << "    *##.                    .*. ..       \n";
	gotoXY(ix, iy + 15); cout << "    ##/  ####### (######*./***/, ####### \n";
	gotoXY(ix, iy + 16); cout << "   (##   ##.  (##   ##   .*//,     /#(   \n";
	gotoXY(ix, iy + 17); cout << "  .###   ##(####*   ##  .*.*(,     /#(   \n";
	gotoXY(ix, iy + 18); cout << "  /###   ##,.       ##   .#*##     /#(   \n";
	gotoXY(ix, iy + 19); cout << "  ####   ##.        ##  *##*##     /#(   \n";
	gotoXY(ix, iy + 20); cout << "  ####   ..         . ,###/ .            \n";
	gotoXY(ix, iy + 21); cout << "  (###/             .####.               \n";
	gotoXY(ix, iy + 22); cout << "  .####(         .#####.                 \n";
	gotoXY(ix, iy + 23); cout << "   .#####,    .(####(                    \n";
	gotoXY(ix, iy + 24); cout << "    .(,,.,/######/                       \n";
	gotoXY(ix, iy + 25); cout << "       .*(((/,                           \n";
	setColorText(ColorCode_White);
}

void Loading::processing()
{
	int height = getConsoleHeight();
	int width = getConsoleWidth();
	int x = getCenterX(width, 180);
	setColorText(ColorCode_DarkBlue);
	gotoXY(x, height - 5);
	cout << char(219);
	setColorText(ColorCode_White);
}

void Loading::main()
{
	drawPage();
	processing();
	_getch();
}