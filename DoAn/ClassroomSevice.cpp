#include "Classroom.h"
#include "Student.h"

// Function add class to list class
// Input: Array class list,  new classroom need to add
bool addClassToClassList(ClassList &classList, const Classroom &classroom) {
	int index = findClassPositionInList(classList, classroom.classCode);
	if (index != -1) {
		return false;
	}
	if(classList.countClass < MAX_NUMBER_CLASS) {
		classList.classes[classList.countClass] = new Classroom;
		*classList.classes[classList.countClass] = classroom;
		classList.countClass++;
		return true;
	} 
	return false;
}

// Function find class by class Code in classList;
int findClassPositionInList(const ClassList& classList, const char* classCode) {
	for (int i = 0; i < classList.countClass; i++) {
		if (strcmp(classList.classes[i]->classCode, classCode) == 0) {
			return i;
		}
	}
	return -1;
}

// Function edit class
bool editClass(ClassList& classList, const char* classCode, const Classroom newClassroom) {
	int index = findClassPositionInList(classList, classCode);
	if (index != -1) {
		classList.classes[index]->className = newClassroom.className;
		saveClassListToFile(classList, "classlist.dat");
		return true;
	}
	return false;
}

// Function print List class;
void printClasses(ClassList &classList) {
	for(int i = 0; i < classList.countClass; i++) {
		cout << "Ma lop: " << classList.classes[i]->classCode << endl;
		cout << "Ten lop: " << classList.classes[i]->className << endl;
		cout << "-------------------------------------------" << endl; 
		printStudents(classList.classes[i]->studentList);
	}
}

// Delete class from classlist
bool deleteClass(ClassList& classList, const char* classCode) {
	int index = findClassPositionInList(classList, classCode);
	if (index != -1) {
		delete classList.classes[index];

		for (int i = index; i < classList.countClass - 1; i++) {
			classList.classes[i] = classList.classes[i + 1];
		}
		classList.countClass--;
		return true;
	}
	return false;
}

// Save class List to file
void saveClassListToFile(const ClassList& classList, const char* fileName) {
	ofstream file(fileName, ios::binary);
	if (!file) {
		cout << "Khong the mo file de ghi!" << endl;
		return;
	}

	// Save count class 
	file.write((char*)&classList.countClass, sizeof(int));

	// Save data each classroom
	for (int i = 0; i < classList.countClass; i++) {
		if (classList.classes[i] == nullptr) continue;

		// Save class code
		file.write(classList.classes[i]->classCode, sizeof(classList.classes[i]->classCode));

		// Save class name
		int classNameLength = classList.classes[i]->className.length();
		file.write((char*)&classNameLength, sizeof(int));
		file.write(classList.classes[i]->className.c_str(), classNameLength);

		// Count student in class
		int studentCount = 0;
		PTRSTUDENT currentStudent = classList.classes[i]->studentList;
		while (currentStudent != nullptr) {
			studentCount++;
			currentStudent = currentStudent->next;
		}

		// save count student in class
		file.write((char*)&studentCount, sizeof(int));

		// Save data each student
		currentStudent = classList.classes[i]->studentList;
		while (currentStudent != nullptr) {
			// Info of student
			file.write(currentStudent->info.studentCode, sizeof(currentStudent->info.studentCode));
			file.write(currentStudent->info.firstName, sizeof(currentStudent->info.firstName));
			file.write(currentStudent->info.lastName, sizeof(currentStudent->info.lastName));
			file.write((char*)&currentStudent->info.gender, sizeof(char));
			file.write(currentStudent->info.password, sizeof(currentStudent->info.password));

			// Count score of student
			int scoreCount = 0;
			PTRSCORE currentScore = currentStudent->info.scoreList;
			while (currentScore != nullptr) {
				scoreCount++;
				currentScore = currentScore->next;
			}

			// Save count score
			file.write((char*)&scoreCount, sizeof(int));

			// Save score
			currentScore = currentStudent->info.scoreList;
			while (currentScore != nullptr) {
				file.write(currentScore->info.subjectCode, sizeof(currentScore->info.subjectCode));
				file.write((char*)&currentScore->info.diem, sizeof(float));
				currentScore = currentScore->next;
			}

			currentStudent = currentStudent->next;
		}
	}

	file.close();
	cout << "Da luu danh sach lop vao file thanh cong!" << endl;
}

