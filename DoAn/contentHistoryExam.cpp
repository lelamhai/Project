#include "ContentHistoryExam.h"

ContentHistoryExam::ContentHistoryExam()
{
}

ContentHistoryExam::~ContentHistoryExam()
{
}

void ContentHistoryExam::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	content();
}

void ContentHistoryExam::init(string subject, string student)
{
	subjectCode = subject;
	studentCode = student;
}

void ContentHistoryExam::drawContent()
{
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + PADDING, DISTANCE_HEADER + PADDING + PADDING);
	cout << "ESC: Tro Lai";
	box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING, WIDTH_INPUT - 5, HEIGHT_INPUT);

	/*int titleTime = getCenterX(COLUMN_CENTER, 26);
	gotoXY(DISTANCE_SIDEBAR + titleTime, DISTANCE_HEADER + PADDING + PADDING);
	cout << "Thoi Gian Lam Bai: " << time << " Phut";*/

	string titleCountQuestion = "So Cau Hoi: ";
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - to_string(rs->totalQuestion).length() - titleCountQuestion.length(), DISTANCE_HEADER + PADDING);
	cout << titleCountQuestion;
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - to_string(rs->totalQuestion).length(), DISTANCE_HEADER + PADDING);
	cout << rs->totalQuestion;

	string titleName = "Ten: ";
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - ManageClass::getStudentNameFromCode(rs->studentCode).length() - titleName.length(), DISTANCE_HEADER + PADDING + PADDING);
	cout << titleName;
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - ManageClass::getStudentNameFromCode(rs->studentCode).length(), DISTANCE_HEADER + PADDING + PADDING);
	cout << ManageClass::getStudentNameFromCode(rs->studentCode);

	string titleMSSV = "MSSV: ";
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - strlen(rs->studentCode) - titleMSSV.length(), DISTANCE_HEADER + PADDING + PADDING + PADDING);
	cout << titleMSSV;
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - strlen(rs->studentCode), DISTANCE_HEADER + PADDING + PADDING + PADDING);
	cout << rs->studentCode;

	string titleSubject = "Mon: ";
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - ManageSubject::getSubjectNameFromCode(rs->subjectCode).length() - titleSubject.length(), DISTANCE_HEADER + PADDING + PADDING + PADDING + PADDING);
	cout << titleSubject;
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER - ManageSubject::getSubjectNameFromCode(rs->subjectCode).length(), DISTANCE_HEADER + PADDING + PADDING + PADDING + PADDING);
	cout << ManageSubject::getSubjectNameFromCode(rs->subjectCode);

	lineY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER, ROW_CENTER + 7);

	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER);
	cout << char(194);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN, DISTANCE_HEADER + ROW_CENTER + 7);
	cout << char(193);


	int titleAnswer = getCenterX(COLUMN_RIGHT + 8, 14);
	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + titleAnswer, DISTANCE_HEADER + PADDING);
	cout << "Dap An Da Chon";

	lineXDot(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, 41, COLUMN_RIGHT + MARGIN);

	gotoXY(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + 2, 43);
	cout<<"Diem: " << rs->score;


	// Bottom
	int tutorialY = 43;
	setColorText(ColorCode_DarkYellow);
	gotoXY(DISTANCE_SIDEBAR + MARGIN, tutorialY);
	cout << "Phim Trai|Phai: Chon Cau Sau|Truoc";
	setColorText(ColorCode_DarkWhite);
}

void ContentHistoryExam::content()
{
	rs = ManageScore::loadResultFromFile(subjectCode.c_str(), studentCode.c_str());
	drawContent();
	loadResult();
	handle();
}

void ContentHistoryExam::loadResult()
{
	bool reset = true;
	int distance = 12;
	int step = 0;
	int resultY = 1;
	int totalQuestion = rs->totalQuestion;
	for (int j = 0; j < totalQuestion; j++)
	{
		answer* p = rs->answerList[j];

		listText.push_back(Text());
		listResults.push_back(' ');
		string content = "Cau " + to_string(j + 1) + ": " + p->chosenAnswer;

		if (j==0)
		{
			if (p->chosenAnswer == ' ')
			{
				indexAnswer = -1;
			}
			else
			{
				if (p->chosenAnswer == 'A')
				{
					indexAnswer = 0;
				}

				if (p->chosenAnswer == 'B')
				{
					indexAnswer = 1;
				}

				if (p->chosenAnswer == 'C')
				{
					indexAnswer = 2;
				}

				if (p->chosenAnswer == 'D')
				{
					indexAnswer = 3;
				}
			}
		}


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

		listText[j].updatePositionY(1);
		listText[j].setContent("Dap an: ");
		listText[j].display();
		cout << p->correctAnswer;
		step++;
	}
}

void ContentHistoryExam::handle()
{
	questionRecordList q;
	int countQuestion = rs->totalQuestion;
	int indexQuestion = 0;
	bool isLoadQuestion = true;
	while (true)
	{
		if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			if (Singleton::getInstance()->moveMenu != 0)
			{
				return;
			}
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			if (indexQuestion > 0)
			{
				indexQuestion--;
				answer* p = rs->answerList[indexQuestion];
				if (p->chosenAnswer == ' ')
				{
					indexAnswer = -1;
				}
				else 
				{
					if (p->chosenAnswer == 'A')
					{
						indexAnswer = 0;
					}

					if (p->chosenAnswer == 'B')
					{
						indexAnswer = 1;
					}

					if (p->chosenAnswer == 'C')
					{
						indexAnswer = 2;
					}

					if (p->chosenAnswer == 'D')
					{
						indexAnswer = 3;
					}
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
				answer* p = rs->answerList[indexQuestion];
				if (p->chosenAnswer == ' ')
				{
					indexAnswer = -1;
				}
				else
				{
					if (p->chosenAnswer == 'A')
					{
						indexAnswer = 0;
					}

					if (p->chosenAnswer == 'B')
					{
						indexAnswer = 1;
					}

					if (p->chosenAnswer == 'C')
					{
						indexAnswer = 2;
					}

					if (p->chosenAnswer == 'D')
					{
						indexAnswer = 3;
					}
				}
				cleanQuestion();
				isLoadQuestion = true;
			}
		}

		if (isLoadQuestion)
		{
			q = ManageScore::getQuestionExamRecord(subjectCode.c_str(), studentCode.c_str());
			loadQuestion(indexQuestion, indexAnswer, q);
			isLoadQuestion = false;
		}
	}
}

void ContentHistoryExam::loadQuestion(int indexQuestion, int indexAnswer, questionRecordList listQuestion)
{
	int contentY = 4;
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING, DISTANCE_HEADER + PADDING + PADDING + contentY + 2);
	setColorText(ColorCode_White);
	cout << "Cau " << to_string(indexQuestion + 1) << ": " << listQuestion.list[indexQuestion].content;

	string listOption[4] = {
		"A) " + listQuestion.list[indexQuestion].optionA,
		"B) " + listQuestion.list[indexQuestion].optionB,
		"C) " + listQuestion.list[indexQuestion].optionC,
		"D) " + listQuestion.list[indexQuestion].optionD
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

void ContentHistoryExam::cleanQuestion()
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