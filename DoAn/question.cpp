#include "Question.h"

Question::Question()
{
}

Question::~Question()
{
}

void Question::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	gotoXY(34, 12);
	cout << "Question";
}