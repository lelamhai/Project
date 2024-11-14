#include "ContentStudent.h"
ContentStudent::ContentStudent()
{
}

ContentStudent::~ContentStudent()
{
}

void ContentStudent::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	gotoXY(34, 12);
	cout << "Student";
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