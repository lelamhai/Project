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

string ManageStudent::logIn(string user, string password) {
    /*char user[15];
    char password[30];*/
    bool isUserCorrect;

    while (true) {
        isUserCorrect = false;
        /*cout << "Nhap tai khoan dang nhap: ";
        cin >> user;
        cout << "Nhap mat khau: ";
        cin >> password;*/

        if (user =="GV") {
            if (password=="GV") {
                cout << "Dang nhap thanh cong tai khoan Giao Vien" << endl;
                return "GV";
            }
            else {
                return "Mat khau khong dung, vui long nhap lai";
            }
        }

        else {
            for (PTRSTUDENT p = studentList; p != NULL; p = p->next) {
                if (user == p->info.studentCode) {
                    isUserCorrect = true;
                    if (password == p->info.password) {
                        cout << "Dang nhap thanh cong!" << endl;
                        return p->info.studentCode;
                    }
                    else {
                        cout << "Mat khau khong dung, vui long nhap lai";
                    }
                }
            }

            if (!isUserCorrect) {
                return "Tai khoan khong ton tai, vui long thu lai";
            }
        }
    }
}