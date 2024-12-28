#include "ContentExecute.h"
int ContentExecute::time = 0;
bool ContentExecute::isEnd = false;

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
}

void ContentExecute::drawContent()
{
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + PADDING, DISTANCE_HEADER + PADDING + PADDING);
	cout << "ESC: Tro Lai";
	box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING, WIDTH_INPUT - 5, HEIGHT_INPUT);

	string titleTimer = "Thoi Gian Lam Bai : " + to_string(time) + " Phut";
	int timePosX = getCenterX(COLUMN_CENTER, titleTimer.length());
	gotoXY(DISTANCE_SIDEBAR + MARGIN + timePosX, DISTANCE_HEADER + PADDING + PADDING);
	cout << titleTimer;

	string formatTime = "(Gio:Phut)";
	int posXTime = getCenterX(COLUMN_CENTER, formatTime.length());
	setColorText(ColorCode_Yellow);
	gotoXY(DISTANCE_SIDEBAR + posXTime + formatTime.length() - 1, DISTANCE_HEADER + PADDING + PADDING + PADDING + PADDING + PADDING);
	cout << formatTime;
	setColorText(ColorCode_White);

	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - to_string(countQuestion).length() - 12, DISTANCE_HEADER + PADDING);
	cout << "So Cau Hoi: ";

	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - to_string(countQuestion).length(), DISTANCE_HEADER + PADDING);
	cout << countQuestion;

	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - exam.getSubjectName().length() - 5, DISTANCE_HEADER + PADDING + PADDING + PADDING);
	cout << "Mon: ";

	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - exam.getSubjectName().length(), DISTANCE_HEADER + PADDING + PADDING + PADDING);
	cout << exam.getSubjectName();

	lineY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER, ROW_CENTER + 7);

	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER);
	cout << char(194);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + ROW_CENTER + 7);
	cout << char(193);


	int titleAnswer = getCenterX(COLUMN_RIGHT + 8, 14);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + titleAnswer, DISTANCE_HEADER + PADDING );
	cout << "Dap An Da Chon";

	lineXDot(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, 41, COLUMN_RIGHT + MARGIN);

	resultScore.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + 2, 43);
	resultScore.setContent("Diem: ");
	resultScore.display();

	int resultY = 3;
	// Right
	for (int i = 0; i < countQuestion; ++i) {
		listText.push_back(Text());
		listResults.push_back(' ');
	}
	loadDisplayChoice();

	// Bottom
	int tutorialY = 37;
	setColorText(ColorCode_DarkYellow);
	gotoXY(DISTANCE_SIDEBAR + MARGIN, tutorialY);
	cout << "Spacebar: Nop Bai";

	tutorialY += 2;
	gotoXY(DISTANCE_SIDEBAR + MARGIN, tutorialY);
	cout << "Enter: Chon Dap An";

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
	hThread = CreateThread(NULL, 0, countdown, this, 0, &ID);
	Sleep(100);
	executeExam();
	finishExam();
}

void ContentExecute::executeExam()
{
	Question* randomQuestionList = exam.getRandomQuestion();
	int contentY = 4;

	int indexQuestion = 0;
	int indexAnswer = -1;
	bool isLoadQuestion = false;

	loadQuestion(indexQuestion, indexAnswer, randomQuestionList);
	while (true)
	{
		if (isEnd)
		{
			return;
		}

		if (GetAsyncKeyState(VK_UP))
		{
			if (indexAnswer > 0)
			{
				indexAnswer--;
			}
			else {
				indexAnswer = 3;
			}
			isLoadQuestion = true;
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
			isLoadQuestion = true;
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			if (indexQuestion > 0)
			{
				indexQuestion--;
				if (listResults[indexQuestion] == ' ')
				{
					indexAnswer = -1;
				}

				if (listResults[indexQuestion] == 'A')
				{
					indexAnswer = 0;
				}

				if (listResults[indexQuestion] == 'B')
				{
					indexAnswer = 1;
				}

				if (listResults[indexQuestion] == 'C')
				{
					indexAnswer = 2;
				}

				if (listResults[indexQuestion] == 'D')
				{
					indexAnswer = 3;
				}

				cleanQuestion();
				isLoadQuestion = true;
			}
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			if (indexQuestion < countQuestion - 1)
			{
				indexQuestion++;
				if (listResults[indexQuestion] == ' ')
				{
					indexAnswer = -1;
				}

				if (listResults[indexQuestion] == 'A')
				{
					indexAnswer = 0;
				}

				if (listResults[indexQuestion] == 'B')
				{
					indexAnswer = 1;
				}

				if (listResults[indexQuestion] == 'C')
				{
					indexAnswer = 2;
				}

				if (listResults[indexQuestion] == 'D')
				{
					indexAnswer = 3;
				}

				cleanQuestion();
				isLoadQuestion = true;
			}
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		{
			if (indexAnswer == -1)
			{
				continue;
			}

			char c = ' ';
			if (indexAnswer == 0)
			{
				c = 'A';
			}

			if (indexAnswer == 1)
			{
				c = 'B';
			}

			if (indexAnswer == 2)
			{
				c = 'C';
			}

			if (indexAnswer == 3)
			{
				c = 'D';
			}

			listResults[indexQuestion] = c;
			displayChoiceQuestion(indexQuestion, indexAnswer);
			isLoadQuestion = true;
			if (indexQuestion < countQuestion - 1)
			{
				cleanQuestion();
				indexQuestion++;
				
				if (listResults[indexQuestion] == ' ')
				{
					indexAnswer = -1;
				}

				if (listResults[indexQuestion] == 'A')
				{
					indexAnswer = 0;
				}

				if (listResults[indexQuestion] == 'B')
				{
					indexAnswer = 1;
				}

				if (listResults[indexQuestion] == 'C')
				{
					indexAnswer = 2;
				}

				if (listResults[indexQuestion] == 'D')
				{
					indexAnswer = 3;
				}
			}
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
		{
			PopupNotification n;
			int x = getCenterX(COLUMN_CENTER, 50);
			n.setPosition(DISTANCE_SIDEBAR + MARGIN + x, 17);
			n.setTitle("Nop bai thi truoc khi tro lai trang truoc");
			n.open();
			n.handle();
			n.close();

			isLoadQuestion = true;
		}

		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			int deletePosX = getCenterX(COLUMN_CENTER, 50);
			PopupComfirm* p = new PopupComfirm();
			p->setTitle("Ban co muon nop bai thi khong?");
			int x = getCenterX(COLUMN_CENTER, 50);
			p->setPosition(deletePosX + 30, 17);
			p->open();
			p->handle();
			if (p->getResult())
			{
				SuspendThread(hThread);
				p->close();
				return;
			}
			p->close();
			delete p;

			isLoadQuestion = true;
		}

		if (isLoadQuestion)
		{
			loadQuestion(indexQuestion, indexAnswer, randomQuestionList);
			isLoadQuestion = false;
		}
		Sleep(80);
	}
}

void ContentExecute::loadQuestion(int indexQuestion, int indexAnswer, Question* randomQuestionList)
{
	int contentY = 4;
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING, DISTANCE_HEADER + PADDING + PADDING + contentY + 2);
	setColorText(ColorCode_White);
	cout << "Cau " << to_string(indexQuestion + 1) << ": " << randomQuestionList[indexQuestion].content;

	string listOption[4] = { 
		"A) " + randomQuestionList[indexQuestion].optionA,
		"B) " + randomQuestionList[indexQuestion].optionB,
		"C) " + randomQuestionList[indexQuestion].optionC,
		"D) " + randomQuestionList[indexQuestion].optionD
	};

	for (int i = 0; i < 4; i++)
	{
		contentY += 3;
		gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING, DISTANCE_HEADER + PADDING + PADDING + contentY + 2);
		
		if (indexAnswer == i)
		{
			setColorText(ColorCode_DarkGreen);
		}
		cout << listOption[i];
		setColorText(ColorCode_White);
	}
}

