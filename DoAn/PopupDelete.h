#pragma once
#include "Popup.h"
class PopupDelete : public Popup
{
private:

public:
	void main();
	void createButtonYes();
	void createButtonNo();
	PopupDelete();
	~PopupDelete();
};
