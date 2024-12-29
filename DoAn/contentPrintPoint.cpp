#include "ContentPrintPoint.h"

ContentPrintPoint::ContentPrintPoint()
{
	
}

ContentPrintPoint::~ContentPrintPoint()
{
}
void ContentPrintPoint::init(string classCode, string subjectCode)
{
	currentSubjectCode = subjectCode;

	int checkInput = manangeScore.setInputPrintScore(classCode.c_str(), subjectCode.c_str());
	listText.push_back(Text());
	listText.push_back(Text());

	listText[0].setColor(ColorCode_DarkGreen);
	listText[0].setContent(manangeScore.getClassName());

	listText[1].setColor(ColorCode_DarkGreen);
	listText[1].setContent(manangeScore.getSubjectName());
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


	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - WIDTH_INPUT - 4, DISTANCE_HEADER + PADDING + PADDING);
	cout << "Tim";
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - WIDTH_INPUT, DISTANCE_HEADER + PADDING, WIDTH_INPUT, HEIGHT_INPUT);

	/*gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - 20, DISTANCE_HEADER + 3);
	cout << "Lop: D23      Mon: Ly";*/
	box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING + 3, COLUMN_CENTER, ROW_CENTER);



	int posXInfo = getCenterX(COLUMN_RIGHT, 9);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + posXInfo, DISTANCE_HEADER + PADDING * 2);
	cout << "Thong Tin";

	string titleInput[] = {
		"Ten Lop: ",
		"Ten Mon: "
	};

	int y = DISTANCE_HEADER + PADDING + 4;
	for (int i = 0; i < 2; i++)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 3, y + (i * 2));
		cout << titleInput[i];

		listText[i].setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 3 + 9, y + (i * 2));
		listText[i].display();
	}

	lineX(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING + 2, COLUMN_RIGHT);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING, COLUMN_RIGHT, 8);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + 3);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, DISTANCE_HEADER + 3);
	cout << char(180);


	int tutorialY = DISTANCE_HEADER + PADDING + 10;
	tutorialY += 1;

	int titleTutorial = getCenterX(COLUMN_RIGHT, 9);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + titleTutorial, tutorialY);
	cout << "Huong Dan";
	tutorialY += 1;

	string note[] = {
		"F3: Tim Kiem Sinh Vien",
		"",
		"ESC: Tro Lai",
		"",
		"Enter: Xem Lai Bai Thi",
		"",
		"Phim Len|Xuong: Chon Du Lieu",
		"",
		"Phim Trai|Phai: Xem Trang Sau|Truoc",
		"",
		"* Xem Lai Ket Qua Thi",
		"  F1->Phim Len|Xuong->Enter"

	};

	int contentY = tutorialY + 2;
	for (int i = 0; i < 10; i++)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 2, contentY + (i * 1));
		cout << note[i];
	}
	setColorText(ColorCode_DarkYellow);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, tutorialY - 2, COLUMN_RIGHT, 13);
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
	currentPrint = C_SELECT;
	handle();
}

void ContentPrintPoint::handle()
{
	while (true)
	{
		if (currentPrint == C_DETAIL)
		{
			cleanContent();
			ContentHistoryExam* h = new ContentHistoryExam();
			h->init(currentSubjectCode, currentStudent);
			h->displayContent();
			int result = h->getExitHistory();
			if (result == 1)
			{
				currentPrint = C_SELECT;
			}
			else
			{
				currentPrint = C_EXIT;
			}
			delete h;
			cleanContent();
			drawContent();
			girdTitle();
			Singleton::getInstance()->moveMenu = 0;

			lineX(0, DISTANCE_HEADER, getConsoleWidth());
			lineX(0, getConsoleHeight() - DISTANCE_HEADER, getConsoleWidth());
			gotoXY(DISTANCE_SIDEBAR, getConsoleHeight() - DISTANCE_HEADER);
			cout << char(193);
			gotoXY(DISTANCE_SIDEBAR, DISTANCE_HEADER);
			cout << char(194);
		}

		switch (currentPrint)
		{
		case ContentPrintPoint::C_SELECT:
			showCur(0);
			selectData();
			break;
		case ContentPrintPoint::C_CREATE:
			break;

		case ContentPrintPoint::C_EDIT:
			break;

		case ContentPrintPoint::C_SEARCH:
			showCur(1);
			findData();
			break;

		case ContentPrintPoint::C_DELETE:
			break;

		case ContentPrintPoint::C_DETAIL:
			break;

		case ContentPrintPoint::C_EXIT:
			return;

		default:
			break;
		}
	}
}