void ContentExecute::loadDisplayChoice()
{
	bool reset = true;
	int distance = 12;
	int step = 0;
	int resultY = 1;
	for (int j = 0; j < countQuestion; j++)
	{
		string content = "Cau " + to_string(j+1) + ": ";

		if (reset)
		{
			resultY = 1;
			step = 0;
			reset = false;
		}

		if (j <= 9)
		{
			listText[j].setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + PADDING + 7, DISTANCE_HEADER + PADDING + PADDING + resultY + (step * 3));
			if (j == 9)
			{
				reset = true;
			}
		}

		if (j > 9 && j <= 19)
		{
			listText[j].setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + PADDING + 7 + distance, DISTANCE_HEADER + PADDING + PADDING + resultY + (step * 3));
			if (j == 19)
			{
				reset = true;
			}
		}

		if (j > 19 && j <= 29)
		{
			listText[j].setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + PADDING + 7 + distance + distance, DISTANCE_HEADER + PADDING + PADDING + resultY + (step * 3));
			if (j == 29)
			{
				reset = true;
			}
		}

		if (j > 29)
		{
			listText[j].setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + PADDING + 7 + distance + distance + distance, DISTANCE_HEADER + PADDING + PADDING + resultY + (step * 3));
		}

		listText[j].setContent(content);
		listText[j].display();
		step++;
	}
}

void ContentExecute::displayChoiceQuestion(int indexQuestion, int indexAnswer)
{
	listText[indexQuestion].display();
	cout << listResults[indexQuestion];
}

void ContentExecute::finishExam()
{
	for (int i = 0; i < countQuestion; i++) {
		exam.setAnswer(i, listResults[i]);
	}

	loadResultExam();

	resultList result = exam.getAnsweredList();
	resultScore.display();
	cout << result.score;

	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			return;
		}
	}
}

void ContentExecute::loadResultExam()
{
	resultList result = exam.getAnsweredList();

	for (int i = 0; i < countQuestion; i++) {
		answer* p = result.answerList[i];
		listText[i].display();
		if (p->chosenAnswer == p->correctAnswer)
		{
			setColorText(ColorCode_DarkGreen);
		}
		else {
			setColorText(ColorCode_Red);
		}
		cout << p->chosenAnswer;
		setColorText(ColorCode_White);

		listText[i].updatePositionY(1);
		listText[i].setContent("Dap an: ");
		listText[i].display();
		cout << p->correctAnswer;
	}
}

DWORD WINAPI ContentExecute::countdown(LPVOID lpParam)
{
	int titleTime = getCenterX(COLUMN_CENTER, 5);
	while (time > 0) {
		int displayHours = time / 60;
		int displayMinutes = time % 60;
		
		gotoXY(DISTANCE_SIDEBAR + titleTime, DISTANCE_HEADER + PADDING + PADDING + 3);
		setColorText(ColorCode_DarkGreen);
		if (displayHours < 10)
			cout << "0";
		cout << displayHours << ":";

		if (displayMinutes < 10)
			cout << "0";
		cout << displayMinutes << "\r";
		cout.flush();
		setColorText(ColorCode_DarkWhite);

		this_thread::sleep_for(chrono::minutes(1));
		time--;
	}
	setColorText(ColorCode_DarkRed);
	gotoXY(DISTANCE_SIDEBAR + titleTime, DISTANCE_HEADER + PADDING + PADDING + 3);
	cout << "00:00";

	isEnd = true;
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