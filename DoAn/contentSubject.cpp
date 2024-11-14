#include "ContentSubject.h"

ContentSubject::ContentSubject()
{
}

ContentSubject::~ContentSubject()
{
}

void ContentSubject::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	gotoXY(34, 12);
	cout << "Subject";
	while (true)
	{
		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			Sleep(150);
			return;
		}
		Sleep(150);
	}
}