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
	loadDataClassroom();
	loadDataSubject();
	handle();
}

void ContentFilterPoint::handle()
{
	_getch();
}

void ContentFilterPoint::selectClassroom()
{
	ClassPage page;

	if (textSearch != "")
	{
		page = nl.searchClass(textSearch, pageNumber);
	}
	else
	{
		page = nl.getClassPerPage(pageNumber);
	}

	int start = 0;
	int end = pageNumber * page.numberClassPerPage;

	if (pageNumber * page.numberClassPerPage < page.totalClass)
	{
		end = page.numberClassPerPage - 1;
	}
	else {
		end = (page.numberClassPerPage - (end - page.totalClass)) - 1;
	}

	int lastHover = -1;
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
				hover = 0;
				cleanTable();
				pageNumber--;
				end = pageNumber * page.numberClassPerPage;
				if (pageNumber * page.numberClassPerPage < page.totalClass)
				{
					end = page.numberClassPerPage - 1;
				}
				else {
					end = (page.numberClassPerPage - (end - page.totalClass)) - 1;
				}
				lastHover = -1;
			}
			Sleep(150);
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			if (pageNumber < page.totalPage)
			{
				cleanTable();
				pageNumber++;

				end = pageNumber * page.numberClassPerPage;
				if (pageNumber * page.numberClassPerPage < page.totalClass)
				{
					end = page.numberClassPerPage - 1;
				}
				else {
					end = (page.numberClassPerPage - (end - page.totalClass)) - 1;
				}
				hover = 0;
				lastHover = -1;
			}
			Sleep(150);
		}

		if (lastHover != hover)
		{
			if (textSearch != "")
			{
				page = nl.searchClass(textSearch, pageNumber);
			}
			else
			{
				page = nl.getClassPerPage(pageNumber);
			}

			for (int i = 0; i < page.classList.countClass; i++)
			{
				setColorText(ColorCode_DarkWhite);
				if (hover == i)
				{
					setColorText(ColorCode_DarkGreen);
					classCode = page.classList.classes[i]->classCode; // Get ClassCode for edit and delete
				}

				int classX = getCenterX(27, strlen(page.classList.classes[i]->classCode));
				gotoXY(DISTANCE_SIDEBAR + MARGIN + classX, DISTANCE_HEADER + 8 + (2 * i));
				cout << page.classList.classes[i]->classCode;

				int nameX = getCenterX(27, page.classList.classes[i]->className.length());
				gotoXY(DISTANCE_SIDEBAR + MARGIN + 27 + nameX, DISTANCE_HEADER + 8 + (2 * i));
				cout << page.classList.classes[i]->className;

				setColorText(ColorCode_DarkWhite);
			}
			lastHover = hover;
			paggingClassroom();
		}
	}
}

void ContentFilterPoint::selectSubject()
{

	SubjectPage a = subject.searchSubjects(textSearchSubject, pageNumberSubject);
	int start = 0;

	int end = pageNumberSubject * a.numberSubjectPerPage;
	if (pageNumberSubject * a.numberSubjectPerPage < a.totalSubject)
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
			if (start < hoverSubject)
			{
				hoverSubject -= 1;
			}
			else {
				hoverSubject = 0;
			}
			Sleep(150);
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x0001)
		{
			if (end > hoverSubject)
			{
				hoverSubject += 1;
			}
			else {
				hoverSubject = end;
			}
			Sleep(150);
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			if (pageNumberSubject > 1)
			{
				cleanTable();
				hoverSubject = 0;
				pageNumberSubject--;
				indexTree = 0;
				end = pageNumberSubject * a.numberSubjectPerPage;
				if (pageNumberSubject * a.numberSubjectPerPage < a.totalSubject)
				{
					end = a.numberSubjectPerPage - 1;
				}
				else {
					end = (a.numberSubjectPerPage - (end - a.totalSubject)) - 1;
				}
				lastHoverSubject = -1;
			}
			Sleep(150);
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			if (pageNumberSubject < a.totalPage)
			{
				cleanTable();
				hoverSubject = 0;
				pageNumberSubject++;
				indexTree = 0;
				end = pageNumberSubject * a.numberSubjectPerPage;
				if (pageNumberSubject * a.numberSubjectPerPage < a.totalSubject)
				{
					end = a.numberSubjectPerPage - 1;
				}
				else {
					end = (a.numberSubjectPerPage - (end - a.totalSubject)) - 1;
				}
				lastHoverSubject = -1;
			}
			Sleep(150);
		}

		/*if (GetAsyncKeyState(VK_INSERT) & 0x0001)
		{
			currentExam = C_CREATE;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_F3) & 0x0001)
		{
			currentExam = C_SEARCH;
			Sleep(150);
			return;
		}*/

		if (hoverSubject != lastHoverSubject)
		{
			indexTree = 0;
			a = subject.searchSubjects(textSearchSubject, pageNumberSubject);
			loadDataTree(a.subjects);
			paggingSubject();
			lastHoverSubject = hoverSubject;
		}
	}
}

