#pragma once
#include "Header.h"
#include "Sidebar.h"
#include "Footer.h"
#include <iostream>
using namespace std;

class PageTemplate
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
    
    virtual void templateContent()
    {
        cout << "content";
    }

    virtual void templateFooter() 
    {
        Footer();
    }
};