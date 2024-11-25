#include "HuyTest.h"

HuyTest::HuyTest()
{
	
}

HuyTest::~HuyTest()
{

}


void HuyTest::main() {

	/*---------------------------THỰC HIỆN THI TRẮC NGHIỆM---------------------------------------------*/
	// KHỞI TẠO
	mutex mtx; // Tạo mutex cho đồng bộ hóa
	ManageExam exam1;

	// PHẦN NHẬP VÀO MÔN HỌC MUỐN THI
	char subjectCode_input[15];
	std::cout << "Nhap ma mon hoc: ";
	cin.getline(subjectCode_input, 15);
	exam1.setSubjectCode(subjectCode_input);
	
	// PHẦN NHẬP VÀO SỐ CÂU HỎI MUỐN THI
	int numberQuestion_input; // số câu hỏi muốn thi
	bool isNumberQuestionInput_Done = false;
	do {
		std::cout << "Nhap so cau muon thi: ";
		cin >> numberQuestion_input;
		isNumberQuestionInput_Done = exam1.setNumberQuestion(numberQuestion_input);
		if (!isNumberQuestionInput_Done) {
			std::cout << "Du lieu khong hop le, hay nhap lai: \n";
		}
	}
	while (!isNumberQuestionInput_Done);

	exam1.getRandomQuestion();

	// PHẦN NHẬP VÀO SỐ PHÚT MUỐN THI
	int timeForExam_min_input; // số phút muốn thi
	bool isTimeInput_Done = false;
	do {
		std::cout << "Nhap so phut thi: ";
		cin >> timeForExam_min_input;
		isTimeInput_Done = exam1.setTimeForExam(timeForExam_min_input);// isTimeInput_Done	trả về false nếu lỗi
		
		if (!isTimeInput_Done) {
			std::cout << "Du lieu khong hop le, hay nhap lai: \n";
		}
	} while (!isTimeInput_Done);
	
	// Xuất thời gian bắt đầu thi
	tm timeStart = exam1.getTimeStart();
	std::cout << "Bat dau thi: "
		<< (timeStart.tm_hour < 10 ? "0" : "") << timeStart.tm_hour << ":"
		<< (timeStart.tm_min < 10 ? "0" : "") << timeStart.tm_min << ":"
		<< (timeStart.tm_sec < 10 ? "0" : "") << timeStart.tm_sec << "\n";

	// Xuất hạn nộp bài
	tm timeEnd = exam1.getTimeEnd(timeStart);
	std::cout << "Han nop bai: "
		<< (timeEnd.tm_hour < 10 ? "0" : "") << timeEnd.tm_hour << ":"
		<< (timeEnd.tm_min < 10 ? "0" : "") << timeEnd.tm_min << ":"
		<< (timeEnd.tm_sec < 10 ? "0" : "") << timeEnd.tm_sec << "\n";

	// Luồng đếm thời gian nguoc
	thread thr_Timer([&exam1, &mtx]() {
		int time_sec_total, time_min, time_sec;

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
				time_sec_total = exam1.getRemainingTime();
				time_min = time_sec_total / 60;
				time_sec = time_sec_total - time_min * 60;
				std::cout << "Thoi gian con lai: " << (time_min < 10 ? "0": "") << time_min << " phut : "
					                         <<(time_sec < 10 ? "0": "") << time_sec << " giay" << endl;
				
				if (exam1.getRemainingTime() <= 0) {
					std::cout << "\nHet thoi gian lam bai. Hay nhan phim bat ky de xem ket qua !\n";
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
			std::cout << "Cau " << currQuestion + 1 << ": " << content << endl;

			string optionA = exam1.getRandomedQuestionByIndex(currQuestion).optionA;
			std::cout << optionA << endl;

			string optionB = exam1.getRandomedQuestionByIndex(currQuestion).optionB;
			std::cout << optionB << endl;

			string optionC = exam1.getRandomedQuestionByIndex(currQuestion).optionC;
			std::cout << optionC << endl;

			string optionD = exam1.getRandomedQuestionByIndex(currQuestion).optionD;
			std::cout << optionD << endl;


			// Nhập lựa chọn của người thi và xử lý
			std::cout << "Nhap lua chon (A, B, C, D, N =next, P =previous, E =exit):" << endl;
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
					std::cout << "Cau " << i + 1 << ": " << p->chosenAnswer << endl;
				}

				if (currQuestion >= numberQuestion - 1) {
					currQuestion = 0;
				}
				else {
					currQuestion++;
				}
			}
			else {
				std::cout << "Nhap lieu khong hop le !" << endl;
			}

		}
	});

	thr_Timer.join();
	thr_Exam.join();

	// In ra kết quả sau khi thi xong
	int numberQuestion = exam1.getNumberQuestion();
	std::cout << "\nKet qua thi la:" << endl;
	for (int i = 0; i < numberQuestion; i++) {
		answer* p = exam1.getAnswer(i);
		std::cout << "Cau " << i + 1 << ": " << (p->chosenAnswer == p->correctAnswer ? "Dung" : "Sai")
				<< " - Da chon " << p->chosenAnswer
				<< " - Dap an la " << p->correctAnswer << endl;
	}

	// CAN THEM CHAM DIEM VA IN RA TONG SO CAU DUNG TREN SO CAU
}
