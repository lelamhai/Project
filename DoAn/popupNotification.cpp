#include "PopupNotification.h"

PopupNotification::PopupNotification()
{
}

PopupNotification::~PopupNotification()
{
}

void PopupNotification::setEnterHandled(bool flag)
{
	this->enterHandled = flag;
}

void PopupNotification::open()
{
	content();
	createButtonEnter();
}

void PopupNotification::createButtonEnter()
{
	int posX = getCenterX(getWidth(), 10);
	box(getPosX() + posX, getPosY() + getHeight() - 4, 10, 2);
	gotoXY(getPosX() + posX + 3, getPosY() + getHeight() - 3);
	cout << "Enter";
}

void PopupNotification::handle()
{
	while (true)
	{
		if (!enterHandled)
		{
			enterHandled = true;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		{
			return;
		}
		Sleep(100);
	}
}

void PopupNotification::close()
{
	textbk(ColorCode_Back);
	clean();
}