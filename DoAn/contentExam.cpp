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

void ContentExam::drawContent()
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
		"So Cau Hoi",
		"So Phut"
	};


	int y = DISTANCE_HEADER + PADDING + 4;

	for (int i = 0; i < 3; i++)
	{
		listInput.push_back(InputField());
		listText.push_back(Text());

		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 3, y + (i * 4));
		cout << titleInput[i];

		listInput[i].setMinLen(LENGTH_MIN);
		listInput[i].setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING + 13, y + (i * 4) - 1);
		listInput[i].drawBox();

		listText[i].setColor(ColorCode_DarkYellow);
		listText[i].setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, y + (i * 4) + 2);
	}

	listInput[0].notUseSpace = true;
	listText[0].setContent(NOTIFICATION_EMPTY);

	listText[1].setContent("Vui Long Nhap So Cau!");
	listInput[1].notUseZero = true;
	listInput[1].useNum = true;
	listInput[1].setText("5");
	listInput[1].display();

	listText[2].setContent("Vui Long Nhap So Phut!");
	listInput[2].notUseZero = true;
	listInput[2].useNum = true;
	listInput[2].setText("5");
	listInput[2].display();


	lineX(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING + 2, COLUMN_RIGHT);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING, COLUMN_RIGHT, 19);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + 3);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, DISTANCE_HEADER + 3);
	cout << char(180);

	y = y + (2 * 3) - 1;
	
	y = y + 6;
	posYMessage = y;
	text.setColor(ColorCode_DarkRed);
	text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, y);

	y = y + 1;
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
		"F3: Tim Mon",
		"Ins: Chinh Sua Thong Tin",
		"Enter: Thi",
		"",
		"Phim Len|Xuong: Chon Du Lieu",
		"Phim Trai|Phai: Xem Trang Sau|Truoc"
	};

	int contentY = tutorialY + 2;
	for (int i = 0; i < 7; i++)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 2, contentY + (i * 1));
		cout << note[i];
	}
	setColorText(ColorCode_DarkYellow);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, y, COLUMN_RIGHT, 13);
	lineX(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, tutorialY, COLUMN_RIGHT);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, tutorialY);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, tutorialY);
	cout << char(180);
	setColorText(ColorCode_DarkWhite);
}

void ContentExam::girdTitle()
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

void ContentExam::content()
{
	drawContent();
	girdTitle();
	currentExam = C_SELECT;
	handle();
}

void ContentExam::handle()
{
	while (true)
	{
		if (currentExam == C_DETAIL)
		{
			showCur(0);

			Singleton::getInstance()->isExecute = true;
			cleanContent();
			ContentExecute* e = new ContentExecute();
			e->initExecute(listInput[0].getText(), stoi(listInput[1].getText()), stoi(listInput[2].getText()));
			e->displayContent();
			delete e;
			cleanContent();
			drawContent();
			girdTitle();
			currentExam = C_EXIT;
			Singleton::getInstance()->moveMenu = 0;
			Singleton::getInstance()->isExecute = false;

			lineX(0, DISTANCE_HEADER, getConsoleWidth());
			lineX(0, getConsoleHeight() - DISTANCE_HEADER, getConsoleWidth());
			gotoXY(DISTANCE_SIDEBAR, getConsoleHeight() - DISTANCE_HEADER);
			cout << char(193);
			gotoXY(DISTANCE_SIDEBAR, DISTANCE_HEADER);
			cout << char(194);
		}

		switch (currentExam)
		{
		case ContentExam::C_SELECT:
			showCur(0);
			lastHover = -1;
			selectData();
			break;
		case ContentExam::C_CREATE:
			showCur(1);
			createData();
			break;
		case ContentExam::C_EDIT:
			break;
		case ContentExam::C_SEARCH:
			showCur(1);
			findData();
			break;
		case ContentExam::C_DELETE:
			break;
	/*	case ContentExam::C_DETAIL:
			break;*/
		case ContentExam::C_EXIT:
			return;
		default:
			break;
		}
	}
}

