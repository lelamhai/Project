#pragma once
#include "Popup.h"

class PopupNotification:public Popup
{
private:
	

public:
	void open();
	void createButtonEnter();
	void handle();
	void close();
	PopupNotification();
	~PopupNotification();
};

