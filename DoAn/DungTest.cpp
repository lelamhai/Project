#include "DungTest.h"


DungTest::DungTest()
{
}

DungTest::~DungTest()
{
}

void DungTest::main()
{
	ManageSubject subjects;
	ManageClass classes;

	//1. Ham kiem tra xem mon hoc co ton tai
	bool isSubjectExist = subjects.isSubjectExist("VL");
	cout << "Mon hoc ton tai " << isSubjectExist << endl;

	//2. Ham kiem tra xem lop co ton tai
	bool isClassExist = classes.isClassExist("");
	cout << "Lop hoc ton tai " << isClassExist << endl;


	//3. Ham kiem tra xem hoc sinh da ton tai
	bool isStudentExist = classes.isStudentExist("");
	cout << "Hoc sinh ton tai " << isStudentExist << endl;

	//4. Ham kiem tra xem lop co the xoa
	bool isClassCanDelete = classes.isClassCanDelete("C002");
	cout << "Lop co the xoa " << isClassCanDelete << endl;

	// 5. Ham kiem tra xem sinh vien co the xoa 
	bool isStudentCanDelete = classes.isStudentCanDelete("K23DTCN273");
	cout << "Hoc sinh co the xoa " << isStudentCanDelete << endl;

	// 6. Ham kiem tra xem lop co the xoa
	bool isSubjectCanDelete = subjects.isSubjectCanDelete("CTDL");
	cout << "Mon hoc Co the xoa " << isSubjectCanDelete << endl;

	// 7. Ham kiem tra xem cau hoi co the xoa
	bool isQuestionCanDelete = subjects.isQuestionCanDelete("CSDL", 65098);
	cout << "Cau hoi co the xoa " << isQuestionCanDelete << endl;
	
	//// 1. get subject name input "SUBJECT CODE"
	//string subjectName = subject.getSubject("CSDL")->info.subjectName;

	//// 2. get number question INPUT SUBJECT CODE
	//int numberQuestion = subject.countQuestionsInSubject("CSDL");

	//// 3. Load all data, input (subject code, "", 1);
	//QuestionPage questionPage = subject.searchQuestionInSubject("CSDL", "", 1);

	//// 4. Tu ket qua lay ra duoc danh sach cau hoi
	//PTRQUESTION questionList = questionPage.questionList;
	//
	//// 5. duyet du lieu de load ra
	//while (questionList != nullptr) {
	//	int maCauHoi = questionList->info.questionId;
	//	string noiDungCauHoi = questionList->info.content;
	//	string dapAnA = questionList->info.optionA;
	//	string dapAnB = questionList->info.optionB;
	//	string dapAnC = questionList->info.optionC;
	//	string dapAnD = questionList->info.optionD;
	//	char dapAnDung = questionList->info.answer;
	//	questionList = questionList->next;
	//}

	// Cac tham so khac trong question Page
	//struct QuestionPage {
	//	PTRQUESTION questionList = new NodeQuestion;
	//	int currentPage; // trang hiện tại
	//	int numberQuestionPerPage; // tổng số question trên 1 trang
	//	int totalPage; // tổng số trang
	//	int totalQuestions; // tổng số class
	//	int startIndex; // Số thứ tự bắt đầu của trang đó
	//	int endIndex; // số kết thúc của trang đó
	//};

	// 6. Hàm lấy câu hỏi ra để edit
	// Question questionFound = subject.getQuestionBySubjectCodeAndId("CSDL", 5731);

	// 7. Hàm thêm mới câu hỏi
	// bool isAdd = subject.addQuestionInSubject("CSDL", "CAU HOI", "DAP AN A", "DAP AN B", "DAP AN C", "DAP AN D", 'A');
	
	// 8. Hàm chỉnh sửa câu hỏi
	// bool isEdit = subject.editQuestionInSubject("CSDL", 18044, "CAU HOI - Update", "DAP AN A", "DAP AN B", "DAP AN C", "DAP AN D", 'A');
	
	// 9. Hàm xóa 1 câu hỏi
	// bool isDeleted = subject.deleteQuestionInSubject("CSDL", 893); // Mã môn, // Câu hỏi ID
	

}
	
