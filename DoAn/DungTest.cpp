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
	// Dùng hàm search để load dữ liệu, nếu keyword để trống, còn tìm kiếm thì nhập keyword vào
	QuestionPage questionPage = subject.searchQuestionInSubject("SUBJECT CODE", "Keyword", 1);

	// Dữ liệu trong class page để phân trang
	//struct QuestionPage {
	//	PTRQUESTION questionList = new NodeQuestion;
	//	int currentPage; // trang hiện tại
	//	int numberQuestionPerPage; // tổng số question trên 1 trang
	//	int totalPage; // tổng số trang
	//	int totalQuestions; // tổng số class
	//	int startIndex; // Số thứ tự bắt đầu của trang đó
	//	int endIndex; // số kết thúc của trang đó
	//};

	// Hàm lấy câu hỏi ra để edit
	// Question questionFound = subject.getQuestionBySubjectCodeAndId("CSDL", 5731);

	// Hàm thêm mới câu hỏi
	// bool isAdd = subject.addQuestionInSubject("CSDL", "CAU HOI", "DAP AN A", "DAP AN B", "DAP AN C", "DAP AN D", 'A');
	
	// Hàm chỉnh sửa câu hỏi
	// bool isEdit = subject.editQuestionInSubject("CSDL", 18044, "CAU HOI - Update", "DAP AN A", "DAP AN B", "DAP AN C", "DAP AN D", 'A');
	
	// Hàm xóa 1 câu hỏi
	// bool isDeleted = subject.deleteQuestionInSubject("CSDL", 893); // Mã môn, // Câu hỏi ID
	

}
	
