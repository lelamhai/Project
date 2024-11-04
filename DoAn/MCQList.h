#pragma once
#include <iostream>
#include <cstring>
#include <fstream> 
#include <sstream> 
#include "StrucData.h"

PTRQUESTION newNodeQuestion(Question x);

void insertFirst_MCQ(PTRQUESTION& p, Question x);

bool saveFile_MCQ(PTRQUESTION mcqList, const char* filename);

bool openFile_MCQ(PTRQUESTION& mcqList, const char* filename);