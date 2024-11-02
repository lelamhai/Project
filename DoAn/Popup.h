#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include <iostream>
using namespace std;

class Popup
{
private:
	int posX=0, posY=0;
	int width = 50, height = 12;
	string title = "Title";

public:
	int getPosX();
	int getPosY();
	int getWidth();
	int getHeight();
	virtual void setPosition(int x, int y);
	virtual void setFrame(int width, int height);
	virtual void setTitle(string title);
	void content();
	
	Popup();
	~Popup();
};
