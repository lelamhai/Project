#pragma once
#include "configApp.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "ManageSubject.h"

#include "ContentQuestion.h"
#include "Singleton.h"
#include "Content.h"
#include <conio.h>
#include <iostream>
using namespace std;

class ContentSubject : public Content
{
private:
	ManageSubject subject;
	int indexTree = 0;

	int pageNumber = 1;
	int hover = 0;
	int lastHover = -1;
	string textSearch = "";

public:
	void displayContent() override;
	void drawContent();
	void girdTitle();
	void handle();
	void selectData();
	void deleteData();
	void createData();
	void editData();
	void findData();
	void loadDataTree(PTRSUBJECT root);

	ContentSubject();
	~ContentSubject();
};
