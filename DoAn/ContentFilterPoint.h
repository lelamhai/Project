#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "configApp.h"
#include "Content.h"
#include <conio.h>
#include <iostream>
using namespace std;

class ContentFilterPoint : public Content
{
private:

public:
	void displayContent() override;
	void content();
	void drawContent();
	void girdTitle();
	void handle();
	ContentFilterPoint();
	~ContentFilterPoint();
};