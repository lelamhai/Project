﻿#include "ManageSubject.h"

ManageSubject::ManageSubject()
{
    loadFromFile();
}

ManageSubject::~ManageSubject()
{
}

PTRSUBJECT ManageSubject::getListSubject()
{
    return subjectList;
}

// ----------------------- PUBLIC METHOD --------------------------//
// Thêm môn học mới
bool ManageSubject::addSubject(const string code, const string name) {
    PTRSUBJECT subjectFound = searchSubject(subjectList, code.c_str());
    if (subjectFound != nullptr) return false;
    Subject newSubject;
    strcpy_s(newSubject.subjectCode, code.c_str());
    newSubject.subjectName = name;
    newSubject.listQuestion = nullptr;
    insertSubject(newSubject);
    saveToFile();
    return true;
}

// Edit một môn học theo mã
bool ManageSubject::editSubject(const string code, const string subjectName)
{
    PTRSUBJECT subjectFound = searchSubject(subjectList, code.c_str());
    if (subjectFound == nullptr) return false;
    subjectFound->info.subjectName = subjectName;
    saveToFile();
    return true;
}

// Tìm kiếm môn học theo mã môn học
PTRSUBJECT ManageSubject::getSubject(const char* code) {
    return searchSubject(subjectList, code);
}

bool ManageSubject::isSubjectExist(const string subjectCode)
{
    PTRSUBJECT subjectFound = getSubject(subjectCode.c_str());
    return subjectFound != nullptr;
}

// Thêm câu hỏi vào môn học
bool ManageSubject::addQuestionInSubject(const char* subjectCode, const string& content,
    const string& optionA, const string& optionB,
    const string& optionC, const string& optionD, char answer) {

    // Tìm kiếm môn học dựa trên mã môn học
    PTRSUBJECT subject = getSubject(subjectCode);
    if (optionA == optionB || optionA == optionC || optionA == optionD || optionB == optionC || optionB == optionD || optionC == optionD) {
        return false;
    }
    if (subject) {
        // Nếu tìm thấy môn học, thêm câu hỏi
        addQuestionToSubject(subject, content, optionA, optionB, optionC, optionD, answer);
        saveToFile();
        return true;
    }
    return false;
}

bool ManageSubject::editQuestionInSubject(const string subjectCode, int questionId, const string content, const string optionA, const string optionB, const string optionC, const string optionD, const char answer)
{
    PTRSUBJECT subjectFound = getSubject(subjectCode.c_str());
    if (subjectFound == nullptr) return false;
    if (optionA == optionB || optionA == optionC || optionA == optionD || optionB == optionC || optionB == optionD || optionC == optionD) {
        return false;
    }

    PTRQUESTION questionList = subjectFound->info.listQuestion;
    while (questionList != nullptr) {
        if (questionList->info.questionId == questionId) {
            questionList->info.content = content;
            questionList->info.optionA = optionA;
            questionList->info.optionB = optionB;
            questionList->info.optionC = optionC;
            questionList->info.optionD = optionD;
            questionList->info.answer = answer;
            saveToFile();
            return true;
        }
        questionList = questionList->next;
    }
    return false;
}

bool ManageSubject::isQuestionCanDelete(const string subjectCode, int questionId)
{
    PTRSUBJECT subjectFound = getSubject(subjectCode.c_str());
    PTRQUESTION questionList = subjectFound->info.listQuestion;
    while (questionList != nullptr) {
        if (questionId == questionList->info.questionId) {
            return questionList->info.isInExam == false;
        }
        questionList = questionList->next;
    }
    return false;
}

