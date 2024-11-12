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

    //ManageStudent hihi;
    //hihi.loadFromFile();
    //hihi.printStudents();

    ///------TEST FOR CLASS----------------
     
     ManageClass test; // Khởi tạo danh sách các lớp load data vào luôn
     //test.printClasses(); // In thử danh sách lớp hiện có
     
     //test.editClass("C003", "D23TXCN06-K Updated"); // Chỉnh sửa thông tin class và lưu vào file

     //test.addClass("C004", "D23TXCN07-K"); // Thêm class đồng thời lưu vào file
     
     ClassPage page = test.getClassPerPage(1); // Phân trang ở đây sẽ lấy class ở trang 1, mặc định 13 phần tử trả về ClassPage có đầy đủ thông số từ đây a sẽ load ra giao diện
     /* ClassList classList;
	    int currentPage; // trang hiện tại
	    int numberClassPerPage; // tổng số class trên 1 trang
	    int totalPage; // tổng số trang
	    int totalClass; // tổng số class
	    int startIndex; // Số thứ tự bắt đầu của trang đó
	    int endIndex; // số kết thúc của trang đó*/
     
     printClassPage(page); // Hàm này để in ra page có gì thuộc page nào

     // Test filter class // nhập vào keyword vào số trang, mặc định là 1 vì tìm cũng cần phân trang chứ
     ClassPage listFound = test.searchClass("C01", 1);
     
     printClassPage(listFound);

     // Hàm này chỉ dùng khi tính số lượng sinh viên bằng mã lớp (trong class)
     int countStudent = test.getCountSudentOfClass("C001");


     // Hàm này để lấy ra số lượng sinh viên trong 1 linked list bất kì (không cần class)
     int countStudentInList = getCountStudentOfList(page.classList.classes[0]->studentList);
        
     

    
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


    // -----------------------------TEST FOR SUBJECT----------------------------
    // ManageSubject testSubject;
    // testSubject.printAllSubjects();
    /*testSubject.addSubject("T01", "Toan roi rac");
    testSubject.addSubject("CNXHKH", "Chu nghia xa hoi khoa hoc");
    testSubject.addQuestion("T01", "Dau la phep toi uu nhat?", "A", "B", "C", "D", 'A');
    testSubject.printAllSubjects();
    cout << testSubject.getCountSubjects();
    testSubject.saveToFile();*/
    

}
	
