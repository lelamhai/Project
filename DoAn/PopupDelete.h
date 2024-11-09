#pragma once
#include "Popup.h"
class PopupDelete : public Popup
{
private:
	bool result = 1;
public:
	void open();
	void createButtonYes();
	void createButtonNo();
	void handle();
	void close();
	bool getResult();
	PopupDelete();
	~PopupDelete();
};