bool ManageSubject::deleteQuestionInSubject(const string subjectCode, int questionId)
{
    PTRSUBJECT subjectFound = getSubject(subjectCode.c_str());
    if (subjectFound == nullptr) return false;

    PTRQUESTION questionList = subjectFound->info.listQuestion;
    if (questionList == nullptr) return false;
    
    // Kiểm tra và xóa câu hỏi đầu tiên nếu khớp
    if (questionList->info.questionId == questionId) {
        if (questionList->info.isInExam) return false;
        PTRQUESTION temp = questionList;
        questionList = questionList->next;
        delete temp;
        subjectFound->info.listQuestion = questionList;
        saveToFile();
        return true;
    }

    PTRQUESTION prev = questionList;
    PTRQUESTION curr = questionList->next;
    while (curr != nullptr) {
        if (curr->info.questionId == questionId) {
            if (curr->info.isInExam) return false;
            prev->next = curr->next;
            delete curr;
            subjectFound->info.listQuestion = questionList;
            saveToFile();
            return true;
        }
        prev = curr;
        curr = curr->next;
    }

    return false;
}

QuestionPage ManageSubject::searchQuestionInSubject(const string subjectCode, const string keyword, int pageNumber)
{
    QuestionPage result;
    result.numberQuestionPerPage = 13;
    result.totalPage = 0;
    result.totalQuestions = 0;
    result.startIndex = 0;
    result.endIndex = 0;
    result.currentPage = 0;
    result.questionList = nullptr;
    PTRSUBJECT foundSubject = getSubject(subjectCode.c_str());
    if (foundSubject == nullptr) return result;
    if (keyword == "") {
        return getQuestionPerPage(foundSubject->info.listQuestion, pageNumber);
    }

    PTRQUESTION resultList = nullptr;
    PTRQUESTION startList = foundSubject->info.listQuestion;

    while (startList != nullptr) {
        string questionIdStr = to_string(startList->info.questionId);
        string questionContent = startList->info.content;
        if (containString(questionIdStr, keyword) || containString(questionContent, keyword)) {
            addQuestionToList(resultList, startList->info);
        }
        startList = startList->next;
    }
    return getQuestionPerPage(resultList, pageNumber);
}

Question ManageSubject::getQuestionBySubjectCodeAndId(const string subjectCode, int questionId)
{
    Question result;
    PTRSUBJECT subjectFound = getSubject(subjectCode.c_str());
    if (subjectFound == nullptr) return result;
    PTRQUESTION questionList = subjectFound->info.listQuestion;
    while (questionList != nullptr) {
        if (questionList->info.questionId == questionId) {
            result.questionId = questionId;
            result.content = questionList->info.content;
            result.optionA = questionList->info.optionA;
            result.optionB = questionList->info.optionB;
            result.optionC = questionList->info.optionC;
            result.optionD = questionList->info.optionD;
            result.answer = questionList->info.answer;
            break;
        }
        questionList = questionList->next;
    }
    return result;
}

void ManageSubject::setIsInExamOfQuestion(const char* subjectCode, int questionId) {
    PTRSUBJECT p =  getSubject(subjectCode);
    
    PTRQUESTION q = p->info.listQuestion;
    while (q != nullptr) {
        if (q->info.questionId == questionId) {
            q->info.isInExam = true;
            saveToFile();
            return;
        }
        q = q->next;
    }
}

// In danh sách tất cả các môn học
void ManageSubject::printAllSubjects() {
    printSubjects(subjectList);
}

int ManageSubject::getCountSubjects()
{
    return countSubjectsInRoot(subjectList);
}



// Hàm tính tổng số câu hỏi của một môn học dựa trên mã môn học
int ManageSubject::countQuestionsInSubject(const char* subjectCode) {
    PTRSUBJECT subject = getSubject(subjectCode);
    if (subject) {
        return getCountQuestionInList(subject->info.listQuestion);
    }
    else {
        return 0;
    }
}

void ManageSubject::saveToFile() {
    json j;  // Tạo đối tượng JSON để lưu dữ liệu môn học

    // Duyệt cây nhị phân theo chiều sâu (DFS)
    saveSubjectToJson(subjectList, j);

    // Ghi đối tượng JSON vào file
    ofstream file(SUBJECT_FILE_NAME);
    if (file.is_open()) {
        file << j.dump(4);  // Lưu với định dạng đẹp (indent = 4)
        file.close();
    }
}

