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
}