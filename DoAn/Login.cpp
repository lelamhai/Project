#include "Login.h"
Login::Login()
{
	
}
Login::~Login()
{
}
void Login::main()
{
	HeaderLogin();
	drawPage();
	drawForm();
	/*drawPassword();
	drawButton();*/
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

	box(posX, 10, 70, 15);
}
void Login::drawForm()
{
	int y = DISTANCE_HEADER + PADDING + 4;
	int posX = getCenterX(getConsoleWidth(), 40);
	int posYEnter;

	int posXValidation = getCenterX(getConsoleWidth(), 24);
	string titleInput[] = {
		"Tai Khoan",
		"Mat Khau"
	};

	for (int i = 0; i < 2; i++)
	{
		listInput.push_back(InputField());
		listText.push_back(Text());

		gotoXY(posX, y + (i * 4));
		cout << titleInput[i];

		listInput[i].notUseSpace = true;
		listInput[i].setMinLen(LENGTH_MIN_DEFAULT);
		listInput[i].setFrame(27, 2);
		listInput[i].setPosition(posX + 13, y + (i * 4) - 1);
		listInput[i].drawBox();

		listText[i].setContent(NOTIFICATION_EMPTY);
		listText[i].setPosition(posXValidation, y + (i * 4) + 2);
		listText[i].setColor(ColorCode_DarkYellow);

		posYEnter = y + (i * 4) + 2;
	}

	listInput[1].useHide = true;

	posYEnter += 1;
	int posXMes = getCenterX(getConsoleWidth(), 21);
	text.setContent("Tai Khoan Khong Dung!");
	text.setPosition(posXMes, posYEnter);
	text.setColor(ColorCode_DarkRed);

	posYEnter += 1;
	int posXEnter = getCenterX(getConsoleWidth(), 10);
	box(posXEnter, posYEnter, 10, 2);
	gotoXY(posXEnter + 3, posYEnter + 1);
	cout << "Enter";
}

void Login::formLogin()
{
	ManageClass classList;
	bool result;

	listInput[0].setText("");
	listInput[1].setText("");
	showCur(1);
	while (true)
	{
		if (stateLoginInput == LOGIN_USERNAME)
		{
			listText[0].display();

			listInput[0].handleInput();

			listText[0].clean();

			switch (listInput[0].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "")
				{
					stateLoginInput = LOGIN_ENTER;
					continue;
				}
				stateLoginInput = LOGIN_PASSWORD;
				break;

			case DOWN:
				stateLoginInput = LOGIN_PASSWORD;
				break;

			case UP:
				stateLoginInput = LOGIN_PASSWORD;
				break;

			default:
				break;
			}
		}

		if (stateLoginInput == LOGIN_PASSWORD)
		{
			
			listText[1].display();

			listInput[1].handleInput();

			listText[1].clean();

			switch (listInput[1].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "")
				{
					stateLoginInput = LOGIN_ENTER;
					continue;
				}
				stateLoginInput = LOGIN_PASSWORD;
				break;

			case DOWN:
				stateLoginInput = LOGIN_USERNAME;
				break;

			case UP:
				stateLoginInput = LOGIN_USERNAME;
				break;

			default:
				break;
			}
		}

		if (stateLoginInput == LOGIN_ENTER)
		{
			result = classList.logIn(listInput[0].getText().c_str(), listInput[1].getText().c_str());
			if (result)
			{
				stateLoginInput = LOGIN_USERNAME;
				return;
			}
			else 
			{
				text.display();
				stateLoginInput = LOGIN_USERNAME;
			}
		}
	}
}