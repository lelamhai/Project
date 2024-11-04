#include "Student.h"


//void Student inputStudent() {
//	cout << "Nhập mã sinh viên: ";
//	do {
//		cin >> 
//	}
//}


// add student to linkedList
void addStudent(PTRSTUDENT& studentList, Student& student) {
	PTRSTUDENT newNode = new NodeStudent;
	newNode->info = student;
	newNode->next = nullptr;

	if (studentList == nullptr) {
		studentList = newNode;
		return;
	}

	PTRSTUDENT temp = studentList;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newNode;
}

void addListStudentTo(PTRSTUDENT& studentList, PTRSTUDENT& studentList2) {
	if (studentList == nullptr) {
		// If studentList is empty, point it to studentList2
		studentList = studentList2;
		return;
	}

	// Traverse to the end of studentList
	PTRSTUDENT temp = studentList;
	while (temp->next != nullptr) {
		temp = temp->next;
	}

	// Append studentList2 at the end of studentList
	temp->next = studentList2;
}

// print all student
void printStudents(PTRSTUDENT studentList) {
	PTRSTUDENT temp = studentList;
	while (temp != nullptr) {
		cout << "Ma sinh vien: " << temp->info.studentCode << endl;
		cout << "Ho va ten: " << temp->info.firstName << " " << temp->info.lastName << endl;
		cout << "Gioi tinh: " << (temp->info.gender == 'M' ? "Nam" : "Nu") << endl;
		cout << "-------------------------------------------" << endl;
		temp = temp->next;
	}
}

// Delete student by student code
bool deleteStudent(PTRSTUDENT& studentList, char* studentCode) {
	if (studentList == nullptr) return false;
	if (strcmp(studentList->info.studentCode, studentCode) == 0) {
		PTRSTUDENT temp = studentList;
		studentList = studentList->next;
		delete temp;
		return true;
	}

	PTRSTUDENT prev = studentList;
	PTRSTUDENT curr = studentList->next;
	while (curr != nullptr && strcmp(curr->info.studentCode, studentCode) != 0) {
		prev = curr;
		curr = curr->next;
	}
	if (curr != nullptr) {
		prev->next = curr->next;
		delete curr;
		return true;
	}
	return false;
}

// Edit info of student
bool editStudent(PTRSTUDENT studentList, char* studentCode, Student& updatedInfo) {
	PTRSTUDENT temp = studentList;
	while (temp != nullptr) {
		if (strcmp(temp->info.studentCode, studentCode) == 0) {
			temp->info = updatedInfo;
			return true;
		}
		temp = temp->next;
	}
	return false;
}

// Find student by code or name
PTRSTUDENT findStudent(PTRSTUDENT studentList, char* studentCode) {
	PTRSTUDENT temp = studentList;
	while (temp != nullptr) {
		if (strcmp(temp->info.studentCode, studentCode) == 0) {
			return temp;
		}
		temp = temp->next;
	}
	return nullptr;
}


// Load student from file
void loadStudentsFromFile(PTRSTUDENT& studentList, const string& fileName) {
	ifstream file(fileName, ios::binary);
	if (!file.is_open()) {
		cout << "Không thể mở file để đọc!" << endl;
		return;
	}

	Student student;
	while (file.read((char*)&student, sizeof(Student))) {
		addStudent(studentList, student);
	}

	file.close();
}

// phân trang
void paginateStudents(PTRSTUDENT studentList, int page, int pageSize) {
	int startIndex = (page - 1) * pageSize;  // Chỉ số bắt đầu
	int currentIndex = 0;  // Chỉ số hiện tại
	PTRSTUDENT temp = studentList;

	// Duyệt qua danh sách sinh viên để tìm các sinh viên trong trang hiện tại
	while (temp != nullptr) {
		// Kiểm tra xem sinh viên hiện tại có nằm trong khoảng chỉ số của trang hay không
		if (currentIndex >= startIndex && currentIndex < startIndex + pageSize) {
			// Hiển thị thông tin sinh viên
			cout << "MSSV: " << temp->info.studentCode << ", "
				<< "Ho: " << temp->info.firstName << ", "
				<< "Ten: " << temp->info.lastName << ", "
				<< "Gioi tinh: " << temp->info.gender << endl;
		}
		currentIndex++;
		temp = temp->next;  // Chuyển đến sinh viên tiếp theo
	}

	// Kiểm tra nếu không có sinh viên nào trên trang
	if (currentIndex == startIndex) {
		cout << "Khong co sinh vien tren trang " << page << "." << endl;
	}
}


void addStudentToClass(Classroom& classroom, Student& student) {
	PTRSTUDENT& studentInClass = classroom.studentList;
	addStudent(studentInClass, student);
}