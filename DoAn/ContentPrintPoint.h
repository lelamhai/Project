#pragma once
#include "configApp.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "InputField.h"
#include "Content.h"
#include <conio.h>
#include <iostream>
using namespace std;

class ContentPrintPoint : public Content
{
private:

public:
	void displayContent() override;
	void content();
	void drawContent();
	void girdTitle();
	void handle();
	ContentPrintPoint();
	~ContentPrintPoint();
};