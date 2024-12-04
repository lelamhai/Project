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

public:
	void displayContent() override;
	void content();
	void drawContent();
	void init(string classCode, int count, int time);
	void handle();
	void cleanQuestion();
	ContentExecute();
	~ContentExecute();
};
