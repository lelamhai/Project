#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "ManageSubject.h"

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


	vector<InputField> listInput;
	vector<Text> listTitle;
	int posYMessage = 0;
	Text text;

public:
	void displayContent() override;
	void init(string code);
	void drawClassroom();
	void content();
	void handle();
	ContentInputQuestion();
	~ContentInputQuestion();
};

