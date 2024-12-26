#pragma once
#include "configApp.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "ManageScore.h"

#include "Text.h"
#include "Singleton.h"
#include "Content.h"
#include <conio.h>
#include <iostream>
using namespace std;

class ContentHistoryExam : public Content
{
private:
	int stageExit;

	string subjectCode;
	string studentCode;
	int indexAnswer;
	vector<Text> listText;
	vector<char> listResults;
	resultList* rs;

	

public:
	void displayContent() override;
	void init(string subject, string student);
	void content();
	void drawContent();
	void loadQuestion(int indexQuestion, int indexAnswer, questionRecordList listQuestion);
	void loadResult();
	void handle();
	void cleanQuestion();
	int getExitHistory();
	ContentHistoryExam();
	~ContentHistoryExam();

};