#pragma once
#include "configApp.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include <conio.h>
#include <string>
#include <iostream>
using namespace std;

class InputField
{
private:
	int x, y;
	int w= WIDTH_INPUT, h = HEIGHT_INPUT;
	int maxLen = 13;
	int minLen = 0;
	string inputString;
	KeyState keyInput;
	int cursorPosition = 0;

public:
	bool useHide = false;
	bool useGender = false;
	bool useNum = false;
	bool useAnswer = false;
	bool useSpecial = false;
	bool notUseZero = false;
	bool notUseSpace = false;
	bool notKeyArrow = false;


	void setMaxLen(int length);
	void setMinLen(int length);
	void setPosition(int posX, int posY);
	void setFrame(int width, int height);
	void focus();
	void drawBox();
	string getText();
	void setText(string value);
	void handleInput();
	void display();
	KeyState getEndKey();
	void clean();
	
	InputField();
	~InputField();
};