#pragma once
#include "Singleton.h"
#include <iostream>
#include <string>
#include <fstream> 
#include <sstream> 
#include "StrucData.h"
using namespace std;

const string SOURCE_STUDENT = "studentdata.json";

struct StudentPage {
	PTRSTUDENT studentList = nullptr;
	int currentPage; // trang hiện tại
	int numberStudentPerPage; // tổng số student trên 1 trang
	int totalPage; // tổng số trang
	int totalStudent; // tổng số class
	int startIndex; // Số thứ tự bắt đầu của trang đó
	int endIndex; // số kết thúc của trang đó
};

class ManageStudent
{
private:
	PTRSTUDENT studentList = nullptr;
public:
	ManageStudent();
	~ManageStudent();

	// Get list student
	PTRSTUDENT getStudentList() {
		return studentList;
	}

	// Set list student 
	void setStudentList(PTRSTUDENT studentList) {
		studentList = studentList;                                                                                                                                    
	}

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

// Add student to list
bool addStudentToList(PTRSTUDENT studentList, Student std1);

// Paginate for student
StudentPage getStudentPerPage(PTRSTUDENT studentList, int page);






















