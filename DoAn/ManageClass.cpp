#include "ManageClass.h"

ManageClass::ManageClass()
{
    loadFromFile();
}

ManageClass::~ManageClass()
{
}

Classroom ManageClass::findClassByCode(const char* classCode)
{
    Classroom classFound;
    strcpy_s(classFound.classCode, "");
    classFound.className = "";
    int index = findClass(classCode);
    if (index != -1) {
        strcpy_s(classFound.classCode, classes[index]->classCode);
        classFound.className = classes[index]->className;
        classFound.studentList = classes[index]->studentList;
    }
    return classFound;
}


ClassPage ManageClass::searchClass(string keyword, int page)
{
    ManageClass classList2;
    if (keyword == "") {
        return classList2.getClassPerPage(page);
    }
    int countClass2 = 0;
    classList2.reset();
    for (int i = 0; i < countClass; i++) {
        string classCodeStr = string(classes[i]->classCode);
        if (containString(classCodeStr, keyword) || containString(classes[i]->className, keyword)) {
            classList2.classes[countClass2] = classes[i];
            countClass2++;
        }
    }
    classList2.countClass = countClass2;
    return classList2.getClassPerPage(page);
}

ClassList ManageClass::getClasses() {
    ClassList classList;
    classList.countClass = countClass;
    for (int i = 0; i < countClass; i++) {
        classList.classes[i] = classes[i];
    }
    return classList;
}

int ManageClass::getCountClass() {
    return countClass;
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
        for (int i = countClass; i > 0 ; i--) {
            classes[i] = classes[i-1];
        }
		classes[0] = new Classroom;
		strcpy_s(classes[0]->classCode, classCode);
		classes[0]->className = className;
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
        printStudentsInList(classes[i]->studentList);
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
}

bool ManageClass::addStudentToClass(const string classCode, const string studentCode, const string firstName, const string lastName, char gender, const string password)
{
    int index = findClass(classCode.c_str()); // Check is classCode exist
    if (index == -1) return false;
    if (findStudentInList(classes[index]->studentList, studentCode.c_str()) != nullptr) return false; //Check is student code exist in class
    
    Student std1;
    strcpy_s(std1.studentCode, studentCode.c_str());
    strcpy_s(std1.firstName, firstName.c_str());
    strcpy_s(std1.lastName, lastName.c_str());
    std1.gender = gender;
    strcpy_s(std1.password, password.c_str());

    PTRSTUDENT tmpStudent = new NodeStudent;
    tmpStudent->info = std1;
    tmpStudent->next = nullptr;
    if (classes[index]->studentList == nullptr) {
        classes[index]->studentList = tmpStudent;
    }
    else {
        tmpStudent->next = classes[index]->studentList;
        classes[index]->studentList = tmpStudent;
    }
    saveToFile();
    return true;
}

bool ManageClass::editStudentInClass(const string classCode, const string studentCode, const string firstName, const string lastName, char gender, const string password)
{
    int index = findClass(classCode.c_str());
    if (index == -1) return false;
    PTRSTUDENT student = findStudentInList(classes[index]->studentList, studentCode.c_str());
    if (student == nullptr) return false;
    strcpy_s(student->info.firstName, firstName.c_str());
    strcpy_s(student->info.lastName, lastName.c_str());
    strcpy_s(student->info.password, password.c_str());
    student->info.gender = gender;
    saveToFile();
    return true;
}


bool ManageClass::deleteStudentInClass(const char* classCode, const char* studentCode) {
    int index = findClass(classCode); // Check is classCode exist
    if (index == -1) return 0;
    deleteStudentInList(classes[index]->studentList, studentCode);
    saveToFile();
}

StudentPage ManageClass::searchStudentInCLass(const string classCode, string keyword, int page)
{
    StudentPage result;
    int index = findClass(classCode.c_str()); // Check is classCode exist
    if (index == -1) return result;
    if (keyword == "") {
        return getStudentPerPage(classes[index]->studentList, page);
    }
    PTRSTUDENT resultList = new NodeStudent;
    PTRSTUDENT startList = classes[index]->studentList;
    while (startList != nullptr) {
        string fullName = string(startList->info.firstName) + " " + string(startList->info.lastName);
        
        if (containString(fullName, keyword) || containString(string(startList->info.studentCode), keyword)) {
            addStudentToList(resultList, startList->info);
        }
        startList = startList->next;
    }
    
    return getStudentPerPage(resultList, page);
}

