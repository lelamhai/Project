#include "ContentStudent.h"

ContentStudent::ContentStudent()
{
}

ContentStudent::~ContentStudent()
{
}

void ContentStudent::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	content();
}

void ContentStudent::drawClassroom()
{
	// Search
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + PADDING, DISTANCE_HEADER + PADDING + PADDING);
	cout << "ESC: Tro Lai";
	box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING, WIDTH_INPUT - 5, HEIGHT_INPUT);

	showTitleStudent();

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
		"MSSV",
		"Ho",
		"Ten",
		"Phai",
		"Mat Khau"
	};

	int posXRight = 0;
	int y = DISTANCE_HEADER + PADDING + 4;
	for (int i = 0; i < 5; i++)
	{
		listInput.push_back(InputField());
		listText.push_back(Text());

		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 3, y + (i * 4));
		cout << titleInput[i];

		listInput[i].setMinLen(LENGTH_MIN);
		listInput[i].setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING + 13, y + (i * 4) - 1);
		listInput[i].drawBox();

		listText[i].setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, y + (i * 4) + 2);
		posXRight = y + (i * 4);
	}

	listInput[0].notUseSpace = true;
	listInput[0].setMinLen(LENGTH_CODE);
	listInput[4].setMinLen(LENGTH_CODE);

	lineX(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING + 2, COLUMN_RIGHT);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING, COLUMN_RIGHT, 27);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + 3);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, DISTANCE_HEADER + 3);
	cout << char(180);

	y = posXRight + 2;
	posYMessage = y + 1;

	y = y + 2;
	int infoX = getCenterX(COLUMN_RIGHT, 11);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + infoX, y, 10, 2);
	int enterX = getCenterX(COLUMN_RIGHT, 5);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + enterX, y + 1);
	cout << "Enter";

	y = y + 5;
	// Tutorial
	int tutorialY = y;
	tutorialY += 1;
	int titleTutorial = getCenterX(COLUMN_RIGHT, 9);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + titleTutorial, tutorialY);
	cout << "Huong Dan";
	tutorialY += 1;

	string note[] = {
		"F12: Xem Huong Dan Chi Tiet",
		"Phim +: Nam",
		"Phim -: Nu"
	};

	int contentY = tutorialY + 1;
	for (int i = 0; i < 3; i++)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 2, contentY + (i * 1));
		cout << note[i];
	}
	setColorText(ColorCode_DarkYellow);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, y, COLUMN_RIGHT, 6);
	lineX(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, tutorialY, COLUMN_RIGHT);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, tutorialY);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, tutorialY);
	cout << char(180);
	setColorText(ColorCode_DarkWhite);
}

void ContentStudent::girdContent()
{
	lineX(34 + 2, 10 + 2 + 2, 120);
	gotoXY(34 + 2, 10 + 2 + 2);
	cout << char(195);
	gotoXY(34 + 2 + 120, 10 + 2 + 2);
	cout << char(180);

	string title[] = {
		"MSSV",
		"Ho",
		"Ten",
		"Phai",
		"Mat Khau"
	};

	int classX = getCenterX(24, title[0].length());
	gotoXY(34 + 3 + classX, 10 + 2 + 1);
	cout << title[0];

	int lastX = getCenterX(24, title[1].length());
	gotoXY(34 + 3 + 24 + lastX, 10 + 2 + 1);
	cout << title[1];

	int firstX = getCenterX(24, title[2].length());
	gotoXY(34 + 3 + 24 + 24 + firstX, 10 + 2 + 1);
	cout << title[2];

	int sexX = getCenterX(24, title[3].length());
	gotoXY(34 + 3 + 24 + 24 + 24 + sexX, 10 + 2 + 1);
	cout << title[3];

	int passX = getCenterX(24, title[4].length());
	gotoXY(34 + 3 + 24 + 24 + 24 + 24 + passX, 10 + 2 + 1);
	cout << title[4];
}

void ContentStudent::setClassCode(string classCode)
{
	this->classCode = classCode;
}

void ContentStudent::content()
{
	cleanContent();
	drawClassroom();
	girdContent();
	currentDetailClassroom = C_SELECT;
	handle();
}

