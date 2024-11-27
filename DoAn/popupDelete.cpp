#include "PopupDelete.h"

PopupDelete::PopupDelete()
{
}

PopupDelete::~PopupDelete()
{
}

void PopupDelete::open()
{
	this->setTitle("Ban co muon xoa du lieu nay khong?");
	this->content();
	createButtonNo();
	createButtonYes();
}

void PopupDelete::close()
{
	textbk(ColorCode_Back);
	cleanTable();
}

void PopupDelete::handle()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		{
			return;
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			setColorText(ColorCode_DarkGreen);
			textbk(ColorCode_DarkCyan);
			gotoXY(getPosX() + 13, getPosY() + getHeight() - 5 + 1);
			cout << "Khong";

			setColorText(ColorCode_White);
			textbk(ColorCode_DarkCyan);
			gotoXY(getPosX() + 13 + 8 + 8 + 4, getPosY() + getHeight() - 5 + 1);
			cout << "Co";

			result = false;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			setColorText(ColorCode_White);
			textbk(ColorCode_DarkCyan);
			gotoXY(getPosX() + 13, getPosY() + getHeight() - 5 + 1);
			cout << "Khong";

			setColorText(ColorCode_DarkGreen);
			textbk(ColorCode_DarkCyan);
			gotoXY(getPosX() + 13 + 8 + 8 + 4, getPosY() + getHeight() - 5 + 1);
			cout << "Co";

			result = true;
		}

		if (GetAsyncKeyState(VK_PRIOR) & 0x8000)
		{
			moveMenu--;
			Sleep(150);
			continue;
		}

		if (GetAsyncKeyState(VK_NEXT) & 0x8000)
		{
			moveMenu++;
			Sleep(150);
			continue;
		}
		Sleep(150);
	}
}

void PopupDelete::createButtonNo()
{
	box(getPosX() + 50 / 2 - 10 - 5, getPosY() + getHeight() - 5, 10, 2);
	gotoXY(getPosX() + 13, getPosY() + getHeight() - 5 + 1);
	cout << "Khong";
}

void PopupDelete::createButtonYes()
{
	box(getPosX() + 50 / 2 + 4, getPosY() + getHeight() - 5, 9, 2);

	setColorText(ColorCode_DarkGreen);
	textbk(ColorCode_DarkCyan);
	gotoXY(getPosX() + 13 + 8 + 8 + 4, getPosY() + getHeight() - 5 + 1);
	cout << "Co";
}

bool PopupDelete::getResult()
{
	return result;
}

void PopupDelete::setMenu(int move)
{
	this->moveMenu = move;
}

int PopupDelete::getMenu()
{
	return this->moveMenu;
}