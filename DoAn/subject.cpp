#include "Subject.h"

Subject::Subject()
{
}

Subject::~Subject()
{
}

void Subject::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	gotoXY(34, 12);
	cout << "Subject";
}