#include "ContentExecute.h"
int ContentExecute::timeExecute = 0;

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
void ContentExecute::initExecute(string classCode, int count, int time)
{
	this->classCode = classCode;
	this->countQuestion = count;
	this->time = time;

	this->timeExecute = time;
}

void ContentExecute::drawContent()
{
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + PADDING, DISTANCE_HEADER + PADDING + PADDING);
	cout << "ESC: Tro Lai";
	box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING, WIDTH_INPUT - 5, HEIGHT_INPUT);

	int titleTime = getCenterX(COLUMN_CENTER, 26);
	gotoXY(DISTANCE_SIDEBAR + titleTime, DISTANCE_HEADER + PADDING + PADDING);
	cout << "Thoi Gian Lam Bai: " << time << " Phut";

	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - exam.getSubjectName().length() - 5, DISTANCE_HEADER + PADDING + PADDING);
	cout << "Mon: ";

	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - exam.getSubjectName().length(), DISTANCE_HEADER + PADDING + PADDING);
	cout << exam.getSubjectName();

	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING, 32);
	cout << "Chon dap an: ";

	lineY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER, ROW_CENTER + 7);

	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER);
	cout << char(194);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + ROW_CENTER + 7);
	cout << char(193);


	int titleAnswer = getCenterX(COLUMN_RIGHT + 8, 14);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + titleAnswer, DISTANCE_HEADER + PADDING + PADDING);
	cout << "Dap An Da Chon";


	int resultY = 3;

	// Right
	vector<char> list(countQuestion);
	for (int i = 0; i < countQuestion; ++i) {
		list[i] = ' ';
	}

	resultY = 3;
	for (int j = 0; j < list.size(); j++)
	{
		gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + PADDING + 7, DISTANCE_HEADER + PADDING + PADDING + resultY + (j * 2));
		cout << "Cau " << j + 1 << ": " << list[j];
	}

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
}

void ContentExecute::content()
{
	exam.setInputExam(classCode.c_str(), Singleton::getInstance()->role.c_str(), countQuestion, time);
	drawContent();
	handle();
}

void ContentExecute::handle()
{
	DWORD ID = 0;

	hThread = CreateThread(NULL, 0, countdown, this, 0, &ID);
	Sleep(100);
	executeExam();
}

void ContentExecute::executeExam()
{
	Question* randomQuestionList = exam.getRandomQuestion();
	char answer[] = { 'A', 'B', 'C', 'D' };
	
	int contentY = 4;

	int indexQuestion = 0;
	int indexAnswer = 0;
	bool isLoadQuestion = false;
	bool isLoadAnswer = true;

	loadQuestion(indexQuestion, randomQuestionList);
	while (true)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			if (indexAnswer > 0)
			{
				indexAnswer--;
			}
			else {
				indexAnswer = 3;
			}
			isLoadAnswer = true;
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			if (indexAnswer < 4 - 1)
			{
				indexAnswer++;
			}
			else
			{
				indexAnswer = 0;
			}
			isLoadAnswer = true;
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			if (indexQuestion > 0)
			{
				indexQuestion--;
				indexAnswer = 0;
				cleanQuestion();
				contentY = 4;
				isLoadAnswer = true;
				isLoadQuestion = true;
			}
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			if (indexQuestion < countQuestion - 1)
			{
				indexQuestion++;
				indexAnswer = 0;
				cleanQuestion();
				contentY = 4;
				isLoadAnswer = true;
				isLoadQuestion = true;
			}
		}

		if (isLoadQuestion)
		{
			loadQuestion(indexQuestion, randomQuestionList);

			isLoadQuestion = false;
			Sleep(150);
		}

		/*if (isLoadAnswer)
		{
			setColorText(ColorCode_DarkGreen);
			gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + 13, 32);
			cout << answer[indexAnswer];
			isLoadAnswer = false;
			Sleep(150);
			setColorText(ColorCode_White);
		}*/
	}
}

void ContentExecute::loadQuestion(int index, Question* randomQuestionList)
{
	int contentY = 4;

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
}

DWORD WINAPI ContentExecute::countdown(LPVOID lpParam)
{
	int total_seconds = timeExecute * 60;

	while (total_seconds >= 0) {
		int hours = total_seconds / 3600;
		int minutes = (total_seconds % 3600) / 60;
		int seconds = total_seconds % 60;

		int titleTime = getCenterX(COLUMN_CENTER, 2);
		gotoXY(DISTANCE_SIDEBAR + titleTime, DISTANCE_HEADER + PADDING + PADDING + 3);
		setColorText(ColorCode_DarkGreen);
		if (hours < 10) 
			cout << "0";
		cout << hours << ":";

		if (minutes < 10) 
			cout << "0";
		cout << minutes << ":";

		if (seconds < 10) 
			cout << "0";
		cout << seconds << "\r";
		cout.flush();
		setColorText(ColorCode_DarkWhite);

		this_thread::sleep_for(chrono::seconds(1));
		total_seconds--;
	}
	return 0;
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