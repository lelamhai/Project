#include "InputField.h"

InputField::InputField()
{
}

InputField::~InputField()
{
}

void InputField::handleInput()
{
	while (true)
	{
		char s = _getch();
		int key = keySpecial(s);

		if (s == ENTER)
		{
			return;
		}

		switch (key)
		{
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

		default:
			break;
		}

		switch (s)
		{
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
				continue;
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

string InputField::getText()
{
	return inputString;
}