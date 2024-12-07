#pragma once
#include "configApp.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "ContentQuestion.h"
#include "Singleton.h"
#include "Content.h"
#include <conio.h>
#include <iostream>
using namespace std;

class ContentSubject : public Content
{
private:

public:
	void displayContent() override;
	void drawContent();
	void girdTitle();
	void handle();
	ContentSubject();
	~ContentSubject();
};
