//#include "QUIZ_SYSTEM_H.h"
//#include <iostream>
//#include <windows.h>
//
//int main()
//{
//    /*-------------------TEST CLASS SERVICE-------------------*/
//    SetConsoleOutputCP(CP_UTF8);
//
//    ClassList classList;
//
//    Classroom classroom1;
//    strcpy_s(classroom1.classCode, "C001");
//    classroom1.className = "D23TXCN04-K";
//
//    Classroom classroom3;
//    strcpy_s(classroom3.classCode, "C003");
//    classroom3.className = "D23TXCN05-K";
//
//    PTRSTUDENT student1 = new NodeStudent;
//    strcpy_s(student1->info.studentCode, "S001");
//    strcpy_s(student1->info.firstName, "Vu");
//    strcpy_s(student1->info.lastName, "Duy Dung");
//    student1->info.gender = 'M';
//    student1->next = nullptr;
//
//
//
//    classroom1.studentList = student1;
//
//    Student s3 = { "003", "Le", "Cuong", 'M', "789" };
//    addStudent(classroom1.studentList, s3);
//
//    Student s4 = { "004", "Pham", "Thao", 'F', "101" };
//    addStudent(classroom1.studentList, s4);
//
//    Student s5 = { "005", "Hoang", "Nam", 'M', "112" };
//    addStudent(classroom3.studentList, s5);
//
//    addClassToClassList(classList, classroom1);
//    addClassToClassList(classList, classroom3);
//
//    cout << "Danh sach lop sau khi them: " << endl;
//
//    printClasses(classList);
//
//
//    // Lưu danh sách lớp xuống file
//    saveClassListToFile(classList, "classlist.dat");
//
//    // Xóa lớp khỏi danh sách
//    deleteClass(classList, "C001");
//
//    cout << "\nDanh sach lop sau khi xoa:" << endl;
//    printClasses(classList);
//
//    // Load lại danh sách lớp từ file
//    loadClassListFromFile(classList, "classlist.dat");
//
//    cout << "\nDanh sach lop sau khi load tu file:" << endl;
//    printClasses(classList);
//
//    // Sửa thông tin lớp
//    Classroom classroom2;
//    strcpy_s(classroom2.classCode, "C001");
//    classroom2.className = "Class A - Updated";
//    editClass(classList, "C001", classroom2);
//
//    cout << "\nDanh sach lop sau khi sua:" << endl;
//    printClasses(classList);
//
//    // Lưu danh sách lớp xuống file
//    saveClassListToFile(classList, "classlist.dat");
//}
