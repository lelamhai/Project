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
    //// Khai báo class list
    //ClassList classList;

    //// Load lại danh sách lớp từ file lên và lưu vào classList
    //// Đầu vào: Classlist, tên file
    //loadClassListFromFile(classList, "classlist.dat");

    //Classroom class1 = *classList.classes[0];
    //// Gọi hàm này để lấy ra số lượng học sinh trong lớp 1
    //// Đầu vào: Struct Classroom
    //int countStudentInClass = getCountStudentInClass(class1);
    //cout << "So hoc sinh trong lop 3 la: " << countStudentInClass << endl;

    //// Gọi hàm này để xóa 1 class trong list
    //// Đầu vào: ClassList, Mã Lớp
    //bool isDeleted = deleteClass(classList, "C004");
    //cout << "Xoa thanh cong ? " << isDeleted << endl;

    ManageStudent hihi;
    bool ketQua = hihi.addStudent("hs", "duy", "dung", 'M', "123456");
    cout << ketQua << endl;

}
	