void ContentExam::selectData()
{
	listInput[0].clean();
	listInput[0].setText("");

	ManageSubject subject;
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

		if (GetAsyncKeyState(VK_INSERT) & 0x0001)
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
		}

		if (GetAsyncKeyState(VK_TAB))
		{
			if (Singleton::getInstance()->moveMenu != 0)
			{
				currentExam = C_EXIT;
				return;
			}
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		{
			int result = ManageExam::checkInputExam1(Singleton::getInstance()->role.c_str(), listInput[0].getText().c_str(), stoi(listInput[1].getText()));
			if (result == 1)
			{
				currentExam = C_DETAIL;
				return;
			}

			if (result == -2)
			{
				int cout = subject.countQuestionsInSubject(listInput[0].getText().c_str());
				string mes;
				if (cout == 0)
				{
					mes = "Chua Co Du Lieu Cau Hoi";
				}
				else
				{
					mes = "Nhap Toi Da " + to_string(subject.countQuestionsInSubject(listInput[0].getText().c_str())) + " Cau Hoi";
				}

				if (text.getLenString() != 0)
				{
					text.clean();
					text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, posYMessage);
					text.setContent("");
				}

				text.setContent(mes);
				int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
				text.updatePositionX(textPosX);

				text.display();
			}

			if (result == -3)
			{
				if (text.getLenString() != 0)
				{
					text.clean();
					text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, posYMessage);
					text.setContent("");
				}

				text.setContent("Mon Nay Da Thi Roi!");
				int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
				text.updatePositionX(textPosX);

				text.display();
			}
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

void ContentExam::createData()
{
	stateInput = FORM_CODE;
	while (true)
	{
		if (stateInput == FORM_CODE)
		{
			listText[0].setContent(NOTIFICATION_EMPTY);
			int textPosX = getCenterX(COLUMN_RIGHT, listText[0].getLenString());
			listText[0].updatePositionX(textPosX);
			listText[0].display();

			listInput[0].handleInput();

			listText[0].clean();
			listText[0].updatePositionX(-textPosX);

			switch (listInput[0].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != "")
				{
					stateInput = FORM_ENTER;
					break;
				}
				stateInput = FORM_COUNT;
				break;

			case F1:
				currentExam = C_SELECT;
				return;

			case F3:
				currentExam = C_SEARCH;
				return;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentExam = C_EXIT;
					return;
				}
				break;

			case UP:
				stateInput = FORM_MINUTE;
				break;

			case DOWN:
				stateInput = FORM_COUNT;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_COUNT)
		{
			listText[0].setContent("Vui Long Nhap Toi Da 40 Cau!");
			int textPosX = getCenterX(COLUMN_RIGHT, listText[1].getLenString());
			listText[1].updatePositionX(textPosX);
			listText[1].display();

			listInput[1].handleInput();

			listText[1].clean();
			listText[1].updatePositionX(-textPosX);
			switch (listInput[1].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != "")
				{
					stateInput = FORM_ENTER;
					break;
				}
				stateInput = FORM_MINUTE;
				break;

			case F1:
				currentExam = C_SELECT;
				return;

			case F3:
				currentExam = C_SEARCH;
				return;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentExam = C_EXIT;
					return;
				}
				break;

			case UP:
				stateInput = FORM_CODE;
				break;

			case DOWN:
				stateInput = FORM_MINUTE;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_MINUTE)
		{
			listText[0].setContent("Vui Long Nhap Toi Da 180 Phut!");
			int textPosX = getCenterX(COLUMN_RIGHT, listText[2].getLenString());
			listText[2].updatePositionX(textPosX);
			listText[2].display();

			listInput[2].handleInput();

			listText[2].clean();
			listText[2].updatePositionX(-textPosX);
			switch (listInput[2].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != "")
				{
					stateInput = FORM_ENTER;
					break;
				}
				stateInput = FORM_COUNT;
				break;

			case F1:
				currentExam = C_SELECT;
				return;

			case F3:
				currentExam = C_SEARCH;
				return;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentExam = C_EXIT;
					return;
				}
				break;

			case UP:
				stateInput = FORM_COUNT;
				break;

			case DOWN:
				stateInput = FORM_CODE;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ENTER)
		{
			int result = ManageExam::checkInputExam1(Singleton::getInstance()->role.c_str(), listInput[0].getText().c_str(), stoi(listInput[1].getText()));

			if (result == 1)
			{
				currentExam = C_DETAIL;
				return;
			}
			else 
			{
				if (result == -1)
				{
					if (text.getLenString() != 0)
					{
						text.clean();
						text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, posYMessage);
						text.setContent("");
					}

					text.setContent(SUBJECT_CODE);
					int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
					text.updatePositionX(textPosX);

					text.display();
					stateInput = FORM_CODE;
				}

				if (result == -2)
				{
					int cout = subject.countQuestionsInSubject(listInput[0].getText().c_str());
					string mes;
					if (cout == 0)
					{
						mes = "Chua Co Du Lieu Cau Hoi";
					}
					else 
					{
						mes = "Nhap Toi Da " + to_string(subject.countQuestionsInSubject(listInput[0].getText().c_str())) + " Cau Hoi";
					}

					if (text.getLenString() != 0)
					{
						text.clean();
						text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, posYMessage);
						text.setContent("");
					}

					text.setContent(mes);
					int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
					text.updatePositionX(textPosX);

					text.display();
					stateInput = FORM_COUNT;
				}

				if (result == -3)
				{
					if (text.getLenString() != 0)
					{
						text.clean();
						text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, posYMessage);
						text.setContent("");
					}

					text.setContent("Mon Nay Da Thi Roi!");
					int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
					text.updatePositionX(textPosX);

					text.display();
					stateInput = FORM_MINUTE;
				}
			}
			
		}
	}
}

