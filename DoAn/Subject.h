#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include "Content.h"
#include <conio.h>
#include <iostream>
using namespace std;

class Subject : public Content
{
public:
	void displayContent() override;
	Subject();
	~Subject();

private:

};
