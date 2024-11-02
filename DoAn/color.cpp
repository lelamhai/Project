#include "mycolor.h"
#include "mydraw.h"

void setColorText(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void setDefualtBT()
{
	system("COLOR 0F");
}

void drawColorBg(int width, int height, int x, int y)
{
	string RED_BACKGROUND = BG_CYAN;
	string RESET_COLOR = BG_REST;

	string line = RED_BACKGROUND + string(width, ' ') + RESET_COLOR;
	for (int i = 0; i < height; i++) {
		
		gotoXY(x, y + i);
		cout << line << endl;
	}
}

void textbk(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}