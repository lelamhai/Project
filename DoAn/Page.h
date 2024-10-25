#pragma once
#include "configApp.h"
#include "Loading.h"
#include "Login.h"
#include "TemplateContent.h"

enum StatePage
{
	LOADING			= 0,
	LOGIN			= 1,
	PAGETEMPLATE	= 2
};

class Page
{
public:
	StatePage currentPage;
	void main();
	Page();
	~Page();
};