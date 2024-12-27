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

void ContentInputQuestion::setStateInputQuestion(StateInputQuestion state)
{
	currentInputQuestion = state;
}

void ContentInputQuestion::init(string code)
{
	subjectCode = code;
}

void ContentInputQuestion::setIdQuestion(int id)
{
	idQuestion = id;
}

void ContentInputQuestion::drawContent()
{
	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + PADDING, DISTANCE_HEADER + PADDING + PADDING);
	cout << "ESC: Tro Lai";
	box(DISTANCE_SIDEBAR + MARGIN, DISTANCE_HEADER + PADDING, WIDTH_INPUT - 5, HEIGHT_INPUT);

	string title = "Mon: " + subject.getSubject(subjectCode.c_str())->info.subjectName;
	int titleContent = getCenterX(MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, title.length());
	gotoXY(DISTANCE_SIDEBAR - MARGIN + titleContent, DISTANCE_HEADER + 2);
	cout << title;
	int y = 5;
	int lastY = 0;
	
	for (int i = 0; i < 6; i++)
	{
		listTitle.push_back(Text());
		listValidation.push_back(Text());
		listInput.push_back(InputField());

		listInput[i].useSpecial = true;
		listInput[i].setMaxLen(166);
		listInput[i].setMinLen(LENGTH_MIN);
		listInput[i].setPosition(DISTANCE_SIDEBAR + MARGIN + PADDING + PADDING + PADDING, DISTANCE_HEADER + 6 + (y * i));
		listInput[i].setFrame(168, HEIGHT_INPUT);
		if (i < 5)
		{
			listInput[i].drawBox();
		}
		

		listTitle[i].setColor(ColorCode_DarkGreen);
		listTitle[i].setPosition(DISTANCE_SIDEBAR + MARGIN + PADDING, DISTANCE_HEADER + 5 + (y * i));
		
		listValidation[i].setPosition(DISTANCE_SIDEBAR + MARGIN + PADDING + PADDING + PADDING, DISTANCE_HEADER + 9 + (y * i));
		listValidation[i].setContent(NOTIFICATION_EMPTY);
		listValidation[i].setColor(ColorCode_DarkYellow);

		lastY = DISTANCE_HEADER + 5 + (y * i);
	}

	listInput[5].useAnswer = true;
	listInput[5].setFrame(4, HEIGHT_INPUT);
	listInput[5].drawBox();
	listInput[5].setMaxLen(LENGTH_MIN-1);


	listTitle[0].setContent("* Noi Dung Chinh");
	listTitle[0].display();

	listTitle[1].setContent("* Noi Dung A");
	listTitle[1].display();

	listTitle[2].setContent("* Noi Dung B");
	listTitle[2].display();

	listTitle[3].setContent("* Noi Dung C");
	listTitle[3].display();

	listTitle[4].setContent("* Noi Dung D");
	listTitle[4].display();
	
	listInput[5].useSpecial = false;
	listTitle[5].setContent("* Dap An");
	listTitle[5].display();

	gotoXY(DISTANCE_SIDEBAR + MARGIN + PADDING + PADDING + PADDING + 5, lastY + 2);
	setColorText(ColorCode_DarkYellow);
	cout << "(A, B, C, D)";
	setColorText(ColorCode_White);

	posYMessage = lastY + 2;
	text.setPosition(DISTANCE_SIDEBAR + MARGIN, posYMessage);

	string titleEnter = "Enter";
	int titleEnterX = getCenterX(MARGIN + COLUMN_CENTER + MARGIN + COLUMN_RIGHT, title.length());
	gotoXY(DISTANCE_SIDEBAR + titleEnterX + 3, lastY + 5);
	cout << titleEnter;
	box(DISTANCE_SIDEBAR + titleEnterX, lastY + 4, 10, 2);
}

void ContentInputQuestion::content()
{
	drawContent();
	handle();
}

void ContentInputQuestion::handle()
{
	switch (currentInputQuestion)
	{
	case ContentInputQuestion::C_SELECT:
		break;
	case ContentInputQuestion::C_CREATE:
		showCur(1);
		createData();
		break;

	case ContentInputQuestion::C_EDIT:
		showCur(1);
		editData();
		break;

	case ContentInputQuestion::C_SEARCH:
		break;
	case ContentInputQuestion::C_DELETE:
		break;
	case ContentInputQuestion::C_DETAIL:
		break;
	case ContentInputQuestion::C_EXIT:
		return;
	default:
		break;
	}
}

