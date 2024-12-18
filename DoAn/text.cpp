#include "Text.h"

Text::Text()
{
}

Text::~Text()
{
}

void Text::setPosition(int posX, int posY)
{
	this->x = posX;
	this->y = posY;
}

void Text::updatePositionX(int posX)
{
	this->x += posX;
}

void Text::updatePositionY(int posY)
{
	this->y += posY;
}

int Text::getLenString()
{
	return content.length();
}

void Text::setColor(int color)
{
	this->color = color;
}

void Text::setContent(string newContent)
{ 
	content = newContent;
}

void Text::display()
{
	gotoXY(x,y);
	setColorText(color);
	cout << content;
	setColorText(ColorCode_White);
}

void Text::clean()
{
	string blankFill;
	blankFill.resize(content.length(), ' ');
	for (int i = 0; i < 1; i++)
	{
		gotoXY(x, y);
		cout << blankFill;
	}
}