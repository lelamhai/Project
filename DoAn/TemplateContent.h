#pragma once
#include "header.h"
#include "sidebar.h"
#include "footer.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
#include <conio.h>
#include <iostream>
using namespace std;


class TemplateContent
{
protected:
    virtual void templateHeader()
    {
        Header();
    }
    virtual void templateSidebar()
    {
        Sidebar();
    }

    /*virtual void templateContent()
    {
        cout << "content";
    }*/

    virtual void templateFooter()
    {
        Footer();
    }

public:
    void menu();
	void main();
	TemplateContent();
	~TemplateContent();
};
