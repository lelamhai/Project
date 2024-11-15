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
	InputField inputStudent;

	gotoXY(34 + 4, 10);
	cout << "ESC: Tro Lai";
	box(34 + 2, 10 - 1, 15, 2);

	int titlePosX = getCenterX(121, 12);
	gotoXY(34 + titlePosX, 10);
	cout << "Ten Lop: K23DTCN100-K";

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

void ContentDetailClassroom::content()
{
	cleanContent();
	drawClassroom();
	girdContent();
	handle();
}

void ContentDetailClassroom::handle()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_F12) & 0x8000)
		{
			int posX = getCenterX(120, 50);
			PopupTutorial pTutorial;
			pTutorial.setFrame(50,19);
			pTutorial.setPosition(posX + 30, 17);
			pTutorial.open();
			pTutorial.handle();
			pTutorial.close();
		}

		Sleep(150);
	}
}

void ContentDetailClassroom::cleanContent()
{
	string blankFill;
	blankFill.resize(WIDTH_CONTENT, ' ');
	for (int i = 0; i < HEIGHT_CONTENT; i++)
	{
		gotoXY(34, 9 + i);
		cout << blankFill;
	}
}