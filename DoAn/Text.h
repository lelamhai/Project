#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
//#include "Content.h"
#include <conio.h>
#include <iostream>
using namespace std;

class Text
{
private:
	string content;

public:
	void display();
	void setContent(string newContent);
	Text();
	~Text();
};