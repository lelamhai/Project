#pragma once
#include "ManageClass.h"
#include "ManageStudent.h"
#include "Content.h"

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
		C_CREATE	= 1, // F2
		C_EDIT		= 2,
		C_SEARCH	= 3,
		C_DELETE	= 4
	};
	StateClassroom currentClassroom;

	enum SelectInput
	{
		FORM_CODE = 0,
		FORM_NAME = 1,
		FORM_ENTER = 2
	};
	SelectInput stateInput;
	string classCode;

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
	void loadData();
	void cleanTable();
	void cleanInput();
	ContentClassroom();
	~ContentClassroom();
};