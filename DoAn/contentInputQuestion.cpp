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
	while (true)
	{

	}
}