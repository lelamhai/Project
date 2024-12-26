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

	int y = DISTANCE_HEADER + PADDING + 4;
	for (int i = 0; i < 2; i++)
	{
		listInput.push_back(InputField());
		listValidation.push_back(Text());

		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 3, y + (i * 4));
		cout << titleInput[i];

		listInput[i].setMinLen(LENGTH_MIN);
		listInput[i].setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING + 13, y + (i * 4) - 1);
		listInput[i].drawBox();

		listValidation[i].setColor(ColorCode_DarkYellow);
		listValidation[i].setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, y + (i * 4) + 2);
	}

	lineX(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING + 2, COLUMN_RIGHT);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING, COLUMN_RIGHT, 15);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + 3);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, DISTANCE_HEADER + 3);
	cout << char(180);

	y = y + (2 * 3);
	posYMessage = y + 1;
	text.setColor(ColorCode_DarkRed);
	text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, posYMessage);
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
		"F2: Chon Bang Mon Hoc",
		"F3: Tim Theo Lop",
		"F4: Tim Theo Mon Hoc",
		"Ins: Nhap Du Lieu Loc",
		"Enter: Bam 2 Lan Xem Bang Diem",
		"Phim Len|Xuong: Chon Du Lieu",
		"Phim Trai|Phai: Xem Trang Sau|Truoc",
		"",
		"* Xem Bang Diem",
		"(Phai Co: Ma Lop Va Ma Mon Hoc)",
		"- F1: Chon Ma Lop, F2: Chon Ma Mon",
		"- Enter: Xem Bang Diem"
	};

	int contentY = tutorialY + 1;
	for (int i = 0; i < 13; i++)
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

	int maSubject = getCenterX(20, titleSubject[0].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN +PADDING + 10 + width + maSubject, DISTANCE_HEADER + MARGIN - 1);
	cout << titleSubject[0];

	int nameSubject = getCenterX(35, titleSubject[1].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + width + 20 + nameSubject, DISTANCE_HEADER + MARGIN - 1);
	cout << titleSubject[1];
}

void ContentFilterPoint::content()
{
	drawContent();
	girdTitle();
	loadDataClassroom();
	loadDataSubject();
	currentFilter = C_SELECTCLASSROOM;
	handle();
}

void ContentFilterPoint::handle()
{
	while (true)
	{
		if (currentFilter == C_DETAIL)
		{
			cleanContent();
			ContentPrintPoint* pp = new ContentPrintPoint();
			pp->init(listInput[0].getText(), listInput[1].getText());
			pp->displayContent();
			delete pp;
			cleanContent();
			cleanContent();
			drawContent();
			girdTitle();
			currentFilter = C_EXIT;
			Singleton::getInstance()->moveMenu = 0;
		}

		switch (currentFilter)
		{
		case ContentFilterPoint::C_SELECTCLASSROOM:
			showCur(0);
			hover = 0;
			selectClassroom();
			break;

		case ContentFilterPoint::C_SELECTSUBJECT:
			hoverSubject = 0;
			lastHoverSubject = -1;
			showCur(0);
			selectSubject();
			break;

		case ContentFilterPoint::C_SEARCHCLASSROOM:
			showCur(1);
			findDataClassroom();
			break;

		case ContentFilterPoint::C_SEARCHSUBJECT:
			showCur(1);
			findDataSubject();
			break;

		case ContentFilterPoint::C_CREATE:
			showCur(1);
			createData();
			break;

		case ContentFilterPoint::C_DETAIL:
			showCur(0);


		case ContentFilterPoint::C_EXIT:
			return;

		default:
			break;
		}
	}
}