void ContentExam::findData()
{
	SubjectPage a;
	int cursorPosition = textSearch.length();
	stateSearchInput = SEARCH_INPUT;
	while (true)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 5 + cursorPosition, DISTANCE_HEADER + 2);
		if (GetAsyncKeyState(VK_F1) & 0x0001)
		{
			currentExam = C_SELECT;
			return;
		}

		if (GetAsyncKeyState(VK_INSERT) & 0x0001)
		{
			currentExam = C_CREATE;
			return;
		}

		if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			if (Singleton::getInstance()->moveMenu != 0)
			{
				currentExam = C_EXIT;
				return;
			}
		}

		if (GetAsyncKeyState(VK_PRIOR) & 0x8000)
		{
			currentExam = C_SELECT;
			return;
		}

		if (GetAsyncKeyState(VK_NEXT) & 0x8000)
		{
			currentExam = C_SELECT;
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

void ContentExam::pagging()
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

void ContentExam::loadDataTree(PTRSUBJECT root)
{
	if (!root) return;
	loadDataTree(root->left);

	setColorText(ColorCode_White);
	if (hover == indexTree)
	{
		listInput[0].setText(root->info.subjectCode);
		listInput[0].display();
		setColorText(ColorCode_DarkGreen);
	}
	int codeX = getCenterX(40, strlen(root->info.subjectCode));
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + codeX, DISTANCE_HEADER + 8 + (indexTree * 2));
	cout << root->info.subjectCode;

	int nameX = getCenterX(40, root->info.subjectName.length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + nameX + 40, DISTANCE_HEADER + 8 + (indexTree * 2));
	cout << root->info.subjectName;

	int countX = getCenterX(40, getCountQuestionInList(root->info.listQuestion));
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + countX + 40 + 40, DISTANCE_HEADER + 8 + (indexTree * 2));
	cout << subject.countQuestionsInSubject(root->info.subjectCode);

	setColorText(ColorCode_White);
	indexTree++;
	loadDataTree(root->right);
}