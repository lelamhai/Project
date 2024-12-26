#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "ManageSubject.h"
#include "Singleton.h"

#include "PopupNotification.h"
#include "ContentInputQuestion.h"
#include "PopupComfirm.h"
#include "Content.h"
#include "Text.h"
#include "InputField.h"

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

class ContentQuestion : public Content
{
private:
	enum StateQuestion
	{
		C_SELECT	= 0, // F1
		C_CREATE	= 1, // Ins
		C_EDIT		= 2, // F2
		C_SEARCH	= 3, // F3
		C_DELETE	= 4, // Del
		C_DETAIL	= 5,

		C_EXIT		= -1
	};
	StateQuestion currentQuestion;

	enum SelectInput
	{
		FORM_ContentMain	= 0,
		FORM_ContentA		= 1,
		FORM_ContentB		= 2,
		FORM_ContentC		= 3,
		FORM_ContentD		= 4,
		FORM_ContentAnswer	= 5,
		FORM_ENTER			= 6,
		FORM_EXIT			= -1
	};
	SelectInput stateInput;

	enum SearchInput
	{
		SEARCH_INPUT = 0,
		SEARCH_F1 = 1,
		SEARCH_EXIT = 2
	};
	SearchInput stateSearchInput;



	string subjectCode;
	int id;
	ManageSubject subject;
	QuestionPage page;

	InputField inputContentMain;
	InputField inputContentA;
	InputField inputContentB;
	InputField inputContentC;
	InputField inputContentD;
	InputField inputAnswer;

	InputField listInput[6] = {
		inputContentMain,
		inputContentA,
		inputContentB,
		inputContentC,
		inputContentD,
		inputAnswer
	};
	Text text;

	int posYMessage = 0;
	int pageNumber = 1;
	int hover = 0;
	string textSearch = "";
public:
	void displayContent() override;
	void init(string subjectCode);
	void drawContent();
	void girdContent();
	void content();
	void handle();
	void selectData();
	void deleteData();
	void createData();
	void editData();
	void findData();
	void pagging();
	void loadData();
	void showTitleQuestion();

	ContentQuestion();
	~ContentQuestion();
};

