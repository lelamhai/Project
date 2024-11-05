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
}