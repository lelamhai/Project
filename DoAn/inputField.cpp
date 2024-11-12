#include "InputField.h"

InputField::InputField()
{
}

InputField::~InputField()
{
}

void InputField::handleInput()
{
	cursorPosition = inputString.length();
	while (true)
	{
		if (GetAsyncKeyState(VK_F1))
		{
			keyInput = F1;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_F2))
		{
			keyInput = F2;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_F3))
		{
			keyInput = F3;
			Sleep(150);
			return;
		}

		char s = _getch();
		int key = keySpecial(s);
		switch (key)
		{
		case PGUP:
			keyInput = PGUP;

		case PGDN:
			keyInput = PGDN;

		case UP:
			keyInput = UP;
			return;

		case DOWN:
			keyInput = DOWN;
			return;

		case LEFT:
			if (cursorPosition <= 0)
			{
				continue;
			}

			cursorPosition--;
			gotoXY(whereX() - 1, whereY());
			continue;

		case RIGHT:
			if (cursorPosition >= inputString.length())
			{
				continue;
			}

			cursorPosition++;
			gotoXY(whereX() + 1, whereY());
			continue;

		case DEL:
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
			continue;
		
		}

		switch (s)
		{
		case ENTER:
			keyInput = ENTER;
			return;

		case SPACEBAR:
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
			if (inputString.length() > 14)
			{
				break;
			}

			if (s >= 'a' && s <= 'z' || s >= 'A' && s <= 'Z' || s >= '0' && s <= '9')
			{
				inputString.insert(inputString.begin() + cursorPosition, s);
				cursorPosition++;
				cout << s;

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