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

void ContentQuestion::drawContent()
{
	// Search
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + PADDING, DISTANCE_HEADER + PADDING + PADDING);
	cout << "ESC: Tro Lai";
	box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING, WIDTH_INPUT - 5, HEIGHT_INPUT);

	showTitleQuestion();

	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - WIDTH_INPUT - 4, DISTANCE_HEADER + PADDING + PADDING);
	cout << "Tim";
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - WIDTH_INPUT, DISTANCE_HEADER + PADDING, WIDTH_INPUT, HEIGHT_INPUT);

	// Gird Data
	box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING * 4, COLUMN_CENTER, ROW_CENTER);

	// Info
	int y = DISTANCE_HEADER + PADDING;
	
	// Tutorial
	int tutorialY = y;
	tutorialY += 1;
	int titleTutorial = getCenterX(COLUMN_RIGHT, 9);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + titleTutorial, tutorialY);
	cout << "Huong Dan";
	tutorialY += 1;

	string note[] = {
		"F1: Chon Du Lieu Trong Bang",
		"F3: Tim Kiem Cau Hoi",
		"Ins: Them Cau Hoi",
		"ESC: Tro Lai",
		"Phim Len|Xuong: Chon Du Lieu",
		"Phim Trai|Phai: Xem Trang Sau|Truoc",
		" ",
		"* Chinh Sua Cau Hoi",
		"   F1->Len|Xuong->F2",
		"* Xoa Cau Hoi",
		"   F1->Len|Xuong->Del->Trai|Phai"
	};

	int contentY = tutorialY + 1;
	for (int i = 0; i < 11; i++)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 2, contentY + (i * 1));
		cout << note[i];
	}
	setColorText(ColorCode_DarkYellow);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, y, COLUMN_RIGHT, 15);
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
	drawContent();
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
	ManageSubject subject;
	QuestionPage page;
	string result;
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

				int classX = getCenterX(sizeColumn, sizeColumn - 2);
				gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + classX, DISTANCE_HEADER + 8 + i * 2);
				result = truncateText(questionList->info.content);
				cout << result;

				int lastX = getCenterX(sizeColumn, sizeColumn - 2);
				gotoXY(DISTANCE_SIDEBAR + MARGIN + 2 + 10 + sizeColumn + lastX, DISTANCE_HEADER + 8 + i * 2);
				result = truncateText(questionList->info.optionA);
				cout << result;

				int firstX = getCenterX(sizeColumn, sizeColumn - 2);
				gotoXY(DISTANCE_SIDEBAR + MARGIN + 2 + 10 + sizeColumn + sizeColumn + firstX, DISTANCE_HEADER + 8 + i * 2);
				result = truncateText(questionList->info.optionB);
				cout << result;
				
				int sexX = getCenterX(sizeColumn, sizeColumn - 2);
				gotoXY(DISTANCE_SIDEBAR + MARGIN + 2 + 10 + sizeColumn + sizeColumn + sizeColumn + sexX, DISTANCE_HEADER + 8 + i * 2);
				result = truncateText(questionList->info.optionC);
				cout << result;

				int passX = getCenterX(sizeColumn, sizeColumn - 2);
				gotoXY(DISTANCE_SIDEBAR + MARGIN + 2 + 10 + sizeColumn + sizeColumn + sizeColumn + sizeColumn + passX, DISTANCE_HEADER + 8 + i * 2);
				result = truncateText(questionList->info.optionD);
				cout << result;

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
	ManageSubject updatedSubject;
	bool isQuestionCanDelete = updatedSubject.isQuestionCanDelete(subjectCode, id);
	if (!isQuestionCanDelete)
	{
		PopupNotification pNotification;
		pNotification.setTitle("Du lieu nay khong the xoa duoc!");
		pNotification.setPosition(deletePosX + 30, 17);
		pNotification.open();
		pNotification.handle();
		pNotification.close();
	}
	else {
		PopupComfirm pDelete;
		pDelete.setPosition(deletePosX + 30, 17);
		pDelete.open();
		pDelete.handle();

		if (pDelete.getResult())
		{
			bool result = updatedSubject.deleteQuestionInSubject(subjectCode, id);
			if (result)
			{
				hover = 0;
				cleanTable();
			}
		}
		pDelete.close();
	}

	currentQuestion = C_SELECT;
	return;
}

void ContentQuestion::createData()
{
	cleanContent();
	ContentInputQuestion* q = new ContentInputQuestion();
	q->setStateInputQuestion(q->C_CREATE);
	q->init(subjectCode);
	q->displayContent();
	int result = q->getExitInput();
	if (result == 1)
	{
		currentQuestion = C_SELECT;
	}
	else
	{
		currentQuestion = C_EXIT;
	}
	delete q;
	cleanContent();
	drawContent();
	girdContent();
}

void ContentQuestion::editData()
{
	cleanContent();
	ContentInputQuestion q;
	q.setStateInputQuestion(q.C_EDIT);
	q.init(subjectCode);
	q.setIdQuestion(id);
	q.displayContent();
	cleanContent();
	drawContent();
	girdContent();
	currentQuestion = C_SELECT;
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

			if (GetAsyncKeyState(VK_PRIOR) & 0x8000)
			{
				currentQuestion = C_SELECT;
				return;
			}

			if (GetAsyncKeyState(VK_NEXT) & 0x8000)
			{
				currentQuestion = C_SELECT;
				return;
			}

			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
			{
				currentQuestion = C_EXIT;
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
	string result;
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

		int classX = getCenterX(sizeColumn, sizeColumn - 2);
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 10 + classX, DISTANCE_HEADER + 8 + i * 2);
		result = truncateText(questionList->info.content);
		cout << result;

		int lastX = getCenterX(sizeColumn, sizeColumn - 2);
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 2 + 10 + sizeColumn + lastX, DISTANCE_HEADER + 8 + i * 2);
		result = truncateText(questionList->info.optionA);
		cout << result;

		int firstX = getCenterX(sizeColumn, sizeColumn - 2);
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 2 + 10 + sizeColumn + sizeColumn + firstX, DISTANCE_HEADER + 8 + i * 2);
		result = truncateText(questionList->info.optionB);
		cout << result;

		int sexX = getCenterX(sizeColumn, sizeColumn - 2);
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 2 + 10 + sizeColumn + sizeColumn + sizeColumn + sexX, DISTANCE_HEADER + 8 + i * 2);
		result = truncateText(questionList->info.optionC);
		cout << result;

		int passX = getCenterX(sizeColumn, sizeColumn - 2);
		gotoXY(DISTANCE_SIDEBAR + MARGIN + 2 + 10 + sizeColumn + sizeColumn + sizeColumn + sizeColumn + passX, DISTANCE_HEADER + 8 + i * 2);
		result = truncateText(questionList->info.optionD);
		cout << result;

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
	string title = "Mon: " + subject.getSubject(subjectCode.c_str())->info.subjectName;
	int titlePosX = getCenterX(COLUMN_CENTER, title.length());
	gotoXY(DISTANCE_SIDEBAR + titlePosX, DISTANCE_HEADER + 2);
	cout << title;
}