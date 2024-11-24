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
	ManageClass test;
	Classroom classFound = test.findClassByCode(classCode.c_str());
	
	int total = test.getCountSudentOfClass(classCode.c_str());

	InputField inputStudent;

	gotoXY(34 + 4, 10);
	cout << "ESC: Tro Lai";
	box(34 + 2, 10 - 1, 15, 2);

	string className = classFound.className;
	string count = to_string(total);
	string title = "Lop:" + className + " - Sinh Vien:" + count;

	int titlePosX = getCenterX(getConsoleWidth(), title.length());
	gotoXY(titlePosX - 12, 10);
	cout << title;

	gotoXY(34 + 2 + 120 - 20 - 4, 10);
	cout << "Tim";
	box(34 + 2 + 120 - 20, 10 - 1, 20, 2);

	box(34 + 2, 10 + 2, 120, 30);
	box(34 + 100 + 30, 9, 40, 25);


	int posX = getCenterX(40, 9);
	gotoXY(34 + 2 + 120 + 8 + posX, 10);
	cout << "Thong Tin";

	lineX(34 + 100 + 30, 11, 40);
	gotoXY(34 + 100 + 30, 11);
	cout << char(195);
	gotoXY(34 + 100 + 30 + 40, 11);
	cout << char(180);

	string titleInput[] = {
		"MSSV",
		"Ho",
		"Ten",
		"Phai",
		"Mat Khau"
	};

	int i;
	for (i = 0; i < 5; i++)
	{
		gotoXY(34 + 100 + 30 + 3, 12 + 2 + (i *3));
		cout << titleInput[i];
		box(34 + 100 + 30 + 4 + 8, 12 + 1 + (i * 3), 24, 2);
	}

	gotoXY(34 + 100 + 30 + 3, 12 + 1 + (i * 3));
	cout << "Message";

	int posEnterX = getCenterX(40, 5);
	gotoXY(34 + 2 + 120 + 8 + posEnterX, 12 + 1 + (i * 3) + 3);
	cout << "Enter";
	int boxPosEnterX = getCenterX(40, 10);
	box(34 + 2 + 120 + 8 + boxPosEnterX, 12 + 1 + (i * 3) + 2, 10, 2);


	int tutorialposX = getCenterX(40, 9);
	gotoXY(34 + 2 + 120 + 8 + tutorialposX, 12 + 1 + (i * 3) + 3 + 6);
	cout << "Huong Dan";
	setColorText(ColorCode_DarkYellow);
	box(34 + 2 + 120 + 8, 12 + 1 + (i * 3) + 3 + 5, 40, 7);
	lineX(34 + 2 + 120 + 8, 12 + 1 + (i * 3) + 3 + 7, 40);
	gotoXY(34 + 2 + 120 + 8, 12 + 1 + (i * 3) + 3 + 7);
	cout << char(195);
	gotoXY(34 + 2 + 120 + 8 + 40, 12 + 1 + (i * 3) + 3 + 7);
	cout << char(180);
	setColorText(ColorCode_DarkWhite);

	gotoXY(34 + 2 + 120 + 8 + 2, 12 + 1 + (i * 3) + 3 + 9);
	cout << "F12: Xem Huong Dan Chi Tiet";
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

	int i = 0;

	KeyState key;
	stateInput = FORM_CODE;
	while (true)
	{
		if (stateInput == FORM_CODE)
		{
			gotoXY(createPosX + inputStudentCode.getText().length(), createPosY);
			inputStudentCode.setMenu(moveMenu);
			inputStudentCode.handleInput();

			key = inputStudentCode.getEndKey();
			if (key == DOWN)
			{
				stateInput = FORM_LAST;
				continue;
			}
		}
		if (stateInput == FORM_LAST)
		{
			gotoXY(createPosX + inputStudentLastName.getText().length(), createPosY + 3);
			inputStudentLastName.setMenu(moveMenu);
			inputStudentLastName.handleInput();

			key = inputStudentLastName.getEndKey();
			if (key == UP)
			{
				stateInput = FORM_CODE;
			}

			if (key == DOWN)
			{
				stateInput = FORM_FIRST;
			}
		}

		if (stateInput == FORM_FIRST)
		{
			gotoXY(createPosX + inputStudentFirstName.getText().length(), createPosY + 6);
			inputStudentFirstName.setMenu(moveMenu);
			inputStudentFirstName.handleInput();

			key = inputStudentFirstName.getEndKey();
			if (key == UP)
			{
				stateInput = FORM_LAST;
			}

			if (key == DOWN)
			{
				stateInput = FORM_SEX;
			}
		}

		if (stateInput == FORM_SEX)
		{
			gotoXY(createPosX + inputStudentSex.getText().length(), createPosY + 9);
			inputStudentSex.setMenu(moveMenu);
			inputStudentSex.handleInput();

			key = inputStudentSex.getEndKey();
			if (key == UP)
			{
				stateInput = FORM_FIRST;
			}

			if (key == DOWN)
			{
				stateInput = FORM_PASSWORD;
			}
		}
		if (stateInput == FORM_PASSWORD)
		{
			gotoXY(createPosX + inputStudentPassword.getText().length(), createPosY + 12);
			inputStudentPassword.setMenu(moveMenu);
			inputStudentPassword.handleInput();

			key = inputStudentPassword.getEndKey();
			if (key == UP)
			{
				stateInput = FORM_SEX;
			}

		}
		if (stateInput == FORM_ENTER)
		{
			stateInput == FORM_CODE;
		}

		if (stateInput == FORM_EXIT)
		{
			return;
		}
	}

	

}