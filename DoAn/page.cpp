#include "Page.h"
#include <conio.h>

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
	ConfigApp config;
	config.init();
	while (true)
	{
		if (currentPage == PAGE_LOADING)
		{
			showCur(0);
			clrscr();
			Loading* load = new Loading();
			load->main();
			delete load;
			currentPage = PAGE_LOGIN;
		}

		if (currentPage == PAGE_LOGIN)
		{
			showCur(0);
			clrscr();
			Login* login = new Login();
			login->main();
			delete login;
			currentPage = PAGE_LAYOUT;
		}

		if (currentPage == PAGE_LAYOUT)
		{
			showCur(0);
			clrscr();
			Layout* layout = new Layout();
			layout->setRunContent(1);
			layout->main();
			delete layout;
			currentPage = PAGE_LOGIN;
		}
			

		/*switch (currentPage)
		{
		case PAGE_LOADING:
			showCur(0);
			clrscr();
			Loading* load = new Loading();
			load->main();
			delete load;

			break;
		case PAGE_LOGIN:
			showCur(0);
			clrscr();
			Login* login = new Login();
			login->main();
			delete login;

			break;
		case PAGE_LAYOUT:
			showCur(0);
			clrscr();
			Layout* layout = new Layout();
			layout->main();
			delete layout;
			currentPage = PAGE_LOGIN;

			break;
		default:
			break;
		}*/
	}
}