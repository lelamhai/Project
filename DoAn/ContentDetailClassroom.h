#pragma once
#include "ManageClass.h"
#include "ManageStudent.h"
#include "Content.h"

#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "PopupTutorial.h"
#include "InputField.h"
#include "Text.h"

#include <conio.h>
#include <string>
#include <iostream>
using namespace std;

class ContentDetailClassroom : public Content
{
private:
	string classCode = "C002";
public:
	void displayContent() override;
	void content();
	void drawClassroom();
	void girdContent();
	void handle();
	ContentDetailClassroom();
	~ContentDetailClassroom();
};