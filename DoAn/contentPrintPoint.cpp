#include "ContentPrintPoint.h"

ContentPrintPoint::ContentPrintPoint()
{
	int checkInput = manangeScore.setInputPrintScore("C001", "VL");
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
		selectData();
		_getch();

		/*if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			return;
		}*/
	}
}

void ContentPrintPoint::selectData()
{
	ScorePage page = manangeScore.searchStudentScore(textSearch, pageNumber);
	int noScoreThisPage = page.endIndex - page.startIndex;
	int n = noScoreThisPage;

	for (int i = 0; i < n; i++) {
		scoreToPrint* p = page.printList.array[i];
		int maStudent = getCenterX(24, strlen(p->studentCode));
		gotoXY(DISTANCE_SIDEBAR + MARGIN + maStudent, DISTANCE_HEADER + MARGIN + PADDING + PADDING + (2 * i));
		cout << p->studentCode;

		int lastName = getCenterX(24, strlen(p->lastName));
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 24 + lastName, DISTANCE_HEADER + MARGIN + PADDING + PADDING + (2 * i));
		cout << p->lastName;

		int firstName = getCenterX(24, strlen(p->firstName));
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 24 + 24 + firstName, DISTANCE_HEADER + MARGIN + PADDING + PADDING + (2 * i));
		cout << p->firstName;

		int sex = getCenterX(24, 3);
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 24 + 24 + 24 + sex, DISTANCE_HEADER + MARGIN + PADDING + PADDING + (2 * i));
		string gender = "Nam";
		if (p->gender == 'F')
		{
			gender = "Nu";
		}
		cout << sex;

		int point = getCenterX(24, 8);
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 24 + 24 + 24 + 24 + point, DISTANCE_HEADER + MARGIN + PADDING + PADDING + (2 * i));
		
		if (p->score == -1)
		{
			cout << "Chua Thi";
		}
		else {
			cout << "  " << p->score;
		}
	}
	pagging();
}

void ContentPrintPoint::pagging()
{
	ScorePage page = manangeScore.searchStudentScore(textSearch, pageNumber);
	string blankFillText;
	blankFillText.resize(10, ' ');

	int currentPage = 0;
	if (page.totalScore > 0)
	{
		currentPage = pageNumber;
	}

	setColorText(ColorCode_DarkWhite);
	string pageTitle = "Trang " + to_string(currentPage) + '/' + to_string(page.totalPage);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - 8, 10 + 28 + 5);
	cout << pageTitle;
}