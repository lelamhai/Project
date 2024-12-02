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

bool ManageExam::setInputExam(char* subjectCode,char* studentCode , int numberQuestion, int timeForExam){
    ManageSubject manageSubject1;
    
    // trả về false nếu mã môn không tồn tại
    PTRSUBJECT subject = manageSubject1.getSubject(subjectCode);
    if (subject == nullptr) {
        return false;
    }

    // trả về false số câu hỏi nhập không hợp lệ
    int totalQuestion = manageSubject1.countQuestionsInSubject(subjectCode);
    if (numberQuestion<0 || numberQuestion > totalQuestion) {
        return false;
    }
    
    this->subjectCode = subjectCode;
    this->studentCode = studentCode;
    this->numberQuestion = numberQuestion;
    this->timeForExam_min = timeForExam;
    remainingTime_sec = timeForExam_min * 60;
    return true;
}

Question* ManageExam::getRandomQuestion() {
    // cấp phát vùng nhớ cho mảng lưu kết quả
    for (int i = 0; i < numberQuestion; i++) {
        answerRecord.answerList[i] = new answer;  
    }

    questionList_Random = subjectList.getRandomQuestion(numberQuestion, subjectCode);
    if (questionList_Random.getCountQuestions() == 0) {
        cout << "Danh sach cau hoi trong!" << endl;
    }

    // Sao chép dữ liệu ID câu hỏi và câu trả lời qua mảng
    PTRQUESTION p = questionList_Random.getQuestionList();
    for (int i = 0; i < numberQuestion; i++) {
        answerRecord.answerList[i]->questionId = p->info.questionId;
        answerRecord.answerList[i]->correctAnswer = p->info.answer;
        
        randomQuestionList[i].content = p->info.content;
        randomQuestionList[i].optionA = p->info.optionA;
        randomQuestionList[i].optionB = p->info.optionB;
        randomQuestionList[i].optionC = p->info.optionC;
        randomQuestionList[i].optionD = p->info.optionD;
        randomQuestionList[i].answer = p->info.answer;
        
        p = p->next;

        //randomQuestionList[i] = questionList_Random.getQuestionByIndex(i);
    }

    //return questionList_Random.getQuestionList();

    return randomQuestionList;
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


resultList ManageExam::getAnsweredList() {
    toCalculateResult();
    return answerRecord;
}

answer* ManageExam::getAnsweredByIndex(int index) {
    return answerRecord.answerList[index];
}
void ManageExam::setAnswer(int index, char choose) {
    answerRecord.answerList[index]->chosenAnswer = choose;
}

void ManageExam::toCalculateResult() {
    int index = 0;
    int correctAnswer = 0;
    float score;
    answer* p;
    
    for (int i = 0; i < numberQuestion; i++) {
        p = answerRecord.answerList[index];
        if (p->chosenAnswer == p->correctAnswer) {
            correctAnswer++;
        }
        index++;
    }
    answerRecord.countCorrect = correctAnswer;
    score = (float)correctAnswer * 10 / numberQuestion;
    answerRecord.score = roundNumber(score, 1); // làm tròn điểm đến 1 số thập phân
    
    // Ghi điểm vào file data
    ManageClass tempClass;
    tempClass.addScoreToStudent(studentCode, subjectCode, answerRecord.score);
}

int ManageExam::countCorrectAnswer() {
    return answerRecord.countCorrect;
}

double ManageExam::getScore() {
    return answerRecord.score;
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

float ManageExam::roundNumber(float number, int n) {
    float x = pow(10.0f, n);
    return round(number * x) / x;
}


