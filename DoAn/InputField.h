#pragma once
#include "configApp.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include <conio.h>
#include <iostream>
using namespace std;

class InputField
{
private:
	int x, y;
	int w= WIDTH_INPUT, h = HEIGHT_INPUT;
	int len = 13;
	int moveMenu = 0;
	string inputString;
	KeyState keyInput;
	int cursorPosition = 0;
public:
	bool useHide = false;
	bool notUseSpace = false;
	bool useGender = false;
	bool notUseNum = false;

	void setLen(int length);
	void setPosition(int posX, int posY);
	void setFrame(int width, int height);
	void focus();
	void drawBox();
	string getText();
	void setText(string value);
	void handleInput();
	void display();
	KeyState getEndKey();
	void setMenu(int move);
	void clean();
	int getMenu();
	InputField();
	~InputField();
};