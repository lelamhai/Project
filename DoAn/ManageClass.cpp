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
        saveToFile();
		return true;
	}
	return false;
}

bool ManageClass::editClass(const char* classCode, const string className) {
	int index = findClass(classCode);
	if (index != -1) {
		classes[index]->className = className;
        saveToFile();
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
        saveToFile();
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

void ManageClass::saveToFile() {
    json j;
    j["classCount"] = countClass;

    for (int i = 0; i < countClass; i++) {
        json classData;
        classData["classCode"] = classes[i]->classCode;
        classData["className"] = classes[i]->className;
        classData["students"] = json::array();  // Mảng sinh viên

        // Duyệt danh sách sinh viên
        PTRSTUDENT studentPtr = classes[i]->studentList;
        while (studentPtr != nullptr) {
            json studentData;
            studentData["studentCode"] = studentPtr->info.studentCode;
            studentData["firstName"] = studentPtr->info.firstName;
            studentData["lastName"] = studentPtr->info.lastName;
            studentData["gender"] = studentPtr->info.gender;
            studentData["password"] = studentPtr->info.password;

            studentData["scores"] = json::array();  // Mảng điểm
            PTRSCORE scorePtr = studentPtr->info.scoreList;
            while (scorePtr != nullptr) {
                json scoreData;
                scoreData["subjectCode"] = scorePtr->info.subjectCode;
                scoreData["score"] = scorePtr->info.diem;
                studentData["scores"].push_back(scoreData);
                scorePtr = scorePtr->next;
            }

            classData["students"].push_back(studentData);
            studentPtr = studentPtr->next;
        }

        j["classes"].push_back(classData);
    }

    ofstream file(SOURCE_CLASS);
    if (file.is_open()) {
        file << j.dump(4);  // Lưu file với định dạng JSON, thụt đầu dòng 4 spaces
        file.close();
        cout << "Data saved successfully in JSON format." << endl;
    }
    else {
        cout << "Unable to open file for saving." << endl;
    }
}

// Hàm load dữ liệu từ file JSON
void ManageClass::loadFromFile() {
    ifstream file(SOURCE_CLASS);
    if (!file.is_open()) {
        cout << "Could not open file!" << endl;
        return;
    }

    json j;
    file >> j;
    file.close();

    // Đọc số lượng lớp học
    countClass = j["classCount"];

    for (int i = 0; i < countClass; i++) {
        classes[i] = new Classroom();
        json classData = j["classes"][i];

        // Đọc thông tin lớp học
        strcpy_s(classes[i]->classCode, classData["classCode"].get<string>().c_str());
        classes[i]->className = classData["className"];

        // Đọc danh sách sinh viên
        classes[i]->studentList = nullptr;
        PTRSTUDENT* lastStudent = &classes[i]->studentList;

        for (const auto& studentData : classData["students"]) {
            PTRSTUDENT newStudent = new NodeStudent();
            strcpy_s(newStudent->info.studentCode, studentData["studentCode"].get<string>().c_str());
            strcpy_s(newStudent->info.firstName, studentData["firstName"].get<string>().c_str());
            strcpy_s(newStudent->info.lastName, studentData["lastName"].get<string>().c_str());
            newStudent->info.gender = studentData["gender"].get<char>();
            strcpy_s(newStudent->info.password, studentData["password"].get<string>().c_str());

            // Đọc danh sách điểm
            newStudent->info.scoreList = nullptr;
            PTRSCORE* lastScore = &newStudent->info.scoreList;
            for (const auto& scoreData : studentData["scores"]) {
                PTRSCORE newScore = new NodeScore();
                strcpy_s(newScore->info.subjectCode, scoreData["subjectCode"].get<string>().c_str());
                newScore->info.diem = scoreData["score"].get<float>();
                *lastScore = newScore;
                lastScore = &newScore->next;
            }
            *lastScore = nullptr;  // Kết thúc danh sách điểm

            *lastStudent = newStudent;
            lastStudent = &newStudent->next;
        }
        *lastStudent = nullptr;  // Kết thúc danh sách sinh viên
    }

    cout << "Data loaded successfully from JSON format." << endl;
}

// phân trang
ClassList ManageClass::getClassPerPage(int pageNumber, int classesPerPage) {
    int totalClasses = countClass;
    int totalPages = (totalClasses + classesPerPage - 1) / classesPerPage;

    ClassList pageResult;  // Tạo đối tượng kết quả trả về

    // Kiểm tra nếu trang không hợp lệ
    if (pageNumber < 1 || pageNumber > totalPages) {
        cout << "Trang " << pageNumber << " không tồn tại!" << endl;
        return pageResult;  // Trả về ClassList rỗng
    }

    // Tính toán chỉ số bắt đầu và kết thúc
    int startIndex = (pageNumber - 1) * classesPerPage;
    int endIndex = min(startIndex + classesPerPage, totalClasses);

    // Thêm các lớp thuộc trang vào kết quả trả về
    for (int i = startIndex; i < endIndex; i++) {
        pageResult.classes[pageResult.countClass++] = classes[i];
    }

    return pageResult;  // Trả về danh sách lớp của trang đã chọn
}













