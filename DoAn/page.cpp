#include "Page.h"
#include <conio.h>

Page::Page()
{
}

Page::~Page()
{
}

void Page::main()
{
	ConfigApp config;
	config.init();

	showCur(0);
	clrscr();
	Loading* load = new Loading();
	load->main();
	delete load;

	showCur(0);
	clrscr();
	Login* login = new Login();
	login->main();
	delete login;

	showCur(0);
	clrscr();
	Layout* layout = new Layout();
	layout->main();
	delete layout;
}