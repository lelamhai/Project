#pragma once
#include "ManageClass.h"
#include "ManageStudent.h"
#include "configApp.h"
#include "Content.h"
#include "ContentStudent.h"

#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"


#include "PopupQuestion.h"
#include "PopupNotification.h"
#include "ToastMessage.h"
#include "InputField.h"
#include "Text.h"

#include <conio.h>
#include <string>
#include <iostream>
using namespace std;

class ContentClassroom : public Content
{
private:
	bool isLoadFirst = true;

	enum StateClassroom
	{
		C_SELECT	= 0, // F1
		C_CREATE	= 1, // Ins
		C_EDIT		= 2, // F2
		C_SEARCH	= 3, // F3
		C_DELETE	= 4, // Del
		C_DETAIL	= 5,

		C_EXIT		= -1
	};
	StateClassroom currentClassroom;

	enum SelectInput
	{
		FORM_CODE	= 0,
		FORM_NAME	= 1,
		FORM_ENTER	= 2,
		FORM_EXIT	= 3
	};
	SelectInput stateInput;

	enum SearchInput
	{
		SEARCH_INPUT	= 0,
		SEARCH_F1		= 1,
		SEARCH_EXIT		= 2
	};
	SearchInput stateSearchInput;
	vector<InputField> listInput;
	vector<Text> listText;
	Text text;

	string classCode;
	int countClass = 0;

	int posYMessage = 0;
	int pageNumber = 1;
	int hover = 0;
	string textSearch = "";
public:
	void displayContent() override;
	void content();
	void drawContent();
	void girdTitle();
	void handle();
	void selectData();
	void deleteData();
	void createData();
	void editData();
	void findData();
	void pagging();
	void loadData();
	void cleanInput();
	bool checkInsert(string code);
	ContentClassroom();
	~ContentClassroom();
};