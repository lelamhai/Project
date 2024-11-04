#include "Page.h"
#include "HuyTest.h"
#include "DungTest.h"

using namespace std;

int main()
{	
	//---------------HAI----------------
	//Page* p = new Page();
	//p->setRun(PAGE_LOADING);
	//p->main();
	//delete p;
	//----------------------------------

	//----------------HUY ----------------
	//HuyTest* h = new HuyTest();
	//h->main();
	//delete h;
	//------------------------------------------
	
	//--------------------DUNG-------------------
	DungTest* shyni = new DungTest();
	shyni->main();
	delete shyni;


	//-------------------------------------------


	system("pause");
	return 0;
}