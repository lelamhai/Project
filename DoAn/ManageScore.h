#pragma once
#include "StrucData.h"

class ManageScore
{
private:
	PTRSCORE scoreList;
public:
	ManageScore();
	~ManageScore();
};

bool addScoreToList(PTRSCORE& scoreList, string subjectCode, float score);