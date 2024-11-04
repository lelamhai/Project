#include "MCQList.h"
using namespace std;

PTRQUESTION newNodeQuestion(Question x) {
    PTRQUESTION tmp = new NodeQuestion();
    tmp->info = x;
    tmp->next = NULL;
    return tmp;
}

void insertFirst_MCQ(PTRQUESTION& p, Question x) {
    PTRQUESTION tmp = newNodeQuestion(x);
    if (p == NULL) {
        p = tmp;
    }
    else {
        tmp->next = p;
        p = tmp;
    }
}

bool saveFile_MCQ(PTRQUESTION MCQList, const char* filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        return false;
    }

    for (PTRQUESTION p = MCQList; p != NULL; p = p->next) {
        outFile << p->info.questionId << "|"
            << p->info.content << "|"
            << p->info.optionA << "|"
            << p->info.optionB << "|"
            << p->info.optionC << "|"
            << p->info.optionD << "|"
            << p->info.answer << endl; // Kết thúc mỗi sinh viên bằng dấu | và xuống dòng
    }
    outFile.close();
    return true;
}

bool openFile_MCQ(PTRQUESTION& MCQtList, const char* filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        return false;
    }

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        Question tempQuestion;
        string temp;

        getline(iss, temp, '|');
        strcpy_s(tempQuestion.questionId, sizeof(tempQuestion.questionId), temp.c_str());

        getline(iss, temp, '|');
        strcpy_s(tempQuestion.content, sizeof(tempQuestion.content), temp.c_str());

        getline(iss, temp, '|');
        strcpy_s(tempQuestion.optionA, sizeof(tempQuestion.optionA), temp.c_str());

        getline(iss, temp, '|');
        strcpy_s(tempQuestion.optionB, sizeof(tempQuestion.optionB), temp.c_str());

        getline(iss, temp, '|');
        strcpy_s(tempQuestion.optionC, sizeof(tempQuestion.optionC), temp.c_str());

        getline(iss, temp, '|');
        strcpy_s(tempQuestion.optionD, sizeof(tempQuestion.optionD), temp.c_str());

        getline(iss, temp, '|');
        tempQuestion.answer = temp[0];

        insertFirst(MCQList, tempQuestion);
    }
    inFile.close();
    return true;
}
