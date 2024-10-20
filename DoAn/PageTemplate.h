#pragma once
#include "Header.h"
#include "Sidebar.h"
#include "Footer.h"

#include <iostream>
using namespace std;

class PageTemplate
{
public:
    void renderPage() 
    {
        header();
        sidebar();
        content();
        footer();
    }
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
        content();
    }

    virtual void footer() 
    {
        Footer();
    }
};