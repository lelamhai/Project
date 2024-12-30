#include "PopupTutorial.h"

PopupTutorial::PopupTutorial()
{
}

PopupTutorial::~PopupTutorial()
{
}

void PopupTutorial::content() 
{
	setColorText(ColorCode_DarkBlue);
	drawColorBg(getWidth(), getHeight(), getPosX(), getPosY());

	string note[] = {
		"F1: Chon Du Lieu Trong Bang",
		"F3: Tim Kiem Sinh Vien",
		"Ins: Them Sinh Vien",
		"ESC: Tro Lai Trang Truoc",
		"Phim Len|Xuong: Chon Du Lieu",
		"Phim Trai|Phai: Xem Trang Cu|Moi",
		" ",
		"* Chinh Sua Sinh Vien",
		"   F1->Len|Xuong->F2",
		"* Xoa Sinh Vien",
		"   F1->Len|Xuong->Del->Trai|Phai"
	};

	setColorText(ColorCode_DarkWhite);
	textbk(ColorCode_DarkBlue);
	int posX = getCenterX(getWidth(), 33);
	for (int i = 0; i < 11; i++)
	{
		gotoXY(getPosX() + posX, getPosY() + 2 + i);
		cout << note[i];
	}
	textbk(ColorCode_Back);
}

void PopupTutorial::open()
{
	setTitle("Ban co muon xoa du lieu nay khong?");
	content();
	createButtonEnter();
}

void PopupTutorial::handle()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			return;
		}
		Sleep(150);
	}
}

void PopupTutorial::setMenu(int move)
{
	this->moveMenu = move;
}

int PopupTutorial::getMenu()
{
	return this->moveMenu;
}

void PopupTutorial::createButtonEnter()
{
	int posX = getCenterX(getWidth(), 10);
	textbk(ColorCode_DarkBlue);
	box(getPosX() + posX, getPosY() + getHeight() - 4, 10, 2);
	gotoXY(getPosX() + posX + 3, getPosY() + getHeight() - 3);
	cout << "Enter";
}

void PopupTutorial::close()
{
	textbk(ColorCode_Back);
	clean();
}