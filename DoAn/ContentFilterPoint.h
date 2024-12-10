#pragma once
#include "configApp.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "ManageSubject.h"
#include "ManageClass.h"
#include "ManageStudent.h"

#include "ContentPrintPoint.h"
#include "Singleton.h"
#include "InputField.h"
#include "Content.h"
#include <conio.h>
#include <iostream>
using namespace std;

class ContentFilterPoint : public Content
{
private:
	InputField inputClassroomCode;
	InputField inputSubjectCode;

	InputField listInput[2] = {
		inputClassroomCode,
		inputSubjectCode
	};
	//classroom
	ManageClass nl;
	string classCode;
	int pageNumber = 1;
	int hover = 0;
	string textSearch = "";

	//Subject
	ManageSubject subject;
	string textSearchSubject = "";
	int pageNumberSubject = 1;
	int hoverSubject = -1;
	int lastHoverSubject = -1;
	int indexTree = 0;

	int width = 55;
	int posXMessage = 0;
	int moveMenu = 0;

public:
	void displayContent() override;
	void content();
	void drawContent();
	void girdTitle();
	void handle();

	
	void selectClassroom();
	void findDataClassroom();
	void paggingClassroom();
	void loadDataClassroom();


	void selectSubject();
	void findDataSubject();
	void paggingSubject();
	void loadDataSubject();


	void loadDataTree(PTRSUBJECT root);
	ContentFilterPoint();
	~ContentFilterPoint();
};