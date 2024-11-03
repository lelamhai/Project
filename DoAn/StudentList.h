#pragma once
#include <iostream>
#include <cstring>
#include <fstream> 
#include <sstream> 
#include "StrucData.h"

PTRSTUDENT newNodeStudent(Student x);

void insertFirst(PTRSTUDENT& p, Student x);

bool saveFile_Student(PTRSTUDENT studentList, const char* filename);

bool openFile_Student(PTRSTUDENT& studentList, const char* filename);