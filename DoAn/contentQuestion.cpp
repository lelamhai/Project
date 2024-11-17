#include "ContentQuestion.h"

ContentQuestion::ContentQuestion()
{
}

ContentQuestion::~ContentQuestion()
{
}

void ContentQuestion::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	gotoXY(34, 12);
	cout << "Question";
	while (true)
	{
		if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			Sleep(150);
			return;
		}
		Sleep(150);
	}
}