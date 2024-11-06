#include "ManageStudent.h"

ManageStudent::ManageStudent()
{
}

ManageStudent::~ManageStudent()
{
}

bool ManageStudent::addStudent(const char* studentCode, const char* firstName, const char* lastName, char gender, const char* password) {
    Student std1;
    strcpy_s(std1.studentCode, studentCode);
    strcpy_s(std1.firstName, firstName);
    strcpy_s(std1.lastName, lastName);
    std1.gender = gender;
    strcpy_s(std1.password, password);

    PTRSTUDENT tmpStudent = new NodeStudent;
    tmpStudent->info = std1;
    tmpStudent->next = nullptr;
    if (studentList == nullptr) {
        studentList = tmpStudent;
    }
    else {
        tmpStudent->next = studentList;
        studentList = tmpStudent;
    }
    
    return true;
}


bool ManageStudent::openFile_Student(const char* filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        return false;
    }

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        Student tempStudent;
        string temp;

        getline(iss, temp, ',');
        strcpy_s(tempStudent.studentCode, sizeof(tempStudent.studentCode), temp.c_str());

        getline(iss, temp, ',');
        strcpy_s(tempStudent.firstName, sizeof(tempStudent.firstName), temp.c_str());

        getline(iss, temp, ',');
        strcpy_s(tempStudent.lastName, sizeof(tempStudent.lastName), temp.c_str());

        getline(iss, temp, ',');
        tempStudent.gender = temp[0];

        getline(iss, temp, ',');
        strcpy_s(tempStudent.password, sizeof(tempStudent.password), temp.c_str());


        addStudent(tempStudent.studentCode, tempStudent.firstName, tempStudent.lastName, tempStudent.gender, tempStudent.password);
    }
    inFile.close();
    return true;
}

bool ManageStudent::logIn(string user, string password) 
{
    if (user.empty() && password.empty())
    {
        return false;
    }

    for (PTRSTUDENT p = studentList; p != NULL; p = p->next) 
    {
        if (user == p->info.studentCode && password == p->info.password)
        {
            return true;
        }
    }
    if (user == "GV" && password == "GV")
    {
        return true;
    } 

    return false;
}

