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

void Popup::setColorBG(int color)
{
	this->color = color;
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
	setColorText(color);
	drawColorBg(width, height, posX, posY);

	int posX = getCenterX(getWidth(), title.length());
	gotoXY(getPosX() + posX, getPosY() + 2);
	setColorText(ColorCode_White);
	textbk(color);
	cout << title;
}

void Popup::clean()
{
	setColorText(ColorCode_Back);
	string blankFill;
	blankFill.resize(width, char(219));
	for (int i = 0; i < height; i++)
	{
		gotoXY(posX, posY + i);
		cout << blankFill;
	}
	setColorText(ColorCode_White);
}