#include "ContentClassroom.h"

ContentClassroom::ContentClassroom()
{
}

ContentClassroom::~ContentClassroom()
{
}

void ContentClassroom::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	content();
}

void ContentClassroom::drawClassroom()
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
		"Ma Lop",
		"Ten Lop"
	};


	int y = DISTANCE_HEADER + PADDING + 4;

	for (int i = 0; i < 2; i++)
	{
		listInput.push_back(InputField());
		listText.push_back(Text());

		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 3, y + (i * 4));
		cout << titleInput[i];

		listInput[i].setMinLen(LENGTH_MIN_INPUT);
		listInput[i].setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING + 13, y + (i * 4) - 1);
		listInput[i].drawBox();

		listText[i].setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, y + (i * 4) + 2);
	}

	lineX(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING + 2, COLUMN_RIGHT);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING, COLUMN_RIGHT, 15);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + 3);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, DISTANCE_HEADER + 3);
	cout << char(180);

	y = y + (2 * 3);
	posYMessage = y + 1;
	text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, y);

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
		"F3: Tim Kiem Lop",
		"Ins: Them Lop",
		"Phim Len|Xuong: Chon Du Lieu",
		"Phim Trai|Phai: Xem Trang Sau|Truoc",
		" ",
		"* Chinh Sua Lop",
		"   F1->Len|Xuong->F2",
		"* Xoa Lop",
		"   F1->Len|Xuong->Del->Trai|Phai",
		"* Xem Danh Sach Sinh Vien Cua Lop",
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

void ContentClassroom::girdContent()
{
	lineX(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + MARGIN, COLUMN_CENTER);
	gotoXY(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + MARGIN);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER, DISTANCE_HEADER + MARGIN);
	cout << char(180);

	string title[] = {
		"Ma Lop",
		"Ten Lop",
		"Sinh Vien"
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

void ContentClassroom::content()
{
	drawClassroom();
	girdContent();
	currentClassroom = C_SELECT;
	handle();
}

void ContentClassroom::handle()
{
	while (true)
	{
		if (currentClassroom == C_DETAIL)
		{
			cleanContent();
			ContentStudent* detail = new ContentStudent();
			detail->setClassCode(classCode);
			detail->content();
			delete detail;
			cleanContent();
			drawClassroom();
			girdContent();
			currentClassroom = C_EXIT;
			Singleton::getInstance()->moveMenu = 0;
		}

		switch (currentClassroom)
		{
		case C_SELECT:
			showCur(0);
			selectData();
			break;

		case C_CREATE:
			showCur(1);
			createData();
			cleanInput();
			cleanMessage(posYMessage);
			break;

		case C_EDIT:
			showCur(1);
			editData();
			cleanInput();
			cleanMessage(posYMessage);
			break;

		case C_SEARCH:
			showCur(1);
			findData();
			break;

		case C_DELETE:
			showCur(0);
			deleteData();
			break;

		case C_EXIT:
			return;

		default:
			break;
		}
	}
}

void ContentClassroom::selectData()
{
	ManageClass nl;
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
		if (GetAsyncKeyState(VK_UP) & 0x8000)
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

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
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

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
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

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
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

		if (GetAsyncKeyState(VK_F1) & 0x0001)
		{
			currentClassroom = C_SELECT;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_F2) & 0x0001)
		{
			if (page.totalClass <= 0)
			{
				continue;
			}

			currentClassroom = C_EDIT;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_F3) & 0x0001)
		{
			currentClassroom = C_SEARCH;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_INSERT) & 0x0001)
		{
			currentClassroom = C_CREATE;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_DELETE) & 0x0001)
		{
			page = nl.getClassPerPage(1);

			if (page.totalClass <= 0)
			{
				currentClassroom = C_SELECT;
				return;
			}

			currentClassroom = C_DELETE;
			return;
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		{
			if (isLoadFirst)
			{
				isLoadFirst = false;
				continue;
			}

			currentClassroom = C_DETAIL;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_TAB))
		{
			if (Singleton::getInstance()->moveMenu != 0)
			{
				currentClassroom = C_EXIT;
				return;
			}
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
					countClass = getCountStudentOfList(page.classList.classes[i]->studentList);
				}

				int classX = getCenterX(40, strlen(page.classList.classes[i]->classCode));
				gotoXY(DISTANCE_SIDEBAR + MARGIN + classX, DISTANCE_HEADER + 8 + (2 * i));
				cout << page.classList.classes[i]->classCode;

				int nameX = getCenterX(40, page.classList.classes[i]->className.length());
				gotoXY(DISTANCE_SIDEBAR + MARGIN + 40 + nameX, DISTANCE_HEADER + 8 + (2 * i));
				cout << page.classList.classes[i]->className;

				string countStr = to_string(getCountStudentOfList(page.classList.classes[i]->studentList));
				int countX = getCenterX(40, countStr.length());
				gotoXY(DISTANCE_SIDEBAR + MARGIN + 40 + 40 + countX, DISTANCE_HEADER + 8 + (2 * i));
				cout << countStr;
				setColorText(ColorCode_DarkWhite);
			}
			lastHover = hover;
			pagging();
		}
	}
}

