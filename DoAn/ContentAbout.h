#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include "Singleton.h"
#include "Content.h"
#include <conio.h>
#include <iostream>
using namespace std;

class ContentAbout : public Content
{
private:
	int moveMenu = 0;

public:
	void displayContent() override;
	void title();
	void content();
	ContentAbout();
	~ContentAbout();
};