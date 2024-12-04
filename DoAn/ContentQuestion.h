#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "Singleton.h"
#include "Content.h"
#include "InputField.h"

#include <conio.h>
#include <iostream>
using namespace std;

class ContentQuestion : public Content
{
private:
	InputField inputContentMain;
	InputField inputContentA;
	InputField inputContentB;
	InputField inputContentC;
	InputField inputContentD;
	InputField inputAnswer;

	InputField listInput[6] = {
		inputContentMain,
		inputContentA,
		inputContentB,
		inputContentC,
		inputContentD,
		inputAnswer
	};
	int posXMessage = 0;
public:
	void displayContent() override;
	void drawClassroom();
	void girdContent();
	void content();
	void handle();
	void showTitleQuestion();

	ContentQuestion();
	~ContentQuestion();
};

