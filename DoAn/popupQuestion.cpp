#include "PopupQuestion.h"

PopupQuestion::PopupQuestion()
{
}

PopupQuestion::~PopupQuestion()
{
}

void PopupQuestion::open()
{
	content();
	createButtonNo();
	createButtonYes();
}

void PopupQuestion::close()
{
	textbk(ColorCode_Back);
	clean();
}

void PopupQuestion::handle()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_RETURN))
		{
			return;
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			gotoXY(getPosX() + 13, getPosY() + getHeight() - 5 + 1);

			setColorText(ColorCode_DarkGreen);
			textbk(ColorCode_DarkBlue);
			cout << NO;
			textbk(ColorCode_Back);
			setColorText(ColorCode_White);

			
			gotoXY(getPosX() + 13 + 8 + 8 + 4, getPosY() + getHeight() - 5 + 1);
			setColorText(ColorCode_White);
			textbk(ColorCode_DarkBlue);
			cout << YES;
			

			result = false;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			gotoXY(getPosX() + 13, getPosY() + getHeight() - 5 + 1);
			setColorText(ColorCode_White);
			textbk(ColorCode_DarkBlue);
			cout << NO;
			textbk(ColorCode_Back);


			gotoXY(getPosX() + 13 + 8 + 8 + 4, getPosY() + getHeight() - 5 + 1);
			setColorText(ColorCode_DarkGreen);
			textbk(ColorCode_DarkBlue);
			cout << YES;
			textbk(ColorCode_Back);
			setColorText(ColorCode_White);

			result = true;
		}

		if (GetAsyncKeyState(VK_PRIOR) & 0x8000)
		{
			Sleep(150);
			continue;
		}

		if (GetAsyncKeyState(VK_NEXT) & 0x8000)
		{
			Sleep(150);
			continue;
		}

		/*if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			if (moveMenu != 0)
			{
				return;
			}
		}*/
		Sleep(150);
	}
}

void PopupQuestion::createButtonNo()
{
	textbk(ColorCode_DarkBlue);
	box(getPosX() + 50 / 2 - 10 - 5, getPosY() + getHeight() - 5, 10, 2);
	gotoXY(getPosX() + 13, getPosY() + getHeight() - 5 + 1);
	cout << NO;
	textbk(ColorCode_Back);
}

void PopupQuestion::createButtonYes()
{
	textbk(ColorCode_DarkBlue);
	box(getPosX() + 50 / 2 + 4, getPosY() + getHeight() - 5, 9, 2);
	gotoXY(getPosX() + 13 + 8 + 8 + 4, getPosY() + getHeight() - 5 + 1);

	setColorText(ColorCode_DarkGreen);
	textbk(ColorCode_DarkBlue);
	cout << YES;
	textbk(ColorCode_Back);
}

bool PopupQuestion::getResult()
{
	return result;
}