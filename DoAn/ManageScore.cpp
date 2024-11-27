#include "ManageScore.h"

ManageScore::ManageScore()
{
}

ManageScore::~ManageScore()
{
}

bool addScoreToList(PTRSCORE& scoreList,string subjectCode, float score)
{
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

