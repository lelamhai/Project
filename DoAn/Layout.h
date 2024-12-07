#pragma once
#include "Singleton.h"
#include "header.h"
#include "sidebar.h"
#include "footer.h"

#include "ContentAbout.h"
#include "ContentClassroom.h"
#include "ContentStudent.h"
#include "ContentSubject.h"
#include "ContentQuestion.h"
#include "ContentExam.h"
#include "ContentFilterPoint.h"
#include "ContentPrintPoint.h"
#include "ContentExecute.h"

#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include <thread>
#include <conio.h>
#include <vector>
#include <iostream>
using namespace std;

enum StateContent
{
    ABOUT       = 0,
    CLASSROOM   = 1,
    SUBJECT     = 2,
    EXAM        = 3,
    FILTERPOINT = 4,

    EXIT        = -1
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
        TutorialMenu();
    }
    virtual void layoutFooter()
    {
        Footer();
    }
    static int choice;
    
    HANDLE hThread;
public:
    void setRunContent(int choice);
	void main();
    void templateMenu();
    static DWORD WINAPI templateContent(LPVOID lpParam);

	Layout();
	~Layout();
};