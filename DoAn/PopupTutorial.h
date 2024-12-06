#pragma once
#include "Popup.h"

class PopupTutorial : public Popup
{
private:
	int moveMenu = 0;
public:
	void content() override;
	void open();
	void createButtonEnter();
	void handle();
	void close();
	void setMenu(int move);
	int getMenu();
	PopupTutorial();
	~PopupTutorial();
};
