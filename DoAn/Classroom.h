#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "PopupDelete.h"
#include "InputField.h"
#include "Text.h"

#include "Content.h"
#include <conio.h>
#include <string>
#include <iostream>
using namespace std;



class Classroom : public Content
{
public:
	void displayContent() override;
	void content();
	void drawClassroom();
	void girdContent();
	void loadData();
	Classroom();
	~Classroom();

private:

};