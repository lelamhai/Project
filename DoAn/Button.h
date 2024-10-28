#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include "Content.h"
#include <conio.h>
#include <iostream>
using namespace std;

class Button
{
public:
	virtual void onKeyPress() = 0;
	virtual bool checkKeyPress(char key) = 0;

	Button();
	~Button();

private:

};