void ContentStudent::handle()
{
	while (true)
	{
		switch (currentDetailClassroom)
		{
		case ContentStudent::C_SELECT:
			showCur(0);
			selectData();
			break;
		case ContentStudent::C_CREATE:
			showCur(1);
			createData();
			cleanInput();
			break;
		case ContentStudent::C_EDIT:
			showCur(1);
			editData();
			cleanInput();
			break;
		case ContentStudent::C_SEARCH:
			showCur(1);
			findData();
			break;
		case ContentStudent::C_DELETE:
			showCur(0);
			deleteData();
			break;
		case ContentStudent::C_DETAIL:
			break;
		case ContentStudent::C_EXIT:
			return;
		default:
			break;
		}
		Sleep(150);
	}
}

void ContentStudent::selectData()
{
	ManageClass test;
	StudentPage studentPage;

	studentPage = test.searchStudentInCLass(classCode, textSearch, pageNumber);

	int start = 0;
	int end = pageNumber * studentPage.numberStudentPerPage;

	if (pageNumber * studentPage.numberStudentPerPage < studentPage.totalStudent)
	{
		end = studentPage.numberStudentPerPage - 1;
	}
	else {
		end = (studentPage.numberStudentPerPage - (end - studentPage.totalStudent)) - 1;
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
				end = pageNumber * studentPage.numberStudentPerPage;
				if (pageNumber * studentPage.numberStudentPerPage < studentPage.totalStudent)
				{
					end = studentPage.numberStudentPerPage - 1;
				}
				else {
					end = (studentPage.numberStudentPerPage - (end - studentPage.totalStudent)) - 1;
				}
				lastHover = -1;
			}
			Sleep(150);
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			if (pageNumber < studentPage.totalPage)
			{
				cleanTable();
				pageNumber++;

				end = pageNumber * studentPage.numberStudentPerPage;
				if (pageNumber * studentPage.numberStudentPerPage < studentPage.totalStudent)
				{
					end = studentPage.numberStudentPerPage - 1;
				}
				else {
					end = (studentPage.numberStudentPerPage - (end - studentPage.totalStudent)) - 1;
				}
				hover = 0;
				lastHover = -1;
			}
			Sleep(150);
		}

		if (GetAsyncKeyState(VK_F1) & 0x0001)
		{
			currentDetailClassroom = C_SELECT;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_F2) & 0x0001)
		{
			if (studentPage.totalStudent <= 0)
			{
				continue;
			}

			currentDetailClassroom = C_EDIT;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_F3) & 0x0001)
		{
			currentDetailClassroom = C_SEARCH;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
		{
			currentDetailClassroom = C_EXIT;
			return;
		}

		if (GetAsyncKeyState(VK_INSERT) & 0x0001)
		{
			currentDetailClassroom = C_CREATE;
			Sleep(150);
			return;
		}

		if (GetAsyncKeyState(VK_DELETE) & 0x0001)
		{
			ManageClass test;
			StudentPage studentPage = test.searchStudentInCLass(classCode, "", pageNumber);

			if (studentPage.totalStudent <= 0)
			{
				currentDetailClassroom = C_SELECT;
				return;
			}

			currentDetailClassroom = C_DELETE;
			return;
		}

		if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			if (Singleton::getInstance()->moveMenu != 0)
			{
				currentDetailClassroom = C_EXIT;
				return;
			}
		}

		if (GetAsyncKeyState(VK_F12) & 0x8000)
		{
			showCur(0);
			showTutorial();
			loadData();
		}

		if (lastHover != hover)
		{
			int posX = 3;
			int i = 0;

			ManageClass test;
			StudentPage studentPage = test.searchStudentInCLass(classCode, textSearch, pageNumber);
			PTRSTUDENT temp = studentPage.studentList;

			if (temp == nullptr)
			{
				cleanTable();
			}

			while (temp != nullptr) 
			{
				setColorText(ColorCode_DarkWhite);
				if (hover == i)
				{
					setColorText(ColorCode_DarkGreen);
					studentCode = temp->info.studentCode;
				}

				int classX = getCenterX(24, strlen(temp->info.studentCode));
				gotoXY(34 + 3 + classX, 10 + 2 + 1 + posX +(2 * i));
				cout << temp->info.studentCode;

				int lastX = getCenterX(24, strlen(temp->info.lastName));
				gotoXY(34 + 3 + 24 + lastX, 10 + 2 + 1 + posX + (2 * i));
				cout << temp->info.lastName;

				int firstX = getCenterX(24, strlen(temp->info.firstName));
				gotoXY(34 + 3 + 24 + 24 + firstX, 10 + 2 + 1 + posX + (2 * i));
				cout << temp->info.firstName;

				int sexX = getCenterX(24, 3);
				gotoXY(34 + 3 + 24 + 24 + 24 + sexX, 10 + 2 + 1 + posX + (2 * i));
				cout << (temp->info.gender == 'M' ? "NAM" : "NU");

				int passX = getCenterX(24, strlen(temp->info.password));
				gotoXY(34 + 3 + 24 + 24 + 24 + 24 + passX, 10 + 2 + 1 + posX + (2 * i));
				cout << temp->info.password;
				setColorText(ColorCode_DarkWhite);

				i++;
				temp = temp->next;
			}
			pagging();
			lastHover = hover;
		}
	}
}

