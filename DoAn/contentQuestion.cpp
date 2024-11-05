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
}