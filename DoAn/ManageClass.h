#pragma once
#include <iostream>
#include <string>
#include <fstream> 
#include <sstream> 
#include "StrucData.h"
#include "ManageStudent.h"

const string SOURCE_CLASS = "classdata.json";

class ManageClass
{
private:
	Classroom* classes[MAX_NUMBER_CLASS];
	int countClass = 0;
public:
	ManageClass();
	~ManageClass();

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
	ClassList getClassPerPage(int pageNumber = 1, int classesPerPage = 10);

	// Delte student in class
	bool deleteStudentInClass(const char* classCode, const char* studentCode);
};






