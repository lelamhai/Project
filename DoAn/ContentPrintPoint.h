#pragma once
#include "configApp.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "ManageScore.h"

#include "InputField.h"
#include "Content.h"
#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

class ContentPrintPoint : public Content
{
private:
	ManageScore manangeScore;
	int pageNumber = 1;
	string textSearch = " ";

public:
	void displayContent() override;
	void content();
	void drawContent();
	void girdTitle();
	void handle();
	void selectData();
	void pagging();

	ContentPrintPoint();
	~ContentPrintPoint();
};