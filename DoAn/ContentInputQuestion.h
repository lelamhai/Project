#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "Content.h"
#include "Text.h"
#include "InputField.h"
#include <vector>

class ContentInputQuestion : public Content
{
private:
	vector<InputField> listInput;
	vector<Text> listTitle;
	int posYMessage = 0;
	Text text;

public:
	void displayContent() override;
	void drawClassroom();
	void content();
	void handle();
	ContentInputQuestion();
	~ContentInputQuestion();
};

