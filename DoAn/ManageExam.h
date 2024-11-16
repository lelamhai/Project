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
	std::mutex mtx; // Tạo mutex cho đồng bộ hóa
	int numberQuestion;
	int timeForExam_min;
	const char* subjectCode;

	bool isTimeUp; // trả về true khi thời gian thi hết    
	bool isSubmitted; // trả về true khi người thi nhấn nộp bài, muốn kết thúc trước khi hết giờ
	int remainingTime_sec; // thời gian còn lại bài thi tính bằng giây

	//ManageSubject subjectList;

	//ManageQuestion questionList_Random;
	//ManageSubject subjectList;
	//ManageQuestion questionList_Random;

	struct resultList answerRecord;

public:
	ManageExam(int numberQuestion, const char* subjectCode, int timeForExam_min);
	~ManageExam();

	void countDown();
	void conductExam();
};