// Hàm hỗ trợ duyệt cây nhị phân và lưu vào JSON
void ManageSubject::saveSubjectToJson(PTRSUBJECT node, json& j) {
    if (node == nullptr) return;

    // Tạo đối tượng JSON cho môn học
    json subjectData;
    subjectData["subjectCode"] = node->info.subjectCode;
    subjectData["subjectName"] = node->info.subjectName;

    // Mảng câu hỏi của môn học
    subjectData["questions"] = json::array();
    PTRQUESTION questionPtr = node->info.listQuestion;
    int questionIndex = 0;
    while (questionPtr != nullptr) {
        json questionData;
        questionData["questionId"] = questionPtr->info.questionId;
        questionData["content"] = questionPtr->info.content;
        questionData["optionA"] = questionPtr->info.optionA;
        questionData["optionB"] = questionPtr->info.optionB;
        questionData["optionC"] = questionPtr->info.optionC;
        questionData["optionD"] = questionPtr->info.optionD;
        questionData["answer"] = questionPtr->info.answer;
        questionData["isInExam"] = questionPtr->info.isInExam;

        subjectData["questions"][questionIndex++] = questionData;
        questionPtr = questionPtr->next;
    }

    // Thêm môn học vào mảng môn học trong JSON
    j["subjects"].push_back(subjectData);

    // Tiếp tục duyệt cây nhị phân
    saveSubjectToJson(node->left, j);
    saveSubjectToJson(node->right, j);
}

void ManageSubject::loadFromFile() {
    ifstream file(SUBJECT_FILE_NAME);

    if (!file.is_open()) {
        return;
    }

    json j;
    file >> j;  // Đọc dữ liệu từ file vào đối tượng JSON
    file.close();

    // Kiểm tra dữ liệu JSON có hợp lệ không
    if (j.contains("subjects") && j["subjects"].is_array()) {
        // Duyệt qua mảng môn học trong JSON và thêm vào cây nhị phân
        for (const auto& subjectData : j["subjects"]) {
            Subject newSubject;

            // Kiểm tra và lấy subjectCode
            if (subjectData.contains("subjectCode") && subjectData["subjectCode"].is_string()) {
                strcpy_s(newSubject.subjectCode, subjectData["subjectCode"].get<string>().c_str());
            }

            // Kiểm tra và lấy subjectName
            if (subjectData.contains("subjectName") && subjectData["subjectName"].is_string()) {
                newSubject.subjectName = subjectData["subjectName"].get<string>();
            }

            // Xử lý danh sách câu hỏi
            PTRQUESTION lastQuestion = nullptr;
            if (subjectData.contains("questions") && subjectData["questions"].is_array()) {
                for (const auto& questionData : subjectData["questions"]) {
                    Question newQuestion;
                    newQuestion.questionId = questionData["questionId"];
                    newQuestion.content = questionData["content"];
                    newQuestion.optionA = questionData["optionA"];
                    newQuestion.optionB = questionData["optionB"];
                    newQuestion.optionC = questionData["optionC"];
                    newQuestion.optionD = questionData["optionD"];

                    // Kiểm tra answer và lấy ký tự đầu tiên
                    //if (questionData.contains("answer") && questionData["answer"].is_string()) {
                    //    newQuestion.answer = questionData["answer"].get<string>()[0];
                    //}
                    newQuestion.answer = questionData["answer"].get<char>();

                    // Kiểm tra và lấy isInExam
                    if (questionData.contains("isInExam") && questionData["isInExam"].is_boolean()) {
                        newQuestion.isInExam = questionData["isInExam"].get<bool>();
                    }

                    // Chèn câu hỏi vào danh sách câu hỏi của môn học
                    PTRQUESTION questionNode = new NodeQuestion;
                    questionNode->info = newQuestion;
                    questionNode->next = nullptr;

                    if (!newSubject.listQuestion) {
                        newSubject.listQuestion = questionNode;
                    }
                    else {
                        lastQuestion->next = questionNode;
                    }
                    lastQuestion = questionNode;
                }
            }

            // Thêm môn học vào cây nhị phân cân bằng
            insertSubject(newSubject);
        }
    }

    //cout << "Data loaded successfully from JSON format." << endl;
}

