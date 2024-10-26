#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include "Content.h"
#include <conio.h>
#include <iostream>
using namespace std;

class Student : public Content
{
public:
	void displayContent() override {
		gotoXY(0,0);
		cout << "Student";
	}
	Student();
	~Student();
private:

};
