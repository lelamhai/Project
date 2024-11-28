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

bool updateScoreToList(PTRSCORE& scoreList, string subjectCode, float score);