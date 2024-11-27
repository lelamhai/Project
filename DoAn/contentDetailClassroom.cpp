#include "ContentDetailClassroom.h"

ContentDetailClassroom::ContentDetailClassroom()
{
}

ContentDetailClassroom::~ContentDetailClassroom()
{
}

void ContentDetailClassroom::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	content();
}

void ContentDetailClassroom::drawClassroom()
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
	int y = DISTANCE_HEADER + PADDING + 5;
	for (int i = 0; i < 5; i++)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 3, y + (i * 3));
		cout << titleInput[i];
		box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING + 13, y + (i * 3) - 1, WIDTH_INPUT, HEIGHT_INPUT);
		posXRight = y + (i * 3);
	}

	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + WIDTH_INPUT + 10 - 2, 23);
	cout << "<-|->";

	lineX(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING + 2, COLUMN_RIGHT);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + PADDING, COLUMN_RIGHT, 25);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + 3);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, DISTANCE_HEADER + 3);
	cout << char(180);

	y = posXRight + 2;
	/*gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, y);
	cout << "Message";*/

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
		"F12: Xem Huong Dan Chi Tiet"
	};

	int contentY = tutorialY + 1;
	for (int i = 0; i < 1; i++)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING * 2, contentY + (i * 1));
		cout << note[i];
	}
	setColorText(ColorCode_DarkYellow);
	box(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, y, COLUMN_RIGHT, 7);
	lineX(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, tutorialY, COLUMN_RIGHT);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, tutorialY);
	cout << char(195);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, tutorialY);
	cout << char(180);
	setColorText(ColorCode_DarkWhite);
}

void ContentDetailClassroom::girdContent()
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

void ContentDetailClassroom::setClassCode(string classCode)
{
	this->classCode = classCode;
}

void ContentDetailClassroom::content()
{
	cleanContent();
	drawClassroom();
	girdContent();
	currentDetailClassroom = C_SELECT;
	handle();
}

void ContentDetailClassroom::handle()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_F12) & 0x0001)
		{
			int posX = getCenterX(120, 50);
			PopupTutorial pTutorial;
			pTutorial.setFrame(50,19);
			pTutorial.setPosition(posX + 30, 17);
			pTutorial.open();
			pTutorial.handle();
			pTutorial.close();
		}

		switch (currentDetailClassroom)
		{
		case ContentDetailClassroom::C_SELECT:
			showCur(0);
			selectData();
			break;
		case ContentDetailClassroom::C_CREATE:
			showCur(1);
			createData();
			break;
		case ContentDetailClassroom::C_EDIT:
			break;
		case ContentDetailClassroom::C_SEARCH:
			break;
		case ContentDetailClassroom::C_DELETE:
			break;
		case ContentDetailClassroom::C_DETAIL:
			break;
		case ContentDetailClassroom::C_EXIT:
			return;
		default:
			break;
		}


		Sleep(150);
	}
}

void ContentDetailClassroom::selectData()
{
	int moveMenu = 0;

	ManageClass test;
	StudentPage studentPage = test.searchStudentInCLass(classCode, "", pageNumber);
	

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
			/*page = nl.getClassPerPage(1);

			if (page.totalClass <= 0)
			{
				currentClassroom = C_SELECT;
				return;
			}*/

			currentDetailClassroom = C_DELETE;
			return;
		}

		if (GetAsyncKeyState(VK_PRIOR) & 0x8000)
		{
			moveMenu--;
			Sleep(150);
			continue;
		}

		if (GetAsyncKeyState(VK_NEXT) & 0x8000)
		{
			moveMenu++;
			Sleep(150);
			continue;
		}

		if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			if (moveMenu != 0)
			{
				currentDetailClassroom = C_EXIT;
				return;
			}
		}

		if (GetAsyncKeyState(VK_F12) & 0x0001)
		{
			showTutorial();
		}

		if (lastHover != hover)
		{
			int posX = 3;
			int i = 0;
			PTRSTUDENT temp = studentPage.studentList;
			while (temp != nullptr) 
			{
				setColorText(ColorCode_DarkWhite);
				if (hover == i)
				{
					setColorText(ColorCode_DarkGreen);
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
				cout << (temp->info.gender == 'M' ? "Nam" : "Nu");

				int passX = getCenterX(24, strlen(temp->info.password));
				gotoXY(34 + 3 + 24 + 24 + 24 + 24 + passX, 10 + 2 + 1 + posX + (2 * i));
				cout << temp->info.password;
				setColorText(ColorCode_DarkWhite);

				i++;
				temp = temp->next;
			}
			lastHover == hover;
			pagging();
		}
	}
}