void ContentFilterPoint::loadDataClassroom()
{
	ClassPage page;

	if (textSearch != "")
	{
		page = nl.searchClass(textSearch, pageNumber);
	}
	else
	{
		page = nl.getClassPerPage(pageNumber);
	}

	int start = 0;
	int end = pageNumber * page.numberClassPerPage;

	if (pageNumber * page.numberClassPerPage < page.totalClass)
	{
		end = page.numberClassPerPage - 1;
	}
	else {
		end = (page.numberClassPerPage - (end - page.totalClass)) - 1;
	}

	if (textSearch != "")
	{
		page = nl.searchClass(textSearch, pageNumber);
	}
	else
	{
		page = nl.getClassPerPage(pageNumber);
	}

	for (int i = 0; i < page.classList.countClass; i++)
	{
		int classX = getCenterX(27, strlen(page.classList.classes[i]->classCode));
		gotoXY(DISTANCE_SIDEBAR + MARGIN + classX, DISTANCE_HEADER + 8 + (2 * i));
		cout << page.classList.classes[i]->classCode;

		int nameX = getCenterX(27, page.classList.classes[i]->className.length());
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 27 + nameX, DISTANCE_HEADER + 8 + (2 * i));
		cout << page.classList.classes[i]->className;

		setColorText(ColorCode_DarkWhite);
	}
	paggingClassroom();
}

void ContentFilterPoint::loadDataSubject()
{
	SubjectPage a = subject.searchSubjects(textSearchSubject, pageNumberSubject);
	int start = 0;

	int end = pageNumberSubject * a.numberSubjectPerPage;
	if (pageNumberSubject * a.numberSubjectPerPage < a.totalSubject)
	{
		end = a.numberSubjectPerPage - 1;
	}
	else {
		end = (a.numberSubjectPerPage - (end - a.totalSubject)) - 1;
	}

	a = subject.searchSubjects(textSearchSubject, pageNumberSubject);
	loadDataTree(a.subjects);
	paggingSubject();
}

void ContentFilterPoint::findDataClassroom()
{

}

void ContentFilterPoint::findDataSubject()
{

}

void ContentFilterPoint::loadDataTree(PTRSUBJECT root)
{
	if (!root) return;
	loadDataTree(root->left);

	setColorText(ColorCode_White);
	if (hoverSubject == indexTree)
	{
		setColorText(ColorCode_DarkGreen);
	}
	int codeX = getCenterX(27, strlen(root->info.subjectCode));
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + width + 10 + codeX, DISTANCE_HEADER + 8 + (indexTree * 2));
	cout << root->info.subjectCode;

	int nameX = getCenterX(27, root->info.subjectName.length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + width + 27 + 10 + nameX, DISTANCE_HEADER + 8 + (indexTree * 2));
	cout << root->info.subjectName;

	/*int countX = getCenterX(40, getCountQuestionInList(root->info.listQuestion));
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + countX + 40 + 40, DISTANCE_HEADER + 8 + (indexTree * 2));
	cout << subject.countQuestionsInSubject(root->info.subjectCode);*/

	setColorText(ColorCode_White);
	indexTree++;
	loadDataTree(root->right);
}

void ContentFilterPoint::paggingSubject()
{
	SubjectPage a = subject.searchSubjects(textSearchSubject, pageNumberSubject);

	string blankFillText;
	blankFillText.resize(10, ' ');

	int currentPage = 0;
	if (a.totalSubject > 0)
	{
		currentPage = pageNumberSubject;
	}

	setColorText(ColorCode_DarkWhite);
	string pageTitle = "Trang " + to_string(currentPage) + '/' + to_string(a.totalPage);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - 8, DISTANCE_HEADER + ROW_CENTER + 5);
	cout << pageTitle;
}

void ContentFilterPoint::paggingClassroom()
{
	ClassPage page;

	if (textSearch != "")
	{
		page = nl.searchClass(textSearch, pageNumber);
	}
	else
	{
		page = nl.getClassPerPage(pageNumber);
	}


	string blankFillText;
	blankFillText.resize(10, ' ');

	int currentPage = 0;
	if (page.totalClass > 0)
	{
		currentPage = pageNumber;
	}

	setColorText(ColorCode_DarkWhite);
	string pageTitle = "Trang " + to_string(currentPage) + '/' + to_string(page.totalPage);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + width - 8, DISTANCE_HEADER + ROW_CENTER + 5);
	cout << pageTitle;
}