#include "Page.h"

Page::Page()
{
}

Page::~Page()
{
}

void Page::setRun(StatePage page)
{
	currentPage = page;
}

void Page::main()
{
	init();
	while (true)
	{
		if (currentPage == PAGE_LOADING)
		{
			setColorText(ColorCode_DarkWhite);
			showCur(0);
			clrscr();
			Loading* load = new Loading();
			load->main();
			delete load;
			currentPage = PAGE_LOGIN;
		}

		if (currentPage == PAGE_LOGIN)
		{
			setColorText(ColorCode_DarkWhite);
			showCur(0);
			clrscr();
			Login* login = new Login();
			login->main();
			delete login;
			currentPage = PAGE_LAYOUT;
		}

		if (currentPage == PAGE_LAYOUT)
		{
			setColorText(ColorCode_DarkWhite);
			showCur(0);
			clrscr();
			Layout* layout = new Layout();
			layout->setRunContent(0);
			layout->main();
			delete layout;
			currentPage = PAGE_LOGIN;
		}
	}
}