void ContentStudent::createData()
{
	for (int i = 0; i < 5; i++)
	{
		listInput[i].setText("");
	}

	string gender = "NAM";
	ManageClass test;
	int i = 0;
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

			listInput[0].handleInput();

			listText[0].clean();
			listText[0].updatePositionX(-textPosX);
			listText[0].setContent("");

			switch (listInput[0].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != "" && listInput[4].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_LAST;
				break;

			case F1:
				currentDetailClassroom = C_SELECT;
				return;

			case F3:
				currentDetailClassroom = C_SEARCH;
				return;

			case ESC:
				currentDetailClassroom = C_EXIT;
				return;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentDetailClassroom = C_EXIT;
					return;
				}
				break;

			case PGUP:
				stateInput == FORM_CODE;
				break;

			case PGDN:
				stateInput == FORM_CODE;
				break;

			case UP:
				stateInput = FORM_PASSWORD;
				break;

			case DOWN:
				stateInput = FORM_LAST;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_LAST)
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
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != "" && listInput[4].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_FIRST;
				break;

			case F1:
				currentDetailClassroom = C_SELECT;
				return;

			case F3:
				currentDetailClassroom = C_SEARCH;
				return;

			case UP:
				stateInput = FORM_CODE;
				break;

			case DOWN:
				stateInput = FORM_FIRST;
				break;

			case ESC:
				currentDetailClassroom = C_EXIT;
				return;

			case PGUP:
				stateInput == FORM_LAST;
				break;

			case PGDN:
				stateInput == FORM_LAST;
				break;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentDetailClassroom = C_EXIT;
					return;
				}
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_FIRST)
		{
			listText[2].setContent(NOTIFICATION_EMPTY);
			listText[2].setColor(ColorCode_DarkYellow);
			int textPosX = getCenterX(COLUMN_RIGHT, listText[2].getLenString());
			listText[2].updatePositionX(textPosX);
			listText[2].display();

			listInput[2].handleInput();

			listText[2].clean();
			listText[2].updatePositionX(-textPosX);
			listText[2].setContent("");
			switch (listInput[2].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != "" && listInput[4].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_SEX;
				break;

			case F1:
				currentDetailClassroom = C_SELECT;
				return;

			case F3:
				currentDetailClassroom = C_SEARCH;
				return;

			case UP:
				stateInput = FORM_LAST;
				break;

			case DOWN:
				stateInput = FORM_SEX;
				break;

			case ESC:
				currentDetailClassroom = C_EXIT;
				return;

			case PGUP:
				stateInput == FORM_FIRST;
				break;

			case PGDN:
				stateInput == FORM_FIRST;
				break;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentDetailClassroom = C_EXIT;
					return;
				}
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_SEX)
		{
			listText[3].setContent("Vui Long Dung Phim + Hoac -");
			listText[3].setColor(ColorCode_DarkYellow);
			int textPosX = getCenterX(COLUMN_RIGHT, listText[3].getLenString());
			listText[3].updatePositionX(textPosX);
			listText[3].display();

			if (listInput[3].getText() == "")
			{
				listInput[3].focus();
				listInput[3].setText(gender);
				listInput[3].display();
			}
			listInput[3].useGender = true;
			listInput[3].handleInput();

			listText[3].clean();
			listText[3].updatePositionX(-textPosX);
			listText[3].setContent("");


			switch (listInput[3].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != "" && listInput[4].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_PASSWORD;
				break;

			case F1:
				currentDetailClassroom = C_SELECT;
				return;

			case F3:
				currentDetailClassroom = C_SEARCH;
				return;

			case UP:
				stateInput = FORM_FIRST;
				break;

			case DOWN:
				stateInput = FORM_PASSWORD;
				break;

			case PGUP:
				stateInput == FORM_SEX;
				break;

			case PGDN:
				stateInput == FORM_SEX;
				break;

			case ESC:
				currentDetailClassroom = C_EXIT;
				return;

			case ADD:
				if (listInput[3].getText() == "NU")
				{
					listInput[3].clean();
					listInput[3].setText("NAM");
					listInput[3].display();
				}
				break;

			case SUBTRACT:
				if (listInput[3].getText() == "NAM")
				{
					listInput[3].clean();
					listInput[3].setText("NU");
					listInput[3].display();
				}
				break;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentDetailClassroom = C_EXIT;
					return;
				}
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_PASSWORD)
		{
			listText[4].setContent(NOTIFICATION_CODE);
			listText[4].setColor(ColorCode_DarkYellow);
			int textPosX = getCenterX(COLUMN_RIGHT, listText[4].getLenString());
			listText[4].updatePositionX(textPosX);
			listText[4].display();

			listInput[4].handleInput();

			listText[4].clean();
			listText[4].updatePositionX(-textPosX);
			listText[4].setContent("");
			switch (listInput[4].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != "" && listInput[4].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_CODE;
				break;

			case F1:
				currentDetailClassroom = C_SELECT;
				return;

			case F3:
				currentDetailClassroom = C_SEARCH;
				return;

			case UP:
				stateInput = FORM_SEX;
				break;

			case DOWN:
				stateInput = FORM_SEX;
				break;

			case ESC:
				currentDetailClassroom = C_EXIT;
				return;

			case PGUP:
				stateInput == FORM_PASSWORD;
				break;

			case PGDN:
				stateInput == FORM_PASSWORD;
				break;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentDetailClassroom = C_EXIT;
					return;
				}
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ENTER)
		{
			char sex;
			if (listInput[3].getText() == "NAM")
			{
				sex = 'M';
			}
			else {
				sex = 'F';
			}

			bool result = test.addStudentToClass(classCode, listInput[0].getText(), listInput[2].getText(), listInput[1].getText(), sex, listInput[4].getText());
			if (result)
			{
				showCur(0);
				int posX = getCenterX(COLUMN_CENTER, 50);
				ToastMessage m;
				m.setFrame(50, 5);
				m.setTitle(NOTIFICATION_INSERT_FINISH);
				m.setPosition(posX + 30, 17);
				m.open();
				m.close();
				cleanInput();
				cleanTable();

				loadData();
				pagging();
				showCur(1);
			}
			else
			{
				text.setContent("MSSV Da Ton Tai!");
				int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
				text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING + textPosX, posYMessage);
				text.setColor(ColorCode_DarkRed);
				text.display();
			}

			stateInput = FORM_CODE;
		}
	}
}

