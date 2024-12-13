#include "DungTest.h"


DungTest::DungTest()
{
}

DungTest::~DungTest()
{
}

void DungTest::main()
{
	ManageSubject subject;
	
	// 1. get subject name input "SUBJECT CODE"
	string subjectName = subject.getSubject("CSDL")->info.subjectName;

	// 2. get number question INPUT SUBJECT CODE
	int numberQuestion = subject.countQuestionsInSubject("CSDL");

	// 3. Load all data, input (subject code, "", 1);
	QuestionPage questionPage = subject.searchQuestionInSubject("CSDL", "", 1);

	// 4. Tu ket qua lay ra duoc danh sach cau hoi
	PTRQUESTION questionList = questionPage.questionList;
	
	// 5. duyet du lieu de load ra
	while (questionList != nullptr) {
		int maCauHoi = questionList->info.questionId;
		string noiDungCauHoi = questionList->info.content;
		string dapAnA = questionList->info.optionA;
		string dapAnB = questionList->info.optionB;
		string dapAnC = questionList->info.optionC;
		string dapAnD = questionList->info.optionD;
		char dapAnDung = questionList->info.answer;
		questionList = questionList->next;
	}

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
	
