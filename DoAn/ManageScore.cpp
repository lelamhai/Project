#include "ManageScore.h"

ManageScore::ManageScore()
{
}

ManageScore::~ManageScore()
{
}

scoreToPrintList ManageScore::getScoreOfClass(const char* classCode, const char* subjectCode) {
    // Lấy ra danh sách sinh viên của một lớp
    ManageClass manageClass;
    Classroom class1 = manageClass.findClassByCode(classCode);
    PTRSTUDENT studentList = class1.studentList;

    // Đếm số sinh viên trong lớp
    int countStudent = 0;
    PTRSTUDENT temp = studentList;
    while (temp != nullptr) {
        countStudent ++;
        temp = temp->next;
    }

    // sao chep thong tin qua array diem
    scoreToPrintList scoreListToPrint;
    scoreListToPrint.countStudent = countStudent;
    strcpy_s(scoreListToPrint.classCode, sizeof(scoreListToPrint.classCode), classCode);
    strcpy_s(scoreListToPrint.subjectCode, sizeof(scoreListToPrint.subjectCode), subjectCode);

    // duyệt qua từng phần tử của studentList để lưu vào array điểm
    PTRSTUDENT p = studentList;
    Student currStudent;
    PTRSCORE q = nullptr; // con trỏ duyệt để tìm điểm của môn học
    for (int i = 0; i < countStudent; i++) {
        currStudent = p->info;
        
        scoreListToPrint.array[i] = new scoreToPrint;

        strcpy_s(scoreListToPrint.array[i]->studentCode, sizeof(scoreListToPrint.array[i]->studentCode), currStudent.studentCode);
        strcpy_s(scoreListToPrint.array[i]->firstName, sizeof(scoreListToPrint.array[i]->firstName), currStudent.firstName);
        strcpy_s(scoreListToPrint.array[i]->lastName, sizeof(scoreListToPrint.array[i]->lastName), currStudent.lastName);
        
        // duyet qua list score cua mot sinh vien va tim diem cua mon hoc
        q = currStudent.scoreList;
        scoreListToPrint.array[i]->score = -1; // SV chưa thi môn này
        while (q != nullptr) {
            if (strcmp(q->info.subjectCode, subjectCode) == 0) {
                scoreListToPrint.array[i]->score = q->info.diem;
                break;
            }
            q = q->next;
        }
        p = p->next; // chuyen con tro qua SV tiep theo
    }

    return scoreListToPrint;
}

//ScorePage ManageScore::getSocrePerPage(int pageNumber){
//
//}


bool updateScoreToList(PTRSCORE& scoreList,string subjectCode, float score)
{
    PTRSCORE temp = scoreList;
    while (temp != nullptr) {
        if (string(temp->info.subjectCode) == subjectCode && temp->info.diem < score) {
            temp->info.diem = score;
            return true;
        }
        else if (string(temp->info.subjectCode) == subjectCode && temp->info.diem >= score) {
            return false;
        }
        temp = temp->next;
    }

    PTRSCORE newScore = new NodeScore;
    newScore->info.diem = score;

    strcpy_s(newScore->info.subjectCode, subjectCode.c_str());
    newScore->next = nullptr;

    if (scoreList == nullptr) {
        scoreList = newScore;
    }
    else {
        newScore->next = scoreList;
        scoreList = newScore;
    }

	return false;
}

