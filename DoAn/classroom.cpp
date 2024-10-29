#include "Classroom.h"

Classroom::Classroom()
{
}

Classroom::~Classroom()
{
}

void Classroom::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	title();
	content();
}

void Classroom::title()
{
	gotoXY(34, 10);
	cout << "Lop";
}

void Classroom::content()
{
	gotoXY(34, 13);
	cout << "Content";
}