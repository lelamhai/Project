#pragma once
#include "configApp.h"
#include "Popup.h"

class ToastMessage : public Popup
{
private:


public:
	void open();
	void close();
	ToastMessage();
	~ToastMessage();
};