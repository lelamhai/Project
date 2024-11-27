#pragma once
#include "ManageClass.h"
#include "ManageStudent.h"
#include "Content.h"

#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "configApp.h"
#include "PopupTutorial.h"
#include "InputField.h"
#include "Text.h"

#include <conio.h>
#include <string>
#include <iostream>
using namespace std;

class ContentDetailClassroom : public Content
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

	InputField inputStudentCode;
	InputField inputStudentLastName;
	InputField inputStudentFirstName;
	InputField inputStudentSex;
	InputField inputStudentPassword;
	Text text;

	InputField listInput[5] = {
		inputStudentCode,
		inputStudentLastName,
		inputStudentFirstName,
		inputStudentSex,
		inputStudentPassword
	};

	int posXMessage = 0;
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
	void createData();
	void showTutorial();
	void showTitleStudent();
	void pagging();
	void loadData();
	void cleanInput();
	void setClassCode(string classCode);
	ContentDetailClassroom();
	~ContentDetailClassroom();
};