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
	// Column Classroom
	gotoXY(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING + PADDING);
	cout << "Lop";

	gotoXY(DISTANCE_SIDEBAR + MARGIN + width - WIDTH_INPUT - 4, DISTANCE_HEADER + PADDING + PADDING);
	cout << "Tim";
	box(DISTANCE_SIDEBAR + MARGIN + width - WIDTH_INPUT, DISTANCE_HEADER + PADDING, WIDTH_INPUT, HEIGHT_INPUT);

	box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING + 3, width, ROW_CENTER);
	
	// Column Subject
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + width, DISTANCE_HEADER + PADDING + PADDING);
	cout << "Mon Hoc";

	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - WIDTH_INPUT - 4, DISTANCE_HEADER + PADDING + PADDING);
	cout << "Tim";
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - WIDTH_INPUT, DISTANCE_HEADER + PADDING, WIDTH_INPUT, HEIGHT_INPUT);


	box(DISTANCE_SIDEBAR + MARGIN + 10 + width, DISTANCE_HEADER + PADDING + 3, width, ROW_CENTER);

	// Column Right
	int posXInfo = getCenterX(COLUMN_RIGHT, 9);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + posXInfo, DISTANCE_HEADER + PADDING * 2);
	cout << "Thong Tin";

	string titleInput[] = {
		"Ma Lop",
		"Ma Mon"
	};

	int y = DISTANCE_HEADER + PADDING + 5;
	for (int i = 0; i < 2; i++)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 3, y + (i * 3));
		cout << titleInput[i];


		listInput[i].setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING + 13, y + (i * 3) - 1);
		listInput[i].drawBox();
	}

	lineX(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING + 2, COLUMN_RIGHT);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING, COLUMN_RIGHT, 16);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + 3);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, DISTANCE_HEADER + 3);
	cout << char(180);

	y = y + (2 * 3) - 1;
	posXMessage = y;
	/*gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, y);
	cout << y;*/

	y = y + 2;
	int infoX = getCenterX(COLUMN_RIGHT, 10);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + infoX, y, 10, 2);
	int enterX = getCenterX(COLUMN_RIGHT, 5);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + enterX, y + 1);
	cout << "Enter";


	y = y + 5 + 1;
	// Tutorial
	int tutorialY = y;
	tutorialY += 1;
	int titleTutorial = getCenterX(COLUMN_RIGHT, 9);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + titleTutorial, tutorialY);
	cout << "Huong Dan";
	tutorialY += 1;

	string note[] = {
		"F1: Chon Bang Lop",
		"",
		"F2: Chon Bang Mon Hoc",
		"",
		"Ins: Nhap Du Lieu Loc",
		"",
		"Phim Len|Xuong: Chon Du Lieu",
		"",
		"Phim Trai|Phai: Xem Trang Sau|Truoc"
	};

	int contentY = tutorialY + 1;
	for (int i = 0; i < 9; i++)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 2, contentY + (i * 1));
		cout << note[i];
	}
	setColorText(ColorCode_DarkYellow);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, y, COLUMN_RIGHT, 16);
	lineX(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, tutorialY, COLUMN_RIGHT);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, tutorialY);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, tutorialY);
	cout << char(180);
	setColorText(ColorCode_DarkWhite);
}
void ContentFilterPoint::girdTitle()
{
	// Classs
	lineX(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + MARGIN, width);
	gotoXY(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + MARGIN);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + width, DISTANCE_HEADER + MARGIN);
	cout << char(180);
	string titleClass[] = {
		"Ma Lop",
		"Ten Lop"
	};

	int maClass = getCenterX(27, titleClass[0].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + maClass, DISTANCE_HEADER + MARGIN - 1);
	cout << titleClass[0];

	int nameClass = getCenterX(27, titleClass[1].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 27 + nameClass, DISTANCE_HEADER + MARGIN - 1);
	cout << titleClass[1];

	// Subject
	lineX(DISTANCE_SIDEBAR + MARGIN + 10 + width, DISTANCE_HEADER + MARGIN, width);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + width, DISTANCE_HEADER + MARGIN);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER, DISTANCE_HEADER + MARGIN);
	cout << char(180);
	string titleSubject[] = {
		"Ma Mon",
		"Ten Mon"
	};

	int maSubject = getCenterX(27, titleSubject[0].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + width + maSubject, DISTANCE_HEADER + MARGIN - 1);
	cout << titleSubject[0];

	int nameSubject = getCenterX(27, titleSubject[1].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + width + 27 + nameSubject, DISTANCE_HEADER + MARGIN - 1);
	cout << titleSubject[1];
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
	while (true)
	{
		if (GetAsyncKeyState(VK_RETURN))
		{
			cleanContent();
			ContentPrintPoint p;
			p.displayContent();
			p.handle();
			cleanContent();
			content();
		}

		if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			if (Singleton::getInstance()->moveMenu != 0)
			{
				return;
			}
		}
		Sleep(100);
	}
}