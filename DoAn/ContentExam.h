#pragma once
#include "Content.h"
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"
class ContentExam : public Content
{
private:

public:
	void displayContent() override;
	ContentExam();
	~ContentExam();
};