void ContentClassroom::createData()
{
	ManageClass nl;
	listInput[0].setText("");
	listInput[1].setText("");

	stateInput = FORM_CODE;
	while (true)
	{
		if (stateInput == FORM_CODE)
		{
			listText[0].setContent(DEFAULT_NOTIFICATION);
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
				currentClassroom = C_SELECT;
				return;

			case F3:
				currentClassroom = C_SEARCH;
				return;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentClassroom = C_EXIT;
					return;
				}
				break;

			case DOWN:
			case UP:
				stateInput = FORM_NAME;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_NAME)
		{
			listText[1].setContent(DEFAULT_NOTIFICATION);
			listText[1].setColor(ColorCode_DarkYellow);
			int textPosX = getCenterX(COLUMN_RIGHT, listText[1].getLenString());
			listText[1].updatePositionX(textPosX);
			listText[1].display();

			listInput[1].notUseSpace = true;
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
				currentClassroom = C_SELECT;
				return;

			case F3:
				currentClassroom = C_SEARCH;
				return;

			case DOWN:
			case UP:
				stateInput = FORM_CODE;
				break;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentClassroom = C_EXIT;
					return;
				}
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ENTER)
		{
			bool result = nl.addClass(listInput[0].getText().c_str(), listInput[1].getText());

			if (result)
			{
				cleanTable();
				loadData();
				cleanMessage(posYMessage);
				text.setContent(INSERT_FINISH);
				text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, posYMessage);
				int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
				text.updatePositionX(textPosX);
				text.setColor(ColorCode_DarkGreen);
			}
			else
			{
				cleanMessage(posYMessage);
				text.setContent("Ma Lop Da Ton Tai!");
				text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, posYMessage);
				int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
				text.updatePositionX(textPosX);
				text.setColor(ColorCode_DarkRed);
			}

			text.display();
			stateInput = FORM_CODE;
		}

		if (stateInput == FORM_EXIT)
		{
			return;
		}
	}
}

void ContentClassroom::deleteData()
{
	int deletePosX = getCenterX(COLUMN_CENTER, 50);

	if (countClass > 0)
	{
		PopupNotification pNotification;
		pNotification.setTitle("Du lieu nay khong the xoa duoc!");
		pNotification.setPosition(deletePosX + 30, 17);
		pNotification.open();
		pNotification.handle();
		pNotification.close();
	}
	else 
	{
		PopupDelete pDelete;
		pDelete.setPosition(deletePosX + 30, 17);
		pDelete.open();
		pDelete.handle();

		if (pDelete.getResult())
		{
			ManageClass nl;
			bool result = nl.deleteClass(classCode.c_str());
			if (result)
			{
				hover = 0;
			}
		}
		pDelete.close();
	}

	currentClassroom = C_SELECT;
	return;
}

