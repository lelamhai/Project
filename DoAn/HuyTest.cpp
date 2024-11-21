#include "HuyTest.h"

HuyTest::HuyTest()
{
	
}

HuyTest::~HuyTest()
{

}


void HuyTest::main() {



	/*---------------------------THỰC HIỆN THI TRẮC NGHIỆM---------------------------------------------*/

	// Khởi tạo
	mutex mtx; // Tạo mutex cho đồng bộ hóa
	int numberQuestion_input = 3; // số câu hỏi muốn thi
	const char* subjectCode_input = "CSDL"; // tên môn học muốn thi
	int timeForExam_min_input = 1; // số phút muốn thi


	ManageExam exam1(numberQuestion_input, subjectCode_input, timeForExam_min_input);

	// Xuất thời gian bắt đầu thi
	tm timeStart = exam1.getTimeStart();
	cout << "Bat dau thi: "
		<< (timeStart.tm_hour < 10 ? "0" : "") << timeStart.tm_hour << ":"
		<< (timeStart.tm_min < 10 ? "0" : "") << timeStart.tm_min << ":"
		<< (timeStart.tm_sec < 10 ? "0" : "") << timeStart.tm_sec << "\n";

	// Xuất hạn nộp bài
	tm timeEnd = exam1.getTimeEnd(timeStart);
	cout << "Han nop bai: "
		<< (timeEnd.tm_hour < 10 ? "0" : "") << timeEnd.tm_hour << ":"
		<< (timeEnd.tm_min < 10 ? "0" : "") << timeEnd.tm_min << ":"
		<< (timeEnd.tm_sec < 10 ? "0" : "") << timeEnd.tm_sec << "\n";

	// Luồng đếm thời gian
	thread thr_Timer([&exam1, &mtx]() {
		while (exam1.getRemainingTime() > 0) {
			{
				lock_guard<mutex> lock(mtx);
				if (exam1.getIsSubmitted()) {
					break; // Nếu người thi chọn nộp bài thi sớm
				}
			}

			this_thread::sleep_for(chrono::seconds(1));
			{
				lock_guard<mutex> lock(mtx);
				exam1.changeRemainingTime(-1);
				cout << "Thoi gian con lai: " << exam1.getRemainingTime() << endl;
				if (exam1.getRemainingTime() <= 0) {
					cout << "\nHet thoi gian lam bai!\n";
				}
			}
		}

		});

	// Luồng thực thi
	thread thr_Exam ([&exam1, &mtx]() {
		int numberQuestion = exam1.getNumberQuestion();
		int currQuestion = 0;
		char choose;

		while (exam1.getRemainingTime() > 0 && !exam1.getIsSubmitted()) {
			//int ID = getRandomedAnswerByIndex(int i)(currQuestion).questionId;

			string content = exam1.getRandomedAnswerByIndex(currQuestion).content;
			std::cout << "Cau " << currQuestion + 1 << ": " << content << endl;

			string optionA = exam1.getRandomedAnswerByIndex(currQuestion).optionA;
			std::cout << optionA << endl;

			string optionB = exam1.getRandomedAnswerByIndex(currQuestion).optionB;
			std::cout << optionB << endl;

			string optionC = exam1.getRandomedAnswerByIndex(currQuestion).optionC;
			std::cout << optionC << endl;

			string optionD = exam1.getRandomedAnswerByIndex(currQuestion).optionD;
			std::cout << optionD << endl;


			std::cout << "Nhap lua chon (A, B, C, D, N =next, P =previous, E =exit):" << endl;
			cin >> choose;

			if (choose == 'N') { // KIỂM TRA PHẦN CHỨC NĂNG NEXT
				if (currQuestion >= numberQuestion) {
					currQuestion = 0;
				}
				else {
					currQuestion++;
				}
			}
			else if (choose == 'P') {
				if (currQuestion <= 0) {
					currQuestion = numberQuestion;
				}
				currQuestion--;

			}
			else if (choose == 'E') {
				exam1.setSubmitted();
				break;
			}
			else if (choose == 'A') {
				exam1.setAnswer(currQuestion, choose);

				if (currQuestion >= numberQuestion - 1) {
					currQuestion = 0;
				}
				else {
					currQuestion++;
				}
			}
			else if (choose == 'B') {
				exam1.setAnswer(currQuestion, choose);
				if (currQuestion >= numberQuestion - 1) {
					currQuestion = 0;
				}
				else {
					currQuestion++;
				}

			}
			else if (choose == 'C') {
				exam1.setAnswer(currQuestion, choose);
				if (currQuestion >= numberQuestion - 1) {
					currQuestion = 0;
				}
				else {
					currQuestion++;
				}
			}
			else if (choose == 'D') {
				exam1.setAnswer(currQuestion, choose);
				if (currQuestion >= numberQuestion - 1) {
					currQuestion = 0;
				}
				else {
					currQuestion++;
				}
			}

			// VIẾT THÊM CODE ĐỂ IN RA TRẠNG THÁI CÁC CÂU HỎI ĐÃ THI , CHƯA THI
		}
		});

	thr_Timer.join();
	thr_Exam.join();

	// In ra kết quả sau khi thi xong
	cout << "\nKet qua thi la:";
	for (int i = 0; i < exam1.getNumberQuestion(); i++) {
		cout << "\nCau hoi " << i + 1 << exam1.getResult().answerList[i]->questionId;
		cout << "\nDap an da chon: " << exam1.getResult().answerList[i]->chosenAnswer;
		cout << "\nDap an dung la: " << exam1.getResult().answerList[i]->correctAnswer;
	}
}
