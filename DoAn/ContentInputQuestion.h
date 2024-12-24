#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "ManageSubject.h"

#include "ToastMessage.h"
#include "Content.h"
#include "Text.h"
#include "InputField.h"
#include <vector>

class ContentInputQuestion : public Content
{
private:
	enum SelectInput
	{
		FORM_ContentMain = 0,
		FORM_ContentA = 1,
		FORM_ContentB = 2,
		FORM_ContentC = 3,
		FORM_ContentD = 4,
		FORM_ContentAnswer = 5,
		FORM_ENTER = 6,
		FORM_EXIT = -1
	};
	SelectInput stateInput;

	ManageSubject subject;
	QuestionPage page;
	string subjectCode;
	int idQuestion;

	vector<InputField> listInput;
	vector<Text> listTitle;
	vector<Text> listValidation;

	int posYMessage = 0;
	Text text;

public:
	enum StateInputQuestion
	{
		C_SELECT = 0, // F1
		C_CREATE = 1, // Ins
		C_EDIT = 2, // F2
		C_SEARCH = 3, // F3
		C_DELETE = 4, // Del
		C_DETAIL = 5,

		C_EXIT = -1
	};
	StateInputQuestion currentInputQuestion;

	void displayContent() override;
	void init(string code);
	void drawContent();
	void content();
	void handle();
	void setIdQuestion(int id);
	void createData();
	void editData();
	void setStateInputQuestion(StateInputQuestion state);
	void cleanInput();
	ContentInputQuestion();
	~ContentInputQuestion();
};

