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
    hihi.loadFromFile();
    hihi.printStudents();



    //ManageClass test;
    //test.loadFromFile();
    //ClassList a = test.getClassPerPage(2,2);
    //cout << a.countClass;
    //test.printClasses();
    
}
	
