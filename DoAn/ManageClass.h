#pragma once
#include <iostream>
#include <string>
#include <fstream> 
#include <sstream> 
#include "StrucData.h"
#include "json.hpp"

using json = nlohmann::json;

const string SOURCE_CLASS = "classdata.json";

class ManageClass
{
private:
	Classroom* classes[MAX_NUMBER_CLASS];
	int countClass = 0;
public:
	ManageClass();
	~ManageClass();

	// Function find class by classcode
	// Input: Class code
	// Output: Position of class in list
	int findClass(const char* classCode);

	// Function add class to classlist
	// Input: classCode, className
	// Output: ++ count and return true if success or false if fail;
	bool addClass(const char* classCode, const string className);

	// Function edit class
	bool editClass(const char* classCode, const string className);

	// Function delete class
	bool deleteClass(const char* classCode);

	// Function print class list;
	void printClasses();

	// Function save class list to file
	void saveToFile();

	// Function load class list from file
	void loadFromFile();

	// Pagination
	ClassList getClassPerPage(int pageNumber = 1, int classesPerPage = 10);
};





