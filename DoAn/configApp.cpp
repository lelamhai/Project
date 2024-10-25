#include "configApp.h"

void ConfigApp::init()
{
	setColorBT();
	setSizeWindow(1920,1080);
	blockResizeWindow();
	removeScroll();
}

ConfigApp::ConfigApp()
{
}

ConfigApp::~ConfigApp()
{
}