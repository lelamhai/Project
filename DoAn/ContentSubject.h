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

class ContentSubject : public Content
{
public:
	void displayContent() override;
	void drawContent();
	void girdTitle();
	void handle();
	ContentSubject();
	~ContentSubject();

private:

};
