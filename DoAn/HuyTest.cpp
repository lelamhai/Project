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
	//subjectList.addQuestion("VL", "dong dien xoay chieu ", " = 1 ", " = 2 ", " = 3 ", " = 4 ", 'D');
	//subjectList.printQuestionList("VL");

	//ManageQuestion questionList_Random = subjectList2.getRandomQuestion(2,"CSDL");
	//questionList_Random.printQuestions();
	//
	//cout << "Cau hoi cua mon hoc la:" << endl;
	//subjectList2.printQuestionList("CSDL");
	
	//ManageExam* test1 = new ManageExam();
	//test1->main();
	
	ManageExam exam1(3, "CSDL", 1); // 100 câu hỏi, mã môn học, số phút thi
	

	// tạo một thread quản lý thời gian và một thread quản lý thi
	thread timerThread(&ManageExam::countDown, &exam1);
	thread examThread(&ManageExam::conductExam, &exam1);
	
	// chờ hai thread hoàn thành
	timerThread.join();
	examThread.join();

	//ManageSubject subjectList;
	//ManageQuestion questionList_Random = subjectList.getRandomQuestion(2, "CSDL");
	//questionList_Random.printQuestions();



}