#include "Classroom.h"

Classroom::Classroom()
{
}

Classroom::~Classroom()
{
}

void Classroom::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	content();

}

void Classroom::content()
{
	drawClassroom();
	girdContent();

	//Popup
	int posX = getCenterX(120, 50);
	PopupDelete* p = new PopupDelete();
	p->setPosition(posX + 30, 17);
;	p->main();
	delete p;
}

void Classroom::drawClassroom()
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

	/*while (true)
	{
		if (GetAsyncKeyState(VK_F1) & 0x8000)
		{
			showCur(1);
			gotoXY(40, 13);
			inputStudent.handleInput();
		}
	}*/


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

	lineX(34 + 100 + 30, 20, 40);
	gotoXY(34 + 100 + 30, 20);
	cout << char(195);
	gotoXY(34 + 100 + 30 + 40, 20);
	cout << char(180);


	int posEnterX = getCenterX(40, 5);
	gotoXY(posEnterX + 34 + 100 + 30, 12 + 1 + 3 + 6);
	cout << "ENTER";

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
		gotoXY(34 + 100 + 30 + 3, 26 + 4 + i *2);
		cout << note[i];
	}
}

void Classroom::girdContent()
{
	lineX(34 + 2, 10 + 2 + 2, 120);
	gotoXY(34 + 2, 10 + 2 + 2);
	cout << char(195);
	gotoXY(34 + 2 + 120, 10 + 2 + 2);
	cout << char(180);

	string title[] = {
		"STT", 
		"Ma Lop", 
		"Ten Lop"
	};

	gotoXY(34 + 3 + 10, 10 + 2 + 1);
	cout << title[0];

	gotoXY(34 + 3 + 20 + 25, 10 + 2 + 1);
	cout << title[1];

	gotoXY(34 + 3 + 10 + 50 + 25, 10 + 2 + 1);
	cout << title[2];
}