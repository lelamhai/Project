#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include <conio.h>
#include <iostream>
using namespace std;

class Text
{
private:
	int x = 0, y = 0;
	string content;
public:
	void setPosition(int posX, int posY);
	void display();
	void setContent(string newContent);
	int getLenString();
	Text();
	~Text();
};