#pragma once
#include <iostream>
#include <string>
#include <fstream> 
#include <sstream> 
#include "StrucData.h"
using namespace std;



class ManageStudent
{
private:
	PTRSTUDENT studentList = nullptr;
public:
	ManageStudent();
	~ManageStudent();

	bool addStudent(const char* studentCode, const char* firstName, const char* lastName, char gender, const char* password);
	bool openFile_Student(const char* filename);
	string logIn(string user, string password);
};




















