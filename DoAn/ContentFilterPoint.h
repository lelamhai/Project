#pragma once
#include "configApp.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "Singleton.h"
#include "InputField.h"
#include "Content.h"
#include <conio.h>
#include <iostream>
using namespace std;

class ContentFilterPoint : public Content
{
private:
	InputField inputClassroomCode;
	InputField inputSubjectCode;

	InputField listInput[2] = {
		inputClassroomCode,
		inputSubjectCode
	};
	int width = 55;
	int posXMessage = 0;
	int moveMenu = 0;

public:
	void displayContent() override;
	void content();
	void drawContent();
	void girdTitle();
	void handle();
	ContentFilterPoint();
	~ContentFilterPoint();
};