#pragma once
#include "Button.h"

class ButtonEnter : public Button
{
public:
	void onKeyPress() override;
	bool checkKeyPress(char key) override;
	ButtonEnter();
	~ButtonEnter();

private:

};
