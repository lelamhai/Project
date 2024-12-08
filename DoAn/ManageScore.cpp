#include "ManageScore.h"

ManageScore::ManageScore()
{
}

ManageScore::~ManageScore()
{
}

int ManageScore::setInputPrintScore(const char* classCode, const char* subjectCode) {
    // trả về -2 nếu mã lớp không tồn tại
    ManageClass manageClass;
    int check = manageClass.findClass(classCode);//hàm trả về -1 nếu không tìm thấy mã lớp
    if (check == -1) {
        return -2;
    }

    // trả về -1 nếu mã môn không tồn tại
    ManageSubject manageSubject;
    PTRSUBJECT subject = manageSubject.getSubject(subjectCode);
    if (subject == nullptr) {
        return -1;
    }

    // trả về 1 nếu input hợp lệ
    strcpy_s(listToPrint.classCode, sizeof(listToPrint.classCode), classCode);
    strcpy_s(listToPrint.subjectCode, sizeof(listToPrint.subjectCode), subjectCode);
    
    getScoreOfClass(); // gọi hàm để thực hiện tạo danh sách điểm theo môn cho một lớp

    return 1; 
}

scoreToPrintList ManageScore::getScoreOfClass() {
    // Lấy ra danh sách sinh viên của một lớp
    ManageClass manageClass;
    Classroom class1 = manageClass.findClassByCode(listToPrint.classCode);
    PTRSTUDENT studentList = class1.studentList;

    // Đếm số sinh viên trong lớp
    int countStudent = 0;
    PTRSTUDENT temp = studentList;
    while (temp != nullptr) {
        countStudent++;
        temp = temp->next;
    }
    listToPrint.countStudent = countStudent;

    // duyệt qua từng phần tử của studentList để lưu vào array điểm
    PTRSTUDENT p = studentList; // con trỏ duyệt sinh viên
    Student currStudent;
    PTRSCORE q = nullptr; // con trỏ duyệt để tìm điểm của môn học
    for (int i = 0; i < countStudent; i++) {
        currStudent = p->info;
        
        listToPrint.array[i] = new scoreToPrint;// cấp phát bộ nhớ mỗi node điểm
        scoreToPrint* prt = listToPrint.array[i];

        strcpy_s(prt->studentCode, sizeof(prt->studentCode), currStudent.studentCode);
        strcpy_s(prt->firstName, sizeof(prt->firstName), currStudent.firstName);
        strcpy_s(prt->lastName, sizeof(prt->lastName), currStudent.lastName);
        prt->gender=currStudent.gender;
        
        // duyet qua list score cua mot sinh vien va tim diem cua mon hoc
        q = currStudent.scoreList;
        listToPrint.array[i]->score = -1; // SV chưa thi môn này
        while (q != nullptr) {
            if (strcmp(q->info.subjectCode, listToPrint.subjectCode) == 0) {
                listToPrint.array[i]->score = q->info.diem;
                break;
            }
            q = q->next;
        }
        p = p->next; // chuyen con tro qua SV tiep theo
    }

    return listToPrint;
}

scoreToPrintList ManageScore::getScoreAllPage(){
    return listToPrint;
}

ScorePage ManageScore::getScorePerPage(int pageNumber) {
    ScorePage scorePage;
    int scorePerPage = 13;
    int totalScore = listToPrint.countStudent;
    int totalPages = (totalScore + scorePerPage - 1) / scorePerPage;
    scorePage.currentPage = pageNumber;
    scorePage.totalPage = totalPages;
    scorePage.totalScore = totalScore;
    scorePage.numberScorePerPage = scorePerPage;

    // Kiểm tra nếu trang không hợp lệ
    if (pageNumber < 1 || pageNumber > totalPages) {
        cout << "Trang " << pageNumber << " không tồn tại!" << endl;
        return scorePage;
    }

    // Tính toán chỉ số bắt đầu và kết thúc
    int startIndex = (pageNumber - 1) * scorePerPage;
    int endIndex = min(startIndex + scorePerPage, totalScore);

    // Thêm các lớp thuộc trang vào kết quả trả về
    for (int i = startIndex; i < endIndex; i++) {
        scorePage.printList.array[i - startIndex] = new scoreToPrint;
        scoreToPrint* p = scorePage.printList.array[i-startIndex];
        scoreToPrint* q = listToPrint.array[i];

        strcpy_s(p->studentCode, sizeof(p->studentCode), q->studentCode);
        strcpy_s(p->firstName, sizeof(p->firstName), q->firstName);
        strcpy_s(p->lastName, sizeof(p->lastName), q->lastName);
        p->gender = q->gender;
        p->score = q->score;
    }

    scorePage.startIndex = startIndex;
    scorePage.endIndex = endIndex;

    return scorePage;  // Trả về danh sách lớp của trang đã chọn
}



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

