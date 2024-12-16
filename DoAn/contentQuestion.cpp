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

void ContentQuestion::init(string code)
{
	this->subjectCode = code;
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
	posYMessage = y;

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
		"ID",
		"Noi Dung Chinh",
		"Noi Dung A",
		"Noi Dung B",
		"Noi Dung C",
		"Noi Dung D",
		"Dap An"
	};

	int sizeColumn = 20;

	int idX = getCenterX(10, title[0].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + idX, 10 + 2 + 1);
	cout << title[0];

	int classX = getCenterX(sizeColumn, title[1].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + classX, 10 + 2 + 1);
	cout << title[1];

	int lastX = getCenterX(sizeColumn, title[2].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + sizeColumn + lastX, 10 + 2 + 1);
	cout << title[2];

	int firstX = getCenterX(sizeColumn, title[3].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + sizeColumn + sizeColumn + firstX, 10 + 2 + 1);
	cout << title[3];

	int sexX = getCenterX(sizeColumn, title[4].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + sizeColumn + sizeColumn + sizeColumn + sexX, 10 + 2 + 1);
	cout << title[4];

	int passX = getCenterX(sizeColumn, title[5].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + sizeColumn + sizeColumn + sizeColumn + sizeColumn + passX, 10 + 2 + 1);
	cout << title[5];

	int passAX = getCenterX(10, title[6].length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + sizeColumn + sizeColumn + sizeColumn + sizeColumn + sizeColumn + passAX, 10 + 2 + 1);
	cout << title[6];
}

void ContentQuestion::content()
{
	drawClassroom();
	girdContent();
	currentQuestion = C_SELECT;
	handle();
}

void ContentQuestion::handle()
{
	while (true)
	{
		switch (currentQuestion)
		{
		case ContentQuestion::C_SELECT:
			showCur(0);
			selectData();
			break;

		case ContentQuestion::C_CREATE:
			showCur(1);
			createData();
			break;

		case ContentQuestion::C_EDIT:
			showCur(1);
			editData();
			break;

		case ContentQuestion::C_SEARCH:
			showCur(1);
			findData();
			break;

		case ContentQuestion::C_DELETE:
			showCur(0);
			deleteData();
			break;

		/*case ContentQuestion::C_DETAIL:
			break;*/

		case ContentQuestion::C_EXIT:
			return;

		default:
			break;
		}
	}
}

void ContentQuestion::selectData()
{
	page = subject.searchQuestionInSubject(subjectCode, textSearch, pageNumber);
	
	int start = 0;
	int end = pageNumber * page.numberQuestionPerPage;

	if (pageNumber * page.numberQuestionPerPage < page.totalQuestions)
	{
		end = page.numberQuestionPerPage - 1;
	}
	else {
		end = (page.numberQuestionPerPage - (end - page.totalQuestions)) - 1;
	}

	int lastHover = -1;
	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			currentQuestion = C_EXIT;
			return;
		}

		if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			if (Singleton::getInstance()->moveMenu != 0)
			{
				currentQuestion = C_EXIT;
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
				end = pageNumber * page.numberQuestionPerPage;
				if (pageNumber * page.numberQuestionPerPage < page.totalQuestions)
				{
					end = page.numberQuestionPerPage - 1;
				}
				else {
					end = (page.numberQuestionPerPage - (end - page.totalQuestions)) - 1;
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
				hover = 0;
				pageNumber++;
				end = pageNumber * page.numberQuestionPerPage;
				if (pageNumber * page.numberQuestionPerPage < page.totalQuestions)
				{
					end = page.numberQuestionPerPage - 1;
				}
				else {
					end = (page.numberQuestionPerPage - (end - page.totalQuestions)) - 1;
				}
				lastHover = -1;
			}
			Sleep(150);
		}

		if (GetAsyncKeyState(VK_INSERT) & 0x0001)
		{
			currentQuestion = C_CREATE;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_DELETE) & 0x0001)
		{
			currentQuestion = C_DELETE;
			return;
		}

		if (GetAsyncKeyState(VK_F2) & 0x0001)
		{
			if (page.totalQuestions <= 0)
			{
				continue;
			}

			currentQuestion = C_EDIT;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_F3) & 0x0001)
		{
			currentQuestion = C_SEARCH;
			Sleep(150);
			return;
		}

		if (lastHover != hover)
		{
			int sizeColumn = 20;
			page = subject.searchQuestionInSubject(subjectCode, textSearch, pageNumber);
			PTRQUESTION questionList = page.questionList;
			int i = 0;
			while (questionList != nullptr) 
			{
				setColorText(ColorCode_DarkWhite);
				if (hover == i)
				{
					setColorText(ColorCode_DarkGreen);
					id = questionList->info.questionId;
				}

				int idX = getCenterX(10, to_string(questionList->info.questionId).length());
				gotoXY(DISTANCE_SIDEBAR + MARGIN + idX, DISTANCE_HEADER + 8 + i *2);
				cout << questionList->info.questionId;

				int classX = getCenterX(sizeColumn, questionList->info.content.length());
				gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + classX, DISTANCE_HEADER + 8 + i * 2);
				cout << questionList->info.content;

				int lastX = getCenterX(sizeColumn, questionList->info.optionA.length());
				gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + sizeColumn + lastX, DISTANCE_HEADER + 8 + i * 2);
				cout << questionList->info.optionA;

				int firstX = getCenterX(sizeColumn, questionList->info.optionB.length());
				gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + sizeColumn + sizeColumn + firstX, DISTANCE_HEADER + 8 + i * 2);
				cout << questionList->info.optionB;

				int sexX = getCenterX(sizeColumn, questionList->info.optionC.length());
				gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + sizeColumn + sizeColumn + sizeColumn + sexX, DISTANCE_HEADER + 8 + i * 2);
				cout << questionList->info.optionC;

				int passX = getCenterX(sizeColumn, questionList->info.optionD.length());
				gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + sizeColumn + sizeColumn + sizeColumn + sizeColumn + passX, DISTANCE_HEADER + 8 + i * 2);
				cout << questionList->info.optionD;

				int passAX = getCenterX(10, 1);
				gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + sizeColumn + sizeColumn + sizeColumn + sizeColumn + sizeColumn + passAX, DISTANCE_HEADER + 8 + i * 2);
				cout << questionList->info.answer;
				setColorText(ColorCode_DarkWhite);
				questionList = questionList->next;
				i++;
			}
			lastHover = hover;
			pagging();
		}
	}
}

