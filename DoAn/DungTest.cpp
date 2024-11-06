#include "DungTest.h"


DungTest::DungTest()
{
}

DungTest::~DungTest()
{
}

void DungTest::main()
{
	    /*-------------------TEST CLASS SERVICE-------------------*/
    //SetConsoleOutputCP(CP_UTF8);

    ManageStudent hihi;
    hihi.addStudent("hs", "duy", "dung", 'M', "123456");
    hihi.addStudent("hs2", "thanh", "nhan", 'F', "123456");
    hihi.addStudent("hs3", "duy", "khoa", 'M', "12345776");
    hihi.printStudents();
    hihi.editStudent("hs", "duy", "dungggg", 'M', "12345776");
    hihi.printStudents();
    cout << "-----------------" << endl;

    PTRSTUDENT page = hihi.paginateStudents(1, 2);
    cout << getCountStudentOfList(page);


    //ManageClass test;
    //test.loadFromFile();
    //ClassList a = test.getClassPerPage(2,2);
    //cout << a.countClass;
    //test.printClasses();
    
}
	
