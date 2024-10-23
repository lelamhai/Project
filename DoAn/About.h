#pragma once
#include "Template.h"
class About : public PageTemplate
{
public:
	void main();
	void menu();
	void content();
	void title();
	About();
	~About();
};