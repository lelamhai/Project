#pragma once
#include "mydraw.h"
#include <iostream>
using namespace std;

#define WIDTH_CONTENT  172
#define HEIGHT_CONTENT  36
class Content
{
public:
	virtual void displayContent() = 0;
	void cleanContent();
	Content();
	~Content();
};