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


	bool addStudent(const char* studentCode, const char* firstName, const char* lastName, char gender, const char* password);
	
	bool editStudent(const char* studentCode, const char* firstName, const char* lastName, char gender, const char* password);
	
	PTRSTUDENT findStudent(char* studentCode);

	bool deleteStudent(const char* studentCode);

	void printStudents();

	bool openFile_Student(const char* filename);

	bool logIn(string user, string password);

	PTRSTUDENT paginateStudents(int page = 0, int pageSize = 10);

	int getCountStudents();
	
	void saveToFile();

	void loadFromFile();
};

int getCountStudentOfList(PTRSTUDENT listStudent);




















