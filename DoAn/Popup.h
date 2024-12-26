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
	int color = ColorCode_DarkBlue;
	string title = "Ban co muon xoa du lieu nay khong?";

public:
	int getPosX();
	int getPosY();
	int getWidth();
	int getHeight();
	virtual void setColorBG(int color);
	virtual void setPosition(int x, int y);
	virtual void setFrame(int width, int height);
	virtual void setTitle(string title);
	virtual void content();
	virtual void clean();
	
	Popup();
	~Popup();
};
