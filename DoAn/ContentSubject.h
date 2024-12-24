#pragma once
#include "configApp.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "ManageSubject.h"

#include "ContentQuestion.h"
#include "PopupNotification.h"
#include "PopupQuestion.h"
#include "ToastMessage.h"
#include "InputField.h"
#include "Text.h"
#include "ContentQuestion.h"
#include "Singleton.h"
#include "Content.h"
#include <conio.h>
#include <iostream>
using namespace std;

class ContentSubject : public Content
{
private:
	bool isLoadFirst = true;

	enum StateSubject
	{
		C_SELECT = 0, // F1
		C_CREATE = 1, // Ins
		C_EDIT = 2, // F2
		C_SEARCH = 3, // F3
		C_DELETE = 4, // Del
		C_DETAIL = 5,

		C_EXIT = -1
	};
	StateSubject currentSubject;

	enum SelectInput
	{
		FORM_CODE = 0,
		FORM_NAME = 1,
		FORM_ENTER = 2,
		FORM_EXIT = 3
	};
	SelectInput stateInput;

	enum SearchInput
	{
		SEARCH_INPUT = 0,
		SEARCH_F1 = 1,
		SEARCH_EXIT = -1
	};
	SearchInput stateSearchInput;

	ManageSubject subject;
	vector<InputField> listInput;
	vector<Text> listText;
	Text text;

	int indexTree = 0;

	string subjectCode;
	int countQuestion;

	int posYMessage = 0;
	int pageNumber = 1;
	int hover = 0;
	int lastHover = -1;
	string textSearch = "";

public:
	void displayContent() override;
	void drawContent();
	void girdTitle();
	void handle();
	void selectData();
	void deleteData();
	void createData();
	void editData();
	void findData();
	void loadDataTree(PTRSUBJECT root);
	void pagging();
	void cleanInput();

	ContentSubject();
	~ContentSubject();
};
