#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "ManageStudent.h"
#include "ManageClass.h"

#include "InputField.h"
#include "Text.h"

#include <conio.h>
#include <iostream>
using namespace std;

class Login
{
private:
	enum SelectLoginInput
	{
		LOGIN_USERNAME	= 0,
		LOGIN_PASSWORD	= 1,
		LOGIN_ENTER		= 2
	};
	SelectLoginInput stateLoginInput;

	vector<InputField> listInput;
	vector<Text> listText;
	Text text;

public:
	void main();
	void HeaderLogin();
	void drawPage();
	void drawForm();
	
	void formLogin();
	Login();
	~Login();
};