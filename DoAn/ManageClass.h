#pragma once
#include <iostream>
#include <string>
#include <fstream> 
#include <sstream> 
#include "StrucData.h"
#include "ManageStudent.h"

const string SOURCE_CLASS = "classdata.json";

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

	ClassPage findClassByKeyword(string classCode, int page = 1);

	ClassList getClasses();
	int getCountClass();

	// Function find class by classcode
	// Input: Class code
	// Output: Position of class in list
	int findClass(const char* classCode);

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

	// Function add student to class
	bool addStudentToClass(const char* classCode, const char* studentCode, const char* firstName, const char* lastName, char gender, const char* password);


	// Function get count student of class by class code
	int getCountSudentOfClass(const char* classCode);

	// Pagination
	ClassPage getClassPerPage(int pageNumber = 1);

	// Delte student in class
	bool deleteStudentInClass(const char* classCode, const char* studentCode);

	bool logIn(const char* user, const char* password);

	void reset();
};

void printClassPage(ClassPage classPage);

bool containString(const string& str, const string& substr);





