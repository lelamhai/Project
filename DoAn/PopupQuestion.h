#pragma once
#include "configApp.h"
#include "Popup.h"
class PopupQuestion : public Popup
{
private:
	bool result;

public:
	void open();
	void createButtonYes();
	void createButtonNo();
	void handle();
	void close();
	bool getResult();
	PopupQuestion();
	~PopupQuestion();
};
