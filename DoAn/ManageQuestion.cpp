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
		cout << temp->info.questionId << " - " << temp->info.content << endl;
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

void ManageQuestion::saveToFile() {
	json js; // tạo một đối tượng JASON để lưu dữ liệu câu hỏi trắc nghiệm
	PTRQUESTION temp = questionList;
	int questionIndex = 0; // chỉ số cho câu hỏi trong mảng JSON

	while (temp != nullptr) {
		// tạo đối tượng JASON để lưu mảng câu hỏi
		json questionData; 
		questionData["questionID"] = temp->info.questionId;
		questionData["content"] = temp->info.content;
		questionData["optionA"] = temp->info.optionA;
		questionData["optionB"] = temp->info.optionB;
		questionData["optionC"] = temp->info.optionC;
		questionData["optionD"] = temp->info.optionD;
		questionData["answer"] = temp->info.answer;

		// thêm câu hỏi vào mảng trong JSON bằng cách sử dụng chỉ số 
		js["question"][questionIndex++] = questionData; 
		temp = temp->next;
	}

	// ghi đối tượng JSON vào file
	ofstream file(SOURCE_QUESTION);
	if (file.is_open()) {
		file << js.dump(4);  // Lưu với định dạng đẹp (indent = 4)
		file.close();
		//cout << "Luu thanh cong";
	}
}

void ManageQuestion::loadFromFile()
{
}

int ManageQuestion::generateUniqueId()
{
	int newId;
	srand(static_cast<unsigned int>(time(NULL)));
	do {
		newId = rand() % 10000 + 1;
	} while (!isUniqueId(newId));
	return newId;
}


bool ManageQuestion::isUniqueId(int randomId) {
	PTRQUESTION temp = questionList;
	while (temp != nullptr) {
		if (temp->info.questionId == randomId) {
			return false;
		}
		temp = temp->next;
	}
	return true;
}

int generateUniqueQuestionId(PTRQUESTION questionList) {
	 //Sử dụng random để tạo số ngẫu nhiên
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 10000); // Sinh số trong khoảng 1 - 10000

	int newId;
	bool isUnique;

	//PTRQUESTION current = questionList;
	do {
		newId = dis(gen);  // Sinh ra một questionId mới
		isUnique = true;

		// Kiểm tra xem questionId này có trùng với bất kỳ câu hỏi nào đã tồn tại không
		PTRQUESTION current = questionList;
		while (current != nullptr) {
			if (current->info.questionId == newId) {
				isUnique = false;
				break;
			}
			current = current->next;
		}
	} while (!isUnique);  // Lặp lại nếu questionId không duy nhất

	return newId;
}

int getCountQuestionInList(PTRQUESTION questionList) {
	// Đếm tổng số câu hỏi của một môn học
	int count = 0;
	PTRQUESTION temp = questionList;
	while (temp) {
		count++;
		temp = temp->next;
	}
	return count;
}
