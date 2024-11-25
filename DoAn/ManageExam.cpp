#include "ManageExam.h"

ManageExam::ManageExam() {
    isTimeUp = false;
    isSubmitted = false;
}

ManageExam::~ManageExam() {

}

bool ManageExam::setTimeForExam(int timeForExam) {
    if (timeForExam <= 0) {
        return false;
    }

    this->timeForExam_min = timeForExam;
    remainingTime_sec = timeForExam_min * 60;
    return true;
}

bool ManageExam::setNumberQuestion(int numberQuestion) {
    ManageSubject subject;
    int totalQuestion = subject.countQuestionsInSubject(subjectCode);
    
    if (numberQuestion<0 || numberQuestion > totalQuestion) {
        return false;
    }

    this->numberQuestion = numberQuestion;
    return true;
}

int ManageExam::getNumberQuestion() {
    return numberQuestion;
}

bool ManageExam::setSubjectCode(char* subjectCode) {
    this->subjectCode = subjectCode;
    return true;
}

bool ManageExam::getRandomQuestion() {
    answerRecord.answerList[MAX_NUMBER_QUESTION];
    for (int i = 0; i < numberQuestion; i++) {
        answerRecord.answerList[i] = new answer; // Cấp phát bộ nhớ cho mỗi phần tử
    }

    questionList_Random = subjectList.getRandomQuestion(numberQuestion, subjectCode);
    if (questionList_Random.getCountQuestions() == 0) {
        cout << "Danh sach cau hoi trong!" << endl;
    }

    // Sao chép dữ liệu ID câu hỏi và câu trả lời qua mảng
    PTRQUESTION p = questionList_Random.getList();
    for (int i = 0; i < numberQuestion; i++) {
        answerRecord.answerList[i]->questionId = p->info.questionId;
        answerRecord.answerList[i]->correctAnswer = p->info.answer;
        p = p->next;
    }

    return true;
}

int ManageExam::getRemainingTime() {
    return remainingTime_sec;
}

void ManageExam::changeRemainingTime(int t) {
    remainingTime_sec += t;
}

bool ManageExam::getIsSubmitted() {
    return isSubmitted;
}
void ManageExam::setSubmitted() {
    isSubmitted = true;
}

bool ManageExam::getTimeUp() {
    return isTimeUp;
}
void ManageExam::setTimeUp() {
    isTimeUp = true;
}


Question ManageExam::getRandomedQuestionByIndex(int i) {
    return questionList_Random.getQuestionByIndex(i); 
}

answer* ManageExam::getAnswer(int index) {
    return answerRecord.answerList[index];
}
void ManageExam::setAnswer(int index, char choose) {
    answerRecord.answerList[index]->chosenAnswer = choose;
}



tm ManageExam::getTimeStart() {
    time_t currentTime = time(NULL); // lấy thời gian hiện tại gán vào biến (format giây)
    tm timeStart;                // thời gian bắt thi format giây, giờ phút giây, ngày tháng năm
    
    localtime_s(&timeStart, &currentTime); // chuyển đối time dạng time_t thành kiểu tm

    return timeStart;
}

tm ManageExam::getTimeEnd(tm timeStart) {
    tm timeEnd;

    time_t timeStart_t = mktime(&timeStart); //chuyển đổi time kiểu tm sang kiểu time_t
    timeStart_t += timeForExam_min * 60; // cộng thêm thời gian thi vào thời gian bắt đầu
    
    localtime_s(&timeEnd, &timeStart_t); // chuyển đối time dạng time_t thành kiểu tm
    
    return timeEnd;
}


