#pragma once
#include "StrucData.h"
#include "ManageClass.h"

const int MAX_STUDENT_PER_CLASS = 100;
const string EXAM_RESULT_FILE_NAME = "examResult.json";

struct scoreToPrint {
	char studentCode[15];
	char firstName[30];
	char lastName[30];
	char gender;
	float score;
};
struct scoreToPrintList {
	char subjectCode[15];
	char classCode[15];
	scoreToPrint* array[MAX_STUDENT_PER_CLASS];
	int countStudent = 0;
};

struct ScorePage {
	scoreToPrintList printList;
	int currentPage; // trang hiện tại
	int numberScorePerPage; // tổng số điểm trên 1 trang
	int totalPage; // tổng số trang
	int totalScore; // tổng số điểm
	int startIndex; // Số thứ tự bắt đầu của trang đó
	int endIndex; // số kết thúc của trang đó
};

struct questionRecordList {
	Question list[MAX_NUMBER_QUESTION];
	int countQuestion = 0;
};


class ManageScore {
private:
	PTRSCORE scoreList;

	scoreToPrintList listToPrint;

public:
	ManageScore();
	~ManageScore();

	int setInputPrintScore(const char* subjectCode, const char* classCode);

	string getClassName();

	string getSubjectName();

	scoreToPrintList getScoreOfClass();

	scoreToPrintList getScoreAllPage();

	ScorePage getScorePerPage(scoreToPrintList* listSoucre, int pageNumber); // phân trang score từ sourcelist bất kỳ

	ScorePage getScorePerPage(int pageNumber); // phân trang score từ scoreList của class

	bool copyScoreToList(scoreToPrintList* list, scoreToPrint* scoreToCopy, int index);

	ScorePage searchStudentScore(string keyWord, int pageNumber);

	static resultList* loadResultFromFile(const char* subjectCode, const char* studentCode);
	
	static questionRecordList getQuestionExamRecord(const char* subjectCode, const char* studentCode);

	static Question getQuestionBySubjectCodeAndId(const string subjectCode, int questionId);

	static void deallocateResulList(resultList* rs);

	static void deallocateScorePage (ScorePage & page); // giải phóng bộ nhớ ScorePage
};

bool updateScoreToList(PTRSCORE& scoreList, string subjectCode, float score);