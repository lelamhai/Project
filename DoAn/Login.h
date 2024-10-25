#pragma once
#include "Template.h"

class Login : public PageTemplate
{
private:
	enum SelectInput
	{
		USERNAME	= 0,
		PASSWORD	= 1,
		CLICKENTER	= 2
	};
	SelectInput stateInput;

public:
	void main();
	void HeaderLogin();
	void drawBox();
	void drawUserName();
	void drawPassword();
	void textMessage(string mess);
	void drawButton();
	void formLogin();
	void inputUserName(string& input, int x, int y);
	void inputPassword(string& input, int x, int y);
	Login();
	~Login();

private:

};