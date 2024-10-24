#include "Login.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include <conio.h>
#include <iostream>
using namespace std;

Login::Login()
{
	HeaderLogin();
}

Login::~Login()
{
}

void Login::main()
{
	showCur(1);
	drawBox();
	drawUserName();
	drawPassword();
	message();
	drawButton();
	formLogin();
}

void Login::HeaderLogin()
{
	char inTitle[5][55] = {
		" ____    _    _   _  ____   _   _ _   _    _    ____  ",
		"|  _ \\  / \\  | \\ | |/ ___| | \\ | | | | |  / \\  |  _ \\ ",
		"| | | |/ _ \\ |  \\| | |  _  |  \\| | |_| | / _ \\ | |_) |",
		"| |_| / ___ \\| |\\  | |_| | | |\\  |  _  |/ ___ \\|  __/ ",
		"|____/_/   \\_\\_| \\_|\\____| |_| \\_|_| |_/_/   \\_\\_|    "
	};

	int width = getConsoleWidth();
	int posX = getCenterX(width, 54);

	int posY = 1;
	for (int i = 0; i < 5; i++)
	{
		gotoXY(posX, posY);
		cout << inTitle[i];
		posY++;
	}
}

void Login::drawBox()
{
	int width = getConsoleWidth();
	int posX = getCenterX(width, 70);

	box(posX, 10, 70, 14);
}

void Login::drawUserName()
{
	int width = getConsoleWidth();
	int posX = getCenterX(width, 40);
	gotoXY(posX, 13);
	cout << "Tai Khoan";

	box(posX+12, 12, 30, 2);
}

void Login::drawPassword()
{
	int width = getConsoleWidth();
	int posX = getCenterX(width, 40);
	gotoXY(posX, 12 + 4);
	cout << "Mat Khau";

	box(posX + 12, 11 + 4, 30, 2);
}

void Login::formLogin()
{
	showCur(true);
	string userName = "";
	string password = "";
	int width = getConsoleWidth();
	int posX = getCenterX(width, 40);
	posX = posX + 13 + 1;
	int tempX = posX;
	int posY = 13;

	stateInput = USERNAME;
	while (true)
	{
		switch (this->stateInput)
		{
		case USERNAME:
			posX += userName.length();
			gotoXY(posX, posY);
			inputUserName(userName, posX , posY);
			posX = tempX;
			break;
		case PASSWORD:
			posX += password.length();
			gotoXY(posX, posY+3);
			inputPassword(password, posX, posY + 3);
			posX = tempX;
			break;
		default:
			break;
		}
	}
}

void Login::inputUserName(string &input, int x, int y)
{
	while (true)
	{
		char s = _getch();
		int key = keyArrow(s);

		switch (key)
		{
		case A_UP:
			stateInput = USERNAME;
			return;

		case A_DOWN:
			stateInput = PASSWORD;
			return;
		default:
			break;
		}

		switch (s)
		{
		case BACKSPACE:
			if (input.length() <= 0)
			{
				continue;
			}
			input.erase(input.length() - 1, 1); 
			x --;
			cout << "\b \b";
			break;

		case SPACE:
			continue;

		case TAB:
			continue;

		default:
			if (input.length() > 14)
			{
				continue;
			}

			input.push_back(s);
			gotoXY(x, y);
			cout << s;
			x++;
			break;
		}
	}
}
void Login::inputPassword(string& input, int x, int y)
{
	while (true)
	{
		char s = _getch();
		int key = keyArrow(s);

		switch (key)
		{
		case A_UP:
			stateInput = USERNAME;
			return;

		case A_DOWN:
			stateInput = PASSWORD;
			return;
		default:
			break;
		}

		switch (s)
		{
		case BACKSPACE:
			if (input.length() <= 0)
			{
				continue;
			}

			input.erase(input.length() - 1, 1);
			x--;
			cout << "\b \b";
			break;

		case SPACE:
			continue;

		case TAB:
			continue;

		default:
			if (input.length() > 14)
			{
				continue;
			}
			input.push_back(s);
			gotoXY(x, y);
			cout << s;
			Sleep(150);

			gotoXY(x, y);
			cout << "*";
			x++;
			break;
		}
	}
}

void Login::message()
{

}

void Login::drawButton()
{
	int width = getConsoleWidth();
	int posX = getCenterX(width, 10);
	box(posX, 16 + 4, 10, 2);

	gotoXY(posX+3, 17 + 4);
	cout << "Enter";
}