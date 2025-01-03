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
		"Ma Mon",
		"Ten Hoc"
	};

	int y = DISTANCE_HEADER + PADDING + 4;
	for (int i = 0; i < 2; i++)
	{
		listInput.push_back(InputField());
		listText.push_back(Text());

		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 3, y + (i * 4));
		cout << titleInput[i];

		listInput[i].setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING + 11, y + (i * 4) - 1);
		listInput[i].setFrame(WIDTH_INPUT + 6, HEIGHT_INPUT);
		listInput[i].drawBox();

		listText[i].setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, y + (i * 4) + 2);
	}

	listInput[0].setMinLen(LENGTH_MIN);

	listInput[1].setMaxLen(24);
	listInput[1].setMinLen(LENGTH_CODE);

	
	lineX(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING + 2, COLUMN_RIGHT);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING, COLUMN_RIGHT, 15);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + 3);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, DISTANCE_HEADER + 3);
	cout << char(180);

	y = y + (2 * 3) - 1;
	posYMessage = y + 2;
	/*gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, y);
	cout << "Message";*/

	y = y + 3;
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
		"   F1->Len|Xuong->Bam 2 Lan Enter"
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
	currentSubject = C_SELECT;
	handle();
}

void ContentSubject::handle()
{
	while (true)
	{
		if (currentSubject == C_DETAIL)
		{
			cleanContent();
			ContentQuestion* detail = new ContentQuestion();
			detail->init(subjectCode);
			detail->content();
			delete detail;
			cleanContent();
			drawContent();
			girdTitle();
			currentSubject = C_EXIT;
			Singleton::getInstance()->moveMenu = 0;
		}

		switch (currentSubject)
		{
		case ContentSubject::C_SELECT:
			showCur(0);
			selectData();
			break;
		case ContentSubject::C_CREATE:
			showCur(1);
			createData();
			cleanInput();
			break;
		case ContentSubject::C_EDIT:
			showCur(1);
			editData();
			cleanInput();
			break;
		case ContentSubject::C_SEARCH:
			showCur(1);
			findData();
			break;
		case ContentSubject::C_DELETE:
			showCur(0);
			deleteData();
			break;
		case ContentSubject::C_EXIT:
			return;
		default:
			break;
		}
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
	lastHover = -1;
	while (true)
	{
		if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			if (Singleton::getInstance()->moveMenu != 0)
			{
				currentSubject = C_EXIT;
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

		if (GetAsyncKeyState(VK_INSERT) & 0x0001)
		{
			currentSubject = C_CREATE;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_DELETE) & 0x0001)
		{
			currentSubject = C_DELETE;
			return;
		}

		if (GetAsyncKeyState(VK_F2) & 0x0001)
		{
			if (a.totalSubject <= 0)
			{
				continue;
			}

			currentSubject = C_EDIT;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_F3) & 0x0001)
		{
			currentSubject = C_SEARCH;
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

			currentSubject = C_DETAIL;
			Sleep(150);
			return;
		}

		if (hover != lastHover)
		{
			indexTree = 0;
			a = subject.searchSubjects(textSearch, pageNumber);
			loadDataTree(a.subjects);
			pagging();
			lastHover = hover;
		}
	}
}

void ContentSubject::deleteData()
{
	int deletePosX = getCenterX(COLUMN_CENTER, 50);
	if (countQuestion > 0)
	{
		PopupNotification pNotification;
		pNotification.setTitle(NOTIFICATION_NOT_DELETE);
		pNotification.setPosition(DISTANCE_SIDEBAR + MARGIN + deletePosX, 17);
		pNotification.open();
		pNotification.handle();
		pNotification.close();
	}
	else
	{
		PopupComfirm pDelete;
		pDelete.setPosition(DISTANCE_SIDEBAR + MARGIN + deletePosX, 17);
		pDelete.open();
		pDelete.handle();

		if (pDelete.getResult())
		{
			bool result = subject.deleteSubject(subjectCode.c_str());
			if (result)
			{
				hover = 0;
				cleanTable();
			}
		}

		pDelete.close();
	}
	
	currentSubject = C_SELECT;
	return;
}

