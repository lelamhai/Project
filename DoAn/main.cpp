#include "Page.h"

using namespace std;

int main()
{	
	Page* p = new Page();
	p->setRunPage(PAGE_LOADING);
	p->main();
	delete p;
	
	system("pause");
	return 0;
}