// Edit info of student
bool ManageStudent::editStudent(const char* studentCode, const char* firstName, const char* lastName, char gender, const char* password) {
    PTRSTUDENT temp = studentList;
    while (temp != nullptr) {
        if (strcmp(temp->info.studentCode, studentCode) == 0) {
            strcpy_s(temp->info.firstName, firstName);
            strcpy_s(temp->info.lastName, lastName);
            strcpy_s(temp->info.password, password);
            temp->info.gender = gender;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Find student by code or name
PTRSTUDENT ManageStudent::findStudent(char* studentCode) {
    PTRSTUDENT temp = studentList;
    while (temp != nullptr) {
        if (strcmp(temp->info.studentCode, studentCode) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

// Delete student by student code
bool ManageStudent::deleteStudent(const char* studentCode) {
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

void ManageStudent::printStudents() {
    PTRSTUDENT temp = studentList;
    while (temp != nullptr) {
        cout << "Ma sinh vien: " << temp->info.studentCode << endl;
        cout << "Ho va ten: " << temp->info.firstName << " " << temp->info.lastName << endl;
        cout << "Gioi tinh: " << (temp->info.gender == 'M' ? "Nam" : "Nu") << endl;
        cout << "-------------------------------------------" << endl;
        temp = temp->next;
    }
}

PTRSTUDENT ManageStudent::paginateStudents(int page, int pageSize) {
    int startIndex = (page - 1) * pageSize;  // Chỉ số bắt đầu
    int currentIndex = 0;  // Chỉ số hiện tại
    PTRSTUDENT temp = studentList;
    PTRSTUDENT paginatedList = nullptr;  // Danh sách sinh viên trả về
    PTRSTUDENT tail = nullptr;  // Dùng để thêm sinh viên vào danh sách kết quả

    // Duyệt qua danh sách sinh viên để tìm các sinh viên trong trang hiện tại
    while (temp != nullptr) {
        // Kiểm tra xem sinh viên hiện tại có nằm trong khoảng chỉ số của trang hay không
        if (currentIndex >= startIndex && currentIndex < startIndex + pageSize) {
            // Tạo một node mới cho sinh viên và thêm vào danh sách kết quả
            PTRSTUDENT newStudent = new NodeStudent;
            newStudent->info = temp->info;  // Sao chép thông tin sinh viên
            newStudent->next = nullptr;

            // Nếu danh sách kết quả rỗng, sinh viên này là phần tử đầu tiên
            if (paginatedList == nullptr) {
                paginatedList = newStudent;
            }
            else {
                tail->next = newStudent;  // Thêm sinh viên vào cuối danh sách
            }
            tail = newStudent;  // Cập nhật con trỏ tail
        }
        currentIndex++;
        temp = temp->next;  // Chuyển đến sinh viên tiếp theo
    }

    // Kiểm tra nếu không có sinh viên nào trên trang
    if (paginatedList == nullptr) {
        cout << "Khong co sinh vien tren trang " << page << "." << endl;
    }

    return paginatedList;  // Trả về danh sách sinh viên trong trang hiện tại
}

void ManageStudent::saveToFile() {
    json j;  // Tạo đối tượng JSON để lưu dữ liệu sinh viên

    PTRSTUDENT temp = studentList;
    int studentIndex = 0;  // Chỉ số cho sinh viên trong mảng JSON

    while (temp != nullptr) {
        // Tạo đối tượng JSON cho sinh viên
        json studentData;
        studentData["studentCode"] = temp->info.studentCode;
        studentData["firstName"] = temp->info.firstName;
        studentData["lastName"] = temp->info.lastName;
        studentData["gender"] = temp->info.gender;
        studentData["password"] = temp->info.password;

        // Mảng điểm của sinh viên
        studentData["scores"] = json::array();
        PTRSCORE scorePtr = temp->info.scoreList;
        int scoreIndex = 0;  // Chỉ số cho điểm trong mảng JSON
        while (scorePtr != nullptr) {
            json scoreData;
            scoreData["subjectCode"] = scorePtr->info.subjectCode;
            scoreData["score"] = scorePtr->info.diem;

            // Thêm điểm vào mảng với chỉ số xác định
            studentData["scores"][scoreIndex++] = scoreData;
            scorePtr = scorePtr->next;
        }

        // Thêm sinh viên vào mảng sinh viên trong JSON bằng cách sử dụng chỉ số
        j["students"][studentIndex++] = studentData;
        temp = temp->next;
}

    // Ghi đối tượng JSON vào file
    ofstream file(SOURCE_STUDENT);
    if (file.is_open()) {
        file << j.dump(4);  // Lưu với định dạng đẹp (indent = 4)
        file.close();
        cout << "Data saved successfully in JSON format." << endl;
    }
    else {
        cout << "Unable to open file for saving." << endl;
    }
}

void ManageStudent::loadFromFile() {
    ifstream file(SOURCE_STUDENT);  // Mở file JSON
    if (!file.is_open()) {
        cout << "Could not open file!" << endl;
        return;
    }

    json j;
    file >> j;  // Đọc dữ liệu từ file vào đối tượng JSON
    file.close();

    studentList = nullptr;  // Khởi tạo danh sách sinh viên
    PTRSTUDENT* lastStudent = &studentList;  // Con trỏ để quản lý sinh viên cuối cùng trong danh sách

    // Duyệt qua từng sinh viên trong JSON
    for (int studentIndex = 0; studentIndex < j["students"].size(); studentIndex++) {
        json studentData = j["students"][studentIndex];  // Lấy dữ liệu của từng sinh viên

        // Tạo sinh viên mới
        PTRSTUDENT newStudent = new NodeStudent();
        strcpy_s(newStudent->info.studentCode, studentData["studentCode"].get<string>().c_str());
        strcpy_s(newStudent->info.firstName, studentData["firstName"].get<string>().c_str());
        strcpy_s(newStudent->info.lastName, studentData["lastName"].get<string>().c_str());
        newStudent->info.gender = studentData["gender"].get<char>();
        strcpy_s(newStudent->info.password, studentData["password"].get<string>().c_str());

        // Đọc danh sách điểm của sinh viên
        newStudent->info.scoreList = nullptr;
        PTRSCORE* lastScore = &newStudent->info.scoreList;
        for (int scoreIndex = 0; scoreIndex < studentData["scores"].size(); scoreIndex++) {
            json scoreData = studentData["scores"][scoreIndex];  // Lấy dữ liệu của từng điểm

            // Tạo điểm mới
            PTRSCORE newScore = new NodeScore();
            strcpy_s(newScore->info.subjectCode, scoreData["subjectCode"].get<string>().c_str());
            newScore->info.diem = scoreData["score"].get<float>();

            // Thêm điểm vào danh sách điểm của sinh viên
            *lastScore = newScore;
            lastScore = &newScore->next;
        }
        *lastScore = nullptr;  // Kết thúc danh sách điểm

        // Thêm sinh viên vào danh sách sinh viên
        *lastStudent = newStudent;
        lastStudent = &newStudent->next;
    }

    *lastStudent = nullptr;  // Kết thúc danh sách sinh viên

    cout << "Data loaded successfully from JSON format." << endl;
}




int ManageStudent::getCountStudents() {
    int count = 0;
    PTRSTUDENT temp = studentList;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

int getCountStudentOfList(PTRSTUDENT listStudent) {
    int count = 0;
    PTRSTUDENT temp = listStudent;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