// Hàm in ra tất cả câu hỏi của một môn học
void ManageSubject::printQuestionList(const char* subjectCode) {

    PTRQUESTION a = getSubject(subjectCode)->info.listQuestion;
    if (a == nullptr) {
        cout << "No questions available for this subject." << endl;
        return;
    }

    // Duyệt qua danh sách câu hỏi và in ra thông tin
    while (a != nullptr) {
        cout << "Question ID: " << a->info.questionId << endl;
        cout << "Content: " << a->info.content << endl;
        cout << "A. " << a->info.optionA << endl;
        cout << "B. " << a->info.optionB << endl;
        cout << "C. " << a->info.optionC << endl;
        cout << "D. " << a->info.optionD << endl;
        cout << "Answer: " << a->info.answer << endl << endl;
        a = a->next; // Di chuyển đến câu hỏi tiếp theo
    }
}

// Hàm trả về n câu hỏi ramdom lấy ra từ một môn học
//int* ManageSubject::getRandomQuestion(int n, const char* subjectCode) { //truyền vào số câu hỏi thi và mã môn học
//    int totalQuestion = countQuestionsInSubject(subjectCode);
//    if (n > totalQuestion) {
//        cout << "Số lượng câu hỏi vượt quá tổng kho câu hỏi " << endl;
//        return nullptr;
//    }
//    // tìm môn học bằng mã môn học
//    PTRSUBJECT subject = searchSubject(subjectList, subjectCode);
//    if (!subject) {
//        cout << "Không tìm thấy môn học" << endl;
//        return nullptr;
//    }
//
//    // Tạo mảng để lưu tất cả các questionId của môn học
//    int* questionID_Subject = new int[totalQuestion];
//    PTRQUESTION p = subject->info.listQuestion;
//    for (int i = 0; i < totalQuestion; i++) {
//        questionID_Subject[i] = p->info.questionId;
//        p = p->next;       
//    }
//    // trộn ngẫu nhiên mảng ID câu hỏi
//    srand(static_cast<unsigned int>(time(NULL)));
//    for (int i = totalQuestion - 1; i > 0; --i) {
//        int j = rand() % (i + 1);
//        swap(questionID_Subject[i], questionID_Subject[j]);
//    }
//    // Tạo mảng kết quả và lấy ra n câu hỏi đầu tiên trong mảng đã trộn trước đó
//    int* questionID_Random = new int[n];
//    for (int i = 0; i < n; i++) {
//        questionID_Random[i] = questionID_Subject[i];
//    }
//
//    // tạo một danh sách các câu hỏi từ mảng các ID đã random
//    //PTRQUESTION questionList_Random;
//    ManageQuestion questionList_Random;
//    
//    p = subject->info.listQuestion;
//    int currID; // biến duyệt ID hiện tại của mảng
//    
//    for (int i = 0; i < n; i++) {
//        p = subject->info.listQuestion;
//        currID = questionID_Random[i];
//
//        while (p != nullptr) {
//            if (currID == p->info.questionId) {
//                
//                break;
//            }
//            p = p->next;
//        }
//
//    }
//
//
//    // Giải phóng bộ nhớ của questionID
//    delete[] questionID_Subject;
//
//    // Trả về mảng chứa n câu hỏi ngẫu nhiên
//    return questionID_Random;
//}

ManageQuestion ManageSubject::getRandomQuestion(int n, const char* subjectCode) { //truyền vào số câu hỏi thi và mã môn học
    PTRSUBJECT subject = searchSubject(subjectList, subjectCode); // tìm môn học bằng mã môn học
    ManageQuestion questionList_Random(subject->info.listQuestion); //tạo đối tượng quản lý danh sách câu hỏi sau khi random
    
    if (!subject) {
        cout << "Không tìm thấy môn học" << endl;
        return questionList_Random;
    }

    int totalQuestion = countQuestionsInSubject(subjectCode);
    if (n > totalQuestion) {
        cout << "Số lượng câu hỏi vượt quá tổng kho câu hỏi " << endl;
        return questionList_Random;
    }

    questionList_Random.getRandomQuestion(n);
    return questionList_Random;
}

