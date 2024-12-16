#pragma once
#include "configApp.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "ManageScore.h"

#include "ContentHistoryExam.h"
#include "Text.h"
#include "InputField.h"
#include "Content.h"
#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

class ContentPrintPoint : public Content
{
private:
	enum StatePrint
	{
		C_SELECT = 0, // F1
		C_CREATE = 1, // Ins
		C_EDIT = 2, // F2
		C_SEARCH = 3, // F3
		C_DELETE = 4, // Del
		C_DETAIL = 5,

		C_EXIT = -1
	};
	StatePrint currentPrint;
	ScorePage page;

	enum SearchInput
	{
		SEARCH_INPUT = 0,
		SEARCH_F1 = 1,
		SEARCH_EXIT = 2
	};
	SearchInput stateSearchInput;

	vector<Text> listText;

	ManageScore manangeScore;
	int pageNumber = 1;
	string textSearch = "";
	string currentSubjectCode;
	string currentStudent;
	int hover = 0;

public:
	void displayContent() override;
	void content();
	void drawContent();
	void girdTitle();
	void init(string subjectCode, string classCode);
	void handle();
	void selectData();
	void findData();
	void loadData();
	void pagging();

	ContentPrintPoint();
	~ContentPrintPoint();
};