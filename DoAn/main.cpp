#include "Page.h"
#include "LoadingData.h"
#include "LoginData.h"
#include <iostream>
using namespace std;

int main()
{
	//Page* p = new Page();
	//p->setRun(PAGE_LOADING);
	//p->main();
	//delete p;

	PTRSTUDENT stdList1 = NULL;

	//createStudentList(stdList1);

	//saveFile_Student(stdList1, "test.txt");
	openFile_Student(stdList1, "StudentList.txt");

	Student* stdPtr;
	stdPtr = logIn(stdList1);

	cout << "Sinh vien da dang nhap thanh cong la Sv co ma " << stdPtr->studentCode << endl;



	system("pause");
	return 0;
}