#include "Page.h"
#include "HuyTest.h"
#include "DungTest.h"

using namespace std;

int main()
{	
	//---------------HAI----------------
//<<<<<<< HEAD
	//Page* p = new Page();
	//p->setRun(PAGE_LOADING);
	//p->main();
	//delete p;
	//----------------------------------
//=======
	Page* p = new Page();
	p->setRunPage(PAGE_LOADING);
	p->main();
	delete p;
	//----------p;------------------------
//>>>>>>> cbff50688a88d1d1a38e063e534e2d97f0302792

	//----------------HUY ----------------
	//HuyTest* h = new HuyTest();
	//h->main();
	//delete h;
	//------------------------------------------
	
	//--------------------DUNG-------------------
	/*DungTest* shyni = new DungTest();
	shyni->main();
	delete shyni;*/
	//-------------------------------------------


	system("pause");
	return 0;
}