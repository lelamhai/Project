#include "DungTest.h"


DungTest::DungTest()
{
}

DungTest::~DungTest()
{
}

void DungTest::main()
{

    // Khai báo quản lý môn học
     ManageSubject subject;
     PTRSUBJECT a = subject.getSubject("CSDL");
    // Tìm môn học theo từ khóa và trang, nếu để từ khóa trống thì sẽ lấy hết
    //struct SubjectPage {
    //    PTRSUBJECT subjects = new SubjectNode;
    //    int currentPage; // trang hiện tại
    //    int numberSubjectPerPage; // tổng số trên 1 trang
    //    int totalPage; // tổng số trang
    //    int totalSubject; // tổng số
    //    int startIndex; // Số thứ tự bắt đầu của trang đó
    //    int endIndex; // số kết thúc của trang đó
    //};
    //SubjectPage a = subject.searchSubjects("", 1);
    //cout << "Tong so bao nhieu " << countSubjectsInList(a.subjects) << endl;
    //printSubjectInAVL(a.subjects);
    ////subject.printAllSubjects();
    //
    //// Hàm thêm mới môn học
    //subject.addSubject("MN", "Mon hoc");
    //// Hàm load dữ liệu lên để edit (input là subject code)
    //PTRSUBJECT subjectFound = subject.getSubject("CSDL");
    //cout << "Mon hoc tim thay: " << subjectFound->info.subjectName << endl;
    //// Hàm thêm môn học mới đầu vào subjectCode, subjectName
    //subject.editSubject("ANM", "An ninh mang - Updateee");

    //// Hàm xóa môn học
    //bool isDeleted = subject.deleteSubject("MTH");
    //cout << "Xoa thanh cong " << isDeleted << endl;
    ////subject.printAllSubjects();

    //QuestionPage page = subject.searchQuestionInSubject("CSDL", "hay", 1);
    //printQuestionsInList(page.questionList);
    
    // Cách duyệt cây 
    // PTRSUBJECT a =  subject.getListSubject();
    //void printSubjectInAVL(PTRSUBJECT root) { //root là phần tử trong class ManageSubject
    //    if (!root) return;
    //    printSubjectInAVL(root->left);
    //    cout << "Subject Code: " << root->info.subjectCode << ", Subject Name: " << root->info.subjectName << endl; (Thao tác gì thì thêm vào giữa chỗ này)
    //    cout << "So cau hoi " << subject.countQuestionsInSubject(root->info.subjectCode); << endl;
    //    printSubjectInAVL(root->right);
    //}

}
	
