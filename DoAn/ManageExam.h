#pragma once
#include "StrucData.h"
#include "ManageQuestion.h"
#include "ManageSubject.h"
#include "ManageClass.h"

#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <ctime>
#include <vector>
using namespace std;


class ManageExam {
private:
	int numberQuestion;
	int timeForExam_min;
	const char* subjectCode;
  
	bool isSubmitted; // trả về true khi người thi nhấn nộp bài, muốn kết thúc trước khi hết giờ
	int remainingTime_sec; // thời gian còn lại bài thi tính bằng giây

	ManageSubject subjectList;
	ManageQuestion questionList_Random;

	resultList answerRecord;

public:
	ManageExam(int numberQuestion, const char* subjectCode, int timeForExam_min);
	~ManageExam();

	int getRemainingTime(); 
	void changeRemainingTime(int t); // hàm thay đổi thời gian còn lại

	bool getIsSubmitted();
	void setSubmitted();

	int getNumberQuestion();


	Question getRandomedAnswerByIndex(int i); // hàm trả về câu hỏi thứ i trong số các câu đã lấy ramdom
	
	void setAnswer(int index, char choose);

	resultList getResult(); // hàm trả về struc lưu kết quả thi


	tm getTimeStart(); // hàm trả về đối tượng lưu thời gian bắt đầu thi

	tm getTimeEnd(tm timeStartExam); // hàm trả về đối tượng lưu thời gian kết thúc thi

};

