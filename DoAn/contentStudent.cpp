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
}