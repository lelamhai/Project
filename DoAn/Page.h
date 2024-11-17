#pragma once
#include "configApp.h"
#include "Loading.h"
#include "Login.h"
#include "Layout.h"
enum StatePage
{
	PAGE_LOADING = 0,
	PAGE_LOGIN = 1,
	PAGE_LAYOUT = 2
};

class Page
{
private:
	StatePage currentPage;

public:
	void setRunPage(StatePage page);
	void main();
	Page();
	~Page();
};