void ContentStudent::deleteData()
{
	ManageClass classes;
	int deletePosX = getCenterX(COLUMN_CENTER, 50);
	bool isStudentCanDelete = classes.isStudentCanDelete(studentCode.c_str());
	if (!isStudentCanDelete)
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
		PopupComfirm pDelete;
		pDelete.setPosition(deletePosX + 30, 17);
		pDelete.open();
		pDelete.handle();

		if (pDelete.getResult())
		{
			bool result = classes.deleteStudentInClass(classCode.c_str(), studentCode.c_str());
			if (result)
			{
				hover = 0;
				cleanTable();
			}
		}
		pDelete.close();
	}

	currentDetailClassroom = C_SELECT;
	return;
}

void ContentStudent::editData()
{
	ManageClass test;
	Student studentFound = test.findStudentByCode(studentCode, classCode);
	listInput[0].setText(studentFound.studentCode);
	listInput[1].setText(studentFound.lastName);
	listInput[2].setText(studentFound.firstName);
	if (studentFound.gender == 'M')
	{
		listInput[3].setText("NAM");
	}
	else {
		listInput[3].setText("NU");
	}
	listInput[4].setText(studentFound.password);

	for (int i = 0; i < 5; i++)
	{
		listInput[i].focus();
		listInput[i].display();
	}

	string gender = "NAM";
	stateInput = FORM_LAST;
	while (true)
	{
		if (stateInput == FORM_LAST)
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
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != "" && listInput[4].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_FIRST;
				break;

			case F1:
				currentDetailClassroom = C_SELECT;
				return;

			case F3:
				currentDetailClassroom = C_SEARCH;
				return;

			case DOWN:
				stateInput = FORM_FIRST;
				break;

			case ESC:
				currentDetailClassroom = C_EXIT;
				return;

			case PGUP:
				stateInput == FORM_LAST;
				break;

			case PGDN:
				stateInput == FORM_LAST;
				break;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentDetailClassroom = C_EXIT;
					return;
				}
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_FIRST)
		{
			listText[2].setContent(NOTIFICATION_EMPTY);
			listText[2].setColor(ColorCode_DarkYellow);
			int textPosX = getCenterX(COLUMN_RIGHT, listText[2].getLenString());
			listText[2].updatePositionX(textPosX);
			listText[2].display();

			listInput[2].handleInput();

			listText[2].clean();
			listText[2].updatePositionX(-textPosX);
			listText[2].setContent("");
			switch (listInput[2].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != "" && listInput[4].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_SEX;
				break;

			case F1:
				currentDetailClassroom = C_SELECT;
				return;

			case F3:
				currentDetailClassroom = C_SEARCH;
				return;

			case ESC:
				currentDetailClassroom = C_EXIT;
				return;

			case UP:
				stateInput = FORM_LAST;
				break;

			case DOWN:
				stateInput = FORM_SEX;
				break;


			case PGUP:
				stateInput == FORM_FIRST;
				break;

			case PGDN:
				stateInput == FORM_FIRST;
				break;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentDetailClassroom = C_EXIT;
					return;
				}
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_SEX)
		{
			if (listInput[3].getText() == "")
			{
				listInput[3].focus();
				listInput[3].setText(gender);
				listInput[3].display();
			}

			listText[3].setContent("Vui Long Dung Phim + Hoac -");
			listText[3].setColor(ColorCode_DarkYellow);
			int textPosX = getCenterX(COLUMN_RIGHT, listText[3].getLenString());
			listText[3].updatePositionX(textPosX);
			listText[3].display();

			listInput[3].useGender = true;
			listInput[3].handleInput();

			listText[3].clean();
			listText[3].updatePositionX(-textPosX);
			listText[3].setContent("");
			switch (listInput[3].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != "" && listInput[4].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_PASSWORD;
				break;

			case F1:
				currentDetailClassroom = C_SELECT;
				return;

			case F3:
				currentDetailClassroom = C_SEARCH;
				return;

			case UP:
				stateInput = FORM_FIRST;
				break;

			case DOWN:
				stateInput = FORM_PASSWORD;
				break;

			case ESC:
				currentDetailClassroom = C_EXIT;
				return;

			case PGUP:
				stateInput == FORM_SEX;
				break;

			case PGDN:
				stateInput == FORM_SEX;
				break;

			case ADD:
				if (listInput[3].getText() == "NU")
				{
					listInput[3].clean();
					listInput[3].setText("NAM");
					listInput[3].display();
				}
				break;

			case SUBTRACT:
				if (listInput[3].getText() == "NAM")
				{
					listInput[3].clean();
					listInput[3].setText("NU");
					listInput[3].display();
				}
				break;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentDetailClassroom = C_EXIT;
					return;
				}
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_PASSWORD)
		{
			listText[4].setContent(NOTIFICATION_CODE);
			listText[4].setColor(ColorCode_DarkYellow);
			int textPosX = getCenterX(COLUMN_RIGHT, listText[4].getLenString());
			listText[4].updatePositionX(textPosX);
			listText[4].display();

			listInput[4].handleInput();

			listText[4].clean();
			listText[4].updatePositionX(-textPosX);
			listText[4].setContent("");

			switch (listInput[4].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != "" && listInput[4].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_CODE;
				break;

			case F1:
				currentDetailClassroom = C_SELECT;
				return;

			case F3:
				currentDetailClassroom = C_SEARCH;
				return;

			case UP:
				stateInput = FORM_SEX;
				break;

			case DOWN:
				stateInput = FORM_LAST;
				break;

			case ESC:
				currentDetailClassroom = C_EXIT;
				return;

			case PGUP:
				stateInput == FORM_PASSWORD;
				break;

			case PGDN:
				stateInput == FORM_PASSWORD;
				break;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentDetailClassroom = C_EXIT;
					return;
				}
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ENTER)
		{
			char sex;
			if (listInput[3].getText() == "NAM")
			{
				sex = 'M';
			}
			else {
				sex = 'F';
			}

			bool result = test.editStudentInClass(classCode,studentCode, listInput[2].getText(), listInput[1].getText(), sex, listInput[4].getText());
			if (result)
			{
				int textPosX;
				if (text.getLenString() != 0)
				{
					textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
					text.clean();
					text.updatePositionX(-textPosX);
					text.setContent("");
				}

				loadData();
				text.setContent(NOTIFICATION_UPDATE_FINISH);
				textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
				text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING + textPosX, posYMessage);
				text.setColor(ColorCode_DarkGreen);
			}
			else
			{
				text.setContent(NOTIFICATION_UPDATE_FAIL);
				int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
				text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING + textPosX, posYMessage);
				text.setColor(ColorCode_DarkRed);
			}
			text.display();
			stateInput = FORM_LAST;
		}
	}
}

