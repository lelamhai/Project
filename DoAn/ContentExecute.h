#pragma once
#include "configApp.h"
#include "ManageQuestion.h"
#include "ManageExam.h"

#include "Singleton.h"
#include "Content.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "Text.h"
#include "InputField.h"
#include "Content.h"
#include <conio.h>
#include <iostream>
using namespace std;

class ContentExecute : public Content
{
private:
	string classCode;
	int countQuestion;
	int time;
	static int timeExecute;
	vector<Text> listText;
	vector<char> listResults;
	HANDLE hThread;
	ManageExam exam;

public:
	void displayContent() override;
	void content();
	void drawContent();
	void initExecute(string classCode, int count, int time);
	void handle();
	void executeExam();
	void loadQuestion(int indexQuestion, int indexAnswer, Question* randomQuestionList);
	void displayResultQuestion(int indexQuestion, int indexAnswer);
	void loadDisplayResult();
	static DWORD WINAPI countdown(LPVOID lpParam);
	void cleanQuestion();
	ContentExecute();
	~ContentExecute();
};
