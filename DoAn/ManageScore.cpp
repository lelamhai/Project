#include "ManageScore.h"

ManageScore::ManageScore() {

}

ManageScore::~ManageScore(){
    // giải phóng bộ nhớ cho listToPrint
    for (int i = 0; i < listToPrint.countStudent; i++) {
        delete listToPrint.array[i];
    }
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

    // xử lý dữ liệu và trả về 1 nếu input hợp lệ
    strcpy_s(listToPrint.classCode, sizeof(listToPrint.classCode), classCode);
    strcpy_s(listToPrint.subjectCode, sizeof(listToPrint.subjectCode), subjectCode);
    getScoreOfClass(); // gọi hàm để thực hiện tạo danh sách điểm theo môn cho một lớp;
    return 1; 
}

string ManageScore::getClassName() {
    ManageClass manageClass;
    Classroom class1 = manageClass.findClassByCode(listToPrint.classCode);
    return class1.className;
}

string ManageScore::getSubjectName() {
    ManageSubject manageSubject;
    PTRSUBJECT p = manageSubject.getSubject(listToPrint.subjectCode);
    
    if (p == nullptr) {
        return "";
    }
    return p->info.subjectName;
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

ScorePage ManageScore::getScorePerPage(scoreToPrintList* listSoucre, int pageNumber) {
    ScorePage scorePage;
    int scorePerPage = 13;
    int totalScore = listSoucre->countStudent;
    
    int totalPages = (totalScore + scorePerPage - 1) / scorePerPage;
    scorePage.currentPage = pageNumber;
    scorePage.totalPage = totalPages;
    scorePage.totalScore = totalScore;
    scorePage.numberScorePerPage = scorePerPage;

    // Kiểm tra nếu trang không hợp lệ
    if (pageNumber < 1 || pageNumber > totalPages) {
        //cout << "Trang " << pageNumber << " không tồn tại!" << endl;
        scorePage.startIndex = 0;
        scorePage.endIndex = 0;
        return scorePage;
    }

    // Tính toán chỉ số bắt đầu và kết thúc
    int startIndex = (pageNumber - 1) * scorePerPage;
    int endIndex = min(startIndex + scorePerPage, totalScore);

    // Thêm các lớp thuộc trang vào kết quả trả về 
    for (int i = startIndex; i < endIndex; i++) {
        scoreToPrintList* p = &scorePage.printList;
        scoreToPrint* q = listSoucre->array[i];

        copyScoreToList(p, q, i - startIndex); // copy điểm từ list tổng sang list phân trang
    }

    scorePage.startIndex = startIndex;
    scorePage.endIndex = endIndex;

    return scorePage;  // Trả về danh sách lớp của trang đã chọn
}

ScorePage ManageScore::getScorePerPage(int pageNumber) {
    ScorePage scorePage;
    scoreToPrintList* p = &listToPrint;

    scorePage = getScorePerPage(p, pageNumber); // phân trang từ danh sách điểm listToPrint của class
    return scorePage;
}

bool ManageScore::copyScoreToList(scoreToPrintList* list, scoreToPrint* scoreToCopy, int index) {
    list->array[index] = new scoreToPrint;
    scoreToPrint* p = list->array[index];
 
    strcpy_s(p->studentCode, sizeof(p->studentCode), scoreToCopy->studentCode);
    strcpy_s(p->firstName, sizeof(p->firstName), scoreToCopy->firstName);
    strcpy_s(p->lastName, sizeof(p->lastName), scoreToCopy->lastName);
    p->gender = scoreToCopy->gender;
    p->score = scoreToCopy->score;

    list->countStudent++;

    return true;
}

ScorePage ManageScore::searchStudentScore(string keyWord, int pageNumber) {
    ScorePage resultPage;
    scoreToPrintList* p;
    p = &resultPage.printList;

    if (keyWord == "") {
        scoreToPrintList* listptr = &listToPrint;
        resultPage = getScorePerPage(listptr, pageNumber);
        return resultPage;
    }

    int countStd = listToPrint.countStudent;
    int indexToCopy = 0;
    for (int i = 0; i < countStd; i++) {
        scoreToPrint* q = listToPrint.array[i];
        string fullName = string(q->firstName) + " " + string(q->lastName);
        if (containString(fullName, keyWord) || containString(q->studentCode, keyWord)) {
            copyScoreToList(p, q, indexToCopy);
            indexToCopy++;
        }
    }
   
    resultPage = getScorePerPage(p, pageNumber);
    return resultPage; 
}

resultList* ManageScore::loadResultFromFile(const char* subjectCode, const char* studentCode) {
    resultList* result = new resultList;
    result->studentCode = studentCode;
    result->subjectCode = subjectCode;
    result->totalQuestion = 0;
    result->countCorrect = 0;
    result->score = 0;

    // Đọc dữ liệu từ file JSON
    std::ifstream inputFile(EXAM_RESULT_FILE_NAME);
    if (!inputFile.is_open()) {
        cout << "Không thể mở file" << EXAM_RESULT_FILE_NAME << endl;
        return nullptr;
    }

    json j;
    inputFile >> j; // Đọc JSON từ file
    inputFile.close();

    // Duyệt qua các phần tử trong JSON
    for (const auto& answerRecordData : j) {
        if (answerRecordData["studentCode"] == studentCode && answerRecordData["subjectCode"] == subjectCode) {
            result->totalQuestion = answerRecordData["totalQuestion"].get<int>();
            result->countCorrect = answerRecordData["countCorrect"].get<int>();
            result->score = answerRecordData["score"].get<float>() / 10; // chia 10 vì lúc lưu đã *10
            result->timeExam = answerRecordData["timeExam"].get<time_t>(); // Lấy thời gian làm bài

            // Lấy danh sách câu trả lời
            int index = 0;
            for (const auto& answered : answerRecordData["Answered"]) {
                result->answerList[index] = new answer;
                result->answerList[index]->questionId = answered["questionId"].get<int>();
                result->answerList[index]->chosenAnswer = answered["chosenAnswer"].get<std::string>()[0];
                result->answerList[index]->correctAnswer = answered["correctAnswer"].get<std::string>()[0];
                index++;
            }
            return result; // Trả về kết quả tìm thấy
        }
    }

    // Nếu không tìm thấy, giải phóng bộ nhớ và trả về nullptr
    delete result;
    return nullptr;
}

Question ManageScore::getQuestionBySubjectCodeAndId(const string subjectCode, int questionId) {
    ManageSubject manageSubject;
    Question q = manageSubject.getQuestionBySubjectCodeAndId(subjectCode, questionId);
    return q;
}

void ManageScore::deallocateResulList(resultList* rs) {
    for (int i = 0; i < rs->totalQuestion; i++) {
        delete rs->answerList[i];
    }
    delete rs;
}


void ManageScore::deallocateScorePage(ScorePage &page) {
    scoreToPrintList* p = &page.printList;

    for (int i = 0; i < p->countStudent; i++) {
        delete p->array[i];
    }
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