void ContentQuestion::deleteData()
{
	int deletePosX = getCenterX(COLUMN_CENTER, 50);
	PopupDelete pDelete;
	pDelete.setPosition(deletePosX + 30, 17);
	pDelete.open();
	pDelete.handle();

	if (pDelete.getMenu() != 0)
	{
		currentQuestion = C_EXIT;
		return;
	}

	if (pDelete.getResult())
	{
		bool result = subject.deleteQuestionInSubject(subjectCode, id);
		if (result)
		{
			hover = 0;
		}
	}
	pDelete.close();

	currentQuestion = C_SELECT;
	return;
}

void ContentQuestion::createData()
{
	cleanContent();
	ContentInputQuestion q;
	q.init(subjectCode);
	q.displayContent();
	cleanContent();
	currentQuestion == C_SELECT;
}

void ContentQuestion::editData()
{
	Question questionFound = subject.getQuestionBySubjectCodeAndId(subjectCode, id);
	listInput[0].setText(questionFound.content);
	listInput[0].display();

	listInput[1].setText(questionFound.optionA);
	listInput[1].display();

	listInput[2].setText(questionFound.optionB);
	listInput[2].display();

	listInput[3].setText(questionFound.optionC);
	listInput[3].display();

	listInput[4].setText(questionFound.optionD);
	listInput[4].display();

	string str(1, questionFound.answer);
	listInput[5].setText(str);
	listInput[5].display();

	while (true)
	{
		if (stateInput == FORM_ContentMain)
		{
			listInput[0].handleInput();

			switch (listInput[0].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != ""
					&& listInput[3].getText() != "" && listInput[4].getText() != "" && listInput[5].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_ContentA;
				break;

			case F1:
				currentQuestion = C_SELECT;
				return;

			case F3:
				currentQuestion = C_SEARCH;
				return;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentQuestion = C_EXIT;
					return;
				}
				break;

			case DOWN:
				stateInput = FORM_ContentA;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ContentA)
		{
			listInput[1].handleInput();
			switch (listInput[1].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != ""
					&& listInput[3].getText() != "" && listInput[4].getText() != "" && listInput[5].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_ContentB;
				break;

			case F1:
				currentQuestion = C_SELECT;
				return;

			case F3:
				currentQuestion = C_SEARCH;
				return;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentQuestion = C_EXIT;
					return;
				}
				break;

			case UP:
				stateInput = FORM_ContentMain;
				break;

			case DOWN:
				stateInput = FORM_ContentB;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ContentB)
		{
			listInput[2].handleInput();

			switch (listInput[2].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != ""
					&& listInput[3].getText() != "" && listInput[4].getText() != "" && listInput[5].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_ContentC;
				break;

			case F1:
				currentQuestion = C_SELECT;
				return;

			case F3:
				currentQuestion = C_SEARCH;
				return;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentQuestion = C_EXIT;
					return;
				}
				break;

			case UP:
				stateInput = FORM_ContentA;
				break;

			case DOWN:
				stateInput = FORM_ContentC;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ContentC)
		{
			listInput[3].handleInput();

			switch (listInput[3].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != ""
					&& listInput[3].getText() != "" && listInput[4].getText() != "" && listInput[5].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_ContentD;
				break;

			case F1:
				currentQuestion = C_SELECT;
				return;

			case F3:
				currentQuestion = C_SEARCH;
				return;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentQuestion = C_EXIT;
					return;
				}
				break;

			case UP:
				stateInput = FORM_ContentB;
				break;

			case DOWN:
				stateInput = FORM_ContentD;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ContentD)
		{
			listInput[4].handleInput();
			switch (listInput[4].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != ""
					&& listInput[3].getText() != "" && listInput[4].getText() != "" && listInput[5].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_ContentAnswer;
				break;

			case F1:
				currentQuestion = C_SELECT;
				return;

			case F3:
				currentQuestion = C_SEARCH;
				return;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentQuestion = C_EXIT;
					return;
				}
				break;

			case UP:
				stateInput = FORM_ContentC;
				break;

			case DOWN:
				stateInput = FORM_ContentAnswer;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ContentAnswer)
		{
			listInput[5].handleInput();

			switch (listInput[5].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != ""
					&& listInput[3].getText() != "" && listInput[4].getText() != "" && listInput[5].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_ContentMain;
				break;

			case F1:
				currentQuestion = C_SELECT;
				return;

			case F3:
				currentQuestion = C_SEARCH;
				return;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentQuestion = C_EXIT;
					return;
				}
				break;

			case UP:
				stateInput = FORM_ContentD;
				break;

			case DOWN:
				stateInput = FORM_ContentMain;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ENTER)
		{
			bool result = subject.editQuestionInSubject(subjectCode.c_str(), id, listInput[0].getText(), listInput[1].getText(), listInput[2].getText(), listInput[3].getText(), listInput[4].getText(), listInput[5].getText()[0]);
			if (result)
			{
				cleanTable();
				loadData();
				cleanMessage(posYMessage);
				text.setContent("Them lop thanh cong!");
				text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, posYMessage);
				int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
				text.updatePositionX(textPosX);
			}
			else
			{
				cleanMessage(posYMessage);
				text.setContent("Them lop that bai!");
				text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, posYMessage);
				int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
				text.updatePositionX(textPosX);
			}

			text.display();
			stateInput = FORM_ContentMain;
		}

		if (stateInput == FORM_EXIT)
		{
			return;
		}
	}
}

