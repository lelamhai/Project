#include "ContentInputQuestion.h"
ContentInputQuestion::ContentInputQuestion()
{
}

ContentInputQuestion::~ContentInputQuestion()
{
}

void ContentInputQuestion::displayContent()
{
	setColorText(ColorCode_DarkWhite);
	content();
}

void ContentInputQuestion::init(string code)
{
	subjectCode = code;
}

void ContentInputQuestion::drawClassroom()
{
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + PADDING, DISTANCE_HEADER + PADDING + PADDING);
	cout << "ESC: Tro Lai";
	box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING, WIDTH_INPUT - 5, HEIGHT_INPUT);

	string title = "Mon: Ly";
	int titleContent = getCenterX(MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, title.length());
	gotoXY(DISTANCE_SIDEBAR+titleContent, DISTANCE_HEADER + 2);
	cout << title;
	//box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + 4, COLUMN_CENTER + MARGIN + COLUMN_RIGHT + PADDING, ROW_CENTER + 2);

	for (int i = 0; i < 6; i++)
	{
		listTitle.push_back(Text());
		listInput.push_back(InputField());
	}

	int y = 5;
	int lastY = 0;
	listTitle[0].setContent("* Noi Dung Chinh");
	listTitle[1].setContent("* Noi Dung A");
	listTitle[2].setContent("* Noi Dung B");
	listTitle[3].setContent("* Noi Dung C");
	listTitle[4].setContent("* Noi Dung D");
	listTitle[5].setContent("* Dap An");

	for (int i = 0; i < 6; i++)
	{
		listTitle[i].setPosition(DISTANCE_SIDEBAR + MARGIN + PADDING, DISTANCE_HEADER + 5 + (y * i));
		
		setColorText(ColorCode_DarkGreen);
		listTitle[i].display();
		setColorText(ColorCode_White);
		lastY = DISTANCE_HEADER + 5 + (y * i);
	}

	for (int i = 0; i < 5; i++)
	{
		listInput[i].setPosition(DISTANCE_SIDEBAR + MARGIN + PADDING + PADDING + PADDING, DISTANCE_HEADER + 6 + (y * i));
		listInput[i].setFrame(168, HEIGHT_INPUT);
		listInput[i].drawBox();
	}

	listInput[5].setPosition(DISTANCE_SIDEBAR + MARGIN + PADDING + PADDING + PADDING + 7, lastY - 1);
	listInput[5].setFrame(4, HEIGHT_INPUT);
	listInput[5].drawBox();

	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + PADDING + PADDING + 15, lastY);
	setColorText(ColorCode_Yellow);
	cout << "(A, B, C, D)";
	setColorText(ColorCode_White);

	posYMessage = lastY + 2;
	text.setPosition(DISTANCE_SIDEBAR + MARGIN, posYMessage);
	/*text.setContent("lelamhai");
	text.display();*/


	string titleEnter = "Enter";
	int titleEnterX = getCenterX(MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, title.length());
	gotoXY(DISTANCE_SIDEBAR + titleEnterX + 3, lastY + 5);
	cout << titleEnter;
	box(DISTANCE_SIDEBAR + titleEnterX, lastY + 4, 10, 2);
}

void ContentInputQuestion::content()
{
	drawClassroom();
	handle();
}