void ContentInputQuestion::createData()
{
	stateInput = FORM_ContentMain;
	while (true)
	{
		if (stateInput == FORM_ContentMain)
		{
			listValidation[0].display();
			listInput[0].handleInput();
			listValidation[0].clean();

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

			case ESC:
				stageExit = 1;
				stateInput = FORM_EXIT;
				break;

			case TAB:
				stageExit = 0;
				stateInput = FORM_EXIT;
				break;

			case UP:
				stateInput = FORM_ContentAnswer;
				break;

			case DOWN:
				stateInput = FORM_ContentA;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ContentA)
		{
			listValidation[1].display();
			listInput[1].handleInput();
			listValidation[1].clean();
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

			case ESC:
				stageExit = 1;
				stateInput = FORM_EXIT;
				break;

			case TAB:
				stageExit = 0;
				stateInput = FORM_EXIT;
				break;

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
			listValidation[2].display();
			listInput[2].handleInput();
			listValidation[2].clean();
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

			case ESC:
				stageExit = 1;
				stateInput = FORM_EXIT;
				break;

			case TAB:
				stageExit = 0;
				stateInput = FORM_EXIT;
				break;

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
			listValidation[3].display();
			listInput[3].handleInput();
			listValidation[3].clean();
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

			case ESC:
				stageExit = 1;
				stateInput = FORM_EXIT;
				break;

			case TAB:
				stageExit = 0;
				stateInput = FORM_EXIT;
				break;

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
			listValidation[4].display();
			listInput[4].handleInput();
			listValidation[4].clean();
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

			case ESC:
				stageExit = 1;
				stateInput = FORM_EXIT;
				break;

			case TAB:
				stageExit = 0;
				stateInput = FORM_EXIT;
				break;

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
			listValidation[5].display();
			listInput[5].handleInput();
			listValidation[5].clean();
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

			case ESC:
				stageExit = 1;
				stateInput = FORM_EXIT;
				break;

			case TAB:
				stageExit = 0;
				stateInput = FORM_EXIT;
				break;

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
				showCur(0);
				int posX = getCenterX(COLUMN_CENTER, 50);
				ToastMessage m;
				m.setFrame(50, 5);
				m.setTitle(NOTIFICATION_INSERT_FINISH);
				m.setPosition(posX + 30, 17);
				m.open();
				m.close();
				cleanInput();
				cleanTable();
				showCur(0);
				drawContent();
			}
			else
			{
				text.setContent("Them Thong Tin That Bai!");
				int textPosX = getCenterX(COLUMN_RIGHT, text.getLenString());
				text.setPosition(DISTANCE_SIDEBAR + MARGIN + COLUMN_CENTER + MARGIN + PADDING + textPosX, posYMessage);
				text.setColor(ColorCode_DarkRed);
				text.display();
			}
			stateInput = FORM_ContentMain;
		}

		if (stateInput == FORM_EXIT)
		{
			return;
		}
	}
}

void ContentInputQuestion::editData()
{
	Question questionFound = subject.getQuestionBySubjectCodeAndId(subjectCode, idQuestion);
	listInput[0].setText(questionFound.content);
	listInput[0].display();

	listInput[1].setText(questionFound.optionA);
	listInput[1].display();

	listInput[2].setText(questionFound.optionB);
	listInput[2].display();

	listInput[3].setText(questionFound.optionC);
	listInput[3].display();

	listInput[4].setText(questionFound.optionD);
	listInput[4].display();

	string str(1, questionFound.answer);
	listInput[5].setText(str);
	listInput[5].display();

	while (true)
	{
		if (stateInput == FORM_ContentMain)
		{
			listValidation[0].display();
			listInput[0].handleInput();
			listValidation[0].clean();

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

			case ESC:
				stageExit = 1;
				stateInput = FORM_EXIT;
				break;

			case TAB:
				stageExit = 0;
				stateInput = FORM_EXIT;
				break;

			case DOWN:
				stateInput = FORM_ContentA;
				break;

			default:
				break;
			}
		}

		if (stateInput == FORM_ContentA)
		{
			listValidation[1].display();
			listInput[1].handleInput();
			listValidation[1].clean();

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

			case ESC:
				stageExit = 1;
				stateInput = FORM_EXIT;
				break;

			case TAB:
				stageExit = 0;
				stateInput = FORM_EXIT;
				break;

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
			listValidation[2].display();
			listInput[2].handleInput();
			listValidation[2].clean();

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

			case ESC:
				stageExit = 1;
				stateInput = FORM_EXIT;
				break;

			case TAB:
				stageExit = 0;
				stateInput = FORM_EXIT;
				break;

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
			listValidation[3].display();
			listInput[3].handleInput();
			listValidation[3].clean();

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
			
			case ESC:
				stageExit = 1;
				stateInput = FORM_EXIT;
				break;

			case TAB:
				stageExit = 0;
				stateInput = FORM_EXIT;
				break;

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
			listValidation[4].display();
			listInput[4].handleInput();
			listValidation[4].clean();
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

			case ESC:
				stageExit = 1;
				stateInput = FORM_EXIT;
				break;

			case TAB:
				stageExit = 0;
				stateInput = FORM_EXIT;
				break;

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
			listValidation[5].display();
			listInput[5].handleInput();
			listValidation[5].clean();

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

			case ESC:
				stageExit = 1;
				stateInput = FORM_EXIT;
				break;

			case TAB:
				stageExit = 0;
				stateInput = FORM_EXIT;
				break;

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
			bool result = subject.editQuestionInSubject(subjectCode.c_str(), idQuestion, listInput[0].getText(), listInput[1].getText(), listInput[2].getText(), listInput[3].getText(), listInput[4].getText(), listInput[5].getText()[0]);
			if (result)
			{
				text.clean();
				text.setContent(NOTIFICATION_UPDATE_FINISH);
				int textPosX = getCenterX(COLUMN_CENTER + MARGIN + COLUMN_RIGHT, text.getLenString());
				text.setPosition(DISTANCE_SIDEBAR + textPosX, posYMessage);
				text.setColor(ColorCode_DarkGreen);
			}
			else
			{
				text.clean();
				text.setContent(NOTIFICATION_UPDATE_FAIL);
				int textPosX = getCenterX(COLUMN_CENTER + MARGIN + COLUMN_RIGHT, text.getLenString());
				text.setPosition(DISTANCE_SIDEBAR + textPosX, posYMessage);
				text.setColor(ColorCode_DarkRed);
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

void ContentInputQuestion::cleanInput()
{
	for (int i = 0; i < 6; i++)
	{
		listInput[i].clean();
		listInput[i].setText("");

		if (listValidation[i].getLenString() != 0)
		{
			int textPosX = getCenterX(COLUMN_RIGHT, listValidation[i].getLenString());
			listValidation[i].clean();
			listValidation[i].updatePositionX(-textPosX);
			listValidation[i].setContent("");
		}
	}
	text.clean();
	text.setPosition(0, posYMessage);
}

int ContentInputQuestion::getExitInput()
{
	return stageExit;
}