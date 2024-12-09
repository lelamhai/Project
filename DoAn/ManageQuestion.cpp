#include "ManageQuestion.h"

ManageQuestion::ManageQuestion()
{
}

// khởi tạo sao chép infor từ q
//ManageQuestion::ManageQuestion(PTRQUESTION q) {
//	if (q == nullptr) {
//		questionList = nullptr;
//		return;
//	}
//
//	// Tạo node đầu tiên của questionList
//	questionList = new NodeQuestion;
//	questionList->info = q->info;
//	questionList->next = nullptr;
//
//	PTRQUESTION temp = questionList;
//	q = q->next;
//
//	// Sao chép phần còn lại của danh sách
//	while (q != nullptr) {
//		// Tạo một node mới và sao chép dữ liệu
//		PTRQUESTION newNode = new NodeQuestion;
//		newNode->info = q->info;
//		newNode->next = nullptr;
//
//		// Kết nối node mới vào danh sách
//		temp->next = newNode;
//		temp = newNode; // Di chuyển con trỏ current đến node mới
//
//		q = q->next; // Di chuyển con trỏ q đến node tiếp theo
//	}
//}

// khởi tạo với con trỏ questionList trỏ vào con trỏ truyền vào hàm
ManageQuestion::ManageQuestion(const PTRQUESTION &q) {
	questionList = q;
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
	int count = 0;
	PTRQUESTION p = questionList;
	while (p != nullptr) {
		count++;
		p = p->next;
	}
	return count;
}

int ManageQuestion::insertFirst_Question(const Question &question) {
	PTRQUESTION temp = new NodeQuestion;
	temp->info = question;
	temp->next = questionList;
	
	questionList = temp;
	return 1;
}

int ManageQuestion::insertLast_Question(const Question& question) {
	PTRQUESTION temp = new NodeQuestion;
	temp->info = question;
	temp->next = nullptr;

	if(questionList == nullptr) {
		questionList = temp;
		return 1;
	}
	
	PTRQUESTION ptrLast = questionList;
	while (ptrLast->next != nullptr) {
		ptrLast = ptrLast->next;
	}
	ptrLast->next = temp;
	return 1;
}

void ManageQuestion::clearQuestionList() {
	// duyệt qua từng phần tử của list và giải phóng bộ nhớ
	while (questionList != nullptr) {
		PTRQUESTION temp = questionList;
		questionList = questionList->next;
		delete temp;
	}
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

int ManageQuestion::loadFromFile(){
	ifstream file(SOURCE_QUESTION);

	if (!file.is_open()) {
		return -1; // load không thành công
	}

	json js;
	file >> js; // Đọc file jason lưu vào đối tượng js
	file.close();

	clearQuestionList(); // xóa danh sách cũ để chuẩn bị cho đọc dữ liệu mới từ file
	
	for (const auto& questionData : js["question"]) {
		Question question;
		question.questionId = questionData["questionID"].get<int>();
		question.content = questionData["content"].get<string>();
		question.optionA = questionData["optionA"].get<string>();
		question.optionB = questionData["optionB"].get<string>();
		question.optionC = questionData["optionC"].get<string>();
		question.optionD = questionData["optionD"].get<string>();
		question.answer = questionData["answer"].get<char>();

		insertLast_Question(question);
	}
	return 1;
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

char ManageQuestion::getAnswer(const int questionID) {
	PTRQUESTION temp = questionList;
	while (temp != nullptr) {
		if (temp->info.questionId == questionID) {
			return temp->info.answer;
		}
		temp = temp->next;
	}
	return NULL; // ID câu hỏi không tồn tại
}

void ManageQuestion::getRandomQuestion(int n) {
	// Tạo mảng để lưu tất cả các questionId của môn học
	int totalQuestion = getCountQuestionInList(questionList);
	int* questionIdAll = new int[totalQuestion];
	PTRQUESTION temp = questionList;
	for (int i = 0; i < totalQuestion; i++) {
		questionIdAll[i] = temp->info.questionId;
		temp = temp->next;
	}
	// trộn ngẫu nhiên mảng ID câu hỏi
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = totalQuestion - 1; i > 0; --i) {
		int j = rand() % (i + 1);
		swap(questionIdAll[i], questionIdAll[j]);
	}

	// tạo một list mới với n ID đã random. xóa list cũ
	PTRQUESTION questionList_Random = nullptr;;
	PTRQUESTION tempR = nullptr; // con trỏ để duyệt questionList_Random
	
	int currID;
	temp = questionList;
	bool isFirstElement = true;
	for (int i = 0; i < n; i++) {
		temp = questionList;
		currID = questionIdAll[i];

		while (temp != nullptr) {
			if (currID == temp->info.questionId) {
				PTRQUESTION newNode = new NodeQuestion; // Khởi tạo một node mới
				newNode->info = temp->info;
				newNode->next = nullptr;

				if (isFirstElement) { // Nếu là node đầu tiên
					questionList_Random = newNode;
					tempR = questionList_Random; // Gán con trỏ để duyệt
					isFirstElement = false;
				}
				else {
					tempR->next = newNode;
					tempR = tempR->next; // Chuyển con trỏ đến node cuối
				}
				break; // Thoát khỏi vòng lặp khi tìm thấy câu hỏi
			}
			temp = temp->next;
		}
	}

	questionList = questionList_Random;
	delete[] questionIdAll;
}

Question ManageQuestion::getQuestionByIndex(int n) {
	PTRQUESTION p = questionList;
	for (int i = 0; i < n; i++) {
		if (p == nullptr) {
			return p->info; // n vượt quá phần tử của list
		}
		p = p->next;
	}
	return p->info;
}

PTRQUESTION ManageQuestion::getQuestionList() {
	return questionList;
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

QuestionPage getQuestionPerPage(PTRQUESTION questionList, int page)
{
	QuestionPage questionPage;
	questionPage.questionList = nullptr;
	int questionPerPage = 13;
	questionPage.totalPage = 0;
	questionPage.totalQuestions = 0;
	if (questionList == nullptr) return questionPage;
	int totalQuestions = getCountQuestionInList(questionList);
	int totalPages = (totalQuestions + questionPerPage - 1) / questionPerPage;
	questionPage.currentPage = page;
	questionPage.totalPage = totalPages;
	questionPage.totalQuestions = totalQuestions;
	questionPage.numberQuestionPerPage = questionPerPage;

	PTRQUESTION pageResult = nullptr;
	
	if (page < 1 || page > totalPages) {
		return questionPage;
	}

	// Tính toán chỉ số bắt đầu và kết thúc
	int startIndex = (page - 1) * questionPerPage;
	int endIndex = min(startIndex + questionPerPage, totalQuestions);
	int count = 0;

	while (questionList != nullptr) {
		if (count >= startIndex && count < endIndex) {
			addQuestionToList(pageResult, questionList->info);
		}
		if (count >= endIndex) {
			break;
		}
		count++;
		questionList = questionList->next;
	}

	questionPage.startIndex = startIndex;
	questionPage.endIndex = endIndex;
	questionPage.questionList = pageResult;

	return questionPage;
}

bool addQuestionToList(PTRQUESTION& questionList, Question question1) {
	PTRQUESTION tmpQuestion = new NodeQuestion;
	tmpQuestion->info = question1;
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

void printQuestionsInList(PTRQUESTION questionList)
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