void loadClassListFromFile(ClassList& classList, const char* fileName) {
	// Release old memory
	freeClassList(classList);

	ifstream file(fileName, ios::binary);
	if (!file) {
		cout << "Khong the mo file!" << endl;
		return;
	}

	// Read count class
	file.read((char*)&classList.countClass, sizeof(int));

	// Read each class
	for (int i = 0; i < classList.countClass; i++) {
		classList.classes[i] = new Classroom;
		classList.classes[i]->studentList = nullptr;

		// Read class code
		file.read(classList.classes[i]->classCode, sizeof(classList.classes[i]->classCode));

		// Read class name
		int classNameLength;
		file.read((char*)&classNameLength, sizeof(int));
		char* tempClassName = new char[classNameLength + 1];
		file.read(tempClassName, classNameLength);
		tempClassName[classNameLength] = '\0';
		classList.classes[i]->className = string(tempClassName);
		delete[] tempClassName;

		// Read count student
		int studentCount;
		file.read((char*)&studentCount, sizeof(int));

		// Read list student
		PTRSTUDENT* lastStudent = &(classList.classes[i]->studentList);

		for (int j = 0; j < studentCount; j++) {
			PTRSTUDENT newStudent = new NodeStudent;
			newStudent->next = nullptr;
			newStudent->info.scoreList = nullptr; 

			// Read info of student
			file.read(newStudent->info.studentCode, sizeof(newStudent->info.studentCode));
			file.read(newStudent->info.firstName, sizeof(newStudent->info.firstName));
			file.read(newStudent->info.lastName, sizeof(newStudent->info.lastName));
			file.read((char*)&newStudent->info.gender, sizeof(char));
			file.read(newStudent->info.password, sizeof(newStudent->info.password));

			// Read score count
			int scoreCount;
			file.read((char*)&scoreCount, sizeof(int));

			// Read list score
			PTRSCORE* lastScore = &(newStudent->info.scoreList);

			for (int k = 0; k < scoreCount; k++) {
				PTRSCORE newScore = new NodeScore;
				newScore->next = nullptr;

				file.read(newScore->info.subjectCode, sizeof(newScore->info.subjectCode));
				file.read((char*)&newScore->info.diem, sizeof(float));

				*lastScore = newScore;
				lastScore = &(newScore->next);
			}

			*lastStudent = newStudent;
			lastStudent = &(newStudent->next);
		}
	}
	file.close();
}


// Function release memory list class
void freeClassList(ClassList& classList) {
	for (int i = 0; i < classList.countClass; i++) {
		if (classList.classes[i] != nullptr) {
			// Release list student
			PTRSTUDENT currentStudent = classList.classes[i]->studentList;
			while (currentStudent != nullptr) {
				// Release list score of student
				PTRSCORE currentScore = currentStudent->info.scoreList;
				while (currentScore != nullptr) {
					PTRSCORE tempScore = currentScore;
					currentScore = currentScore->next;
					delete tempScore;
				}

				PTRSTUDENT tempStudent = currentStudent;
				currentStudent = currentStudent->next;
				delete tempStudent;
			}

			delete classList.classes[i];
			classList.classes[i] = nullptr;
		}
	}
	classList.countClass = 0;
}

// Function get total student in class
int getCountStudentInClass(Classroom classroom) {
	int count = 0;
	PTRSTUDENT student= classroom.studentList;
	while (student != nullptr) {
		count++;
		student = student->next;
	}
	return count;
}