void ContentFilterPoint::createData()
{
	stateInput = FORM_CLASSROOM;
	while (true)
	{
		if (stateInput == FORM_CLASSROOM)
		{
			listValidation[0].setContent(NOTIFICATION_EMPTY);
			int textPosX = getCenterX(COLUMN_RIGHT, listValidation[0].getLenString());
			listValidation[0].updatePositionX(textPosX);
			listValidation[0].display();

			listInput[0].notUseSpace = true;
			listInput[0].handleInput();

			listValidation[0].clean();
			listValidation[0].updatePositionX(-textPosX);
			switch (listInput[0].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_SUBJECT;
				break;

			case F1:
				currentFilter = C_SELECTCLASSROOM;
				return;

			case F2:
				currentFilter = C_SELECTSUBJECT;
				return;

			case F3:
				currentFilter = C_SEARCHCLASSROOM;
				return;

			case F4:
				currentFilter = C_SEARCHSUBJECT;
				return;

			case DOWN:
				stateInput = FORM_SUBJECT;
				break;

			case UP:
				stateInput = FORM_SUBJECT;
				break;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentFilter = C_EXIT;
					return;
				}
				break;
			default:
				break;
			}
		}

		if (stateInput == FORM_SUBJECT)
		{
			listValidation[1].setContent(NOTIFICATION_EMPTY);
			int textPosX = getCenterX(COLUMN_RIGHT, listValidation[1].getLenString());
			listValidation[1].updatePositionX(textPosX);
			listValidation[1].display();

			listInput[1].notUseSpace = true;
			listInput[1].handleInput();

			listValidation[1].clean();
			listValidation[1].updatePositionX(-textPosX);

			switch (listInput[1].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_CLASSROOM;
				break;

			case F1:
				currentFilter = C_SELECTCLASSROOM;
				return;

			case F2:
				currentFilter = C_SELECTSUBJECT;
				return;

			case F3:
				currentFilter = C_SEARCHCLASSROOM;
				return;

			case F4:
				currentFilter = C_SEARCHSUBJECT;
				return;

			case DOWN:
				stateInput = FORM_CLASSROOM;
				break;

			case UP:
				stateInput = FORM_CLASSROOM;
				break;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentFilter = C_EXIT;
					return;
				}
				break;
			default:
				break;
			}
		}

		if (stateInput == FORM_ENTER)
		{
			if (text.getLenString() != 0)
			{
				text.clean();
				text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, posYMessage);
				text.setContent("");
			}

			bool isClassExist = nl.isClassExist(listInput[0].getText().c_str());
			if (!isClassExist)
			{
				text.setContent(CLASSROOM_CODE);
				int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
				text.updatePositionX(textPosX);
				text.display();

				stateInput = FORM_CLASSROOM;
				continue;
			}

			if (text.getLenString() != 0)
			{
				text.clean();
				text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, posYMessage);
				text.setContent("");
			}
			bool isSubjectExist = subject.isSubjectExist(listInput[1].getText().c_str());
			if (!isSubjectExist)
			{
				text.setContent(SUBJECT_CODE);
				int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
				text.updatePositionX(textPosX);

				text.display();
				stateInput = FORM_SUBJECT;
				continue;
			}
			currentFilter = C_DETAIL;
			return;
		}

		if (stateInput == FORM_EXIT)
		{
			return;
		}
	}
}

