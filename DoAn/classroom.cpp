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
	InputField inputStudent;

	gotoXY(34, 13);
	cout << "Tim ";
	
	showCur(1);
	box(34 + 4, 12, 16, 2);
	gotoXY(40, 13);
	inputStudent.handleInput();

}