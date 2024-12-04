#include "ContentExecute.h"

ContentExecute::ContentExecute()
{
}

ContentExecute::~ContentExecute()
{
}

void ContentExecute::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	content();
}
void ContentExecute::init(string classCode, int count, int time)
{
	this->classCode = classCode;
	this->countQuestion = count;
	this->time;
}

void ContentExecute::drawContent()
{
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + PADDING, DISTANCE_HEADER + PADDING + PADDING);
	cout << "ESC: Tro Lai";
	box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING, WIDTH_INPUT - 5, HEIGHT_INPUT);

	int titleTime = getCenterX(COLUMN_CENTER, 26);
	gotoXY(DISTANCE_SIDEBAR + titleTime, DISTANCE_HEADER + PADDING + PADDING);
	cout << "Thoi Gian Lam Bai: 90 Phut";

	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - 6, DISTANCE_HEADER + PADDING + PADDING);
	cout << "Mon: Ly";

	//box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING * 4, COLUMN_CENTER, ROW_CENTER);

	lineY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER, ROW_CENTER + 7);

	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER);
	cout << char(194);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + ROW_CENTER + 7);
	cout << char(193);


	int titleAnswer = getCenterX(COLUMN_RIGHT + 8, 14);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + titleAnswer, DISTANCE_HEADER + PADDING + PADDING);
	cout << "Dap An Da Chon";
}

void ContentExecute::content()
{
	drawContent();
	handle();
}

void ContentExecute::handle()
{
	ManageExam exam;

	exam.setInputExam(classCode.c_str(), Singleton::getInstance()->role.c_str(), countQuestion, time);

	Question* randomQuestionList = exam.getRandomQuestion();

	int y = 3;
	int titleTime = getCenterX(COLUMN_CENTER, 2);
	gotoXY(DISTANCE_SIDEBAR + titleTime, DISTANCE_HEADER + PADDING + PADDING + y);
	setColorText(ColorCode_DarkGreen);
	cout << "00:00:00";
	setColorText(ColorCode_DarkWhite);
	
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING, 32);
	cout << "Chon dap an: A";

	// Bottom
	int tutorialY = 37;
	setColorText(ColorCode_DarkYellow);
	gotoXY(DISTANCE_SIDEBAR + MARGIN, tutorialY);
	cout << "Enter: Chon Dap An";

	tutorialY += 2;
	gotoXY(DISTANCE_SIDEBAR + MARGIN, tutorialY);
	cout << "Spacebar: Nop Bai";

	tutorialY += 2;
	gotoXY(DISTANCE_SIDEBAR + MARGIN, tutorialY);
	cout << "Phim Tren|Duoi: Lua Chon Dap An";

	tutorialY += 2;
	gotoXY(DISTANCE_SIDEBAR + MARGIN, tutorialY);
	cout << "Phim Trai|Phai: Chon Cau Sau|Truoc";
	setColorText(ColorCode_DarkWhite);


	int contentY = 4;
	int resultY = 3;

	int index = 0;
	bool isLoadQuest = true;
	while (true)
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			if (index > 0)
			{
				index--;
				cleanQuestion();
				isLoadQuest = true;
			}
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			if (index < countQuestion - 1)
			{
				index++;
				cleanQuestion();
				isLoadQuest = true;
			}
		}

		if (isLoadQuest)
		{
			gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING, DISTANCE_HEADER + PADDING + PADDING + contentY + 2);
			cout << "Cau " << to_string(index + 1) << ": " << randomQuestionList[index].content;
			contentY += 3;
			gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING, DISTANCE_HEADER + PADDING + PADDING + contentY + 2);
			cout << "A) " + randomQuestionList[index].optionA;
			contentY += 3;
			gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING, DISTANCE_HEADER + PADDING + PADDING + contentY + 2);
			cout << "B) " + randomQuestionList[index].optionB;
			contentY += 3;
			gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING, DISTANCE_HEADER + PADDING + PADDING + contentY + 2);
			cout << "C) " + randomQuestionList[index].optionC;
			contentY += 3;
			gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING, DISTANCE_HEADER + PADDING + PADDING + contentY + 2);
			cout << "D) " + randomQuestionList[index].optionD;

			isLoadQuest = false;
			Sleep(150);
			contentY = 4;
		}

		// Right
		resultY = 3;
		for (int j = 0; j < countQuestion; j++)
		{
			gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + PADDING + 7, DISTANCE_HEADER + PADDING + PADDING + resultY + (j * 2));
			cout << "Cau " << j + 1 << ": ";
		}
	}
}

void ContentExecute::cleanQuestion()
{
	int posX = DISTANCE_SIDEBAR + MARGIN + PADDING - 5;
	int posY = DISTANCE_HEADER + PADDING + PADDING + 4;

	string blankFill;
	blankFill.resize(COLUMN_CENTER + 5, ' ');
	for (int i = 0; i < 15; i++)
	{
		gotoXY(posX, posY + i);
		cout << blankFill;
	}
}