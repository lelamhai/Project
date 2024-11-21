#include "HuyTest.h"

HuyTest::HuyTest()
{
	
}

HuyTest::~HuyTest()
{

}


void HuyTest::main() {

	/*---------------------------THỰC HIỆN THI TRẮC NGHIỆM---------------------------------------------*/
	mutex mtx; // Tạo mutex cho đồng bộ hóa

	// Phần nhập thông tin đầu vào
	int numberQuestion_input = 3; // số câu hỏi muốn thi
	const char* subjectCode_input = "CSDL"; // tên môn học muốn thi
	int timeForExam_min_input = 1; // số phút muốn thi

	// Khởi tạo đối tượng quản lý thi
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
		while (true) {
			{
				lock_guard<mutex> lock(mtx);
				if (exam1.getIsSubmitted() || exam1.getTimeUp()) {
					break; // Nếu người thi chọn nộp bài thi sớm
				}
			}

			this_thread::sleep_for(chrono::seconds(1));
			{
				lock_guard<mutex> lock(mtx);
				exam1.changeRemainingTime(-1);
				cout << "Thoi gian con lai: " << exam1.getRemainingTime() << endl;
				if (exam1.getRemainingTime() <= 0) {
					cout << "\nHet thoi gian lam bai. Hay nhan phim bat ky de xem ket qua !\n";
					exam1.setTimeUp();
					break;
				}
			}
		}

		});

	

	// Luồng thực thi
	thread thr_Exam ([&exam1, &mtx]() {
		int numberQuestion = exam1.getNumberQuestion();
		int currQuestion = 0;
		char choose;

		while (true) {

			if (exam1.getTimeUp() || exam1.getIsSubmitted()) {
				break;
			}

			// In ra câu hỏi và các đáp án để lựa chọn
			string content = exam1.getRandomedQuestionByIndex(currQuestion).content;
			cout << "Cau " << currQuestion + 1 << ": " << content << endl;

			string optionA = exam1.getRandomedQuestionByIndex(currQuestion).optionA;
			cout << optionA << endl;

			string optionB = exam1.getRandomedQuestionByIndex(currQuestion).optionB;
			cout << optionB << endl;

			string optionC = exam1.getRandomedQuestionByIndex(currQuestion).optionC;
			cout << optionC << endl;

			string optionD = exam1.getRandomedQuestionByIndex(currQuestion).optionD;
			cout << optionD << endl;


			// Nhập lựa chọn của người thi và xử lý
			cout << "Nhap lua chon (A, B, C, D, N =next, P =previous, E =exit):" << endl;
			cin >> choose;

			{
				lock_guard<mutex> lock(mtx);
				if (exam1.getTimeUp()) {
					break; // Nếu hết thời gian trong lúc nhập lựa chọn, thì thoát
				}
			}

			if (choose == 'N') {
				if (currQuestion >= numberQuestion - 1) {
					currQuestion = 0;
				}
				else {
					currQuestion++;
				}
			}
			else if (choose == 'P') {
				if (currQuestion <= 0) {
					currQuestion = numberQuestion - 1;
				}
				else {
					currQuestion--;
				}
			}
			else if (choose == 'E') {
				exam1.setSubmitted();
				break;
			}

			else if (choose == 'A' || choose == 'B' || choose == 'C' || choose == 'D') {
				exam1.setAnswer(currQuestion, choose);

				// In ra trạng thái bài thi
				for (int i = 0; i < numberQuestion; i++) {
					answer* p = exam1.getAnswer(i);
					cout << "Cau " << i + 1 << ": " << p->chosenAnswer << endl;
				}

				if (currQuestion >= numberQuestion - 1) {
					currQuestion = 0;
				}
				else {
					currQuestion++;
				}
			}
			else {
				cout << "Nhap lieu khong hop le !" << endl;
			}

		}
	});

	thr_Timer.join();
	thr_Exam.join();

	// In ra kết quả sau khi thi xong
	int numberQuestion = exam1.getNumberQuestion();
	cout << "\nKet qua thi la:" << endl;
	for (int i = 0; i < numberQuestion; i++) {
		answer* p = exam1.getAnswer(i);
		cout << "Cau " << i + 1 << ": " << (p->chosenAnswer == p->correctAnswer ? "Dung" : "Sai")
			<< " - Da chon " << p->chosenAnswer
			<< " - Dap an la " << p->correctAnswer << endl;
	}
}
