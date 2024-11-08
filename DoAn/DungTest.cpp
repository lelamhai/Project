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



    // ManageClass test;
    // test.printClasses();
    
    // Lấy danh sách các lớp 
    //ClassList listClass = test.getClasses();

    // Lấy ra tổng các lớp
    // int countClass = test.getCountClass();

    // Tạo mới
    //bool isCreated = test.addStudentToClass("C001", "K23DTCN290", "Bui", "Thi Thanh Nhan", 'F', "123456");

    // Xóa học sinh của lớp
    // bool isdeleted = test.deleteStudentInClass("C001", "K23DTCN269");

    // test.printClasses();

    // Phân trang
    //ClassList a = test.getClassPerPage(2,2);
   
    //test.printClasses();

    // ManageSubject testSubject;
    // testSubject.printAllSubjects();
    /*testSubject.addSubject("T01", "Toan roi rac");
    testSubject.addSubject("CNXHKH", "Chu nghia xa hoi khoa hoc");
    testSubject.addQuestion("T01", "Dau la phep toi uu nhat?", "A", "B", "C", "D", 'A');
    testSubject.printAllSubjects();
    cout << testSubject.getCountSubjects();
    testSubject.saveToFile();*/
    

}
	
