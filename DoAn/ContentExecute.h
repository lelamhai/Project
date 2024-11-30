#pragma once
#include "configApp.h"
#include "Content.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

class ContentExecute : public Content
{
private:

public:
	void displayContent() override;
	ContentExecute();
	~ContentExecute();
};
