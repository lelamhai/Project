#include "ManageQuestion.h"

ManageQuestion::ManageQuestion()
{
}

ManageQuestion::~ManageQuestion()
{
}

bool ManageQuestion::addQuestion(const string content, const string optionA, const string optionB, const string optionC, const string optionD, const char answer)
{
	Question newQuestion;
	newQuestion.questionId = generateUniqueId();
	newQuestion.content = content;
	newQuestion.optionA = optionA;
	newQuestion.optionB = optionB;
	newQuestion.optionC = optionC;
	newQuestion.optionD = optionD;
	newQuestion.answer = answer;

	PTRQUESTION tmpQuestion = new NodeQuestion;
	tmpQuestion->info = newQuestion;
	tmpQuestion->next = nullptr;

	if (questionList == nullptr) {
		questionList = tmpQuestion;
	}
	else {
		tmpQuestion->next = questionList;
		questionList = tmpQuestion;
	}

	return true;
}

bool ManageQuestion::editQuestion(int questionId, const string content, const string optionA, const string optionB, const string optionC, const string optionD, const char answer)
{
	PTRQUESTION tmp = questionList;
	
	while (tmp != nullptr) {
		if (tmp->info.questionId == questionId) {
			tmp->info.content = content;
			tmp->info.optionA = optionA;
			tmp->info.optionB = optionB;
			tmp->info.optionC = optionC;
			tmp->info.optionD = optionD;
			tmp->info.answer = answer;
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

PTRQUESTION ManageQuestion::findQuestion(int questionId)
{
	PTRQUESTION tmp = questionList;
	while (tmp != nullptr) {
		if (tmp->info.questionId == questionId) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return nullptr;
}

bool ManageQuestion::deleteQuestion(int questionId)
{
	if (questionList == nullptr) return false;
	if (questionList->info.questionId == questionId) {
		PTRQUESTION temp = questionList;
		questionList = questionList->next;
		delete temp;
		return true;
	}

	PTRQUESTION prev = questionList;
	PTRQUESTION curr = questionList->next;
	while (curr != nullptr && curr->info.questionId == questionId) {
		prev = curr;
		curr = curr->next;
	}
	if (curr != nullptr) {
		prev->next = curr->next;
		delete curr;
		return true;
	}
	return false;
}

void ManageQuestion::printQuestions()
{
	PTRQUESTION temp = questionList;
	while (temp != nullptr) {
		cout << "Cau hoi: " << temp->info.questionId << endl;
		cout << "A. " << temp->info.optionA << endl;
		cout << "B. " << temp->info.optionB << endl;
		cout << "C. " << temp->info.optionC << endl;
		cout << "D. " << temp->info.optionD << endl;
		temp = temp->next;
	}

}

PTRSTUDENT ManageQuestion::paginateQuestions(int page, int pageSize)
{
	return PTRSTUDENT();
}

int ManageQuestion::getCountQuestions()
{
	return 0;
}

void ManageQuestion::saveToFile()
{
}

void ManageQuestion::loadFromFile()
{
}

int ManageQuestion::generateUniqueId()
{
	int newId;
	do {
		newId = rand() % 10000 + 1000;
	} while (isUniqueId(newId));
	return newId;
}

bool ManageQuestion::isUniqueId(int randomId) {
	while (questionList != nullptr) {
		if (questionList->info.questionId == randomId) {
			return false;
		}
		questionList = questionList->next;
	}
	return true;
}
