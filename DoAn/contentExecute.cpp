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
	this->count = count;
	this->time;
}

void ContentExecute::drawContent()
{
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + PADDING, DISTANCE_HEADER + PADDING + PADDING);
	cout << "ESC: Tro Lai";
	box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING, WIDTH_INPUT - 5, HEIGHT_INPUT);

	int titleTime = getCenterX(COLUMN_CENTER, 26);
	gotoXY(DISTANCE_SIDEBAR + titleTime, DISTANCE_HEADER + PADDING + PADDING);
	cout << "Thoi Gian Lam Bai: 90 phut";

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

	exam.setInputExam(classCode.c_str(), Singleton::getInstance()->role.c_str(), count, time);

	Question* randomQuestionList = exam.getRandomQuestion();

	int y = 3;
	int titleTime = getCenterX(COLUMN_CENTER, 2);
	gotoXY(DISTANCE_SIDEBAR + titleTime, DISTANCE_HEADER + PADDING + PADDING + y);
	setColorText(ColorCode_DarkGreen);
	cout << "00:00:00";
	setColorText(ColorCode_DarkWhite);
	

	int index = 1;

	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING, DISTANCE_HEADER + PADDING + PADDING + y + index + 2);
	cout << "Cau " << to_string(index + 1) << ": " << randomQuestionList[index].content;

	y += 3;
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING, DISTANCE_HEADER + PADDING + PADDING + y + index + 2);
	cout << "A) " + randomQuestionList[index].optionA;

	y += 3;
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING, DISTANCE_HEADER + PADDING + PADDING + y + index + 2);
	cout << "B) " + randomQuestionList[index].optionB;

	y += 3;
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING, DISTANCE_HEADER + PADDING + PADDING + y + index + 2);
	cout << "C) " + randomQuestionList[index].optionC;

	y += 3;
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING, DISTANCE_HEADER + PADDING + PADDING + y + index + 2);
	cout << "D) " + randomQuestionList[index].optionD;


	

	y += 6;
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING, DISTANCE_HEADER + PADDING + PADDING + y);
	cout << "Chon dap an: A";

	// Right
	int resultY = 3;
	string listQuestionResult[] = {
		"Cau 1: A",
		"Cau 2: A",
		"Cau 3: C",
		"Cau 4: A",
		"Cau 5: D",
		"Cau 6: A",
		"Cau 7: NULL",
		"Cau 8: A",
		"Cau 9: A",
		"Cau 10: NULL"
	};

	for (int j = 0; j < 10; j++)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + PADDING + 7, DISTANCE_HEADER + PADDING + PADDING + resultY + (j*2));
		cout << listQuestionResult[j];
	}


	// Bottom
	setColorText(ColorCode_DarkYellow);
	y += 4;
	gotoXY(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING + PADDING + y);
	cout << "Enter: Chon Dap An";
	
	y += 2;
	gotoXY(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING + PADDING + y);
	cout << "Spacebar: Nop Bai";

	y += 2;
	gotoXY(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING + PADDING + y);
	cout << "Phim Tren|Duoi: Lua Chon Dap An";

	y += 2;
	gotoXY(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING + PADDING + y);
	cout << "Phim Trai|Phai: Chon Cau Sau|Truoc";

	setColorText(ColorCode_DarkWhite);
	//_getch();
}