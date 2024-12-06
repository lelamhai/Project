#pragma once
#include "configApp.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "Popup.h"

class PopupFinishExam : public Popup
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
	PopupFinishExam();
	~PopupFinishExam();
};