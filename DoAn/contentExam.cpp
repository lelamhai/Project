#include "ContentExam.h"

ContentExam::ContentExam()
{
}

ContentExam::~ContentExam()
{
}

void ContentExam::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	gotoXY(34, 12);
	cout << "Exam";
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