#include "ContentStudent.h"

ContentStudent::ContentStudent()
{
}

ContentStudent::~ContentStudent()
{
}

void ContentStudent::drawContent()
{
	// Search
	gotoXY(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING + PADDING);
	cout << "Tim";
	box(DISTANCE_SIDEBAR + MARGIN + 4, DISTANCE_HEADER + PADDING, 20, 2);

	// Gird Data
	box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING * 4, COLUMN_CENTER, ROW_CENTER);

	// Tutorial
	int posXT = getCenterX(COLUMN_RIGHT, 9);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + posXT, DISTANCE_HEADER + PADDING * 2);
	cout << "Huong Dan";

	string note[] = {
		"F1: Chon Du Lieu Trong Bang",
		"F3: Tim Kiem Lop",
		"Phim Len|Xuong: Chon Du Lieu",
		"Phim Trai|Phai: Xem Trang Sau|Truoc"
	};

	int y = DISTANCE_HEADER + PADDING + 4;
	for (int i = 0; i < 4; i++)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING *2, y + (i * 2));
		cout << note[i];
	}

	setColorText(ColorCode_DarkYellow);
	lineX(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING + 2, COLUMN_RIGHT);

	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING, COLUMN_RIGHT, 12);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + 3);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, DISTANCE_HEADER + 3);
	cout << char(180);
	setColorText(ColorCode_DarkWhite);
}

void ContentStudent::girdTitle()
{
	lineX(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + MARGIN, COLUMN_CENTER);
	gotoXY(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + MARGIN);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER, DISTANCE_HEADER + MARGIN);
	cout << char(180);

	string title[] = {
		"MSSV",
		"Ho Va Ten",
		"Phai",
		"Ma Lop",
		"Ten Lop",
		"Mon Hoc",
		"Diem"
	};

	int mssvX = getCenterX(17, title[0].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + mssvX, DISTANCE_HEADER + MARGIN - 1);
	cout << title[0];

	int fullnameX = getCenterX(17, title[1].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 17 + fullnameX, DISTANCE_HEADER + MARGIN - 1);
	cout << title[1];

	int sexX = getCenterX(17, title[2].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 17 + 17 + sexX, DISTANCE_HEADER + MARGIN - 1);
	cout << title[2];

	int codeX = getCenterX(17, title[3].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 17 + 17 + 17 + codeX, DISTANCE_HEADER + MARGIN - 1);
	cout << title[3];

	int classX = getCenterX(17, title[4].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 17 + 17 + 17 + 17 + classX, DISTANCE_HEADER + MARGIN - 1);
	cout << title[4];

	int subjectX = getCenterX(17, title[5].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 17 + 17 + 17 + 17 + 17 + subjectX, DISTANCE_HEADER + MARGIN - 1);
	cout << title[5];

	int pointX = getCenterX(17, title[6].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 17 + 17 + 17 + 17 + 17 + 17 + pointX, DISTANCE_HEADER + MARGIN - 1);
	cout << title[6];
}

void ContentStudent::displayContent()
{
	drawContent();
	girdTitle();
	handle();
}

void ContentStudent::handle()
{

	setColorText(ColorCode_DarkWhite);
	/*gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER, DISTANCE_HEADER);
	cout << "Student";*/
	while (true)
	{
		if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			return;
		}
		Sleep(150);
	}
}