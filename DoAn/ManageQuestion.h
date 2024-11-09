#pragma once
#include "StrucData.h"
#include <fstream>
using namespace std;
const string SOURCE_QUESTION = "QuestionData.json";


class ManageQuestion
{
private:
	PTRQUESTION questionList = nullptr;
public:
	ManageQuestion();
	~ManageQuestion();

	bool addQuestion(const string content, const string optionA, const string optionB, const string optionC, const string optionD, const char answer);

	bool editQuestion(int questionId, const string content, const string optionA, const string optionB, const string optionC, const string optionD, const char answer);

	PTRQUESTION findQuestion(int questionId);

	bool deleteQuestion(int questionId);

	void printQuestions();

	PTRSTUDENT paginateQuestions(int page = 0, int pageSize = 10);

	int getCountQuestions();

	void saveToFile();

	void loadFromFile();


	// Tạo ra 1 id ngẫu nhiên không trùng lặp
	int generateUniqueId();

	// Kiểm tra xem Id đã tồn tại chưa
	bool isUniqueId(int randomId);
	
};

int generateUniqueQuestionId(PTRQUESTION listQuestion);

int getCountQuestionInList(PTRQUESTION questionList);









