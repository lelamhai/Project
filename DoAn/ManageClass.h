﻿#pragma once
#include <iostream>
#include <string>
#include <fstream> 
#include <sstream> 
#include "StrucData.h"
#include "ManageStudent.h"
#include "ManageSubject.h"
#include "ManageScore.h"

const string SOURCE_CLASS = "ClassData.json";

struct ClassPage {
	ClassList classList;
	int currentPage; // trang hiện tại
	int numberClassPerPage; // tổng số class trên 1 trang
	int totalPage; // tổng số trang
	int totalClass; // tổng số class
	int startIndex; // Số thứ tự bắt đầu của trang đó
	int endIndex; // số kết thúc của trang đó
};

class ManageClass
{
private:
	Classroom* classes[MAX_NUMBER_CLASS];
	int countClass = 0;
public:
	ManageClass();
	~ManageClass();

	ClassPage searchClass(string classCode, int page = 1);

	ClassList getClasses();
	int getCountClass();

	// Function find class by classcode
	// Input: Class code
	// Output: Position of class in list
	int findClass(const char* classCode);

	Classroom findClassByCode(const char* classCode);

	// Function check is class exist
	bool isClassExist(const string classCode);

	// Funtion check is class can delete
	bool isClassCanDelete(const string classCode);

	// Function get student by code
	Student findStudentByCode(const string studentCode, const string classCode);

	// Check student exist by studentcode
	bool isStudentExist(const string studentCode);

	// Check can delete student by studentCode
	bool isStudentCanDelete(const string studentCode);

	// Function add class to classlist
	// Input: classCode, className
	// Output: ++ count and return true if success or false if fail;
	bool addClass(const char* classCode, const string className);

	// Function edit class
	bool editClass(const char* classCode, const string className);

	// Function delete class
	bool deleteClass(const char* classCode);

	// Function print class list;
	void printClasses();

	// Function save class list to file
	void saveToFile();

	// Function load class list from file
	void loadFromFile();

	
	// Pagination
	ClassPage getClassPerPage(int pageNumber = 1);

	bool logIn(const char* user, const char* password);

	bool startExam(const char* studentCode, const char* subjectCode, int n, int timeSetting_Minute);

	void reset();


	// -------- FUNCTION FOR STUDENT IN CLASS ----------- //
	// Function add student to class
	bool addStudentToClass(const string classCode, const string studentCode, const string firstName, const string lastName, char gender, const string password);

	// Function edit student in class
	bool editStudentInClass(const string classCode, const string studentCode, const string firstName, const string lastName, char gender, const string password);

	// Function get count student of class by class code
	int getCountSudentOfClass(const char* classCode);

	// Delte student in class
	bool deleteStudentInClass(const char* classCode, const char* studentCode);

	// Search student In class
	StudentPage searchStudentInCLass(const string classCode, string keyword, int page = 1);

	// View score of class in subject
	//StudentPage getListScoreByClassAndSubject(const string classCode, const string subjectCode);

	// Function add score for student at subject
	bool addScoreToStudent(const string studentCode, const string subjectCode, float score);

	static string getStudentNameFromCode(const char* studentCode);

	static bool isFirstExam(const char* studentCode, const char* sujectCode);

};

void printClassPage(ClassPage classPage);

bool containString(const string& str, const string& substr);

string toLowerString(string str);







