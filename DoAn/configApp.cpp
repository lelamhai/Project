#include "configApp.h"

void init()
{
	setDefualtBT();
	setSizeWindow(1920,1080);
	blockResizeWindow();
	removeScroll();
}

void cleanContent()
{
    string blankFill;
    blankFill.resize(WIDTH_CONTENT, ' ');
    for (int i = 0; i < HEIGHT_CONTENT; i++)
    {
        gotoXY(DISTANCE_SIDEBAR + PADDING, DISTANCE_HEADER + PADDING + i);
        cout << blankFill;
    }
}

void cleanTable()
{
    int posX = DISTANCE_SIDEBAR + 7;
    int posY = DISTANCE_HEADER + 7;

    string blankFill;
    blankFill.resize(COLUMN_CENTER - 1, ' ');
    for (int i = 0; i < 27; i++)
    {
        gotoXY(posX, posY + i);
        cout << blankFill;
    }
}

void cleanMessage(int y)
{
    string blankFill;
    blankFill.resize(COLUMN_RIGHT - 1, ' ');
    for (int i = 0; i < 1; i++)
    {
        gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, y);
        cout << blankFill;
    }
}