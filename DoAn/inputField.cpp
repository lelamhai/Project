#include "InputField.h"

InputField::InputField()
{
}

InputField::~InputField()
{
}

void InputField::setPosition(int posX, int posY)
{
	this->x = posX;
	this->y = posY;
}

void InputField::setFrame(int width, int height)
{
	this->w = width;
	this->h = height;
}

void InputField::drawBox()
{
	box(x, y, w, h);
}

void InputField::focus()
{
	gotoXY(x+1,y+1);
}

void InputField::clean()
{
	string blankFill;
	blankFill.resize(WIDTH_INPUT - 1, ' ');
	for (int i = 0; i < 1; i++)
	{
		gotoXY(x+1, y+1);
		cout << blankFill;
	}
}

void InputField::handleInput()
{
	cursorPosition = inputString.length();
	gotoXY(x + 1 + cursorPosition, y + 1);
	while (true)
	{
		if (GetAsyncKeyState(VK_F1) & 0x0001)
		{
			keyInput = F1;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_F2) & 0x0001)
		{
			keyInput = F2;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_F3) & 0x0001)
		{
			keyInput = F3;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_UP) & 0x0001)
		{
			keyInput = UP;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x0001)
		{
			keyInput = DOWN;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			if (useGender)
			{
				continue;
			}

			if (cursorPosition <= 0)
			{
				Sleep(150);
				continue;
			}

			cursorPosition--;
			gotoXY(whereX() - 1, whereY());
			Sleep(150);
			continue;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			if (useGender)
			{
				continue;
			}

			if (cursorPosition >= inputString.length())
			{
				Sleep(150);
				continue;
			}

			cursorPosition++;
			gotoXY(whereX() + 1, whereY());
			Sleep(150);
			continue;
		}

		if (GetAsyncKeyState(VK_DELETE) & 0x0001)
		{
			if (cursorPosition == inputString.length())
			{
				Sleep(150);
				continue;
			}

			inputString.erase(cursorPosition, 1);
			for (int i = cursorPosition; i < inputString.length(); i++)
			{
				cout << inputString[i];
			}
			gotoXY(whereX(), whereY());
			cout << " ";
			gotoXY(whereX() - 1 - (inputString.length() - cursorPosition), whereY());
			Sleep(150);
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		{
			keyInput = ENTER;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_PRIOR) & 0x8000)
		{
			moveMenu--;
			Sleep(150);
			showCur(1);
			return;
		}

		if (GetAsyncKeyState(VK_NEXT) & 0x8000)
		{
			moveMenu++;
			Sleep(150);
			showCur(1);
			return;
		}

		if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			keyInput = TAB;
			Sleep(150);
			return;
		}

		

		char s = _getch();
		int key = keySpecial(s);
		switch (key)
		{
	/*	case PGUP:
			moveMenu--;
			break;

		case PGDN:
			moveMenu++;
			break;*/

	/*	case UP:
			keyInput = UP;
			return;

		case DOWN:
			keyInput = DOWN;
			return;*/

		/*case LEFT:
			if (cursorPosition <= 0)
			{
				continue;
			}

			cursorPosition--;
			gotoXY(whereX() - 1, whereY());
			continue;*/

	/*	case RIGHT:
			if (cursorPosition >= inputString.length())
			{
				continue;
			}

			cursorPosition++;
			gotoXY(whereX() + 1, whereY());
			continue;*/

		/*case DEL:
			if (cursorPosition == inputString.length())
			{
				continue;
			}

			inputString.erase(cursorPosition, 1);
			for (int i = cursorPosition; i < inputString.length(); i++)
			{
				cout << inputString[i];
			}
			gotoXY(whereX(), whereY());
			cout << " ";
			gotoXY(whereX() - 1 - (inputString.length() - cursorPosition), whereY());
			continue;*/
		}

		switch (s)
		{
		/*case ENTER:
			keyInput = ENTER;
			return;*/
		case ADD:
			keyInput = ADD;
			return;

		case SUBTRACT:
			keyInput = SUBTRACT;
			return;

		case SPACEBAR:
			if (useGender)
			{
				continue;
			}

			if (useSpace)
			{
				continue;
			}

			inputString.insert(inputString.begin() + cursorPosition, s);
			cursorPosition++;
			cout << " ";
			for (int i = cursorPosition; i < inputString.length(); i++)
			{
				cout << inputString[i];
			}

			gotoXY(whereX() - (inputString.length() - cursorPosition), whereY());
			break;

		case BACKSPACE:
			if (useGender)
			{
				break;
			}

			if (inputString.length() <= 0 || cursorPosition <= 0)
			{
				break;
			}

			if (cursorPosition == inputString.length())
			{
				inputString.erase(inputString.length() - 1, 1);
				cursorPosition--;
				cout << "\b \b";
			}
			else {
				inputString.erase(--cursorPosition, 1);
				gotoXY(whereX() - 1, whereY());
				for (int i = cursorPosition; i < inputString.length(); i++)
				{
					cout << inputString[i];
				}
				gotoXY(whereX(), whereY());
				cout << " ";
				gotoXY(whereX() - 1 - (inputString.length() - cursorPosition), whereY());
			}

			break;

		default:
			if (inputString.length() > 13)
			{
				break;
			}

			if (s >= 'a' && s <= 'z' || s >= 'A' && s <= 'Z' || s >= '0' && s <= '9')
			{
				inputString.insert(inputString.begin() + cursorPosition, s);
				cursorPosition++;
				cout << s;
				if (useHide)
				{
					Sleep(150);
					gotoXY(whereX() - 1, whereY());
					cout << "*";
				}

				if (cursorPosition != inputString.length())
				{
					for (int i = cursorPosition; i <= inputString.length(); i++)
					{
						cout << inputString[i];
					}
					gotoXY(whereX() - (inputString.length() - cursorPosition), whereY());
				}
			}

			break;
		}
	}
}

KeyState InputField::getEndKey()
{
	return keyInput;
}

string InputField::getText()
{
	return inputString;
}

void InputField::setText(string value)
{
	inputString = value;
}

void InputField::display()
{
	cout << inputString;
}

void InputField::setMenu(int move)
{
	this->moveMenu = move;
}

int InputField::getMenu()
{
	return this->moveMenu;
}