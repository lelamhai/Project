#include "Student.h"
Student::Student()
{
}

Student::~Student()
{
}

void Student:: displayContent() 
{
	setColorText(ColorCode_DarkWhite);
	gotoXY(34, 12);
	cout << "Student";
}