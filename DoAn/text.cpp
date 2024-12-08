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

void Text::setContent(string newContent)
{ 
	content = newContent;
}

void Text::display()
{
	gotoXY(x,y);
	cout << content;
}