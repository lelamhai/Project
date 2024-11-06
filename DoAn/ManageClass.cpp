#include "ManageClass.h"

ManageClass::ManageClass()
{
}

ManageClass::~ManageClass()
{
}

int ManageClass::findClass(const char* classCode) {
	for (int i = 0; i < countClass; i++) {
		if (strcmp(classes[i]->classCode, classCode) == 0) {
			return i;
		}
	}
	return -1;
}

bool ManageClass::addClass(const char* classCode, const string className) {
	int index = findClass(classCode);
	if (index != -1) {
		return false;
	}
	if (countClass < MAX_NUMBER_CLASS) {
		classes[countClass] = new Classroom;
		strcpy_s(classes[countClass]->classCode, classCode);
		classes[countClass]->className = className;
		countClass++;
		return true;
	}
	return false;
}

bool ManageClass::editClass(const char* classCode, const string className) {
	int index = findClass(classCode);
	if (index != -1) {
		classes[index]->className = className;
		return true;
	}
	return false;
}

bool ManageClass::deleteClass(const char* classCode) {
	int index = findClass(classCode);
	if (index != -1) {
		delete classes[index];
		for (int i = index; i < countClass - 1; i++) {
			classes[i] = classes[i + 1];
		}
		countClass--;
		return true;
	}
	return false;
}

void ManageClass::printClasses() {
	for (int i = 0; i < countClass; i++) {
		cout << "Ma lop: " << classes[i]->classCode << endl;
		cout << "Ten lop: " << classes[i]->className << endl;
		cout << "-------------------------------------------" << endl;
	}
}






