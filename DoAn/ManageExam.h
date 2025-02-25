﻿#pragma once
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
#include <cmath>

using namespace std;


class ManageExam {
private:
	int numberQuestion;
	//int timeForExam_min;
	const char* subjectCode;
	const char* studentCode;
  
	//bool isSubmitted; // trả về true khi người thi nhấn nộp bài, muốn kết thúc trước khi hết giờ
	//bool isTimeUp;
	//int remainingTime_sec; // thời gian còn lại bài thi tính bằng giây

	ManageSubject subjectList;
	ManageQuestion questionList_Random;
	Question randomQuestionList[MAX_NUMBER_QUESTION];

	resultList answerRecord;

public:
	ManageExam();
	~ManageExam();

	//bool setTimeForExam(int timeForExam); // hàm set thời gian thi

	bool setNumberQuestion(int numberQuestion);
	int getNumberQuestion();

	bool setSubjectCode(char* subjectCode);
	
	bool setInputExam(const char* subjectCode, const char* studentCode, const int numberQuestion, const int timeForExam);

	Question* getRandomQuestion(); // hàm tạo ra va trả về các câu hỏi random
	
	//int getRemainingTime(); 

	//void changeRemainingTime(int t); // hàm thay đổi thời gian còn lại

	//bool getIsSubmitted();
	//void setSubmitted();

	//bool getTimeUp();
	//void setTimeUp();




	Question getRandomedQuestionByIndex(int i); // hàm trả về câu hỏi thứ i trong số các câu đã lấy ramdom
	
	void setAnswer(int index, char choose); // lưu đáp án người thi đã chọn
	
	resultList getAnsweredList(); // hàm trả về list lưu kết quả thi sau khi thi xong
	answer* getAnsweredByIndex(int index); // hàm trả về kết quat thi của câu thứ i

	string getSubjectName(); // hàm trả về tên môn thi

	void toCalculateResult();

	int countCorrectAnswer();

	double getScore();

	tm getTimeStart(); // hàm trả về đối tượng lưu thời gian bắt đầu thi

	tm getTimeEnd(tm timeStartExam); // hàm trả về đối tượng lưu thời gian kết thúc thi

	void saveResultToFile();

	static float roundNumber(float number, int n);

	static int checkInputExam(const char* subjectCode, const int numberQuestion);

	static int checkInputExam1(const char* studentCode, const char* subjectCode, const int numberQuestion);

};


