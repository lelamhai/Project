#pragma once
#include "StrucData.h"

class ManageQuestion
{
private:
	PTRQUESTION questionList;
public:
	ManageQuestion();
	~ManageQuestion();

	bool addQuestion(const char* studentCode, const char* firstName, const char* lastName, char gender, const char* password);

	bool editQuestion(const char* studentCode, const char* firstName, const char* lastName, char gender, const char* password);

	PTRSTUDENT findQuestion(char* studentCode);

	bool deleteQuestion(const char* studentCode);

	void printQuestions();

	PTRSTUDENT paginateQuestions(int page = 0, int pageSize = 10);

	int getCountQuestions();

	void saveToFile();

	void loadFromFile();
 
};