void ContentClassroom::editData()
{
	listInput[0].setText("");
	listInput[1].setText("");

	ManageClass nl;

	// Display data
	Classroom cl = nl.findClassByCode(classCode.c_str());
	listInput[0].setText(classCode);
	listInput[0].display();
	listInput[1].setText(cl.className);
	listInput[1].display();

	stateInput = FORM_NAME;
	while (true)
	{
		if (stateInput == FORM_NAME)
		{
			listText[1].setContent(DEFAULT_NOTIFICATION);
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
				currentClassroom = C_SELECT;
				return;

			case F3:
				currentClassroom = C_SEARCH;
				return;


			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentClassroom = C_EXIT;
					return;
				}
				break;
			default:
				break;
			}
		}

		if (stateInput == FORM_ENTER)
		{
			bool result = nl.editClass(listInput[0].getText().c_str(), listInput[1].getText());
			
			if (result)
			{
				cleanTable();
				loadData();
				cleanMessage(posYMessage);
				text.setContent(UPDATE_FINISH);
				text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, posYMessage);
				int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
				text.updatePositionX(textPosX);
				text.setColor(ColorCode_DarkGreen);
			}
			else {
				cleanMessage(posYMessage);
				text.setContent(UPDATE_FAIL);
				text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, posYMessage);
				int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
				text.updatePositionX(textPosX);
				text.setColor(ColorCode_DarkRed);
			}
			text.display();
			stateInput = FORM_NAME;
		}
	}
}

void ContentClassroom::findData()
{
	int cursorPosition = textSearch.length();
	stateSearchInput = SEARCH_INPUT;
	while (true)
	{
		if (stateSearchInput == SEARCH_INPUT)
		{
			gotoXY(34 + 2 + 4 + 2 + textSearch.length(), 10);

			if (GetAsyncKeyState(VK_F1) & 0x0001)
			{
				currentClassroom = C_SELECT;
				Sleep(150);
				return;
			}

			if (GetAsyncKeyState(VK_INSERT) & 0x0001)
			{
				currentClassroom = C_CREATE;
				Sleep(150);
				return;
			}

			if (GetAsyncKeyState(VK_TAB) & 0x8000)
			{
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentClassroom = C_EXIT;
					return;
				}
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
					showCur(1);

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

void ContentClassroom::pagging()
{
	ManageClass nl;
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
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - 8, 10 + 28 + 5);
	cout << pageTitle;
}

void ContentClassroom::loadData()
{
	cleanTable();
	ManageClass nl;
	ClassPage page;
	if (textSearch != "")
	{
		page = nl.searchClass(textSearch, 1);
	}
	else {
		page = nl.getClassPerPage(pageNumber);
	}

	for (int i = 0; i < page.classList.countClass; i++)
	{
		setColorText(ColorCode_DarkWhite);
		if (hover == i)
		{
			setColorText(ColorCode_DarkGreen);
		}

		int classX = getCenterX(40, strlen(page.classList.classes[i]->classCode));
		gotoXY(DISTANCE_SIDEBAR + MARGIN + classX, 10 + 2 + 1 + 3 + (2 * i));
		cout << page.classList.classes[i]->classCode;

		int nameX = getCenterX(40, page.classList.classes[i]->className.length());
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 40 + nameX, 10 + 2 + 1 + 3 + (2 * i));
		cout << page.classList.classes[i]->className;

		string countStr = to_string(getCountStudentOfList(page.classList.classes[i]->studentList));
		int countX = getCenterX(40, countStr.length());
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 40 + 40 + countX, 10 + 2 + 1 + 3 + (2 * i));
		cout << countStr;
		setColorText(ColorCode_DarkWhite);
	}
}

void ContentClassroom::cleanInput()
{
	for (int i = 0; i < 2; i++)
	{
		listInput[i].clean();

		if (listText[i].getLenString() != 0)
		{
			int textPosX = getCenterX(COLUMN_RIGHT, listText[i].getLenString());
			listText[i].clean();
			listText[i].updatePositionX(-textPosX);
			listText[i].setContent("");
		}
	}
}

bool ContentClassroom::checkInsert(string code)
{
	ManageClass classes;
	bool isClassExist = classes.isClassExist(code);
	return isClassExist;
}