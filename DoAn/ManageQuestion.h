#pragma once
#include "StrucData.h"
#include <fstream>
using namespace std;
const string SOURCE_QUESTION = "QuestionData.json";

struct QuestionPage {
	PTRQUESTION questionList = new NodeQuestion;
	int currentPage; // trang hiện tại
	int numberQuestionPerPage; // tổng số question trên 1 trang
	int totalPage; // tổng số trang
	int totalQuestions; // tổng số class
	int startIndex; // Số thứ tự bắt đầu của trang đó
	int endIndex; // số kết thúc của trang đó
};

class ManageQuestion
{
private:
	PTRQUESTION questionList = nullptr;
public:
	ManageQuestion();
	//ManageQuestion(PTRQUESTION q);
	ManageQuestion(const PTRQUESTION& q);

	~ManageQuestion();

	bool addQuestion(const string content, const string optionA, const string optionB, const string optionC, const string optionD, const char answer);

	bool editQuestion(int questionId, const string content, const string optionA, const string optionB, const string optionC, const string optionD, const char answer);

	PTRQUESTION findQuestion(int questionId);

	bool deleteQuestion(int questionId);

	void printQuestions();

	PTRSTUDENT paginateQuestions(int page = 0, int pageSize = 10);

	int getCountQuestions();

	int insertFirst_Question(const Question &question);

	int insertLast_Question(const Question &question);

	void clearQuestionList();

	void saveToFile();

	int loadFromFile();


	// Tạo ra 1 id ngẫu nhiên không trùng lặp
	int generateUniqueId();

	// Kiểm tra xem Id đã tồn tại chưa
	bool isUniqueId(int randomId);

	char getAnswer(const int questionID);

	// Hàm chuyển một list question thành n question random. Sau khi thực hiện hàm sẽ thay thế list cũ
	void getRandomQuestion(int n);

	// Hàm trả về infor của Node ở vị trí i của list
	Question getQuestionByIndex(int n);
	
	PTRQUESTION getQuestionList();
};

int generateUniqueQuestionId(PTRQUESTION listQuestion);

int getCountQuestionInList(PTRQUESTION questionList);

QuestionPage getQuestionPerPage(PTRQUESTION questionList, int page);









