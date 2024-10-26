#pragma once
#include "header.h"
#include "sidebar.h"
#include "footer.h"

#include "About.h"
#include "Classroom.h"
#include "Student.h"

#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include <thread>
#include <conio.h>
#include <iostream>
using namespace std;

enum StateContent
{
    ABOUT       = 0,
    CLASSROOM   = 1,
    STUDENT     = 2,
    SUBJECT     = 3,
};

class Layout
{
protected:
    virtual void layoutHeader()
    {
        Header();
    }
    virtual void layoutSidebar()
    {
        Sidebar();
    }

    virtual void layoutFooter()
    {
        Footer();
    }

public:
    int choice;
    void templateMenu();
    void templateConent();
	void main();
	Layout();
	~Layout();
};
