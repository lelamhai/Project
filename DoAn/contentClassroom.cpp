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
	InputField inputStudent;
	Text txtSearch;
	Text txtPaging;
	txtSearch.setContent("Tim");
	txtPaging.setContent("Trang 1/2");

	gotoXY(34 + 2, 10);
	txtSearch.display();
	box(34 + 2 + 4, 10 - 1, 20, 2);


	box(34 + 2, 10 + 2, 120, 30);
	box(34 + 100 + 30, 9, 40, 15);

	gotoXY(34 + 120 - 6, 10 + 28 + 5);
	txtPaging.display();

	int posX = getCenterX(40, 9);
	gotoXY(posX + 34 + 100 + 30, 10);
	cout << "Thong Tin";

	lineX(34 + 100 + 30, 11, 40);
	gotoXY(34 + 100 + 30, 11);
	cout << char(195);
	gotoXY(34 + 100 + 30 + 40, 11);
	cout << char(180);

	gotoXY(34 + 100 + 30 + 3, 12 + 2);
	cout << "Ma Lop";
	box(34 + 100 + 30 + 4 + 8, 12 + 1, 24, 2);

	gotoXY(34 + 100 + 30 + 3, 12 + 1 + 1 + 3);
	cout << "Ten Lop";
	box(34 + 100 + 30 + 4 + 8, 12 + 1 + 3, 24, 2);

	int posFrameX = getCenterX(40, 11);
	box(posFrameX + 34 + 100 + 30, 12 + 1 + 3 + 5, 10, 2);

	/*lineX(34 + 100 + 30, 20, 40);
	gotoXY(34 + 100 + 30, 20);
	cout << char(195);
	gotoXY(34 + 100 + 30 + 40, 20);
	cout << char(180);*/


	int posEnterX = getCenterX(40, 5);
	gotoXY(posEnterX + 34 + 100 + 30, 12 + 1 + 3 + 6);
	cout << "Enter";

	gotoXY(posX + 34 + 100 + 30, 26 + 1);
	cout << "Huong Dan";

	setColorText(ColorCode_DarkYellow);
	box(34 + 100 + 30, 26, 40, 16);
	lineX(34 + 100 + 30, 26 + 2, 40);
	gotoXY(34 + 100 + 30, 26 + 2);
	cout << char(195);
	gotoXY(34 + 100 + 30 + 40, 26 + 2);
	cout << char(180);
	setColorText(ColorCode_DarkWhite);

	string note[] = {
		"F1: Tim Thong Tin Lop",
		"F2: Sua Thong Tin Lop",
		"INS: Them Thong Tin Lop",
		"DEL: Xoa Thong Tin Lop",
		"ENTER: Xem Chi Tiet Lop"
	};

	for (int i = 0; i < 5; i++)
	{
		gotoXY(34 + 100 + 30 + 3, 26 + 4 + i * 2);
		cout << note[i];
	}
}

void ContentClassroom::girdContent()
{
	lineX(34 + 2, 10 + 2 + 2, 120);
	gotoXY(34 + 2, 10 + 2 + 2);
	cout << char(195);
	gotoXY(34 + 2 + 120, 10 + 2 + 2);
	cout << char(180);

	string title[] = {
		"STT",
		"Ma Lop",
		"Ten Lop",
		"Sinh Vien"
	};

	int idX = getCenterX(10, title[0].length());
	gotoXY(34 + 3 + idX, 10 + 2 + 1);
	cout << title[0];

	int classX = getCenterX(40, title[1].length());
	gotoXY(34 + 3 + 10 + classX, 10 + 2 + 1);
	cout << title[1];

	int nameX = getCenterX(40, title[2].length());
	gotoXY(34 + 3 + 10 + 40 + nameX, 10 + 2 + 1);
	cout << title[2];

	int countX = getCenterX(30, title[3].length());
	gotoXY(34 + 3 + 10 + 40 + 40 + countX, 10 + 2 + 1);
	cout << title[3];
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
			break;

		case C_SEARCH:

			break;

		case C_EDIT:
			showCur(1);
			editData();
			break;

		case C_DELETE:
			showCur(0);
			deleteData();
			break;

		default:
			break;
		}
	}
}

void ContentClassroom::selectData()
{
	ManageClass nl;

	int hover = 0;
	int lastHover = -1;
	while (true)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			hover -= 1;
			Sleep(150);
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			hover += 1;
			Sleep(150);
		}

		if (GetAsyncKeyState(VK_F1) & 0x8000)
		{
			currentClassroom = C_SELECT;
			return;
		}

		if (GetAsyncKeyState(VK_F2) & 0x8000)
		{
			currentClassroom = C_CREATE;
			return;
		}

		if (GetAsyncKeyState(VK_F3) & 0x8000)
		{
			currentClassroom = C_EDIT;
			return;
		}

		if (GetAsyncKeyState(VK_DELETE) & 0x8000)
		{
			ClassPage page = nl.getClassPerPage(1);

			if (page.totalClass <= 0)
			{
				currentClassroom = C_SELECT;
				return;
			}

			currentClassroom = C_DELETE;
			return;
		}

		if (lastHover != hover)
		{
			ClassPage page = nl.getClassPerPage(1);

			for (int i = 0; i < page.classList.countClass; i++)
			{
				setColorText(ColorCode_DarkWhite);
				if (hover == i)
				{
					setColorText(ColorCode_DarkCyan);
					classCode = page.classList.classes[i]->classCode;
				}

				string iStr = to_string(i + 1);
				int idX = getCenterX(10, iStr.length());
				gotoXY(34 + 3 + idX, 10 + 2 + 1 + 3 + (2 * i));
				cout << i + 1;

				int classX = getCenterX(40, 10);
				gotoXY(34 + 3 + 10 + classX, 10 + 2 + 1 + 3 + (2 * i));
				cout << page.classList.classes[i]->classCode;

				int nameX = getCenterX(40, page.classList.classes[i]->className.length());
				gotoXY(34 + 3 + 10 + 40 + nameX, 10 + 2 + 1 + 3 + (2 * i));
				cout << page.classList.classes[i]->className;

				string countStr = to_string(getCountStudentOfList(page.classList.classes[i]->studentList));
				int countX = getCenterX(30, countStr.length());
				gotoXY(34 + 3 + 10 + 40 + 40 + countX, 10 + 2 + 1 + 3 + (2 * i));
				cout << countStr;
			}
			lastHover = hover;
		}
	}
}

