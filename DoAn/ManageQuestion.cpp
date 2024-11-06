#include "ManageQuestion.h"

ManageQuestion::ManageQuestion()
{
}

ManageQuestion::~ManageQuestion()
{
}

bool ManageQuestion::addQuestion(const char* studentCode, const char* firstName, const char* lastName, char gender, const char* password)
{
	return false;
}

bool ManageQuestion::editQuestion(const char* studentCode, const char* firstName, const char* lastName, char gender, const char* password)
{
	return false;
}

PTRSTUDENT ManageQuestion::findQuestion(char* studentCode)
{
	return PTRSTUDENT();
}

bool ManageQuestion::deleteQuestion(const char* studentCode)
{
	return false;
}

void ManageQuestion::printQuestions()
{
}

PTRSTUDENT ManageQuestion::paginateQuestions(int page, int pageSize)
{
	return PTRSTUDENT();
}

int ManageQuestion::getCountQuestions()
{
	return 0;
}

void ManageQuestion::saveToFile()
{
}

void ManageQuestion::loadFromFile()
{
}
