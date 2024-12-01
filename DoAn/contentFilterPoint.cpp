#include "ContentFilterPoint.h"
ContentFilterPoint::ContentFilterPoint()
{
}

ContentFilterPoint::~ContentFilterPoint()
{
}

void ContentFilterPoint::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	content();
}

void ContentFilterPoint::drawContent()
{
	int width = 50;
	// Column Classroom
	gotoXY(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING + PADDING);
	cout << "Tim";
	box(DISTANCE_SIDEBAR + MARGIN + 4, DISTANCE_HEADER + PADDING, WIDTH_INPUT, HEIGHT_INPUT);


	// Column Subject
}
void ContentFilterPoint::girdTitle()
{

}

void ContentFilterPoint::content()
{
	drawContent();
	girdTitle();
	//currentClassroom = C_SELECT;
	handle();
}

void ContentFilterPoint::handle()
{

}