#include "PopupDelete.h"

PopupDelete::PopupDelete()
{
}

PopupDelete::~PopupDelete()
{
}

void PopupDelete::main()
{
	this->setTitle("Ban co muon xoa du lieu nay khong?");
	this->content();
	createButtonYes();
	createButtonNo();
}

void PopupDelete::createButtonYes()
{
	box(getPosX() + 50 / 2 - 10 - 5, getPosY() + getHeight() - 5, 9, 2);
	gotoXY(getPosX() + 50 / 2 - 10 - 5 + 4, getPosY() + getHeight() - 5 + 1);
	cout << "Co";
}

void PopupDelete::createButtonNo()
{
	box(getPosX() + 50 / 2 + 5, getPosY() + getHeight() - 5, 10, 2);
	gotoXY(getPosX() + 50 / 2 + 5 + 3, getPosY() + getHeight() - 5 + 1);
	cout << "Khong";
}