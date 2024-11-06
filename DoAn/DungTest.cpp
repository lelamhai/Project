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
    test.addClass("C001", "D23TXCN04-K");
    test.addClass("C002", "D23TXCN05-K");
    test.addClass("C003", "D23TXCN06-K");
    test.printClasses();

}
	
