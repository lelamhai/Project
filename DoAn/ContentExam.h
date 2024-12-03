#pragma once
#include "configApp.h"
#include "ManageExam.h"

#include "InputField.h"
#include "Content.h"
#include "ContentExecute.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
class ContentExam : public Content
{
private:
	enum StateExam
	{
		C_SELECT	= 0, // F1
		C_CREATE	= 1, // Ins
		C_EDIT		= 2, // F2
		C_SEARCH	= 3, // F3
		C_DELETE	= 4, // Del
		C_DETAIL	= 5,

		C_EXIT		= -1
	};
	StateExam currentExam;

	enum SelectInput
	{
		FORM_CODE	= 0,
		FORM_COUNT	= 1,
		FORM_MINUTE = 2,
		FORM_ENTER	= 3,
		FORM_EXIT	= -1
	};
	SelectInput stateInput;


	InputField inputExamCode;
	InputField inputCount;
	InputField inputMinute;

	InputField listInput[3] = {
		inputExamCode,
		inputCount,
		inputMinute
	};
	int moveMenu = 0;
	int posXMessage = 0;
	string textSearch = "";
public:
	void displayContent() override;
	void drawExam();
	void girdContent();
	void content();
	void handle();
	void selectData();
	void createData();

	ContentExam();
	~ContentExam();
};

