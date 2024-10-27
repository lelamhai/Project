#pragma once
#include "header.h"
#include "sidebar.h"
#include "footer.h"

#include "About.h"
#include "Classroom.h"
#include "Student.h"
#include "Subject.h"
#include "Question.h"

#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include <thread>
#include <conio.h>
#include <iostream>
using namespace std;
#define WIDTH_CONTENT  170
#define HEIGHT_CONTENT  34

enum StateContent
{
    ABOUT       = 0,
    CLASSROOM   = 1,
    STUDENT     = 2,
    SUBJECT     = 3,
    QUESTION    = 4
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
    void cleanContent();
	Layout();
	~Layout();
};
