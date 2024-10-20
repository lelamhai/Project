#pragma once
#include "PageTemplate.h"

class ManageLop : public PageTemplate
{
protected:
	void content() override {
		cout << "Lop content" << endl;
	}
};