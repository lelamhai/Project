#pragma once
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
		C_SEARCH = 0,
		C_CREATE = 1,
		C_EDIT = 2,
		C_DELETE = 3
	};
	StateClassroom currentClassroom = C_EDIT;


public:
	void displayContent() override;
	void content();
	void drawClassroom();
	void girdContent();
	void loadData();
	ContentClassroom();
	~ContentClassroom();
};