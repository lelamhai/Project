#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include "Content.h"
#include <conio.h>
#include <iostream>
using namespace std;

class ContentSubject : public Content
{
public:
	void displayContent() override;
	ContentSubject();
	~ContentSubject();

private:

};
