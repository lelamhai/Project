#include "Exam.h"

Exam::Exam()
{
}

Exam::~Exam()
{
}

void Exam::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	gotoXY(34, 12);
	cout << "Exam";
}