void ContentQuestion::findData()
{
	int cursorPosition = textSearch.length();
	stateSearchInput = SEARCH_INPUT;
	while (true)
	{
		if (stateSearchInput == SEARCH_INPUT)
		{
			gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - WIDTH_INPUT + 1 + textSearch.length(), DISTANCE_HEADER + PADDING + 1);

			if (GetAsyncKeyState(VK_F1) & 0x0001)
			{
				currentQuestion = C_SELECT;
				Sleep(150);
				return;
			}

			if (GetAsyncKeyState(VK_INSERT) & 0x0001)
			{
				currentQuestion = C_CREATE;
				Sleep(150);
				return;
			}

			if (GetAsyncKeyState(VK_TAB) & 0x8000)
			{
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentQuestion = C_EXIT;
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

void ContentQuestion::pagging()
{
	page = subject.searchQuestionInSubject(subjectCode, textSearch, pageNumber);

	string blankFillText;
	blankFillText.resize(10, ' ');

	int currentPage = 0;
	if (page.totalQuestions > 0)
	{
		currentPage = pageNumber;
	}

	setColorText(ColorCode_DarkWhite);
	string pageTitle = "Trang " + to_string(currentPage) + '/' + to_string(page.totalPage);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - 8, 10 + 28 + 5);
	cout << pageTitle;
}

void ContentQuestion::loadData()
{
	cleanTable();
	page = subject.searchQuestionInSubject(subjectCode, textSearch, pageNumber);
	PTRQUESTION questionList = page.questionList;
	int sizeColumn = 20;
	int i = 0;
	while (questionList != nullptr)
	{
		setColorText(ColorCode_DarkWhite);
		if (hover == i)
		{
			setColorText(ColorCode_DarkGreen);
		}

		int idX = getCenterX(10, to_string(questionList->info.questionId).length());
		gotoXY(DISTANCE_SIDEBAR + MARGIN + idX, DISTANCE_HEADER + 8 + i * 2);
		cout << questionList->info.questionId;

		int classX = getCenterX(sizeColumn, questionList->info.content.length());
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + classX, DISTANCE_HEADER + 8 + i * 2);
		cout << questionList->info.content;

		int lastX = getCenterX(sizeColumn, questionList->info.optionA.length());
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + sizeColumn + lastX, DISTANCE_HEADER + 8 + i * 2);
		cout << questionList->info.optionA;

		int firstX = getCenterX(sizeColumn, questionList->info.optionB.length());
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + sizeColumn + sizeColumn + firstX, DISTANCE_HEADER + 8 + i * 2);
		cout << questionList->info.optionB;

		int sexX = getCenterX(sizeColumn, questionList->info.optionC.length());
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + sizeColumn + sizeColumn + sizeColumn + sexX, DISTANCE_HEADER + 8 + i * 2);
		cout << questionList->info.optionC;

		int passX = getCenterX(sizeColumn, questionList->info.optionD.length());
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + sizeColumn + sizeColumn + sizeColumn + sizeColumn + passX, DISTANCE_HEADER + 8 + i * 2);
		cout << questionList->info.optionD;

		int passAX = getCenterX(10, 1);
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + sizeColumn + sizeColumn + sizeColumn + sizeColumn + sizeColumn + passAX, DISTANCE_HEADER + 8 + i * 2);
		cout << questionList->info.answer;
		setColorText(ColorCode_DarkWhite);
		questionList = questionList->next;
		i++;
	}
	pagging();
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