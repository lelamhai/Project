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
	// Dùng hàm search để load dữ liệu, nếu keyword để trống, còn tìm kiếm
	QuestionPage questionPage = subject.searchQuestionInSubject("SUBJECT CODE", "Keyword", 1);

	// bool isAdd = subject.addQuestionInSubject("CSDL", "CAU HOI", "DAP AN A", "DAP AN B", "DAP AN C", "DAP AN D", 'A');
	// Hàm lấy câu hỏi ra để edit
	// Question questionFound = subject.getQuestionBySubjectCodeAndId("CSDL", 5731);
	// bool isEdit = subject.editQuestionInSubject("CSDL", 18044, "CAU HOI - Update", "DAP AN A", "DAP AN B", "DAP AN C", "DAP AN D", 'A');
	
	
	// bool isDeleted = subject.deleteQuestionInSubject("CSDL", 893); // Mã môn, // Câu hỏi ID
	

}
	