void ContentDetailClassroom::createData()
{
	int moveMenu = 0;
	InputField inputStudentCode;
	InputField inputStudentLastName;
	InputField inputStudentFirstName;
	InputField inputStudentSex;
	InputField inputStudentPassword;
	Text text;

	int createPosX = 34 + 100 + 30 + 4 + 8 + 2;
	int createPosY = 12 + 2;

	ManageClass test;
	int i = 0;
	stateInput = FORM_CODE;
	while (true)
	{
		if (stateInput == FORM_CODE)
		{
			gotoXY(createPosX + inputStudentCode.getText().length(), createPosY);
			inputStudentCode.setMenu(moveMenu);
			inputStudentCode.handleInput();
			switch (inputStudentCode.getEndKey())
			{
			case ENTER:
				if (inputStudentCode.getText() != "" && inputStudentLastName.getText() != "" && inputStudentFirstName.getText() != "" && inputStudentPassword.getText() != "")
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

			case TAB:
				if (moveMenu != 0)
				{
					currentDetailClassroom = C_EXIT;
					return;
				}
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
			gotoXY(createPosX + inputStudentLastName.getText().length(), createPosY + 3);
			inputStudentLastName.setMenu(moveMenu);
			inputStudentLastName.handleInput();
			switch (inputStudentLastName.getEndKey())
			{
			case ENTER:
				if (inputStudentCode.getText() != "" && inputStudentLastName.getText() != "" && inputStudentFirstName.getText() != "" && inputStudentPassword.getText() != "")
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

			case TAB:
				if (moveMenu != 0)
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
			gotoXY(createPosX + inputStudentFirstName.getText().length(), createPosY + 6);
			inputStudentFirstName.setMenu(moveMenu);
			inputStudentFirstName.handleInput();
			switch (inputStudentFirstName.getEndKey())
			{
			case ENTER:
				if (inputStudentCode.getText() != "" && inputStudentLastName.getText() != "" && inputStudentFirstName.getText() != "" && inputStudentPassword.getText() != "")
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

			case TAB:
				if (moveMenu != 0)
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
			gotoXY(createPosX + inputStudentSex.getText().length(), createPosY + 9);
			inputStudentSex.setMenu(moveMenu);
			inputStudentSex.handleInput();
			switch (inputStudentSex.getEndKey())
			{
			case ENTER:
				if (inputStudentCode.getText() != "" && inputStudentLastName.getText() != "" && inputStudentFirstName.getText() != "" && inputStudentPassword.getText() != "")
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

			case TAB:
				if (moveMenu != 0)
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
			gotoXY(createPosX + inputStudentPassword.getText().length(), createPosY + 12);
			inputStudentPassword.setMenu(moveMenu);
			inputStudentPassword.handleInput();
			switch (inputStudentPassword.getEndKey())
			{
			case ENTER:
				if (inputStudentCode.getText() != "" && inputStudentLastName.getText() != "" && inputStudentFirstName.getText() != "" && inputStudentPassword.getText() != "")
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
				stateInput = FORM_CODE;
				break;

			case TAB:
				if (moveMenu != 0)
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
			bool result = test.addStudentToClass(classCode, inputStudentCode.getText(), inputStudentLastName.getText(), inputStudentFirstName.getText(), 'M', inputStudentPassword.getText());
			if (result)
			{
				loadData();

				text.setContent("Them sinh vien thanh cong!");
				int textPosX = getCenterX(40, text.getLenString());
				gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING + textPosX, 26 + 2);
				text.display();
			}
			else
			{
				string blankFillText;
				blankFillText.resize(36, ' ');

				gotoXY(34 + 120 + 8 + 2 + 1, 19);
				cout << blankFillText;

				text.setContent("Them sinh vien that bai!");
				int textPosX = getCenterX(40, text.getLenString());
				gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING + textPosX, 26 + 2);
				text.display();
			}
			stateInput = FORM_CODE;
		}
	}

}

void ContentDetailClassroom::loadData()
{
	ManageClass test;
	StudentPage studentPage = test.searchStudentInCLass(classCode, textSearch, pageNumber);
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

void ContentDetailClassroom::pagging()
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

void ContentDetailClassroom::showTitleStudent()
{
	ManageClass test;
	Classroom classFound = test.findClassByCode(classCode.c_str());
	string className = classFound.className;
	int total = test.getCountSudentOfClass(classCode.c_str());

	string count = to_string(total);
	string title = "Lop:" + className + " - Sinh Vien:" + count;

	int titlePosX = getCenterX(getConsoleWidth(), title.length());
	gotoXY(titlePosX - 12, 10);
	cout << title;
}

void ContentDetailClassroom::showTutorial()
{
	int posX = getCenterX(120, 50);
	PopupTutorial pTutorial;
	pTutorial.setFrame(50, 19);
	pTutorial.setPosition(posX + 30, 17);
	pTutorial.open();
	pTutorial.handle();
	pTutorial.close();
}