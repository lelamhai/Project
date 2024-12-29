#include "configApp.h"

void init()
{
	setSizeWindow(1920, 1080);
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

string truncateText(const string& text) {
    if (text.length() > 16) {
        return text.substr(0, 16) + "...";
    }
    return text;
}