#include "InputField.h"

InputField::InputField()
{
}

InputField::~InputField()
{
}

void InputField::setMaxLen(int length)
{
	this->maxLen = length;
}

void InputField::setMinLen(int length)
{
	this->minLen = length;
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
	gotoXY(x + 1, y + 1);
}

void InputField::clean()
{
	string blankFill;
	blankFill.resize(w - 1, ' ');
	for (int i = 0; i < 1; i++)
	{
		gotoXY(x + 1, y + 1);
		cout << blankFill;
	}
}

void InputField::handleInput()
{
	showCur(1);
	int count;
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

		if (GetAsyncKeyState(VK_F4) & 0x0001)
		{
			keyInput = F4;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_UP) & 0x0001)
		{
			if (inputString.length() < minLen)
			{
				continue;
			}

			keyInput = UP;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x0001)
		{
			if (inputString.length() < minLen)
			{
				continue;
			}

			keyInput = DOWN;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			if (notKeyArrow)
			{
				continue;
			}

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
			if (notKeyArrow)
			{
				continue;
			}

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
			if (inputString.length() < minLen)
			{
				continue;
			}

			keyInput = ENTER;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			keyInput = TAB;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
		{
			keyInput = ESC;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_PRIOR) & 0x8000)
		{
			keyInput = PGUP;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_NEXT) & 0x8000)
		{
			keyInput = PGDN;
			Sleep(150);
			return;
		}

		char s = _getch();
		int key = keySpecial(s);
		switch (key)
		{
		case LEFT:
			continue;

		case RIGHT:
			continue;

		/*default:
			break;*/
		}
		switch (s)
		{
		case ADD:
			if (useGender)
			{
				keyInput = ADD;
				return;
			}
			if (!useSpecial)
			{
				break;
			}
			inputString.insert(inputString.begin() + cursorPosition, s);
			cursorPosition++;
			cout << s;
			break;

		case SUBTRACT:
			if (useGender)
			{
				keyInput = SUBTRACT;
				return;
			}

			if (!useSpecial)
			{
				break;
			}
			inputString.insert(inputString.begin() + cursorPosition, s);
			cursorPosition++;
			cout << s;
			break;

		case SPACEBAR:
			if (notUseSpace)
			{
				break;
			}

			if (useGender)
			{
				break;
			}

			if (inputString.length() == 0)
			{
				break;
			}

			if (inputString.length() > maxLen)
			{
				break;
			}

			if (cursorPosition <= 0)
			{
				break;
			}

			if (inputString[cursorPosition - 1] == ' ')
			{
				break;
			}

			if (inputString[cursorPosition - 1] != char(32) && inputString[cursorPosition] == char(32))
			{
				break;
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
			if (useGender)
			{
				break;
			}

			if (inputString.length() > maxLen)
			{
				break;
			}

			if (useSpecial && (s == '!' || s == '@' || s == '#' || s == '$' || s == '%' || s == '^' || s == '&' || s == '*' ||  
				s == '_' || s == '=' || s == '/' || s == '(' || s == ')'))
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
				break;
			}

			if (!useAnswer && !useNum && (s >= 'a' && s <= 'z' || s >= 'A' && s <= 'Z'))
			{
				if (s >= 'a' && s <= 'z')
				{
					s = s - ('a' - 'A');
				}
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

				break;
			}

			if (notUseZero && s == '0' && inputString.length() == 0)
			{
				break;
			}

			if (!useAnswer && s >= '0' && s <= '9')
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

				break;
			}

			if (useAnswer && s >= 'a' && s <= 'd' || s >= 'A' && s <= 'D')
			{
				if (s >= 'a' && s <= 'd')
				{
					s = s - ('a' - 'A');
				}

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

				break;
			}
		}
	}
}

KeyState InputField::getEndKey()
{
	return keyInput;
}

string InputField::getText()
{
	if (!inputString.empty() && inputString.back() == ' ')
	{
		inputString.pop_back();
	}

	return inputString;
}

void InputField::setText(string value)
{
	inputString = value;
}

void InputField::display()
{
	gotoXY(x + 1, y + 1);
	cout << inputString;
}