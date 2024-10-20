#pragma once
#include "Header.h"
#include "Sidebar.h"
#include "Footer.h"
#include <iostream>
using namespace std;

class PageTemplate
{
protected:
    virtual void header() 
    {
        Header();
    }
    virtual void sidebar() 
    {
        Sidebar();
    }
    
    virtual void content()
    {
        cout << "content";
    }

    virtual void footer() 
    {
        Footer();
    }
};