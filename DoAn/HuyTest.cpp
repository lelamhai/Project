#include "HuyTest.h"


HuyTest::HuyTest()
{
}

HuyTest::~HuyTest()
{
}

void HuyTest::main()
{
	PTRSTUDENT stdList1 = NULL;

	//createStudentList(stdList1);

	//saveFile_Student(stdList1, "test.txt");
	openFile_Student(stdList1, "StudentList.txt");

	Student* stdPtr;
	stdPtr = logIn(stdList1);

	cout << "Sinh vien da dang nhap thanh cong la Sv co ma " << stdPtr->studentCode << endl;
}