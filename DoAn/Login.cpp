#include "Login.h"
Login::Login()
{
	
}
Login::~Login()
{
}
void Login::main()
{
	showCur(1);
	HeaderLogin();
	drawBox();
	drawUserName();
	drawPassword();
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
void Login::drawButton()
{
	int width = getConsoleWidth();
	int posX = getCenterX(width, 10);
	box(posX, 16 + 4, 10, 2);

	gotoXY(posX + 3, 17 + 4);
	cout << "Enter";
}
void Login::formLogin()
{
	string userName = "";
	string password = "";
	string message = "";
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
			showCur(1);
			posX += userName.length();
			gotoXY(posX, posY);
			inputUserName(userName, posX , posY);
			posX = tempX;
			break;
		case PASSWORD:
			showCur(1);
			posX += password.length();
			gotoXY(posX, posY+3);
			inputPassword(password, posX, posY + 3);
			posX = tempX;
			break;

		case CLICKENTER:
			// Event enter
			showCur(0);
			textMessage("Message");
			return;
		default:
			break;
		}
	}
}
void Login::inputUserName(string &input, int x, int y)
{
	int len = input.length();
	while (true)
	{
		char s = _getch();
		int key = keyArrow(s);

		switch (key)
		{
		case UP:
			stateInput = USERNAME;
			return;

		case DOWN:
			stateInput = PASSWORD;
			return;

		/*case LEFT:
			if (len <= 0)
			{
				continue;
			}
			--len;
			gotoXY(--x, y);

			continue;

		case RIGHT:
			if (len >= input.length())
			{
				continue;
			}
			++len;
			gotoXY(++x, y);*/

			continue;
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

		case ENTER:
			stateInput = CLICKENTER;
			return;

		case SPACE:
			continue;

		case TAB:
			continue;

		default:
			if (input.length() > 14)
			{
				continue;
			}
			if (s >= 'A' && s <= 'z' || s >= '0' && s <= '9')
			{
				input.push_back(s);
				gotoXY(x, y);
				cout << s;
				x++;
				len = input.length();
			}
			
			break;
		}
	}
}
void Login::inputPassword(string& input, int x, int y)
{
	int len = input.length();
	while (true)
	{
		char s = _getch();
		int key = keyArrow(s);

		switch (key)
		{
		case UP:
			stateInput = USERNAME;
			return;

		case DOWN:
			stateInput = PASSWORD;
			return;

		/*case LEFT:
			if (len <= 0)
			{
				continue;
			}
			--len;
			gotoXY(--x, y);

			continue;

		case RIGHT:
			if (len >= input.length())
			{
				continue;
			}
			++len;
			gotoXY(++x, y);

			continue;*/
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

		case ENTER:
			stateInput = CLICKENTER;
			return;

		case SPACE:
			continue;

		case TAB:
			continue;

		default:
			if (input.length() > 14)
			{
				continue;
			}
			if (s >= 'A' && s <= 'z' || s >= '0' && s <= '9')
			{
				input.push_back(s);
				gotoXY(x, y);
				cout << s;
				Sleep(150);

				gotoXY(x, y);
				cout << "*";
				x++;
				len = input.length();
			}
			
			break;
		}
	}
}
void Login::textMessage(string mess)
{
	int width = getConsoleWidth();
	int posX = getCenterX(width, mess.length());
	
	gotoXY(posX - 20, 16 + 2);
	cout << "                                        ";

	gotoXY(posX, 16 + 2);
	cout << mess;

	Sleep(400);
	stateInput = USERNAME;
}