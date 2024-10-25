#pragma once
#include "header.h"
#include "sidebar.h"
#include "footer.h"

#include "About.h"
#include "Student.h"

#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include <conio.h>
#include <iostream>
using namespace std;

enum StateContent
{
    ABOUT       = 1,
    CLASSROOM   = 2,
    STUDENT     = 3,
    SUBJECT     = 4,
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