SubjectPage ManageSubject::getSubjectPerPage(int pageNumber)
{
    SubjectPage subjectPage;
    subjectPage.subjects = nullptr;
    int subjectPerPage = 13;
    int totalSubject = getCountSubjects();
    int totalPages = (totalSubject + subjectPerPage - 1) / subjectPerPage;
    subjectPage.currentPage = pageNumber;
    subjectPage.totalPage = totalPages;
    subjectPage.totalSubject = totalSubject;
    subjectPage.numberSubjectPerPage = subjectPerPage;

    PTRSUBJECT pageResult = nullptr;

    if (pageNumber < 1 || pageNumber > totalPages) {
        return subjectPage;
    }

    // Tính toán chỉ số bắt đầu và kết thúc
    int startIndex = (pageNumber - 1) * subjectPerPage;
    int endIndex = min(startIndex + subjectPerPage, totalSubject);
    int count = 0;
    getPageSubject(pageResult, subjectList, count, startIndex, endIndex);

    subjectPage.startIndex = startIndex;
    subjectPage.endIndex = endIndex;
    subjectPage.subjects = pageResult;
    return subjectPage;
}



SubjectPage ManageSubject::searchSubjects(string keyword, int page)
{

    ManageSubject manageSubject;
    if (keyword == "") {
        return manageSubject.getSubjectPerPage(page);
    }
    int countSubject = 0;
    manageSubject.reset();
    // Duyệt cây AVL gốc và thêm các môn học khớp từ khóa vào cây tạm
    collectMatchingSubjects(this->subjectList, manageSubject.subjectList, keyword);

    // Trả về danh sách phân trang từ cây tạm
    return manageSubject.getSubjectPerPage(page);
}

void ManageSubject::reset() {
    deleteTree(subjectList);
    subjectList = nullptr; // Đặt cây về trạng thái rỗng
}

bool ManageSubject::deleteSubject(string code) {
    bool isDeleted = deleteNode(subjectList, code);
    if (!isDeleted) return false;
    saveToFile();
    return true;
}


// ----------------------- PRIVATE METHOD --------------------------//
// Hàm giúp tạo SubjectNode mới
PTRSUBJECT ManageSubject::createSubjectNode(const char* code, const string& name) {
    PTRSUBJECT newNode = new SubjectNode;
    strcpy_s(newNode->info.subjectCode, code);
    newNode->info.subjectName = name;
    newNode->left = newNode->right = nullptr;
    newNode->info.listQuestion = nullptr; // Danh sách câu hỏi bắt đầu là trống
    return newNode;
}

void ManageSubject::insertSubjectHelper(PTRSUBJECT& subjectList, const Subject& subject)
{
    if (subjectList == nullptr) {
        subjectList = new SubjectNode;
        subjectList->info = subject;
        subjectList->left = subjectList->right = nullptr;
    }
    else if ((string) subject.subjectCode < (string) subjectList->info.subjectCode) {
        insertSubjectHelper(subjectList->left, subject);
    }
    else if ((string)subject.subjectCode > (string)subjectList->info.subjectCode) {
        insertSubjectHelper(subjectList->right, subject);
    }
}

// Hàm chèn môn học vào cây nhị phân cân bằng
void ManageSubject::insertSubject(const Subject& subject) {
    insertSubjectHelper(subjectList, subject);
}

// Hàm tìm kiếm môn học theo mã môn
PTRSUBJECT ManageSubject::searchSubject(PTRSUBJECT root, const char* code) {
    PTRSUBJECT p;
    p = root;
    while (p != nullptr) {
        int cmp = strcmp(code, p->info.subjectCode);
        if (cmp == 0) return p;
        else if (cmp < 0) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }
    return nullptr;
}

