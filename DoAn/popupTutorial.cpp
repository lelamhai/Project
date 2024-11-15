#include "PopupTutorial.h"

PopupTutorial::PopupTutorial()
{
}

PopupTutorial::~PopupTutorial()
{
}

void PopupTutorial::content() 
{
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
		"   F1->Len|Xuong->Del->Trai|Phai",
		"* Xem Diem Sinh Vien",
		"   F1->Len|Xuong->Enter"
	};

	int posX = getCenterX(getWidth(), 33);
	textbk(ColorCode_DarkCyan);
	for (int i = 0; i < 13; i++)
	{
		gotoXY(getPosX() + posX, getPosY() + 1 + i);
		cout << note[i];
	}
}

void PopupTutorial::open()
{
	this->setTitle("Ban co muon xoa du lieu nay khong?");
	this->content();
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
	textbk(ColorCode_DarkCyan);
	int posX = getCenterX(getWidth(), 10);
	box(getPosX() + posX, getPosY() + getHeight() - 4, 10, 2);
	gotoXY(getPosX() + posX + 3, getPosY() + getHeight() - 3);
	cout << "Enter";
}

void PopupTutorial::close()
{
	string blankFill;
	blankFill.resize(getWidth(), ' ');

	for (int i = 0; i < getHeight(); i++)
	{
		setColorText(ColorCode_Back);
		gotoXY(getPosX(), getPosY() + i);
		cout << blankFill;
	}
}