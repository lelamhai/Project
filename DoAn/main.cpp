#include "Page.h"
#include <iostream>
using namespace std;

int main()
{
	Page* p = new Page();
	p->currentPage = LOADING;
	p->main();
	delete p;

	system("pause");
	return 0;
}