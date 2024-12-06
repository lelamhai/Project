#include "PopupFinishExam.h"
PopupFinishExam::PopupFinishExam()
{
}

PopupFinishExam::~PopupFinishExam()
{
}

void PopupFinishExam::open()
{
	this->setTitle("Ban co muon nop bai thi khong?");
	this->content();
	createButtonNo();
	createButtonYes();
}

void PopupFinishExam::createButtonNo()
{
	box(getPosX() + 50 / 2 - 10 - 5, getPosY() + getHeight() - 5, 10, 2);
	gotoXY(getPosX() + 13, getPosY() + getHeight() - 5 + 1);
	cout << "Khong";
}

void PopupFinishExam::createButtonYes()
{
	box(getPosX() + 50 / 2 + 4, getPosY() + getHeight() - 5, 9, 2);

	setColorText(ColorCode_DarkGreen);
	textbk(ColorCode_DarkCyan);
	gotoXY(getPosX() + 13 + 8 + 8 + 4, getPosY() + getHeight() - 5 + 1);
	cout << "Co";
}

void PopupFinishExam::handle()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_RETURN))
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
		Sleep(150);
	}
}


void PopupFinishExam::close()
{
	textbk(ColorCode_Back);
	clean();
}

bool PopupFinishExam::getResult()
{
	return result;
}