// Hàm thêm câu hỏi vào môn học
void ManageSubject::addQuestionToSubject(PTRSUBJECT& subjectNode, const string& content,
    const string& optionA, const string& optionB,
    const string& optionC, const string& optionD, char answer) {
    // Tạo câu hỏi mới
    PTRQUESTION newQuestion = new NodeQuestion;
    // Sinh tự động questionId

    newQuestion->info.questionId = generateUniqueQuestionId(subjectNode->info.listQuestion);

    newQuestion->info.content = content;
    newQuestion->info.optionA = optionA;
    newQuestion->info.optionB = optionB;
    newQuestion->info.optionC = optionC;
    newQuestion->info.optionD = optionD;
    newQuestion->info.answer = answer;
    newQuestion->next = nullptr;
    // Thêm câu hỏi vào danh sách câu hỏi của môn học
    //newQuestion->next = subjectNode->info.listQuestion;
    //subjectNode->info.listQuestion = newQuestion;
    if (subjectNode->info.listQuestion == nullptr) {
        subjectNode->info.listQuestion = newQuestion;
    } 
    else {
        newQuestion->next = subjectNode->info.listQuestion;
        subjectNode->info.listQuestion = newQuestion;
    }
    return;
}

// Hàm in tất cả các môn học (traversal cây nhị phân)
void ManageSubject::printSubjects(PTRSUBJECT root) {
    const int STACKSIZE = 500;
    PTRSUBJECT Stack[STACKSIZE];
    int sp = -1; // Stack rong
    PTRSUBJECT p = root;
    while (p != nullptr) {
        cout << "Subject Code: " << p->info.subjectCode << ", Subject Name: " << p->info.subjectName << endl;
        cout << "So cau hoi " << getCountQuestionInList(p->info.listQuestion) << endl;

        if (p->right != nullptr) {
            Stack[++sp] = p->right;
        }
        if (p->left != nullptr) {
            p = p->left;
        }
        else if (sp == -1) break;
        else p = Stack[sp--];
    }

}

// Hàm in tất cả các môn học (traversal cây nhị phân)
void ManageSubject::printSubjectsD(PTRSUBJECT root) {

    if (!root) return;
    cout << "Subject Code: " << root->info.subjectCode << ", Subject Name: " << root->info.subjectName << endl;
    cout << "So cau hoi " << getCountQuestionInList(root->info.listQuestion) << endl;
    printSubjectsD(root->left);
    printSubjectsD(root->right);
}

// Hàm giải phóng bộ nhớ khi xóa môn học
void ManageSubject::deleteSubject(PTRSUBJECT root) {
    if (!root) return;
    deleteSubject(root->left);
    deleteSubject(root->right);

    // Xóa danh sách câu hỏi
    PTRQUESTION temp = root->info.listQuestion;
    while (temp) {
        PTRQUESTION toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }

    delete root;
}

int ManageSubject::countSubjectsInRoot(PTRSUBJECT root) {
    // Đếm tổng số môn học
    if (!root) return 0;
    return 1 + countSubjectsInRoot(root->left) + countSubjectsInRoot(root->right);
}

// Hàm xác định vị trí cây
void ManageSubject::getPageSubject(PTRSUBJECT& result, PTRSUBJECT root, int& count, int startIndex, int endIndex) {
    if (!root || count >= endIndex) return;

    getPageSubject(result, root->left, count, startIndex, endIndex);

    if (count >= startIndex && count < endIndex) {
        // Chỉ thêm node vào kết quả nếu trong khoảng
        insertSubjectToTree(result, root->info.subjectCode, root->info.subjectName);
    }

    count++; 

    getPageSubject(result, root->right, count, startIndex, endIndex);
}

bool ManageSubject::isSubjectCanDelete(const string subjectCode)
{
    PTRSUBJECT subjectFound = getSubject(subjectCode.c_str());
    if (subjectFound == nullptr) return false;
    return subjectFound->info.listQuestion == nullptr;
}

