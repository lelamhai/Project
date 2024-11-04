#ifndef QUIZ_SYSTEM_H
#define QUIZ_SYSTEM_H

#include<iostream>
#include<cstring>
#include <string>
#include <fstream>

using namespace std; 

const int MAX_NUMBER_CLASS = 1000;

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
	NodeQuestion *next;
};

typedef NodeQuestion *PTRQUESTION;

struct Subject {
	char subjectCode[15];
	string subjectName;
	PTRQUESTION listQuestion = nullptr;
	
};

struct SubjectNode {
	int key;
	Subject info;
	int height;
	SubjectNode *left;
	SubjectNode *right;
};

typedef SubjectNode *PTRSUBJECT;

struct Score {
	char subjectCode[15];
	float diem;
};

struct NodeScore {
	Score info;
	NodeScore *next;
};

typedef NodeScore *PTRSCORE;

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
	NodeStudent *next;
};

typedef NodeStudent *PTRSTUDENT;

struct Classroom {
	char classCode[15];
	string className;
	PTRSTUDENT studentList = nullptr;
};

struct ClassList {
	Classroom* classes[MAX_NUMBER_CLASS];
	int countClass = 0;
};

/*--------------------------------------------------------------------*/
/*-----------------------------STUDENT FUNCTION-----------------------*/

// add student to linkedList
void addStudent(PTRSTUDENT& studentList, Student& student);

void addListStudentTo(PTRSTUDENT& studentList, PTRSTUDENT& studentList2);

// print all student
void printStudents(PTRSTUDENT studentList);
// Delete student by student code
bool deleteStudent(PTRSTUDENT& studentList, char* studentCode);

// Edit info of student
bool editStudent(PTRSTUDENT studentList, char* studentCode, Student& updatedInfo);

// Find student by code or name
PTRSTUDENT findStudent(PTRSTUDENT studentList, char* studentCode);

// Save student in file
void saveStudentsToFile(PTRSTUDENT studentList, const string fileName);

// Load student from file
void loadStudentsFromFile(PTRSTUDENT& studentList, const string& fileName);
 
// phân trang
void paginateStudents(PTRSTUDENT studentList, int page, int pageSize);

void addStudentToClass(Classroom& classroom, Student& student);

/*--------------------------------------------------------------------*/
/*-----------------------------QUESTION FUNCTION----------------------*/
// Add question to linked list
void addQuestion(PTRQUESTION& questionList, const Question& question);

// Print all questions
void printQuestions(const PTRQUESTION& questionList);

// Delete question by question ID
bool deleteQuestion(PTRQUESTION& questionList, int questionId);

// Edit info of question
bool editQuestion(PTRQUESTION& questionList, int questionId, const Question& updatedInfo);

// Find question by ID
PTRQUESTION findQuestion(PTRQUESTION questionList, int questionId);

// Save questions to file
void saveQuestionsToFile(const PTRQUESTION& questionList, const std::string& fileName);

// Load questions from file
void loadQuestionsFromFile(PTRQUESTION& questionList, const std::string& fileName);

// Paginate questions
void paginateQuestions(const PTRQUESTION& questionList, int page, int pageSize);

/*--------------------------------------------------------------------*/
/*-----------------------------CLASSROOM FUNCTION---------------------*/
// Add class to class list
void addClassToClassList(ClassList& classList, const Classroom &classroom);

// Print class and student in class
void printClasses(ClassList& classList);

// Find class in class list
int findClass(const ClassList& classList, const char* classCode);

// Edit class
void editClass(ClassList& classList, const char* classCode, const Classroom newClassroom);

// Delete class in list
void deleteClass(ClassList& classList, const char* classCode);

// Save class list to file
void saveClassListToFile(const ClassList& classList, const char* filename);

// Load class list from file
void loadClassListFromFile(ClassList& classList, const char* filename);

// Function release memory list class
void freeClassList(ClassList& classList);
 #endif
