#include "HuyTest.h"


HuyTest::HuyTest()
{

}

HuyTest::~HuyTest()
{

}

void HuyTest::main()
{
	ManageQuestion mcq1;
	mcq1.addQuestion("Mot cong mot bang bao nhieu ? ", " = 1 ", " = 2 ", " = 3 ", " = 4 ", 'A');
	mcq1.addQuestion("Mot cong mot bang bao nhieu 1 ? ", " = 1 ", " = 2 ", " = 3 ", " = 4 ", 'A');
	mcq1.saveToFile();
	mcq1.printQuestions();
	//ManageStudent stdList1;
	//stdList1.openFile_Student("StudentList.txt");
	//cout << stdList1.logIn("K31", "333A");
	
}