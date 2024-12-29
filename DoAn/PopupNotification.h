#pragma once
#include "Popup.h"

class PopupNotification:public Popup
{
private:
	bool enterHandled = true;

public:
	void setEnterHandled(bool flag);
	void open();
	void createButtonEnter();
	void handle();
	void close();
	PopupNotification();
	~PopupNotification();
};

