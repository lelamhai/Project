#pragma once
#include <iostream>
#include <string>
#include "StrucData.h"
using namespace std;



class ManageStudent
{
private:
	PTRSTUDENT student;
public:
	ManageStudent();
	~ManageStudent();

	bool addStudent(const char* studentCode, const char* firstName, const char* lastName, char gender, const char* password);

};




