void ContentFilterPoint::selectClassroom()
{
	listInput[0].clean();
	listInput[0].setText("");

	ClassPage page;

	page = nl.searchClass(textSearch, pageNumber);

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
		if (GetAsyncKeyState(VK_TAB))
		{
			if (Singleton::getInstance()->moveMenu != 0)
			{
				currentFilter = C_EXIT;
				return;
			}
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
				clean(0);
				pageNumber--;
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

		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			if (pageNumber < page.totalPage)
			{
				clean(0);
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

		if (GetAsyncKeyState(VK_INSERT) & 0x0001)
		{
			currentFilter = C_CREATE;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_F2) & 0x0001)
		{
			currentFilter = C_SELECTSUBJECT;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_F3) & 0x0001)
		{
			currentFilter = C_SEARCHCLASSROOM;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_F4) & 0x0001)
		{
			currentFilter = C_SEARCHSUBJECT;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		{
			if (isLoadFirst)
			{
				isLoadFirst = false;
				continue;
			}
			
			if (listInput[1].getText() != "")
			{
				currentFilter = C_DETAIL;
				return;
			}
		}

		if (lastHover != hover)
		{
			page = nl.searchClass(textSearch, pageNumber);

			for (int i = 0; i < page.classList.countClass; i++)
			{
				setColorText(ColorCode_DarkWhite);
				if (hover == i)
				{
					listInput[0].setText(page.classList.classes[i]->classCode);
					listInput[0].display();
					setColorText(ColorCode_DarkGreen);
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
	listInput[1].clean();
	listInput[1].setText("");

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
		if (GetAsyncKeyState(VK_TAB))
		{
			if (Singleton::getInstance()->moveMenu != 0)
			{
				currentFilter = C_EXIT;
				return;
			}
		}

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
				clean(width + 10);
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
				clean(width + 10);
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

		if (GetAsyncKeyState(VK_INSERT) & 0x0001)
		{
			currentFilter = C_CREATE;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_F1) & 0x0001)
		{
			currentFilter = C_SELECTCLASSROOM;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_F3) & 0x0001)
		{
			currentFilter = C_SEARCHCLASSROOM;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_F4) & 0x0001)
		{
			currentFilter = C_SEARCHSUBJECT;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		{
			if (listInput[0].getText() != "")
			{
				currentFilter = C_DETAIL;
				return;
			}
		}

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
	page = nl.searchClass(textSearch, pageNumber);
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
	int cursorPosition = textSearch.length();
	stateSearchInput = SEARCH_INPUT;
	while (true)
	{
		if (stateSearchInput == SEARCH_INPUT)
		{
			gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + width - WIDTH_INPUT + textSearch.length(), 10);
			if (GetAsyncKeyState(VK_INSERT) & 0x0001)
			{
				currentFilter = C_CREATE;
				Sleep(150);
				return;
			}

			if (GetAsyncKeyState(VK_F1) & 0x0001)
			{
				currentFilter = C_SELECTCLASSROOM;
				Sleep(150);
				return;
			}

			if (GetAsyncKeyState(VK_F2) & 0x0001)
			{
				currentFilter = C_SELECTSUBJECT;
				Sleep(150);
				return;
			}
			
			if (GetAsyncKeyState(VK_F4) & 0x0001)
			{
				currentFilter = C_SEARCHSUBJECT;
				Sleep(150);
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
				clean(0);
				loadDataClassroom();
				paggingClassroom();
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
					clean(0);
					loadDataClassroom();
					paggingClassroom();
				}
				break;
			}
		}
	}
}

void ContentFilterPoint::findDataSubject()
{
	SubjectPage a;
	int cursorPosition = textSearch.length();
	stateSearchInput = SEARCH_INPUT;
	while (true)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + PADDING - WIDTH_INPUT + textSearch.length(), DISTANCE_HEADER + 2);
		if (GetAsyncKeyState(VK_INSERT) & 0x0001)
		{
			currentFilter = C_CREATE;
			return;
		}
		
		if (GetAsyncKeyState(VK_F1) & 0x0001)
		{
			currentFilter = C_SELECTCLASSROOM;
			return;
		}

		if (GetAsyncKeyState(VK_F2) & 0x0001)
		{
			currentFilter = C_SELECTSUBJECT;
			return;
		}

		if (GetAsyncKeyState(VK_F3) & 0x0001)
		{
			currentFilter = C_SEARCHCLASSROOM;
			Sleep(150);
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
			indexTree = 0;
			clean(width + 10);
			a = subject.searchSubjects(textSearch, pageNumber);
			loadDataTree(a.subjects);
			paggingSubject();
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

				indexTree = 0;
				clean(width + 10);
				a = subject.searchSubjects(textSearch, pageNumber);
				loadDataTree(a.subjects);
				paggingSubject();
			}
			break;
		}
	}
}

void ContentFilterPoint::loadDataTree(PTRSUBJECT root)
{
	if (!root) return;
	loadDataTree(root->left);

	setColorText(ColorCode_White);
	if (hoverSubject == indexTree)
	{
		listInput[1].setText(root->info.subjectCode);
		listInput[1].display();
		setColorText(ColorCode_DarkGreen);
	}
	int codeX = getCenterX(20, strlen(root->info.subjectCode));
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + width + 10 + codeX, DISTANCE_HEADER + 8 + (indexTree * 2));
	cout << root->info.subjectCode;

	int nameX = getCenterX(35, root->info.subjectName.length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + width + 20 + 10 + nameX, DISTANCE_HEADER + 8 + (indexTree * 2));
	cout << root->info.subjectName;

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

void ContentFilterPoint::clean(int x)
{
	int posX = DISTANCE_SIDEBAR + 7 + x;
	int posY = DISTANCE_HEADER + 7;

	string blankFill;
	blankFill.resize(width - 1, ' ');
	for (int i = 0; i < 27; i++)
	{
		gotoXY(posX, posY + i);
		cout << blankFill;
	}
}