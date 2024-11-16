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
	txtSearch.setContent("Tim");

	gotoXY(34 + 2, 10);
	txtSearch.display();
	box(34 + 2 + 4, 10 - 1, 20, 2);


	box(34 + 2, 10 + 2, 120, 30);
	box(34 + 100 + 30, 9, 40, 15);


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
	box(34 + 100 + 30, 26, 40, 17);
	lineX(34 + 100 + 30, 26 + 2, 40);
	gotoXY(34 + 100 + 30, 26 + 2);
	cout << char(195);
	gotoXY(34 + 100 + 30 + 40, 26 + 2);
	cout << char(180);
	setColorText(ColorCode_DarkWhite);

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
		"* Xem Chi Tiet Lop",
		"   F1->Len|Xuong->Spacebar"
	};

	for (int i = 0; i < 12; i++)
	{
		gotoXY(34 + 100 + 30 + 2, 26 + 3 + i);
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
		"Ma Lop",
		"Ten Lop",
		"Sinh Vien"
	};

	int classX = getCenterX(40, title[0].length());
	gotoXY(34 + 3 + classX, 10 + 2 + 1);
	cout << title[0];

	int nameX = getCenterX(40, title[1].length());
	gotoXY(34 + 3  + 40 + nameX, 10 + 2 + 1);
	cout << title[1];

	int countX = getCenterX(40, title[2].length());
	gotoXY(34 + 3 + 40 + 40 + countX, 10 + 2 + 1);
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
			ContentDetailClassroom* detail = new ContentDetailClassroom();
			detail->content();
			delete detail;
			currentClassroom = C_SELECT;
			cleanContent();
			displayContent();
			drawClassroom();
			girdContent();
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
			break;

		case C_EDIT:
			showCur(1);
			editData();
			cleanInput();
			//cleanTable();
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
	int moveMenu = 0;

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

		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
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

		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			currentClassroom = C_DETAIL;
			Sleep(150);
			return;
		}


		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			if (moveMenu != 0)
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
				}

				int classX = getCenterX(40, strlen(page.classList.classes[i]->classCode));
				gotoXY(34 + 3 + classX, 10 + 2 + 1 + 3 + (2 * i));
				cout << page.classList.classes[i]->classCode;

				int nameX = getCenterX(40, page.classList.classes[i]->className.length());
				gotoXY(34 + 3 + 40 + nameX, 10 + 2 + 1 + 3 + (2 * i));
				cout << page.classList.classes[i]->className;

				string countStr = to_string(getCountStudentOfList(page.classList.classes[i]->studentList));
				int countX = getCenterX(40, countStr.length());
				gotoXY(34 + 3 + 40 + 40 + countX, 10 + 2 + 1 + 3 + (2 * i));
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
	int moveMenu = 0;

	ManageClass nl;
	InputField inputClassroomCode;
	InputField inputClassroomName;
	Text text;

	int createPosX = 34 + 100 + 30 + 4 + 8 + 2;
	stateInput = FORM_CODE;
	while (true)
	{
		if (stateInput == FORM_CODE)
		{
			gotoXY(createPosX + inputClassroomCode.getText().length(), 12 + 1 + 1);
			inputClassroomCode.setMenu(moveMenu);
			inputClassroomCode.handleInput();
			moveMenu = inputClassroomCode.getMenu();

			switch (inputClassroomCode.getEndKey())
			{
			case ENTER:
				if (moveMenu != 0)
				{
					currentClassroom = C_EXIT;
					return;
				}

				if (inputClassroomCode.getText() != "" && inputClassroomName.getText() != "")
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
			gotoXY(createPosX + inputClassroomName.getText().length(), 12 + 1 + 3 + 1);
			inputClassroomName.setMenu(moveMenu);
			inputClassroomName.handleInput();
			moveMenu = inputClassroomName.getMenu();

			switch (inputClassroomName.getEndKey())
			{
			case ENTER:
				if (moveMenu != 0)
				{
					currentClassroom = C_EXIT;
					return;
				}

				if (inputClassroomCode.getText() != "" && inputClassroomName.getText() != "")
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

			default:
				break;
			}
		}

		if (stateInput == FORM_ENTER)
		{
			bool result = nl.addClass(inputClassroomCode.getText().c_str(), inputClassroomName.getText());
			
			if (result)
			{
				cleanTable();
				loadData();
				text.setContent("Them lop thanh cong!");

				int textPosX = getCenterX(40, text.getLenString());
				gotoXY(34 + 100 + 30 + textPosX, 19);
				text.display();
			}
			else 
			{
				string blankFillText;
				blankFillText.resize(36, ' ');

				gotoXY(34 + 120 + 8 + 2 + 1, 19);
				cout << blankFillText;

				text.setContent("Them lop that bai!");
				int textPosX = getCenterX(40, text.getLenString());
				gotoXY(34 + 100 + 30 + textPosX, 19);
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

void ContentClassroom::deleteData()
{
	int deletePosX = getCenterX(120, 50);
	PopupDelete pDelete;
	pDelete.setPosition(deletePosX + 30, 17);
	pDelete.open();
	pDelete.handle();

	if (pDelete.getMenu() != 0)
	{
		currentClassroom = C_EXIT;
		return;
	}

	pDelete.close();

	if (pDelete.getResult())
	{
		ManageClass nl;
		bool result = nl.deleteClass(classCode.c_str());
		if (result)
		{
			hover = 0;
		}

		cleanTable();
	}
	currentClassroom = C_SELECT;
	return;
}

void ContentClassroom::editData()
{
	int moveMenu = 0;
	ManageClass nl;

	Text text;
	InputField inputClassroomCode;
	InputField inputClassroomName;

	// Display data
	Classroom cl = nl.findClassByCode(classCode.c_str());
	inputClassroomCode.setText(classCode);
	inputClassroomName.setText(cl.className);

	int createPosX = 34 + 100 + 30 + 4 + 8 + 2;
	gotoXY(createPosX, 12 + 1 + 1);
	inputClassroomCode.display();

	stateInput = FORM_NAME;
	while (true)
	{
		if (stateInput == FORM_NAME)
		{
			gotoXY(createPosX, 12 + 1 + 3 + 1);
			inputClassroomName.display();
			inputClassroomName.handleInput();
			moveMenu = inputClassroomName.getMenu();

			switch (inputClassroomName.getEndKey())
			{
			case ENTER:
				if (moveMenu != 0)
				{
					currentClassroom = C_EXIT;
					return;
				}

				if (inputClassroomName.getText() != "")
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
			default:
				break;
			}
		}

		if (stateInput == FORM_ENTER)
		{
			bool result = nl.editClass(inputClassroomCode.getText().c_str(), inputClassroomName.getText());
			
			string blankFillText;
			blankFillText.resize(36, ' ');
			int x = getCenterX(40, 36);
			setColorText(ColorCode_Back);
			gotoXY(34 + 100 + 30 + x, 19);
			cout << blankFillText;
			
			if (result)
			{
				gotoXY(0, 0);
				cleanTable();
				loadData();
				text.setContent("Cap nhat thong tin thanh cong!");
			}
			else {
				gotoXY(0, 0);
				text.setContent("Cap nhat thong tin that bai!");
			}

			int textPosX = getCenterX(40, text.getLenString());

			gotoXY(34 + 100 + 30 + textPosX, 19);
			text.display();
			stateInput = FORM_NAME;
		}
	}
}

void ContentClassroom::findData()
{
	int moveMenu = 0;

	int currentX = 0;
	int currentY = 0;

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

			char s = _getch();
			int key = keySpecial(s);
			switch (s)
			{
			case ENTER:
				if (moveMenu != 0)
				{
					currentClassroom = C_EXIT;
					Sleep(150);
					return;
				}
				break;
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
	gotoXY(34 + 120 - 6, 10 + 28 + 5);
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
		gotoXY(34 + 3 + classX, 10 + 2 + 1 + 3 + (2 * i));
		cout << page.classList.classes[i]->classCode;

		int nameX = getCenterX(40, page.classList.classes[i]->className.length());
		gotoXY(34 + 3 + 40 + nameX, 10 + 2 + 1 + 3 + (2 * i));
		cout << page.classList.classes[i]->className;

		string countStr = to_string(getCountStudentOfList(page.classList.classes[i]->studentList));
		int countX = getCenterX(40, countStr.length());
		gotoXY(34 + 3 + 40 + 40 + countX, 10 + 2 + 1 + 3 + (2 * i));
		cout << countStr;
		setColorText(ColorCode_DarkWhite);
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

	string blankFillText;
	blankFillText.resize(36, ' ');
	int textPosX = getCenterX(40, 36);
	setColorText(ColorCode_Back);
	gotoXY(34 + 100 + 30 + textPosX, 19);
	cout << blankFillText;
}