void ContentStudent::findData()
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
				currentDetailClassroom = C_SELECT;
				Sleep(150);
				return;
			}

			if (GetAsyncKeyState(VK_INSERT) & 0x0001)
			{
				currentDetailClassroom = C_CREATE;
				Sleep(150);
				return;
			}

			if (GetAsyncKeyState(VK_PRIOR) & 0x8000)
			{
				currentDetailClassroom = C_SELECT;
				return;
			}

			if (GetAsyncKeyState(VK_NEXT) & 0x8000)
			{
				currentDetailClassroom = C_SELECT;
				return;
			}

			if (GetAsyncKeyState(VK_TAB) & 0x8000)
			{
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentDetailClassroom = C_EXIT;
					Sleep(150);
					return;
				}
			}

			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
			{
				currentDetailClassroom = C_EXIT;
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

void ContentStudent::loadData()
{
	cleanTable();
	ManageClass test;
	StudentPage studentPage;
	studentPage = test.searchStudentInCLass(classCode, textSearch, pageNumber);
	PTRSTUDENT temp = studentPage.studentList;

	int posX = 3;
	int i = 0;
	while (temp != nullptr)
	{
		setColorText(ColorCode_DarkWhite);
		if (hover == i)
		{
			setColorText(ColorCode_DarkGreen);
		}

		int classX = getCenterX(24, strlen(temp->info.studentCode));
		gotoXY(34 + 3 + classX, 10 + 2 + 1 + posX + (2 * i));
		cout << temp->info.studentCode;

		int lastX = getCenterX(24, strlen(temp->info.lastName));
		gotoXY(34 + 3 + 24 + lastX, 10 + 2 + 1 + posX + (2 * i));
		cout << temp->info.lastName;

		int firstX = getCenterX(24, strlen(temp->info.firstName));
		gotoXY(34 + 3 + 24 + 24 + firstX, 10 + 2 + 1 + posX + (2 * i));
		cout << temp->info.firstName;

		int sexX = getCenterX(24, 3);
		gotoXY(34 + 3 + 24 + 24 + 24 + sexX, 10 + 2 + 1 + posX + (2 * i));
		cout << (temp->info.gender == 'M' ? "Nam" : "Nu");

		int passX = getCenterX(24, strlen(temp->info.password));
		gotoXY(34 + 3 + 24 + 24 + 24 + 24 + passX, 10 + 2 + 1 + posX + (2 * i));
		cout << temp->info.password;
		setColorText(ColorCode_DarkWhite);

		i++;
		temp = temp->next;
	}
}

void ContentStudent::pagging()
{
	ManageClass test;
	StudentPage studentPage = test.searchStudentInCLass(classCode, textSearch, pageNumber);
	PTRSTUDENT temp = studentPage.studentList;

	string blankFillText;
	blankFillText.resize(10, ' ');

	int currentPage = 0;
	if (studentPage.totalPage > 0)
	{
		currentPage = pageNumber;
	}

	setColorText(ColorCode_DarkWhite);
	string pageTitle = "Trang " + to_string(currentPage) + '/' + to_string(studentPage.totalPage);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - 8, 10 + 28 + 5);
	cout << pageTitle;
}

void ContentStudent::cleanInput()
{
	for (int i = 0; i < 5; i++)
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

void ContentStudent::showTitleStudent()
{
	ManageClass test;
	Classroom classFound = test.findClassByCode(classCode.c_str());
	string className = classFound.className;
	int total = test.getCountSudentOfClass(classCode.c_str());

	string count = to_string(total);
	string title = "Lop: " + className;

	int titlePosX = getCenterX(COLUMN_CENTER, title.length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN +titlePosX, 10);
	cout << title;
}

void ContentStudent::showTutorial()
{
	int posX = getCenterX(120, 50);
	PopupTutorial pTutorial;
	pTutorial.setFrame(50, 19);
	pTutorial.setPosition(posX + 30, 17);
	pTutorial.open();
	pTutorial.handle();
	pTutorial.close();
	currentDetailClassroom = C_SELECT;
}