#pragma once
#include "StrucData.h"


/*--------------------------------------------------------------------*/
/*-----------------------------CLASSROOM FUNCTION---------------------*/
// Add class to class list
bool addClassToClassList(ClassList& classList, const Classroom& classroom);

// Print class and student in class
void printClasses(ClassList& classList);

// Find class in class list
int findClassPositionInList(const ClassList& classList, const char* classCode);

// Edit class
bool editClass(ClassList& classList, const char* classCode, const Classroom newClassroom);

// Delete class in list
bool deleteClass(ClassList& classList, const char* classCode);

// Save class list to file
void saveClassListToFile(const ClassList& classList, const char* filename);

// Load class list from file
void loadClassListFromFile(ClassList& classList, const char* filename);

// Function release memory list class
void freeClassList(ClassList& classList);

// Function to get Count student in class
int getCountStudentInClass(const Classroom classroom);