void ContentClassroom::deleteData()
{
	int deletePosX = getCenterX(120, 50);
	PopupDelete pDelete;
	pDelete.setPosition(deletePosX + 30, 17);
	pDelete.open();
	pDelete.close();

	if (pDelete.getResult())
	{
		cleanTable();
		ManageClass nl;
		nl.deleteClass(classCode.c_str());
	}

	currentClassroom = C_SELECT;
	return;
}

void ContentClassroom::createData()
{
	ManageClass nl;
	InputField inputClassroomCode;
	InputField inputClassroomName;
	Text text;

	int createPosX = 34 + 100 + 30 + 4 + 8 + 2;
	stateInput = FORM_NAME;
	while (true)
	{
		if (stateInput == FORM_CODE)
		{
			gotoXY(createPosX + inputClassroomCode.getText().length(), 12 + 1 + 1);
			inputClassroomCode.handleInput();

			if (inputClassroomCode.getEndKey() == ENTER)
			{
				if (inputClassroomCode.getText() != "" && inputClassroomName.getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
			}

			if (inputClassroomCode.getEndKey() == F1)
			{
				currentClassroom = C_SELECT;
				return;
			}

			stateInput = FORM_NAME;
		}

		if (stateInput == FORM_NAME)
		{
			gotoXY(createPosX + inputClassroomName.getText().length(), 12 + 1 + 3 + 1);
			inputClassroomName.handleInput();
			if (inputClassroomName.getEndKey() == ENTER)
			{
				if (inputClassroomCode.getText() != "" && inputClassroomName.getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
			}

			if (inputClassroomName.getEndKey() == F1)
			{
				currentClassroom = C_SELECT;
				return;
			}

			stateInput = FORM_CODE;
		}

		if (stateInput == FORM_ENTER)
		{
			bool result = nl.addClass(inputClassroomCode.getText().c_str(), inputClassroomName.getText());
			if (result)
			{
				gotoXY(0, 0);
				cleanTable();
				loadData();
				text.setContent("Them lop thanh cong!");
			}
			else {
				gotoXY(0, 0);
				text.setContent("Them lop that bai!");
			}

			int textPosX = getCenterX(40, text.getLenString());

			gotoXY(34 + 100 + 30 + textPosX, 19);
			text.display();
			stateInput = FORM_CODE;
		}
	}
}

void ContentClassroom::editData()
{
	// Display data

	// Update data


}

void ContentClassroom::loadData()
{
	ManageClass nl;
	ClassPage page = nl.getClassPerPage(1);

	for (int i = 0; i < page.classList.countClass; i++)
	{
		setColorText(ColorCode_DarkWhite);

		string iStr = to_string(i + 1);
		int idX = getCenterX(10, iStr.length());
		gotoXY(34 + 3 + idX, 10 + 2 + 1 + 3 + (2 * i));
		cout << i + 1;

		int classX = getCenterX(40, 10);
		gotoXY(34 + 3 + 10 + classX, 10 + 2 + 1 + 3 + (2 * i));
		cout << page.classList.classes[i]->classCode;

		int nameX = getCenterX(40, page.classList.classes[i]->className.length());
		gotoXY(34 + 3 + 10 + 40 + nameX, 10 + 2 + 1 + 3 + (2 * i));
		cout << page.classList.classes[i]->className;

		string countStr = to_string(getCountStudentOfList(page.classList.classes[i]->studentList));
		int countX = getCenterX(30, countStr.length());
		gotoXY(34 + 3 + 10 + 40 + 40 + countX, 10 + 2 + 1 + 3 + (2 * i));
		cout << countStr;
	}
}

void ContentClassroom::cleanTable()
{
	int posX = 34 + 2 + 1;
	int posY = 10 + 2 + 3;

	string blankFill;
	blankFill.resize(118, ' ');

	for (int i = 0; i < 26; i++)
	{
		setColorText(ColorCode_Back);
		gotoXY(posX, posY + i);
		cout << blankFill;
		gotoXY(posX, posY + i);
	}
}

void ContentClassroom::cleanInput()
{
	int inputPosX = 34 + 100 + 30 + 4 + 8 + 2;

	string blankFill;
	blankFill.resize(21, ' ');

	setColorText(ColorCode_Back);
	gotoXY(inputPosX, 12 + 1 + 1);
	cout << blankFill;

	setColorText(ColorCode_Back);
	gotoXY(inputPosX, 12 + 1 + 3 + 1);
	cout << blankFill;

	int textPosX = getCenterX(40, 22);
	setColorText(ColorCode_Back);
	gotoXY(34 + 100 + 30 + textPosX, 19);
	cout << blankFill;
}