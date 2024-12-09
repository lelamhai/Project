#include "ContentPrintPoint.h"

ContentPrintPoint::ContentPrintPoint()
{
}

ContentPrintPoint::~ContentPrintPoint()
{
}

void ContentPrintPoint::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	content();
}

void ContentPrintPoint::drawContent()
{
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + PADDING, DISTANCE_HEADER + PADDING + PADDING);
	cout << "ESC: Tro Lai";
	box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING, WIDTH_INPUT - 5, HEIGHT_INPUT);

	int titlePoint = getCenterX(COLUMN_CENTER, 9);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + titlePoint, DISTANCE_HEADER + PADDING + PADDING);
	cout << "BANG DIEM";

	/*gotoXY(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + 3);
	cout << "Lop: D23";*/

	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - 20, DISTANCE_HEADER + 3);
	cout << "Lop: D23      Mon: Ly";
	box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING + 3, COLUMN_CENTER, ROW_CENTER);

	int y = DISTANCE_HEADER + PADDING ;
	int tutorialY = y;
	tutorialY += 1;
	int titleTutorial = getCenterX(COLUMN_RIGHT, 9);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + titleTutorial, tutorialY);
	cout << "Huong Dan";
	tutorialY += 1;

	string note[] = {
		"ESC: Tro Lai",
		"",
		"Phim Len|Xuong: Chon Du Lieu",
		"",
		"Phim Trai|Phai: Xem Trang Sau|Truoc"
	};

	int contentY = tutorialY + 1;
	for (int i = 0; i < 5; i++)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 2, contentY + (i * 1));
		cout << note[i];
	}
	setColorText(ColorCode_DarkYellow);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, y, COLUMN_RIGHT, 8);
	lineX(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, tutorialY, COLUMN_RIGHT);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, tutorialY);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, tutorialY);
	cout << char(180);
	setColorText(ColorCode_DarkWhite);
}

void ContentPrintPoint::girdTitle()
{
	lineX(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + MARGIN, COLUMN_CENTER);
	gotoXY(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + MARGIN);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER, DISTANCE_HEADER + MARGIN);
	cout << char(180);

	string title[] = {
		"MSSV",
		"Ho",
		"Ten",
		"Phai",
		"Diem"
	};

	int maStudent = getCenterX(24, title[0].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + maStudent, DISTANCE_HEADER + MARGIN - 1);
	cout << title[0];

	int lastName = getCenterX(24, title[1].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 24 + lastName, DISTANCE_HEADER + MARGIN - 1);
	cout << title[1];

	int firstName = getCenterX(24, title[2].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 24 + 24 + firstName, DISTANCE_HEADER + MARGIN - 1);
	cout << title[2];

	int sex = getCenterX(24, title[3].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 24 + 24  + 24 + sex, DISTANCE_HEADER + MARGIN - 1);
	cout << title[3];

	int point = getCenterX(24, title[4].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 24 + 24 + 24 + 24 + point, DISTANCE_HEADER + MARGIN - 1);
	cout << title[4];
}

void ContentPrintPoint::content()
{
	drawContent();
	girdTitle();
	//currentClassroom = C_SELECT;
	handle();
}

void ContentPrintPoint::handle()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			return;
		}
	}
}