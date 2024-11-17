#include "HuyTest.h"

HuyTest::HuyTest()
{

}

HuyTest::~HuyTest()
{

}

void HuyTest::main() {
	//ManageSubject subjectList2;
	//subjectList.addSubject("VL", "vatly");
	//subjectList.addQuestion("VL", "do dai quang duong ", " = 1 ", " = 2 ", " = 3 ", " = 4 ", 'B');
	//subjectList.addQuestion("VL", "dong dien xoay chieu
	// ", " = 1 ", " = 2 ", " = 3 ", " = 4 ", 'D');
	//subjectList.printQuestionList("VL");

	//ManageQuestion questionList_Random = subjectList2.getRandomQuestion(2,"CSDL");
	//questionList_Random.printQuestions();
	//
	//cout << "Cau hoi cua mon hoc la:" << endl;
	//subjectList2.printQuestionList("CSDL");
	
	//ManageExam* test1 = new ManageExam();
	//test1->main();
	
	ManageExam exam1(3, "CSDL", 1); // 100 câu hỏi, mã môn học, số phút thi
	

	// Tạo promise và future cho kết quả thi
	std::promise<resultList> promiseResult;
	std::future<resultList> futureResult = promiseResult.get_future();

	// Tạo thread quản lý thời gian
	thread timerThread(&ManageExam::countDown, &exam1);

	// Tạo thread quản lý thi với promise để nhận kết quả
	thread examThread([&exam1, &promiseResult]() {
		// Lấy kết quả thi từ phương thức conductExam
		resultList result = exam1.conductExam();
		// Đặt kết quả vào promise
		promiseResult.set_value(result);
		});

	// Chờ hai thread hoàn thành
	timerThread.join();
	examThread.join();

	// Nhận kết quả từ future sau khi thread hoàn thành
	resultList examResult = futureResult.get();

	// In ra kết quả thi hoặc xử lý tiếp kết quả
	cout << "Ket qua thi cua sinh vien:" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Cau hoi " << examResult.answerList[i]->questionId << ": "
			<< "Chon dap an " << examResult.answerList[i]->chosenAnswer
			<< " - Dap an dung: " << examResult.answerList[i]->correctAnswer << endl;
	}

}

	// tạo một thread quản lý thời gian và một thread quản lý thi
	//thread timerThread(&ManageExam::countDown, &exam1);
	//thread examThread(&ManageExam::conductExam, &exam1);
	
	// chờ hai thread hoàn thành
	//timerThread.join();
	//examThread.join();
//}