void ManageSubject::deleteTree(PTRSUBJECT& root) {
    if (!root) return;
    // Đệ quy giải phóng các node con
    deleteTree(root->left);
    deleteTree(root->right);

    // Giải phóng node hiện tại
    delete root;
    root = nullptr; // Đảm bảo không trỏ tới vùng nhớ đã giải phóng
}

void ManageSubject::collectMatchingSubjects(PTRSUBJECT root, PTRSUBJECT& tempTree, const string& keyword) {
    if (!root) return;

    // Duyệt cây theo thứ tự in-order (left → root → right)
    collectMatchingSubjects(root->left, tempTree, keyword);

    // Kiểm tra nếu khớp từ khóa trong tên hoặc mã môn học
    if (containString(root->info.subjectName, keyword) || containString(root->info.subjectCode, keyword)) {
        insertSubjectToTree(tempTree, root->info.subjectCode, root->info.subjectName);
    }

    collectMatchingSubjects(root->right, tempTree, keyword);
}

string ManageSubject::getSubjectNameFromCode(const char* subjectCode) {
    ManageSubject manageSubject;
    PTRSUBJECT subject = manageSubject.getSubject(subjectCode);
    if (subject == nullptr) {
        return "";
    }
    return subject->info.subjectName;
}


// Hàm chèn môn học vào cây nhị phân cân bằng
void insertSubjectToTree(PTRSUBJECT& root, string subjectCode, string subjectName) {

    if (root == nullptr) {
        root = new SubjectNode;
        strcpy_s(root->info.subjectCode, subjectCode.c_str());
        root->info.subjectName = subjectName;
        root->info.listQuestion = nullptr;
        root->left = root->right = nullptr;
    }
    else if (subjectCode < (string)root->info.subjectCode) {
        insertSubjectToTree(root->left, subjectCode, subjectName);
    }
    else if(subjectCode > (string)root->info.subjectCode) {
        insertSubjectToTree(root->right, subjectCode, subjectName);
    }
}


// Hàm in tất cả các môn học (traversal cây nhị phân)
void printSubjectInAVL(PTRSUBJECT root) {
    if (!root) return;
    printSubjectInAVL(root->left);
    cout << "Subject Code: " << root->info.subjectCode << ", Subject Name: " << root->info.subjectName << endl;
    printSubjectInAVL(root->right);
}

// Tìm nút có giá trị nhỏ nhất trong cây con
PTRSUBJECT getMinValueNode(PTRSUBJECT node) {
    PTRSUBJECT current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

void deleteNodeCase3(PTRSUBJECT& root)
{
    if (root->left != nullptr) {
        deleteNodeCase3(root->left);
    }
    else {
        PTRSUBJECT temp = root;
        root = root->right; 
        delete temp;
    }
}

// Hàm xóa nút theo code
bool deleteNode(PTRSUBJECT& root, string code) {
    if (root == nullptr) return false; // Base case: node not found

    // Traverse the tree
    if (code < root->info.subjectCode) {
        return deleteNode(root->left, code); // Traverse left
    }
    else if (code > root->info.subjectCode) {
        return deleteNode(root->right, code); // Traverse right
    }
    else {
        // Node found
        PTRSUBJECT temp = root;

        if (root->left == nullptr) {
            root = root->right; // No left child, move right child up
        }
        else if (root->right == nullptr) {
            root = root->left; // No right child, move left child up
        }
        else {
            // Both children exist, need to replace with the leftmost node of the right subtree
            deleteNodeCase3(root->right); // Remove the leftmost node in right subtree
            root->info = temp->info; // Copy data from the node to be deleted
        }

        delete temp; // Delete the original node
        return true; // Node successfully deleted
    }
}


int countSubjectsInList(PTRSUBJECT root) {
    // Đếm tổng số môn học
    if (!root) return 0;
    return 1 + countSubjectsInList(root->left) + countSubjectsInList(root->right);
}