void ContentSubject::createData()
{
	listInput[0].setText("");
	listInput[1].setText("");
	stateInput = FORM_CODE;
	while (true)
	{
		if (stateInput == FORM_CODE)
		{
			listText[0].setContent(NOTIFICATION_CODE);
			listText[0].setColor(ColorCode_DarkYellow);
			int textPosX = getCenterX(COLUMN_RIGHT, listText[0].getLenString());
			listText[0].updatePositionX(textPosX);
			listText[0].display();

			listInput[0].notUseSpace = true;
			listInput[0].handleInput();

			listText[0].clean();
			listText[0].updatePositionX(-textPosX);
			listText[0].setContent("");

			switch (listInput[0].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_NAME;
				break;

			case F1:
				currentSubject = C_SELECT;
				return;

			case F3:
				currentSubject = C_SEARCH;
				return;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentSubject = C_EXIT;
					return;
				}
				break;

			case PGUP:
				stateInput == FORM_CODE;
				break;

			case PGDN:
				stateInput == FORM_CODE;
				break;

			case DOWN:
				stateInput = FORM_NAME;
				break;

			case UP:
				stateInput = FORM_NAME;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_NAME)
		{
			listText[1].setContent(NOTIFICATION_EMPTY);
			listText[1].setColor(ColorCode_DarkYellow);
			int textPosX = getCenterX(COLUMN_RIGHT, listText[1].getLenString());
			listText[1].updatePositionX(textPosX);
			listText[1].display();

			listInput[1].handleInput();

			listText[1].clean();
			listText[1].updatePositionX(-textPosX);
			listText[1].setContent("");

			switch (listInput[1].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_CODE;
				break;

			case F1:
				currentSubject = C_SELECT;
				return;

			case F3:
				currentSubject = C_SEARCH;
				return;

			case DOWN:
				stateInput = FORM_CODE;
				break;

			case UP:
				stateInput = FORM_CODE;
				break;

			case PGUP:
				stateInput == FORM_NAME;
				break;

			case PGDN:
				stateInput == FORM_NAME;
				break;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentSubject = C_EXIT;
					return;
				}
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ENTER)
		{
			bool result = subject.addSubject(listInput[0].getText(), listInput[1].getText());
			if (result)
			{
				showCur(0);
				int posX = getCenterX(COLUMN_CENTER, 50);
				ToastMessage m;
				m.setFrame(50, 5);
				m.setTitle(NOTIFICATION_INSERT_FINISH);
				m.setPosition(DISTANCE_SIDEBAR + MARGIN + posX, 17);
				m.open();
				m.close();
				indexTree = 0;
				SubjectPage a = subject.searchSubjects(textSearch, pageNumber);
				cleanInput();
				cleanTable();

				loadDataTree(a.subjects);
				pagging();
				showCur(1);
			}
			else
			{
				text.setContent("Ma Mon Hoc Da Ton Tai!");
				int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
				text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING + textPosX, posYMessage);
				text.setColor(ColorCode_DarkRed);
				text.display();
			}

			stateInput = FORM_CODE;
		}

		if (stateInput == FORM_EXIT)
		{
			return;
		}
	}
}

void ContentSubject::editData()
{
	PTRSUBJECT subjectFound = subject.getSubject(subjectCode.c_str());
	listInput[0].setText(subjectCode);
	listInput[1].setText(subjectFound->info.subjectName);

	for (int i = 0; i < listInput.size(); i++)
	{
		listInput[i].display();
	}

	stateInput = FORM_NAME;
	while (true)
	{
		if (stateInput == FORM_NAME)
		{
			listText[1].setContent(NOTIFICATION_EMPTY);
			listText[1].setColor(ColorCode_DarkYellow);
			int textPosX = getCenterX(COLUMN_RIGHT, listText[1].getLenString());
			listText[1].updatePositionX(textPosX);
			listText[1].display();

			listInput[1].handleInput();

			listText[1].clean();
			listText[1].updatePositionX(-textPosX);
			listText[1].setContent("");
			switch (listInput[1].getEndKey())
			{
			case ENTER:
				if (listInput[1].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				break;

			case F1:
				currentSubject = C_SELECT;
				return;

			case F3:
				currentSubject = C_SEARCH;
				return;

			case PGUP:
				stateInput == FORM_NAME;
				break;

			case PGDN:
				stateInput == FORM_NAME;
				break;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentSubject = C_EXIT;
					return;
				}
				break;
			default:
				break;
			}
		}

		if (stateInput == FORM_ENTER)
		{
			bool result = subject.editSubject(subjectCode, listInput[1].getText());
			if (result)
			{
				indexTree = 0;
				SubjectPage a = subject.searchSubjects(textSearch, pageNumber);
				cleanTable();
				text.clean();
				loadDataTree(a.subjects);

				text.setContent(NOTIFICATION_UPDATE_FINISH);
				int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
				text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING + textPosX, posYMessage);
				text.setColor(ColorCode_DarkGreen);

			}
			else {
				text.setContent(NOTIFICATION_UPDATE_FAIL);
				int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
				text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING + textPosX, posYMessage);
				text.setColor(ColorCode_DarkRed);
			}
			text.display();
			stateInput = FORM_NAME;
		}
	}
}

