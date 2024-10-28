#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include "Content.h"
#include <conio.h>
#include <iostream>
using namespace std;

class InputField
{
private:
	string inputString;
	int cursorPosition = 0;
public:
	string getText();
	void handleInput();
	InputField();
	~InputField();
};