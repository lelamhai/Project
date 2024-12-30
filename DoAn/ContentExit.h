#pragma once
#include "mycolor.h"
#include "mydraw.h"
#include "mykeyboard.h"
#include "mywindows.h"

#include "Content.h"

#include <conio.h>
#include <vector>
#include <iostream>
using namespace std;

class ContentExit : public Content
{
private:

public:
	void displayContent() override;

	ContentExit();
	~ContentExit();
};
