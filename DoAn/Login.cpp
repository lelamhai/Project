#include "Login.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

Login::Login()
{
	HeaderLogin();
}

Login::~Login()
{
}

void Login::mainLogin()
{
	drawBox();
}

void Login::HeaderLogin()
{
	int width = getConsoleWidth();
	int height = getConsoleHeight();
	lineX(0, 7, width);
	int y = 1;
	gotoXY(0, y++); cout << " ____    _    _   _  ____   _   _ _   _    _    ____  ";
	gotoXY(0, y++); cout << "|  _ \\  / \\  | \\ | |/ ___| | \\ | | | | |  / \\  |  _ \\ ";
	gotoXY(0, y++); cout << "| | | |/ _ \\ |  \\| | |  _  |  \\| | |_| | / _ \\ | |_) |";
	gotoXY(0, y++); cout << "| |_| / ___ \\| |\\  | |_| | | |\\  |  _  |/ ___ \\|  __/ ";
	gotoXY(0, y++); cout << "|____/_/   \\_\\_| \\_|\\____| |_| \\_|_| |_/_/   \\_\\_|    ";
}

void Login::drawBox()
{
	box(50,8,70,12);
}