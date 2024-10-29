#include "Page.h"
#include "ButtonEnter.h"
#include <iostream>
using namespace std;

int main()
{
	Page* p = new Page();
	p->currentPage = LOADING;
	p->main();
	delete p;

	/*ButtonEnter bEnter;
	while (true)
	{
		char s = _getch();
		if (bEnter.checkKeyPress(s))
		{
			cout << "Enter";
			break;
		}
	}*/

	/*InputField inputUser;
	gotoXY(5, 5);
	inputUser.handleInput();*/


	system("pause");
	return 0;
}