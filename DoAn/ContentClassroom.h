#pragma once
#include "ManageClass.h"
#include "ManageStudent.h"
#include "configApp.h"
#include "Content.h"
#include "ContentDetailClassroom.h"

#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "PopupDelete.h"
#include "InputField.h"
#include "Text.h"

#include <conio.h>
#include <string>
#include <iostream>
using namespace std;

class ContentClassroom : public Content
{

private:
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

	InputField inputClassroomCode;
	InputField inputClassroomName;

	InputField listInput[2] = {
		inputClassroomCode,
		inputClassroomName
	};
	Text text;
	int moveMenu = 0;

	int posYMessage = 0;
	string classCode;
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
	void deleteData();
	void createData();
	void editData();
	void findData();
	void pagging();
	void loadData();
	void cleanInput();
	ContentClassroom();
	~ContentClassroom();
};