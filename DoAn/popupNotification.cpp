#include "PopupNotification.h"

PopupNotification::PopupNotification()
{
}

PopupNotification::~PopupNotification()
{
}

void PopupNotification::open()
{
	setTitle("Nop bai thi truoc khi tro lai trang truoc");
	content();
	createButtonEnter();
}

void PopupNotification::createButtonEnter()
{
	textbk(ColorCode_DarkCyan);
	int posX = getCenterX(getWidth(), 10);
	box(getPosX() + posX, getPosY() + getHeight() - 4, 10, 2);
	gotoXY(getPosX() + posX + 3, getPosY() + getHeight() - 3);
	cout << "Enter";
}

void PopupNotification::handle()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
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