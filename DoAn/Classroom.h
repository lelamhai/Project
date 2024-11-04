#pragma once
#include "StrucData.h"


/*--------------------------------------------------------------------*/
/*-----------------------------CLASSROOM FUNCTION---------------------*/
// Add class to class list
void addClassToClassList(ClassList& classList, const Classroom& classroom);

// Print class and student in class
void printClasses(ClassList& classList);

// Find class in class list
int findClass(const ClassList& classList, const char* classCode);

// Edit class
void editClass(ClassList& classList, const char* classCode, const Classroom newClassroom);

// Delete class in list
void deleteClass(ClassList& classList, const char* classCode);

// Save class list to file
void saveClassListToFile(const ClassList& classList, const char* filename);

// Load class list from file
void loadClassListFromFile(ClassList& classList, const char* filename);

// Function release memory list class
void freeClassList(ClassList& classList);
