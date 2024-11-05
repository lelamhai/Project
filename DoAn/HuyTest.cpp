#include "HuyTest.h";


HuyTest::HuyTest()
{
}

HuyTest::~HuyTest()
{
}

void HuyTest::main()
{
	ManageStudent stdList1;
	stdList1.openFile_Student("StudentList.txt");
	cout << stdList1.logIn("K31", "333A");
	
	//PTRSTUDENT stdList1 = NULL;

	////createStudentList(stdList1);

	////saveFile_Student(stdList1, "test.txt");
	//openFile_Student(stdList1, "StudentList.txt");

	//Student* stdPtr;
	//stdPtr = logIn(stdList1);

	//cout << "Sinh vien da dang nhap thanh cong la Sv co ma " << stdPtr->studentCode << endl;
}