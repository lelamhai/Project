#include "ButtonEnter.h"

ButtonEnter::ButtonEnter()
{
}

ButtonEnter::~ButtonEnter()
{
}

void ButtonEnter::onKeyPress()
{
	cout << "da nhan enter";
}

bool ButtonEnter::checkKeyPress(char s)
{
	return s == ENTER;
}