#include "ManageExam.h"

ManageExam::ManageExam(int numberQuestion, const char* subjectCode, int timeForExam_min) {
    this->numberQuestion = numberQuestion;
    this->timeForExam_min = timeForExam_min;
    this->subjectCode = subjectCode;
    
    isTimeUp = false;
    isSubmitted = false;

    answerRecord.countDone = 0;
    answerRecord.answerList[MAX_NUMBER_QUESTION];
    for (int i = 0; i < numberQuestion; i++) {
        answerRecord.answerList[i] = new answer; // Cấp phát bộ nhớ cho mỗi phần tử
    }

    //ManageSubject subjectList;
    //ManageQuestion questionList_Random;
    //questionList_Random = subjectList.getRandomQuestion(numberQuestion, subjectCode);

    //if (questionList_Random.getCountQuestions() == 0) {
    //    cout << "Danh sach cau hoi trong!" << endl;
    //}

}

ManageExam::~ManageExam() {

}

void ManageExam::countDown() {
    remainingTime_sec = timeForExam_min * 60;
    while (remainingTime_sec > 0) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            if (isSubmitted) {
                break; // Nếu người thi chọn nộp bài thi sớm
            }
        }

        this_thread::sleep_for(chrono::seconds(1));
        {
            std::lock_guard<std::mutex> lock(mtx);
            remainingTime_sec--;
            cout << "Thoi gian con lai: " << remainingTime_sec << endl;
            if (remainingTime_sec == 0) {
                isTimeUp = true;
                cout << "\nHet thoi gian lam bai!\n";
            }
        }
    }
}

void ManageExam::conductExam() {
    // Xử lý hiển thị thời gian bắt đầu thi
    time_t currentTime = time(NULL); // thời gian bắt thi format giây
    tm timeStartExam;                // thời gian bắt thi format giây, giờ phút giây, ngày tháng năm
    localtime_s(&timeStartExam, &currentTime);

    cout << "Bat dau thi: "
        << (timeStartExam.tm_hour < 10 ? "0" : "") << timeStartExam.tm_hour << ":"
        << (timeStartExam.tm_min < 10 ? "0" : "") << timeStartExam.tm_min << ":"
        << (timeStartExam.tm_sec < 10 ? "0" : "") << timeStartExam.tm_sec << "\n";

    // Xử lý hiển thị thời gian kết thúc thi
    time_t endTime = currentTime + timeForExam_min * 60;
    tm timeEndExam;
    localtime_s(&timeEndExam, &endTime);

    cout << "Han nop bai: "
        << (timeEndExam.tm_hour < 10 ? "0" : "") << timeEndExam.tm_hour << ":"
        << (timeEndExam.tm_min < 10 ? "0" : "") << timeEndExam.tm_min << ":"
        << (timeEndExam.tm_sec < 10 ? "0" : "") << timeEndExam.tm_sec << "\n";

    
    
    
    ManageSubject subjectList;
    ManageQuestion questionList_Random;
    questionList_Random = subjectList.getRandomQuestion(numberQuestion, subjectCode);

    if (questionList_Random.getCountQuestions() == 0) {
        cout << "Danh sach cau hoi trong!" << endl;
    }


    // Sao chép dữ liệu ID câu hỏi và câu trả lời qua mảng
    int currQuestion = 0;
    Question q = questionList_Random.getQuestionByIndex(currQuestion);
    PTRQUESTION p = questionList_Random.getList();

    //if (q == NULL) {
    //    cout << "Loi truy cap cau hoi!" << endl;
    //    return;
    //}

    //struct resultList answerRecord;
    for (int i = 0; i < numberQuestion; i++) {
        answerRecord.answerList[i]->questionId = p->info.questionId;
        answerRecord.answerList[i]->correctAnswer = p->info.answer;
        p = p->next;
    }

    // Bắt đầu quá trình thi
    while (!isTimeUp && !isSubmitted) {
        int ID = questionList_Random.getQuestionByIndex(currQuestion).questionId;

        string content = questionList_Random.getQuestionByIndex(currQuestion).content;
        cout << "Cau " << currQuestion+1 << ": " << content << endl;

        string optionA = questionList_Random.getQuestionByIndex(currQuestion).optionA;
        cout << optionA << endl;

        string optionB = questionList_Random.getQuestionByIndex(currQuestion).optionB;
        cout << optionB << endl;

        string optionC = questionList_Random.getQuestionByIndex(currQuestion).optionC;
        cout << optionC << endl;

        string optionD = questionList_Random.getQuestionByIndex(currQuestion).optionD;
        cout << optionD << endl;

        string choose;
        cout << "Nhap lua chon (A, B, C, D, N =next, P =previous, E =exit):" << endl;
        cin >> choose;
        if (choose == "N") {
            if (currQuestion >= numberQuestion) {
                currQuestion = 0;
            }
            else {
                currQuestion++;
            }
        }
        else if (choose == "P"){
            if (currQuestion <= 0) {
                currQuestion = numberQuestion;
            }
            currQuestion--;
                
        }
        else if (choose == "E") {
            isSubmitted = true;
            return;
        }
        else if (choose == "A") {
            answerRecord.answerList[currQuestion]->chosenAnswer = 'A';
            if (currQuestion >= numberQuestion-1) {
                currQuestion = 0;
            }
            else {
                currQuestion++;
            }
        }
        else if (choose == "B") {
            answerRecord.answerList[currQuestion]->chosenAnswer = 'B';
            if (currQuestion >= numberQuestion-1) {
                currQuestion = 0;
            }
            else {
                currQuestion++;
            }

        }
        else if (choose == "C") {
            answerRecord.answerList[currQuestion]->chosenAnswer = 'C';
            if (currQuestion >= numberQuestion-1) {
                currQuestion = 0;
            }
            else {
                currQuestion++;
            }
        }
        else if (choose == "D") {
            answerRecord.answerList[currQuestion]->chosenAnswer = 'D';
            if (currQuestion >= numberQuestion-1) {
                currQuestion = 0;
            }
            else {
                currQuestion++;
            }
        }
  
    }
}

