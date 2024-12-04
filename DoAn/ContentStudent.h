#pragma once
#include "configApp.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "Singleton.h"
#include "Content.h"
#include <conio.h>
#include <iostream>
using namespace std;

class ContentStudent : public Content
{
public:
	void displayContent() override;
	void drawContent();
	void girdTitle();
	void handle();
	ContentStudent();
	~ContentStudent();
private:

};