void ContentSubject::findData()
{
	SubjectPage a;
	int cursorPosition = textSearch.length();
	stateSearchInput = SEARCH_INPUT;
	while (true)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 5 + cursorPosition, DISTANCE_HEADER + 2);
		if (GetAsyncKeyState(VK_F1) & 0x0001)
		{
			currentSubject = C_SELECT;
			return;
		}

		if (GetAsyncKeyState(VK_INSERT) & 0x0001)
		{
			currentSubject = C_CREATE;
			return;
		}

		if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			if (Singleton::getInstance()->moveMenu != 0)
			{
				currentSubject = C_EXIT;
				return;
			}
		}

		if (GetAsyncKeyState(VK_PRIOR) & 0x8000)
		{
			currentSubject = C_SELECT;
			return;
		}

		if (GetAsyncKeyState(VK_NEXT) & 0x8000)
		{
			currentSubject = C_SELECT;
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
			cleanTable();
			a = subject.searchSubjects(textSearch, pageNumber);
			loadDataTree(a.subjects);
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

				indexTree = 0;
				cleanTable();
				a = subject.searchSubjects(textSearch, pageNumber);
				loadDataTree(a.subjects);
				pagging();
			}
			break;
		}
	}
}

void ContentSubject::loadDataTree(PTRSUBJECT root)
{
	if (!root) return;
	loadDataTree(root->left);

	setColorText(ColorCode_White);
	if (hover == indexTree)
	{
		setColorText(ColorCode_DarkGreen);
		subjectCode = root->info.subjectCode;// Get subject Code for edit and delete
		countQuestion = subject.countQuestionsInSubject(root->info.subjectCode);
	}
	int codeX = getCenterX(40, strlen(root->info.subjectCode));
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + codeX, DISTANCE_HEADER + 8 + (indexTree * 2));
	cout << root->info.subjectCode;

	int nameX = getCenterX(40, root->info.subjectName.length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + nameX + 40, DISTANCE_HEADER + 8 + (indexTree * 2));
	cout << root->info.subjectName;

	int countX = getCenterX(40, getCountQuestionInList(root->info.listQuestion));
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + countX  + 40 + 40, DISTANCE_HEADER + 8 + (indexTree * 2));
	cout << subject.countQuestionsInSubject(root->info.subjectCode);

	setColorText(ColorCode_White);
	indexTree++;
	loadDataTree(root->right);
}

void ContentSubject::pagging()
{
	SubjectPage a = subject.searchSubjects(textSearch, pageNumber);

	string blankFillText;
	blankFillText.resize(10, ' ');

	int currentPage = 0;
	if (a.totalSubject > 0)
	{
		currentPage = pageNumber;
	}

	setColorText(ColorCode_DarkWhite);
	string pageTitle = "Trang " + to_string(currentPage) + '/' + to_string(a.totalPage);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - 8, 10 + 28 + 5);
	cout << pageTitle;
}

void ContentSubject::cleanInput()
{
	for (int i = 0; i < 2; i++)
	{
		listInput[i].clean();
		listInput[i].setText("");

		if (listText[i].getLenString() != 0)
		{
			int textPosX = getCenterX(COLUMN_RIGHT, listText[i].getLenString());
			listText[i].clean();
			listText[i].updatePositionX(-textPosX);
			listText[i].setContent("");
		}
	}
	text.clean();
	text.setPosition(0, posYMessage);
}