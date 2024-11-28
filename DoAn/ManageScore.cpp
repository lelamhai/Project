#include "ManageScore.h"

ManageScore::ManageScore()
{
}

ManageScore::~ManageScore()
{
}

bool updateScoreToList(PTRSCORE& scoreList,string subjectCode, float score)
{
    PTRSCORE temp = scoreList;
    while (temp != nullptr) {
        if (string(temp->info.subjectCode) == subjectCode && temp->info.diem < score) {
            temp->info.diem = score;
            return true;
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

