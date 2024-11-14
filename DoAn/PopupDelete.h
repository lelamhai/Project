#pragma once
#include "Popup.h"
class PopupDelete : public Popup
{
private:
	bool result;
	int moveMenu = 0;
public:
	void open();
	void createButtonYes();
	void createButtonNo();
	void handle();
	void close();
	bool getResult();
	void setMenu(int move);
	int getMenu();
	PopupDelete();
	~PopupDelete();
};
