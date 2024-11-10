#pragma once
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
	string inputString;
	KeyState keyInput;
	int cursorPosition = 0;
public:
	string getText();
	void setText(string value);
	void handleInput();
	void display();
	KeyState getEndKey();
	InputField();
	~InputField();
};