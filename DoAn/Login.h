#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include <conio.h>
#include <iostream>
using namespace std;

class Login
{
private:
	enum SelectInput
	{
		USERNAME	= 0,
		PASSWORD	= 1,
		CLICKENTER	= 2
	};
	SelectInput stateInput;

public:
	void main();
	void HeaderLogin();
	void drawBox();
	void drawUserName();
	void drawPassword();
	void textMessage(string mess);
	void drawButton();
	void formLogin();
	void inputUserName(string& input, int x, int y);
	void inputPassword(string& input, int x, int y);
	Login();
	~Login();
};