#pragma once
#include "StrucData.h"
#include "ManageClass.h"

struct ScorePage {
	scoreToPrint* scoreListToPrint[MAX_SCORE_SUBJECT_PER_CLASS];
	int currentPage; // trang hiện tại
	int totalScorePerPage; // tổng số dòng điểm trên 1 trang
	int totalPage; // tổng số trang
	int totalClass; // tổng số class
	int startIndex; // Số thứ tự bắt đầu của trang đó
	int endIndex; // số kết thúc của trang đó
};

class ManageScore
{
private:
	PTRSCORE scoreList;
	scoreToPrint* scorePrintList[MAX_SCORE_SUBJECT_PER_CLASS];

public:
	ManageScore();
	~ManageScore();

	scoreToPrintList getScoreOfClass(const char* classCode, const char* subjectCode);
	//ScorePage getSocrePerPage(int pageNumber);
	
};

bool updateScoreToList(PTRSCORE& scoreList, string subjectCode, float score);