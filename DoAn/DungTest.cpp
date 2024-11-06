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

    /*ManageStudent hihi;
    bool ketQua = hihi.addStudent("hs", "duy", "dung", 'M', "123456");
    cout << ketQua << endl;*/

    ManageClass test;
    test.loadFromFile();
    ClassList a = test.getClassPerPage(2,2);
    cout << a.countClass;
    test.printClasses();
    
}
	
