#pragma once
#include "configApp.h"

#include "ManageClass.h"
#include "ManageStudent.h"
#include "Content.h"

#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "PopupNotification.h"
#include "PopupComfirm.h"
#include "PopupTutorial.h"
#include "ToastMessage.h"
#include "InputField.h"
#include "Text.h"

#include <conio.h>
#include <string>
#include <iostream>
using namespace std;

class ContentStudent : public Content
{
private:
	enum StateDetailClassroom
	{
		C_SELECT	= 0, // F1
		C_CREATE	= 1, // Ins
		C_EDIT		= 2, // F2
		C_SEARCH	= 3, // F3
		C_DELETE	= 4, // Del
		C_DETAIL	= 5,

		C_EXIT		= -1
	};
	StateDetailClassroom currentDetailClassroom;

	enum SelectInput
	{
		FORM_CODE		= 0,
		FORM_LAST		= 1,
		FORM_FIRST		= 2,
		FORM_SEX		= 3,
		FORM_PASSWORD	= 4,
		FORM_ENTER		= 5,
		FORM_EXIT		= -1
	};
	SelectInput stateInput;

	enum SearchInput
	{
		SEARCH_INPUT = 0,
		SEARCH_F1 = 1,
		SEARCH_EXIT = 2
	};
	SearchInput stateSearchInput;

	vector<InputField> listInput;
	vector<Text> listText;
	Text text;

	int posYMessage = 0;
	string classCode;
	string studentCode;
	int pageNumber = 1;
	int hover = 0;
	string textSearch = "";

public:
	void displayContent() override;
	void content();
	void drawClassroom();
	void girdContent();
	void handle();
	void selectData();
	void createData();
	void deleteData();
	void editData();
	void findData();
	void showTutorial();
	void showTitleStudent();
	void pagging();
	void loadData();
	void cleanInput();
	void setClassCode(string classCode);
	ContentStudent();
	~ContentStudent();
};