void ContentPrintPoint::selectData()
{
	page = manangeScore.searchStudentScore(textSearch, pageNumber);

	int start = 0;
	int end = pageNumber * page.numberScorePerPage;

	if (pageNumber * page.numberScorePerPage < page.totalScore)
	{
		end = page.numberScorePerPage - 1;
	}
	else {
		end = (page.numberScorePerPage - (end - page.totalScore)) - 1;
	}

	int lastHover = -1;
	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
		{
			currentPrint = C_EXIT;
			return;
		}

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
				end = pageNumber * page.numberScorePerPage;
				if (pageNumber * page.numberScorePerPage < page.totalScore)
				{
					end = page.numberScorePerPage - 1;
				}
				else {
					end = (page.numberScorePerPage - (end - page.totalScore)) - 1;
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

				end = pageNumber * page.numberScorePerPage;
				if (pageNumber * page.numberScorePerPage < page.totalScore)
				{
					end = page.numberScorePerPage - 1;
				}
				else {
					end = (page.numberScorePerPage - (end - page.totalScore)) - 1;
				}
				hover = 0;
				lastHover = -1;
			}
			Sleep(150);
		}

		if (GetAsyncKeyState(VK_F3) & 0x0001)
		{
			currentPrint = C_SEARCH;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_RETURN))
		{
			if (point > 0)
			{
				currentPrint = C_DETAIL;
				return;
			}
			else
			{
				int deletePosX = getCenterX(COLUMN_CENTER, 50);
				PopupNotification pNotification;
				pNotification.setEnterHandled(false);
				pNotification.setTitle("Sinh vien nay chua thi");
				pNotification.setPosition(deletePosX + 30, 17);
				pNotification.open();
				pNotification.handle();
				pNotification.close();
				lastHover = -1;
			}
			Sleep(150);
		}

		if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			if (Singleton::getInstance()->moveMenu != 0)
			{
				currentPrint = C_EXIT;
				return;
			}
		}

		if (lastHover != hover)
		{
			page = manangeScore.searchStudentScore(textSearch, pageNumber);
			int noScoreThisPage = page.endIndex - page.startIndex;
			int n = noScoreThisPage;

			for (int i = 0; i < n; i++) 
			{
				scoreToPrint* p = page.printList.array[i];
				setColorText(ColorCode_DarkWhite);
				if (hover == i)
				{
					setColorText(ColorCode_DarkGreen);
					currentStudent = p->studentCode;
					point = p->score;
				}

				
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
				string gender = "NAM";
				if (p->gender == 'F')
				{
					gender = "NU";
				}
				cout << gender;

				int point = getCenterX(24, 8);
				gotoXY(DISTANCE_SIDEBAR + MARGIN + 24 + 24 + 24 + 24 + point, DISTANCE_HEADER + MARGIN + PADDING + PADDING + (2 * i));

				if (p->score == -1)
				{
					cout << "CHUA THI";
				}
				else {
					cout << "  " << p->score;
				}
			}
			pagging();
			lastHover = hover;
		}
	}
}

void ContentPrintPoint::findData()
{
	int cursorPosition = textSearch.length();
	stateSearchInput = SEARCH_INPUT;
	while (true)
	{
		if (stateSearchInput == SEARCH_INPUT)
		{
			gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - WIDTH_INPUT + 1 + cursorPosition, DISTANCE_HEADER + PADDING + 1);

			if (GetAsyncKeyState(VK_F1) & 0x0001)
			{
				currentPrint = C_SELECT;
				Sleep(150);
				return;
			}

			if (GetAsyncKeyState(VK_TAB) & 0x8000)
			{
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentPrint = C_EXIT;
					Sleep(150);
					return;
				}
			}

			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
			{
				currentPrint = C_EXIT;
				Sleep(150);
				return;
			}

			if (GetAsyncKeyState(VK_PRIOR) & 0x8000)
			{
				currentPrint = C_SELECT;
				return;
			}

			if (GetAsyncKeyState(VK_NEXT) & 0x8000)
			{
				currentPrint = C_SELECT;
				return;
			}

			char s = _getch();
			int key = keySpecial(s);
			switch (s)
			{
			case BACKSPACE:
				if (textSearch.length() <= 0 || cursorPosition <= 0)
				{
					break;
				}

				if (cursorPosition == textSearch.length())
				{
					textSearch.erase(textSearch.length() - 1, 1);
					cursorPosition--;
					cout << "\b \b";
				}
				else {
					textSearch.erase(--cursorPosition, 1);
					gotoXY(whereX() - 1, whereY());
					for (int i = cursorPosition; i < textSearch.length(); i++)
					{
						cout << textSearch[i];
					}
					gotoXY(whereX(), whereY());
					cout << " ";
					gotoXY(whereX() - 1 - (textSearch.length() - cursorPosition), whereY());
				}
				loadData();
				pagging();
				break;

			default:
				if (textSearch.length() > 14)
				{
					break;
				}

				if (s >= 'a' && s <= 'z' || s >= 'A' && s <= 'Z' || s >= '0' && s <= '9')
				{
					if (s >= 'a' && s <= 'z')
					{
						s = s - ('a' - 'A');
					}
					textSearch.insert(textSearch.begin() + cursorPosition, s);
					cursorPosition++;
					cout << s;

					if (cursorPosition != textSearch.length())
					{
						for (int i = cursorPosition; i <= textSearch.length(); i++)
						{
							cout << textSearch[i];
						}
						gotoXY(whereX() - (textSearch.length() - cursorPosition), whereY());
					}
					loadData();
					pagging();
				}
				break;
			}
		}
	}
}

void ContentPrintPoint::loadData()
{
	cleanTable();

	page = manangeScore.searchStudentScore(textSearch, pageNumber);
	int noScoreThisPage = page.endIndex - page.startIndex;
	int n = noScoreThisPage;

	for (int i = 0; i < n; i++)
	{
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
		string gender = "NAM";
		if (p->gender == 'F')
		{
			gender = "NU";
		}
		cout << gender;

		int point = getCenterX(24, 8);
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 24 + 24 + 24 + 24 + point, DISTANCE_HEADER + MARGIN + PADDING + PADDING + (2 * i));

		if (p->score == -1)
		{
			cout << "CHUA THI";
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