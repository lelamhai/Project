#include "HuyTest.h";


HuyTest::HuyTest()
{

}

HuyTest::~HuyTest()
{

}

void HuyTest::main()
{
	ManageQuestion mcq1;
	mcq1.addQuestion("mot cong mot ?", " = 1 ", " = 2 ", " = 3 ", " = 4 ", 'A');
	mcq1.saveToFile();
	cout << "Test" << endl;
	//ManageStudent stdList1;
	//stdList1.openFile_Student("StudentList.txt");
	//cout << stdList1.logIn("K31", "333A");
	
}