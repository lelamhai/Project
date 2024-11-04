#pragma once

#include "StrucData.h"
#include<cstring>
#include <string>
#include <fstream>
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

// Load student from file
void loadStudentsFromFile(PTRSTUDENT& studentList, const string& fileName);

// phân trang
void paginateStudents(PTRSTUDENT studentList, int page, int pageSize);

void addStudentToClass(Classroom& classroom, Student& student);