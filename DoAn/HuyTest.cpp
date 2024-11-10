#include "HuyTest.h"


HuyTest::HuyTest()
{

}

HuyTest::~HuyTest()
{

}

void HuyTest::main()
{
	ManageSubject subjectList;
	subjectList.addSubject("VL", "vatly");
	subjectList.addQuestion("VL", "nhiet do la ", " = 1 ", " = 2 ", " = 3 ", " = 4 ", 'B');
	subjectList.addQuestion("CSDL", "hay lam ", " = 1 ", " = 2 ", " = 3 ", " = 4 ", 'D');
	subjectList.printQuestionList("VL");
	//subjectList.saveToFile();

	//ManageQuestion ;
	//mcq1.addQuestion("Mot cong mot bang bao nhieu ? ", " = 1 ", " = 2 ", " = 3 ", " = 4 ", 'A');
	//mcq1.addQuestion("Mot cong mot bang bao nhieu 1 ? ", " = 1 ", " = 2 ", " = 3 ", " = 4 ", 'A');
	//mcq1.addQuestion("co bao nhieu con ga ? ", " = 0 ", " = 2 ", " = 3 ", " = 4 ", 'B');
	//mcq1.saveToFile();
	//x.loadFromFile();
	//x.printQuestions();
	//cout << "Dap an la: " << x.getAnswer(2324) << endl;

	//ManageStudent stdList1;
	//stdList1.openFile_Student("StudentList.txt");
	//cout << stdList1.logIn("K31", "333A");
	
}