#include "Popup.h"

Popup::Popup()
{
}

Popup::~Popup()
{
}

int Popup::getPosX()
{
	return this->posX;
}

int Popup::getPosY()
{
	return this->posY;
}

int Popup::getWidth()
{
	return this->width;
}

int Popup::getHeight()
{
	return this->height;
}

void Popup::setPosition(int x, int y)
{
	posX = x;
	posY = y;
}

void Popup::setFrame(int width, int height)
{
	this->width = width;
	this->height = height;
}

void Popup::setTitle(string title)
{
	this->title = title;
}

void Popup::content()
{
	drawColorBg(width, height, posX, posY);

	int posX = getCenterX(getWidth(), title.length());
	gotoXY(getPosX() + posX, getPosY() + 2);
	textbk(ColorCode_DarkCyan);
	cout << title;
}

void Popup::clean()
{
	string blankFill;
	blankFill.resize(width, ' ');
	for (int i = 0; i < height; i++)
	{
		gotoXY(posX, posY + i);
		cout << blankFill;
	}
}