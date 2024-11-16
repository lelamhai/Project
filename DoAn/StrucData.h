#pragma once

#include<iostream>
#include<cstring>
#include <string>
#include "json.hpp"
#include <random>
#include <ctime>

using json = nlohmann::json;
using namespace std;

const int MAX_NUMBER_CLASS = 1000;
const int MAX_NUMBER_QUESTION = 200; // số câu hỏi chọn tối đa cho một lần thi

// Struct question with question id, 4 option and answer;
struct Question {
	int questionId;
	string content;
	string optionA;
	string optionB;
	string optionC;
	string optionD;
	char answer;
};

struct NodeQuestion {
	Question info;
	NodeQuestion* next;
};

typedef NodeQuestion* PTRQUESTION;

struct Subject {
	char subjectCode[15];
	string subjectName;
	PTRQUESTION listQuestion = nullptr;

};

struct SubjectNode {
	int key;
	Subject info;
	int height;
	SubjectNode* left;
	SubjectNode* right;
};

typedef SubjectNode* PTRSUBJECT;

struct Score {
	char subjectCode[15];
	float diem;
};

struct NodeScore {
	Score info;
	NodeScore* next;
};

typedef NodeScore* PTRSCORE;

struct Student {
	char studentCode[15];
	char firstName[30];
	char lastName[30];
	char gender;
	char password[30];
	PTRSCORE scoreList = nullptr;
};

struct NodeStudent {
	Student info;
	NodeStudent* next;
};

typedef NodeStudent* PTRSTUDENT;

struct Classroom {
	char classCode[15];
	string className;
	PTRSTUDENT studentList = nullptr;
};

struct ClassList {
	Classroom* classes[MAX_NUMBER_CLASS];
	int countClass = 0;
};

// struc để lưu kết quả thi sau mỗi lần thi
struct answer {
	int questionId;
	char chosenAnswer;
	char correctAnswer;
};
struct resultList {
	char studentCode[15];
	char* subjectCode;
	answer* answerList[MAX_NUMBER_QUESTION];
	int countDone; //đếm số câu hỏi đã thi
	int score;
};