void ContentInputQuestion::handle()
{
	stateInput = FORM_ContentMain;
	showCur(1);
	while (true)
	{
		if (stateInput == FORM_ContentMain)
		{
			listInput[0].handleInput();

			switch (listInput[0].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != ""
					&& listInput[3].getText() != "" && listInput[4].getText() != "" && listInput[5].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_ContentA;
				break;

			/*case F1:
				currentQuestion = C_SELECT;
				return;

			case F3:
				currentQuestion = C_SEARCH;
				return;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentQuestion = C_EXIT;
					return;
				}
				break;*/

			case DOWN:
				stateInput = FORM_ContentA;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ContentA)
		{
			listInput[1].handleInput();
			switch (listInput[1].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != ""
					&& listInput[3].getText() != "" && listInput[4].getText() != "" && listInput[5].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_ContentB;
				break;

			/*case F1:
				currentQuestion = C_SELECT;
				return;

			case F3:
				currentQuestion = C_SEARCH;
				return;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentQuestion = C_EXIT;
					return;
				}
				break;*/

			case UP:
				stateInput = FORM_ContentMain;
				break;

			case DOWN:
				stateInput = FORM_ContentB;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ContentB)
		{
			listInput[2].handleInput();

			switch (listInput[2].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != ""
					&& listInput[3].getText() != "" && listInput[4].getText() != "" && listInput[5].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_ContentC;
				break;

			/*case F1:
				currentQuestion = C_SELECT;
				return;

			case F3:
				currentQuestion = C_SEARCH;
				return;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentQuestion = C_EXIT;
					return;
				}
				break;*/

			case UP:
				stateInput = FORM_ContentA;
				break;

			case DOWN:
				stateInput = FORM_ContentC;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ContentC)
		{
			listInput[3].handleInput();

			switch (listInput[3].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != ""
					&& listInput[3].getText() != "" && listInput[4].getText() != "" && listInput[5].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_ContentD;
				break;

			/*case F1:
				currentQuestion = C_SELECT;
				return;

			case F3:
				currentQuestion = C_SEARCH;
				return;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentQuestion = C_EXIT;
					return;
				}
				break;*/

			case UP:
				stateInput = FORM_ContentB;
				break;

			case DOWN:
				stateInput = FORM_ContentD;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ContentD)
		{
			listInput[4].handleInput();
			switch (listInput[4].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != ""
					&& listInput[3].getText() != "" && listInput[4].getText() != "" && listInput[5].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_ContentAnswer;
				break;

			/*case F1:
				currentQuestion = C_SELECT;
				return;

			case F3:
				currentQuestion = C_SEARCH;
				return;

			case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentQuestion = C_EXIT;
					return;
				}
				break;*/

			case UP:
				stateInput = FORM_ContentC;
				break;

			case DOWN:
				stateInput = FORM_ContentAnswer;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ContentAnswer)
		{
			listInput[5].handleInput();

			switch (listInput[5].getEndKey())
			{
			case ENTER:
				if (listInput[0].getText() != "" && listInput[1].getText() != "" && listInput[2].getText() != ""
					&& listInput[3].getText() != "" && listInput[4].getText() != "" && listInput[5].getText() != "")
				{
					stateInput = FORM_ENTER;
					continue;
				}
				stateInput = FORM_ContentMain;
				break;

			/*case F1:
				currentQuestion = C_SELECT;
				return;

			case F3:
				currentQuestion = C_SEARCH;
				return;*/

			/*case TAB:
				if (Singleton::getInstance()->moveMenu != 0)
				{
					currentQuestion = C_EXIT;
					return;
				}
				break;*/

			case UP:
				stateInput = FORM_ContentD;
				break;

			case DOWN:
				stateInput = FORM_ContentMain;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ENTER)
		{
			bool result = subject.addQuestionInSubject(subjectCode.c_str(), listInput[0].getText(), listInput[1].getText(), listInput[2].getText(), listInput[3].getText(), listInput[4].getText(), listInput[5].getText()[0]);
			if (result)
			{
				/*cleanTable();
				loadData();*/
				cleanMessage(posYMessage);
				text.setContent("Them lop thanh cong!");
				text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, posYMessage);
				int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
				text.updatePositionX(textPosX);
			}
			else
			{
				cleanMessage(posYMessage);
				text.setContent("Them lop that bai!");
				text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING, posYMessage);
				int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
				text.updatePositionX(textPosX);
			}

			text.display();
			stateInput = FORM_ContentMain;

		}

		if (stateInput == FORM_EXIT)
		{
			return;
		}
	}
}