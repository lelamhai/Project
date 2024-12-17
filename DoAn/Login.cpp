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
	drawPage();
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
void Login::drawPage()
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
	ManageClass classList;
	bool result;

	int width = getConsoleWidth();
	int posX = getCenterX(width, 40);
	posX = posX + 13 + 1;
	int posY = 13;
	
	InputField inputUserName;
	InputField inputPassword;
	Text text;
	text.setContent("Tai khoan khong dung!");


	Login::stateLoginInput = LOGIN_USERNAME;
	while (true)
	{
		switch (stateLoginInput)
		{
		case LOGIN_USERNAME:
			gotoXY(posX + inputUserName.getText().length(), posY); 
			inputUserName.notUseSpace = true;
			inputUserName.handleInput();

			if (inputUserName.getEndKey()== ENTER)
			{
				if (inputUserName.getText() != "" && inputPassword.getText() != "")
				{
					stateLoginInput = LOGIN_ENTER;
					break;
				}
			}
			stateLoginInput = LOGIN_PASSWORD;
			break;

		case LOGIN_PASSWORD:
			gotoXY(posX + inputPassword.getText().length(), posY+3);
			inputPassword.useHide = true;
			inputPassword.notUseSpace = true;
			inputPassword.handleInput();
			if (inputPassword.getEndKey() == ENTER)
			{
				if (inputPassword.getText() != "" && inputUserName.getText() != "")
				{
					stateLoginInput = LOGIN_ENTER;
					break;
				}
			}
			stateLoginInput = LOGIN_USERNAME;
			break;

		case LOGIN_ENTER:
			result = classList.logIn(inputUserName.getText().c_str(), inputPassword.getText().c_str());
			if (result)
			{
				return;
			}
			else {

				int x = getCenterX(getConsoleWidth(), 22);
				text.setPosition(x, 13 + 3 + 2);
				text.display();
				stateLoginInput = LOGIN_USERNAME;
			}
			break;

		default:
			break;
		}
	}
}