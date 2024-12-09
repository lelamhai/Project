#include "ContentSubject.h"

ContentSubject::ContentSubject()
{
}

ContentSubject::~ContentSubject()
{
}

void ContentSubject::drawContent()
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
		"Ma Mon Hoc",
		"Ten Mon Hoc"
	};

	int y = DISTANCE_HEADER + PADDING + 5;
	for (int i = 0; i < 2; i++)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 3, y + (i * 3));
		cout << titleInput[i];
		box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 2 + 15, y + (i * 3) - 1, 20, 2);
	}

	
	lineX(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING + 2, COLUMN_RIGHT);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING, COLUMN_RIGHT, 16);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + 3);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, DISTANCE_HEADER + 3);
	cout << char(180);

	y = y + (2 * 3) - 1;
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, y);
	cout << "Message";

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
		"F1: Chon Du Lieu Trong Bang",
		"F3: Tim Kiem Mon Hoc",
		"Ins: Them Mon Hoc",
		"Phim Len|Xuong: Chon Du Lieu",
		"Phim Trai|Phai: Xem Trang Sau|Truoc",
		" ",
		"* Chinh Sua Mon Hoc",
		"   F1->Len|Xuong->F2",
		"* Xoa Mon Hoc",
		"   F1->Len|Xuong->Del->Trai|Phai",
		"* Xem Danh Sach Cau Hoi",
		"   F1->Len|Xuong->Enter"
	};

	int contentY = tutorialY + 1;
	for (int i = 0; i < 12; i++)
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

void ContentSubject::girdTitle()
{
	lineX(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + MARGIN, COLUMN_CENTER);
	gotoXY(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + MARGIN);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER, DISTANCE_HEADER + MARGIN);
	cout << char(180);

	string title[] = {
		"Ma Mon Hoc",
		"Ten Mon Hoc",
		"Cau Hoi"
	};

	int maMHX = getCenterX(40, title[0].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + maMHX, DISTANCE_HEADER + MARGIN - 1);
	cout << title[0];

	int nameX = getCenterX(40, title[1].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 40 + nameX, DISTANCE_HEADER + MARGIN - 1);
	cout << title[1];

	int countX = getCenterX(40, title[2].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 40 + 40 + countX, DISTANCE_HEADER + MARGIN - 1);
	cout << title[2];
}

void ContentSubject::displayContent()
{
	drawContent();
	girdTitle();
	handle();
}

void ContentSubject::handle()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			cleanContent();
			ContentQuestion q;
			q.displayContent();
			q.handle();
			cleanContent();
			displayContent();
		}

		if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			if (Singleton::getInstance()->moveMenu != 0)
			{
				return;
			}
		}
		selectData();

		Sleep(100);
	}
}

void ContentSubject::selectData()
{
	SubjectPage a = subject.searchSubjects(textSearch, pageNumber);
	int start = 0;

	int end = pageNumber * a.numberSubjectPerPage;
	if (pageNumber * a.numberSubjectPerPage < a.totalSubject)
	{
		end = a.numberSubjectPerPage - 1;
	}
	else {
		end = (a.numberSubjectPerPage - (end - a.totalSubject)) - 1;
	}

	while (true)
	{
		if (GetAsyncKeyState(VK_UP) & 0x0001)
		{
			if (start < hover)
			{
				hover -= 1;
			}
			else {
				hover = 0;
			}
			Sleep(150);
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x0001)
		{
			if (end > hover)
			{
				hover += 1;
			}
			else {
				hover = end;
			}
			Sleep(150);
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			if (pageNumber > 1)
			{
				cleanTable();
				hover = 0;
				pageNumber--;
				indexTree = 0;
				end = pageNumber * a.numberSubjectPerPage;
				if (pageNumber * a.numberSubjectPerPage < a.totalSubject)
				{
					end = a.numberSubjectPerPage - 1;
				}
				else {
					end = (a.numberSubjectPerPage - (end - a.totalSubject)) - 1;
				}
				lastHover = -1;
			}
			Sleep(150);
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			if (pageNumber < a.totalPage)
			{
				cleanTable();
				hover = 0;
				pageNumber++;
				indexTree = 0;
				end = pageNumber * a.numberSubjectPerPage;
				if (pageNumber * a.numberSubjectPerPage < a.totalSubject)
				{
					end = a.numberSubjectPerPage - 1;
				}
				else {
					end = (a.numberSubjectPerPage - (end - a.totalSubject)) - 1;
				}
				lastHover = -1;
			}
			Sleep(150);
		}

		if (hover != lastHover)
		{
			indexTree = 0;
			a = subject.searchSubjects(textSearch, pageNumber);
			loadDataTree(a.subjects);
			lastHover = hover;
		}
	}
}

void ContentSubject::deleteData()
{

}

void ContentSubject::createData()
{

}

void ContentSubject::editData()
{

}

void ContentSubject::findData()
{

}

void ContentSubject::loadDataTree(PTRSUBJECT root)
{
	if (!root) return;
	loadDataTree(root->left);

	setColorText(ColorCode_White);
	if (hover == indexTree)
	{
		setColorText(ColorCode_DarkGreen);
	}
	int codeX = getCenterX(40, strlen(root->info.subjectCode));
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + codeX, DISTANCE_HEADER + 8 + (indexTree * 2));
	cout << root->info.subjectCode;

	int nameX = getCenterX(40, root->info.subjectName.length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + nameX + 40, DISTANCE_HEADER + 8 + (indexTree * 2));
	cout << root->info.subjectName;

	int countX = getCenterX(40, getCountQuestionInList(root->info.listQuestion));
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + countX  + 40 + 40, DISTANCE_HEADER + 8 + (indexTree * 2));
	cout << getCountQuestionInList(root->info.listQuestion);

	setColorText(ColorCode_White);
	indexTree++;
	loadDataTree(root->right);
}