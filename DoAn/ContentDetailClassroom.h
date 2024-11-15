#pragma once
#include "ManageClass.h"
#include "ManageStudent.h"
#include "Content.h"

#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "PopupDelete.h"
#include "InputField.h"
#include "Text.h"

#include <conio.h>
#include <string>
#include <iostream>
using namespace std;
#define WIDTH_CONTENT  172
#define HEIGHT_CONTENT  36

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
	void cleanContent();
	ContentDetailClassroom();
	~ContentDetailClassroom();
};