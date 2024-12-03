#include "HuyTest.h"
#include <cmath>

HuyTest::HuyTest()
{
	
}

HuyTest::~HuyTest()
{

}


void HuyTest::main() {
	
	/*---------------------------THỰC HIỆN THI TRẮC NGHIỆM VERSION R1 ---------------------------------------------*/
	// KHỞI TẠO
	mutex mtx; // Tạo mutex cho đồng bộ hóa
	ManageExam exam1;
	
	//char subjectCode_input[15];	 //mã môn muốn thi
	//char studentCode[15];		 // mã sinh viên
	int numberQuestion_input = 7;    //số câu hỏi muốn thi
	int timeForExam_min_input = 1;   //số phút muốn thi

	//// NHẬP THÔNG TIN INPUT ĐỂ THI
	//cin.getline(subjectCode_input, 15);
	//cin.getline(studentCode, 15);
	//cin >> numberQuestion_input;
	//cin >> timeForExam_min_input;

	// KIỂM TRA INPUT VÀO CÓ HỢP LỆ ?
	bool isCorrectInput = false;
	//isCorrectInput = exam1.setInputExam(subjectCode_input, studentCode, numberQuestion_input, timeForExam_min_input);
	isCorrectInput = exam1.setInputExam("VL", "GV", numberQuestion_input, timeForExam_min_input);

	if (!isCorrectInput) {
		cout << "Du lieu nhap khong hop le ! " << endl;
	}

	// LẤY LIST CÁC CÂU HỎI NGẪU NHIÊN
	Question* randomQuestionList = exam1.getRandomQuestion();
	
	// demo in ra thông tin câu hỏi
	for (int i = 0; i < numberQuestion_input; i++) {
		cout << randomQuestionList[i].content << endl;
		cout << randomQuestionList[i].optionA << endl;
		cout << randomQuestionList[i].optionB << endl;
		cout << randomQuestionList[i].optionC << endl;
		cout << randomQuestionList[i].optionD << endl;
	}
	

	// TRUYỀN KẾT QUẢ ĐÃ THI XUỐNG BACK END SAU KHI KẾT THÚC BÀI TI
	char answeredList[MAX_NUMBER_QUESTION] = {'D','D','D','C',' ','A','B' }; // dòng này đê giả lập danh sách câu trả lời
	for (int i=0; i < numberQuestion_input; i++){
		exam1.setAnswer(i, answeredList[i]);
	}

	// LẤY KẾT QUẢ THI ̃& ĐIỂM SAU KHI THI XONG
	resultList result = exam1.getAnsweredList();

	// demo in ra kết quả thi cho từng câu
	cout << "\nKet qua thi la:" << endl;
	for (int i = 0; i < numberQuestion_input; i++) {
		answer* p = result.answerList[i];
		cout << "Cau " << i + 1 << ": " << (p->chosenAnswer == p->correctAnswer ? "Dung" : "Sai")
			<< " - Da chon " << p->chosenAnswer
			<< " - Dap an la " << p->correctAnswer << endl;
	}
	
	// demo in ra số câu trả lời đúng
	int countCorrectAnswer = result.countCorrect;
	printf("Dung %d/%d cau\n", countCorrectAnswer, numberQuestion_input);
	
	// demo in ra điểm số
	float scoreExam = result.score;
	printf("Diem so: %.1f\n", scoreExam);

	/*---------------------------THỰC HIỆN THI TRẮC NGHIỆM VERSION R0 ---------------------------------------------*/
	// KHỞI TẠO
	//mutex mtx; // Tạo mutex cho đồng bộ hóa
	//ManageExam exam2;

	//// PHẦN NHẬP VÀO MÔN HỌC MUỐN THI
	//char subjectCode_input[15];
	//cout << "Nhap ma mon hoc: ";
	//cin.getline(subjectCode_input, 15);
	//exam2.setSubjectCode(subjectCode_input);
	//
	//// PHẦN NHẬP VÀO SỐ CÂU HỎI MUỐN THI
	//int numberQuestion_input; // số câu hỏi muốn thi
	//bool isNumberQuestionInput_Done = false;
	//do {
	//	cout << "Nhap so cau muon thi: ";
	//	cin >> numberQuestion_input;
	//	isNumberQuestionInput_Done = exam2.setNumberQuestion(numberQuestion_input);
	//	if (!isNumberQuestionInput_Done) {
	//		cout << "Du lieu khong hop le, hay nhap lai: \n";
	//	}
	//}
	//while (!isNumberQuestionInput_Done);

	//exam2.getRandomQuestion();

	//// PHẦN NHẬP VÀO SỐ PHÚT MUỐN THI
	//int timeForExam_min_input; // số phút muốn thi
	//bool isTimeInput_Done = false;
	//do {
	//	cout << "Nhap so phut thi: ";
	//	cin >> timeForExam_min_input;
	//	isTimeInput_Done = exam2.setTimeForExam(timeForExam_min_input);// isTimeInput_Done	trả về false nếu lỗi
	//	
	//	if (!isTimeInput_Done) {
	//		cout << "Du lieu khong hop le, hay nhap lai: \n";
	//	}
	//} while (!isTimeInput_Done);
	//
	//// XUẤT RA THỜI GIAN ĐÃ BẮT ĐẦU THI
	//tm timeStart = exam2.getTimeStart();
	//cout << "Bat dau thi: "
	//	<< (timeStart.tm_hour < 10 ? "0" : "") << timeStart.tm_hour << ":"
	//	<< (timeStart.tm_min < 10 ? "0" : "") << timeStart.tm_min << ":"
	//	<< (timeStart.tm_sec < 10 ? "0" : "") << timeStart.tm_sec << "\n";

	//// XUẤT RA THỜI GIAN HẾT GIỜ
	//tm timeEnd = exam2.getTimeEnd(timeStart);
	//cout << "Han nop bai: "
	//	<< (timeEnd.tm_hour < 10 ? "0" : "") << timeEnd.tm_hour << ":"
	//	<< (timeEnd.tm_min < 10 ? "0" : "") << timeEnd.tm_min << ":"
	//	<< (timeEnd.tm_sec < 10 ? "0" : "") << timeEnd.tm_sec << "\n";

	//// LUỒNG ĐẾM THỜI GIAN COUNT DOWN
	//thread thr_Timer([&exam2, &mtx]() {
	//	int time_sec_total, time_min, time_sec;

	//	while (true) {
	//		{
	//			lock_guard<mutex> lock(mtx);
	//			if (exam2.getIsSubmitted() || exam2.getTimeUp()) {
	//				break; // Nếu người thi chọn nộp bài thi sớm
	//			}
	//		}

	//		this_thread::sleep_for(chrono::seconds(1));
	//		{
	//			lock_guard<mutex> lock(mtx);
	//			exam2.changeRemainingTime(-1);
	//			time_sec_total = exam2.getRemainingTime();
	//			time_min = time_sec_total / 60;
	//			time_sec = time_sec_total - time_min * 60;
	//			cout << "Thoi gian con lai: " << (time_min < 10 ? "0": "") << time_min << " phut : "
	//				                         <<(time_sec < 10 ? "0": "") << time_sec << " giay" << endl;
	//			
	//			if (exam2.getRemainingTime() <= 0) {
	//				cout << "\nHet thoi gian lam bai. Hay nhan phim bat ky de xem ket qua !\n";
	//				exam2.setTimeUp();
	//				break;
	//			}
	//		}
	//	}

	//	});

	//

	//// LUỒNG THỰC HIỆN BÀI THI
	//thread thr_Exam ([&exam2, &mtx]() {
	//	int numberQuestion = exam2.getNumberQuestion();
	//	int currQuestion = 0;
	//	char choose;

	//	while (true) {

	//		if (exam2.getTimeUp() || exam2.getIsSubmitted()) {
	//			break;
	//		}

	//		// In ra câu hỏi và các đáp án để lựa chọn
	//		string content = exam2.getRandomedQuestionByIndex(currQuestion).content;
	//		cout << "Cau " << currQuestion + 1 << ": " << content << endl;

	//		string optionA = exam2.getRandomedQuestionByIndex(currQuestion).optionA;
	//		cout << optionA << endl;

	//		string optionB = exam2.getRandomedQuestionByIndex(currQuestion).optionB;
	//		cout << optionB << endl;

	//		string optionC = exam2.getRandomedQuestionByIndex(currQuestion).optionC;
	//		cout << optionC << endl;

	//		string optionD = exam2.getRandomedQuestionByIndex(currQuestion).optionD;
	//		cout << optionD << endl;


	//		// Nhập lựa chọn của người thi và xử lý
	//		cout << "Nhap lua chon (A, B, C, D, N =next, P =previous, E =exit):" << endl;
	//		cin >> choose;

	//		{
	//			lock_guard<mutex> lock(mtx);
	//			if (exam2.getTimeUp()) {
	//				break; // Nếu hết thời gian trong lúc nhập lựa chọn, thì thoát
	//			}
	//		}

	//		if (choose == 'N') {
	//			if (currQuestion >= numberQuestion - 1) {
	//				currQuestion = 0;
	//			}
	//			else {
	//				currQuestion++;
	//			}
	//		}
	//		else if (choose == 'P') {
	//			if (currQuestion <= 0) {
	//				currQuestion = numberQuestion - 1;
	//			}
	//			else {
	//				currQuestion--;
	//			}
	//		}
	//		else if (choose == 'E') {
	//			exam2.setSubmitted();
	//			break;
	//		}

	//		else if (choose == 'A' || choose == 'B' || choose == 'C' || choose == 'D') {
	//			exam2.setAnswer(currQuestion, choose);

	//			// In ra trạng thái bài thi
	//			for (int i = 0; i < numberQuestion; i++) {
	//				answer* p = exam2.getAnswer(i);
	//				cout << "Cau " << i + 1 << ": " << p->chosenAnswer << endl;
	//			}

	//			if (currQuestion >= numberQuestion - 1) {
	//				currQuestion = 0;
	//			}
	//			else {
	//				currQuestion++;
	//			}
	//		}
	//		else {
	//			cout << "Nhap lieu khong hop le !" << endl;
	//		}

	//	}
	//});

	//thr_Timer.join();
	//thr_Exam.join();

	//// IN RA KẾT QUẢ SAU KHI KẾT THỰC BÀI THI
	//int numberQuestion = exam2.getNumberQuestion();
	//exam2.toCalculateResult();

	//cout << "\nKet qua thi la:" << endl;
	//for (int i = 0; i < numberQuestion; i++) {
	//	answer* p = exam2.getAnsweredByIndex(i);
	//	cout << "Cau " << i + 1 << ": " << (p->chosenAnswer == p->correctAnswer ? "Dung" : "Sai")
	//		<< " - Da chon " << p->chosenAnswer
	//		<< " - Dap an la " << p->correctAnswer << endl;
	//}
	//printf("Dung %d/%d cau\n", exam2.countCorrectAnswer(), numberQuestion);
	//float scoreExam = exam2.getScore();
	//printf("Diem so: %.1f\n", scoreExam);

	//// LƯU ĐIỂM THI VÀO DANH SÁCH
	//ManageClass tempClass;
	//char studentCode[15] = "K23DTCN270";
	//tempClass.addScoreToStudent(studentCode, subjectCode_input, scoreExam);
	
	/*---------------------------------------------------------------------------------------*/
}
