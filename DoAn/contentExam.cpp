#include "ContentExam.h"

ContentExam::ContentExam()
{
}

ContentExam::~ContentExam()
{
}

void ContentExam::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	content();
}

void ContentExam::drawExam()
{
	// Search
	gotoXY(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING + PADDING);
	cout << "Tim";
	box(DISTANCE_SIDEBAR + MARGIN + 4, DISTANCE_HEADER + PADDING, WIDTH_INPUT, HEIGHT_INPUT);

	// Gird Data
	box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING * 4, COLUMN_CENTER, ROW_CENTER);

	// Info
	int posXInfo = getCenterX(COLUMN_RIGHT, 9);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + posXInfo, DISTANCE_HEADER + PADDING * 2);
	cout << "Thong Tin";


	string titleInput[] = {
		"Ma Mon",
		"So Cau Hoi",
		"So Phut"
	};


	int y = DISTANCE_HEADER + PADDING + 5;

	for (int i = 0; i < 3; i++)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 3, y + (i * 3));
		cout << titleInput[i];


		listInput[i].setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING + 13, y + (i * 3) - 1);
		listInput[i].drawBox();
	}

	lineX(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING + 2, COLUMN_RIGHT);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING, COLUMN_RIGHT, 18);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + 3);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, DISTANCE_HEADER + 3);
	cout << char(180);

	y = y + (2 * 3) - 1;
	

	y = y + 4;
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
		"F1: Chon Du Lieu Trong Bang",
		"",
		"F3: Tim Mon",
		"",
		"Enter: Thi",
		"",
		"Phim Len|Xuong: Chon Du Lieu",
		"",
		"Phim Trai|Phai: Xem Trang Sau|Truoc"
	};

	int contentY = tutorialY + 2;
	for (int i = 0; i < 9; i++)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 2, contentY + (i * 1));
		cout << note[i];
	}
	setColorText(ColorCode_DarkYellow);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, y, COLUMN_RIGHT, 14);
	lineX(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, tutorialY, COLUMN_RIGHT);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, tutorialY);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, tutorialY);
	cout << char(180);
	setColorText(ColorCode_DarkWhite);
}

void ContentExam::girdContent()
{
	lineX(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + MARGIN, COLUMN_CENTER);
	gotoXY(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + MARGIN);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER, DISTANCE_HEADER + MARGIN);
	cout << char(180);

	string title[] = {
		"Ma Mon Hoc",
		"Ten Mon Hoc"
	};

	int maMHX = getCenterX(60, title[0].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + maMHX, DISTANCE_HEADER + MARGIN - 1);
	cout << title[0];

	int nameX = getCenterX(60, title[1].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 60 + nameX, DISTANCE_HEADER + MARGIN - 1);
	cout << title[1];
}

void ContentExam::content()
{
	drawExam();
	girdContent();
	currentExam = C_CREATE;
	handle();
}

void ContentExam::handle()
{
	while (true)
	{
		/*if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			return;
		}
		Sleep(150);*/
		switch (currentExam)
		{
		case C_SELECT:
			showCur(0);
			selectData();
			break;

		case C_CREATE:
			showCur(1);
			createData();
			//cleanInput();
			cleanMessage(posXMessage);
			break;

		case C_EDIT:
			/*showCur(1);
			editData();
			cleanInput();
			cleanMessage(posXMessage);*/
			break;

		case C_SEARCH:
			showCur(1);
			//findData();
			break;

		case C_DELETE:
			/*showCur(0);
			deleteData();*/
			break;

		case C_EXIT:
			return;

		default:
			break;
		}
	}
}

void ContentExam::selectData()
{

}

void ContentExam::createData()
{
	stateInput = FORM_CODE;
	while (true)
	{
		if (stateInput == FORM_CODE)
		{
			listInput[0].setMenu(moveMenu);
			listInput[0].handleInput();
			moveMenu = listInput[0].getMenu();
			switch (listInput[0].getEndKey())
			{
			case ENTER:
				stateInput == FORM_ENTER;
				break;

			case F1:
				break;

			case DOWN:
				break;

			case UP:
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_COUNT)
		{
			listInput[1].setMenu(moveMenu);
			listInput[1].handleInput();
			moveMenu = listInput[1].getMenu();
			switch (listInput[1].getEndKey())
			{
			case ENTER:
				stateInput == FORM_ENTER;
				break;

			case F1:
				break;

			case DOWN:
				break;

			case UP:
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_MINUTE)
		{
			listInput[2].setMenu(moveMenu);
			listInput[2].handleInput();
			moveMenu = listInput[2].getMenu();
			switch (listInput[2].getEndKey())
			{
			case ENTER:
				stateInput == FORM_ENTER;
				break;

			case F1:
				break;

			case DOWN:
				break;

			case UP:
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ENTER)
		{

		}

		if (stateInput == FORM_EXIT)
		{

		}
	}
}