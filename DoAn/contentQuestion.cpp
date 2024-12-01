#include "ContentQuestion.h"

ContentQuestion::ContentQuestion()
{
}

ContentQuestion::~ContentQuestion()
{
}

void ContentQuestion::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	content();
}

void ContentQuestion::drawClassroom()
{
	// Search
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + PADDING, DISTANCE_HEADER + PADDING + PADDING);
	cout << "ESC: Tro Lai";
	box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING, WIDTH_INPUT - 5, HEIGHT_INPUT);

	/*ManageClass test;
	Classroom classFound = test.findClassByCode(classCode.c_str());
	string className = classFound.className;
	int total = test.getCountSudentOfClass(classCode.c_str());

	string count = to_string(total);
	string title = "Lop:" + className + " - Sinh Vien:" + count;

	int titlePosX = getCenterX(getConsoleWidth(), title.length());
	gotoXY(titlePosX - 12, 10);
	cout << title;*/
	showTitleQuestion();

	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - WIDTH_INPUT - 4, DISTANCE_HEADER + PADDING + PADDING);
	cout << "Tim";
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - WIDTH_INPUT, DISTANCE_HEADER + PADDING, WIDTH_INPUT, HEIGHT_INPUT);

	// Gird Data
	box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING * 4, COLUMN_CENTER, ROW_CENTER);

	// Info
	int posXInfo = getCenterX(COLUMN_RIGHT, 9);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + posXInfo, DISTANCE_HEADER + PADDING * 2);
	cout << "Thong Tin";


	string titleInput[] = {
		"Noi Dung Chinh",
		"Noi Dung A",
		"Noi Dung B",
		"Noi Dung C",
		"Noi Dung D",
		"Dap An"
	};

	int posXRight = 0;
	int y = DISTANCE_HEADER + PADDING + 4;
	for (int i = 0; i <6; i++)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 3, y + (i * 3));
		cout << titleInput[i];


		listInput[i].setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING + 17, y + (i * 3) - 1);
		listInput[i].drawBox();
		posXRight = y + (i * 3);
	}

	lineX(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING + 2, COLUMN_RIGHT);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING, COLUMN_RIGHT, 26);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + 3);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, DISTANCE_HEADER + 3);
	cout << char(180);

	y = posXRight + 2;
	posXMessage = y;

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
		"F12: Xem Huong Dan Chi Tiet",
		"ESC: Tro Lai"
	};

	int contentY = tutorialY + 1;
	for (int i = 0; i < 2; i++)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 2, contentY + (i * 1));
		cout << note[i];
	}
	setColorText(ColorCode_DarkYellow);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, y, COLUMN_RIGHT,5);
	lineX(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, tutorialY, COLUMN_RIGHT);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, tutorialY);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, tutorialY);
	cout << char(180);
	setColorText(ColorCode_DarkWhite);
}

void ContentQuestion::girdContent()
{
	lineX(34 + 2, 10 + 2 + 2, 120);
	gotoXY(34 + 2, 10 + 2 + 2);
	cout << char(195);
	gotoXY(34 + 2 + 120, 10 + 2 + 2);
	cout << char(180);

	string title[] = {
		"Noi Dung Chinh",
		"Noi Dung A",
		"Noi Dung B",
		"Noi Dung C",
		"Noi Dung D",
		"Dap An"
	};

	int sizeColumn = 20;

	int classX = getCenterX(sizeColumn, title[0].length());
	gotoXY(34 + 3 + classX, 10 + 2 + 1);
	cout << title[0];

	int lastX = getCenterX(sizeColumn, title[1].length());
	gotoXY(34 + 3 + sizeColumn + lastX, 10 + 2 + 1);
	cout << title[1];

	int firstX = getCenterX(sizeColumn, title[2].length());
	gotoXY(34 + 3 + sizeColumn + sizeColumn + firstX, 10 + 2 + 1);
	cout << title[2];

	int sexX = getCenterX(sizeColumn, title[3].length());
	gotoXY(34 + 3 + sizeColumn + sizeColumn + sizeColumn + sexX, 10 + 2 + 1);
	cout << title[3];

	int passX = getCenterX(sizeColumn, title[4].length());
	gotoXY(34 + 3 + sizeColumn + sizeColumn + sizeColumn + sizeColumn + passX, 10 + 2 + 1);
	cout << title[4];

	int passAX = getCenterX(sizeColumn, title[5].length());
	gotoXY(34 + 3 + sizeColumn + sizeColumn + sizeColumn + sizeColumn + sizeColumn + passAX, 10 + 2 + 1);
	cout << title[5];
}

void ContentQuestion::content()
{
	drawClassroom();
	girdContent();
	handle();
}

void ContentQuestion::handle()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			Sleep(150);
			return;
		}
		Sleep(150);
	}
}

void ContentQuestion::showTitleQuestion()
{
	/*ManageClass test;
	Classroom classFound = test.findClassByCode(classCode.c_str());
	string className = classFound.className;
	int total = test.getCountSudentOfClass(classCode.c_str());

	string count = to_string(total);
	string title = "Lop:" + className + " - Sinh Vien:" + count;*/

	string title = "Mon: Ly - Cau Hoi: 67";
	int titlePosX = getCenterX(getConsoleWidth(), title.length());
	gotoXY(titlePosX - 12, 10);
	cout << title;
}