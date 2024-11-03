#include "StudentList.h"
using namespace std;

PTRSTUDENT newNodeStudent(Student x) {
    PTRSTUDENT tmp = new NodeStudent();
    tmp->info = x;
    tmp->next = NULL;
    return tmp;
}

void insertFirst(PTRSTUDENT& p, Student x) {
    PTRSTUDENT tmp = newNodeStudent(x);
    if (p == NULL) {
        p = tmp;
    }
    else {
        tmp->next = p;
        p = tmp;
    }
}

bool saveFile_Student(PTRSTUDENT studentList, const char* filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        return false;
    }

    for (PTRSTUDENT p = studentList; p != NULL; p = p->next) {
        outFile << p->info.studentCode << ","
            << p->info.firstName << ","
            << p->info.lastName << ","
            << p->info.gender << ","
            << p->info.password << endl; // Kết thúc mỗi sinh viên bằng xuống dòng
    }
    outFile.close();
    return true;
}

bool openFile_Student(PTRSTUDENT& studentList, const char* filename) {
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


        insertFirst(studentList, tempStudent);
    }
    inFile.close();
    return true;
}