// Get count student in class
int ManageClass::getCountSudentOfClass(const char* classCode)
{
    int count = 0;
    int index = findClass(classCode);
    if (index == -1) return 0;
    PTRSTUDENT studentList = classes[index]->studentList;
    while (studentList != nullptr) {
        count++;
        studentList = studentList->next;
    }
    return count;
}

// phân trang
ClassPage ManageClass::getClassPerPage(int pageNumber) {
    ClassPage classPage;
    int classesPerPage = 13;
    int totalClasses = countClass;
    int totalPages = (totalClasses + classesPerPage - 1) / classesPerPage;
    classPage.currentPage = pageNumber;
    classPage.totalPage = totalPages;
    classPage.totalClass = countClass;
    classPage.numberClassPerPage = classesPerPage;

    ClassList pageResult;  // Tạo đối tượng kết quả trả về

    // Kiểm tra nếu trang không hợp lệ
    if (pageNumber < 1 || pageNumber > totalPages) {
        //cout << "Trang " << pageNumber << " không tồn tại!" << endl;
        return classPage;
    }

    // Tính toán chỉ số bắt đầu và kết thúc
    int startIndex = (pageNumber - 1) * classesPerPage;
    int endIndex = min(startIndex + classesPerPage, totalClasses);

    // Thêm các lớp thuộc trang vào kết quả trả về
    for (int i = startIndex; i < endIndex; i++) {
        pageResult.classes[pageResult.countClass++] = classes[i];
    }

    classPage.startIndex = startIndex;
    classPage.endIndex = endIndex;
    classPage.classList = pageResult;

    return classPage;  // Trả về danh sách lớp của trang đã chọn
}

// Login
bool ManageClass::logIn(const char* user, const char* password)
{
    if (strcmp(user, "") == 0 && strcmp(password, "") == 0)
    {
        return false;
    }

    if (strcmp(user,"GV") == 0 && strcmp(password, "GV")==0) 
    {
        Singleton::getInstance()->role = "GV";
        return true;
    }

    for (int i = 0 ; i < countClass; i++) 
    {
        PTRSTUDENT temp = classes[i]->studentList;
        while (temp != nullptr) {
            if (strcmp(temp->info.studentCode, user) == 0 && strcmp(temp->info.password, password) == 0) {
                 Singleton::getInstance()->role = temp->info.studentCode;
                 return true;
            }
            temp = temp->next;
        }
    }

    return false;
}

// hàm bắt đầu thi trắc nghiệm
bool ManageClass::startExam(const char* studentCode, const char* subjectCode, int n, int timeSetting_Minute) {
    ManageSubject subject;
    ManageQuestion questionList_Random;
    // tạo ra danh sách n câu hỏi ngẫu nhiên từ môn học
    questionList_Random = subject.getRandomQuestion(n, subjectCode);
    
    // khởi tạo mảng để lưu kết quả thi
    resultList result_List;
    result_List.countDone = 0;
    result_List.score = 0;

    // đưa ra từng nội dung câu hỏi cho front end hiển thị sau đó


    // khởi tạo thời gian theo dõi làm bài
    int startTime = static_cast<int>(time(NULL));
    int endTime = startTime + timeSetting_Minute * 60;  // Chuyển thời gian từ phút sang giây
    int remainingTime = timeSetting_Minute * 60;        // Thời gian còn lại, tính bằng giây



    return true;
}

// Reset class
void ManageClass::reset() {
    for (int i = 0; i < countClass; i++) {
        delete classes[i]; 
        classes[i] = nullptr;
    }
    
    countClass = 0; 
}

void printClassPage(ClassPage classPage)
{
    cout << "Trang " << classPage.currentPage << "/" << classPage.totalPage<<endl;
    cout << classPage.classList.countClass << "/" << classPage.numberClassPerPage<<endl;
    for (int i = 0; i < classPage.classList.countClass; i++) {
        cout << "Ma lop: " << classPage.classList.classes[i]->classCode << endl;
        cout << "Ten lop: " << classPage.classList.classes[i]->className << endl;
        cout << "-------------------------------------------" << endl;
    }
}

// Hàm kiểm tra chuỗi
bool containString(const string& str, const string& substr) {
    return toLowerString(str).find(toLowerString(substr)) != string::npos;
}

string toLowerString(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    return str;
}