#pragma once
#include "Singleton.h"
#include <iostream>
#include <string>
#include <fstream> 
#include <sstream> 
#include "StrucData.h"
using namespace std;

const string SOURCE_STUDENT = "studentdata.json";

class ManageStudent
{
private:
	PTRSTUDENT studentList = nullptr;
public:
	ManageStudent();
	~ManageStudent();

	// Add new student to list
	bool addStudent(const char* studentCode, const char* firstName, const char* lastName, char gender, const char* password);
	
	// edit student data
	bool editStudent(const char* studentCode, const char* firstName, const char* lastName, char gender, const char* password);
	
	// find student in list by student code
	PTRSTUDENT findStudent(char* studentCode);

	// Delete student by code
	bool deleteStudent(const char* studentCode);

	// Print student list
	void printStudents();

	bool openFile_Student(const char* filename);

	// Pagination for student list default page 0, size 10
	PTRSTUDENT paginateStudents(int page = 0, int pageSize = 10);
	
	// Get count student in list;
	int getCountStudents();
	
	// Save list student to file
	void saveToFile();

	// Load list student from file
	void loadFromFile();


};


// Get count student in list
int getCountStudentOfList(PTRSTUDENT listStudent);

// Print student in list
void printStudentsInList(PTRSTUDENT studentList);

// Find student in list
PTRSTUDENT findStudentInList(PTRSTUDENT studentList, const char* studentCode);

// Delete student in list
bool deleteStudentInList(PTRSTUDENT studentList, const char* studentCode);






















