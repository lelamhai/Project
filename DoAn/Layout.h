#pragma once
#include "header.h"
#include "sidebar.h"
#include "footer.h"

#include "ContentAbout.h"
#include "ContentClassroom.h"
#include "ContentStudent.h"
#include "ContentSubject.h"
#include "ContentQuestion.h"
#include "ContentExam.h"

#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include <thread>
#include <conio.h>
#include <iostream>
using namespace std;
#define WIDTH_CONTENT  172
#define HEIGHT_CONTENT  36

enum StateContent
{
    ABOUT       = 0,
    CLASSROOM   = 1,
    STUDENT     = 2,
    SUBJECT     = 3,
    QUESTION    = 4,
    EXAM        = 5,
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
    bool isRun = true;
    int choice;
public:
    void setRunContent(int choice);
    void templateMenu();
    void templateContent();
	void main();
    void cleanContent();
	Layout();
	~Layout();
};
